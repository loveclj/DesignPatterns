
/**
 * Copyright 1993-2012 NVIDIA Corporation.  All rights reserved.
 *
 * Please refer to the NVIDIA end user license agreement (EULA) associated
 * with this source code for terms and conditions that govern your use of
 * this software. Any use, reproduction, disclosure, or distribution of
 * this software and related documentation outside the terms of the EULA
 * is strictly prohibited.
 */

#include "kernel.hpp"
#include <cstdio>
using namespace std;


/*
 * calculate vec1 + vec2
 */
__global__ void kernel_vector_add(VALTUE_TYPE *X, VALTUE_TYPE *delta, int size, float alpha){
	unsigned int tid = threadIdx.x;
	unsigned int blockId = blockIdx.x;
	unsigned int offset = blockId * blockDim.x + tid;

	if(offset < size){
		X[offset] -= alpha * delta[offset];
	}
}

void update_output(VALTUE_TYPE *X, VALTUE_TYPE *Y, VALTUE_TYPE *deltaX, VALTUE_TYPE *deltaY, int size, float alpha){
	int num_grid = size / WORK_SIZE + 1;
	dim3 grid(num_grid);
	dim3 block(WORK_SIZE);

	cublasHandle_t handle;
	cublasCreate(&handle);

	kernel_vector_add <<< grid, block >>>(X, deltaX, size, alpha);
	kernel_vector_add <<< grid, block >>>(Y, deltaY, size, alpha);
}



/*
 * tanimoto distance
 */


__global__ void kernel_tanimoto_distance(VALTUE_TYPE *d_weight_sum, VALTUE_TYPE* d_dist_matrix, size_t n_vec){

	unsigned int row = blockIdx.x;
	unsigned int tid = threadIdx.x;
	unsigned int base = row * n_vec;

	float sum1 = d_weight_sum[row];

	int n = (n_vec + blockDim.x - 1) / blockDim.x;

	for(int i=0; i<n; ++i){
		unsigned int offset = tid + i * blockDim.x;
		if(offset < n_vec){
			float sum2 = d_weight_sum[offset];
			float comm = d_dist_matrix[base + offset];
			float dist = 1 - comm / (sum1 + sum2 - comm);

			if(dist < 0.001){
				dist = 0.01;
			}
			d_dist_matrix[base + offset] = dist;
		}

	}
}



void tanimoto_distance(VALTUE_TYPE *d_data_matrix, VALTUE_TYPE *d_weight_sum, VALTUE_TYPE* d_dist_matrix, size_t n_vec, int dimension){

	int thread_num_per_block = WORK_SIZE;
	while(thread_num_per_block > n_vec){
		thread_num_per_block /= 2;
	}

	dim3 grid(n_vec);
	dim3 block(thread_num_per_block);

	float alpha = 1.0;
	float beta = 0;
	cublasHandle_t handle;
	cublasCreate(&handle);
	cublasSgemm(handle, CUBLAS_OP_T, CUBLAS_OP_N, n_vec, n_vec, dimension, &alpha, d_data_matrix, dimension, d_data_matrix, dimension, &beta, d_dist_matrix, n_vec);


	kernel_tanimoto_distance <<< grid, block>>>(d_weight_sum, d_dist_matrix, n_vec);
}


/*
 * cat gradient from point start to point end
 */
__global__ void kernel_calculate_gradient(VALTUE_TYPE *d_tanimoto_dist, VALTUE_TYPE *d_x_arr, VALTUE_TYPE * d_y_arr,
		VALTUE_TYPE *d_gradient_x, VALTUE_TYPE *d_gradient_y,
		size_t start, size_t end, size_t n_vec){

	unsigned int tid = threadIdx.x;
	unsigned int vec_i = blockIdx.x; // row,
	unsigned int base = vec_i * n_vec;

	unsigned int n = (n_vec + blockDim.x - 1) / blockDim.x;
//	printf("%d\n", tid);

//		for(int vec_j=tid; vec_j<n_vec; vec_j += blockDim.x){
		for(int i=0; i<n; ++i){

			unsigned int vec_j = tid + i * blockDim.x;
			if(vec_j >= n_vec){
				continue;
			}
			int offset = base + vec_j;

			if(vec_i == vec_j){
				d_gradient_x[offset] = 0;
				d_gradient_y[offset] = 0;
					continue;
			}

			float x1 = d_x_arr[vec_i];
			float y1 = d_y_arr[vec_i];

			float x2 = d_x_arr[vec_j];
			float y2 = d_y_arr[vec_j];

			float dx = x1 - x2;
			float dy = y1 - y2;

			float dist_2D = sqrt(pow(dx, 2) + pow(dy, 2));


			float tanimoto_distance = d_tanimoto_dist[offset];

			float c = (dist_2D - tanimoto_distance)/(dist_2D*tanimoto_distance);
//			printf("%f %d\n", tanimoto_distance, offset);

			d_gradient_x[offset] = c * dx;
			d_gradient_y[offset] = c * dy;
//			printf("(%d, %d) %f %f\n", vec_i, vec_j, c*dx, c*dy);


//			printf("%f\n", dx);

		}

}




void caculate_gradient(VALTUE_TYPE *d_tanimoto_dist, VALTUE_TYPE *d_x_arr, VALTUE_TYPE * d_y_arr,
		VALTUE_TYPE *d_gradient_x, VALTUE_TYPE *d_gradient_y,
		size_t start, size_t end, size_t n_vec){

	dim3 grid(end-start);
	dim3 block(WORK_SIZE);

	kernel_calculate_gradient<<< grid, block >>>(d_tanimoto_dist, d_x_arr, d_y_arr,d_gradient_x, d_gradient_y, start, end, n_vec);
}

__global__ void kernel_calculate_gradient2(VALTUE_TYPE *d_gradient_x, VALTUE_TYPE *d_gradient_y,VALTUE_TYPE *d_x_arr, VALTUE_TYPE *d_y_arr, VALTUE_TYPE *d_tanimoto_dist, int n_vec)
{
		unsigned int tid = threadIdx.x;
		unsigned int vec_i = blockIdx.x; // row,
		unsigned int base = vec_i * n_vec;

		__shared__ float sum_x[WORK_SIZE];
		__shared__ float sum_y[WORK_SIZE];

		unsigned int n = (n_vec + blockDim.x - 1) / blockDim.x;
	//	printf("%d\n", tid);


			sum_x[tid] = 0;
			sum_y[tid] = 0;
	//		for(int vec_j=tid; vec_j<n_vec; vec_j += blockDim.x){
			for(int i=0; i<n; ++i){

				unsigned int vec_j = tid + i * blockDim.x;
				if(vec_j >= n_vec){
					continue;
				}
				int offset = base + vec_j;

				if(vec_i == vec_j){
//					d_gradient_x[offset] = 0;
//					d_gradient_y[offset] = 0;
						continue;
				}

				float x1 = d_x_arr[vec_i];
				float y1 = d_y_arr[vec_i];

				float x2 = d_x_arr[vec_j];
				float y2 = d_y_arr[vec_j];

				float dx = x1 - x2;
				float dy = y1 - y2;

				float dist_2D = sqrt(pow(dx, 2) + pow(dy, 2));


				float tanimoto_distance = d_tanimoto_dist[offset];

				float c = (dist_2D - tanimoto_distance)/(dist_2D*tanimoto_distance);
	//			printf("%f %d\n", tanimoto_distance, offset);

//				d_gradient_x[offset] = c * dx;
//				d_gradient_y[offset] = c * dy;
				float a = c * dx;

				sum_x[tid] += a;

				a = c * dy;
				sum_y[tid] += a;
//				printf("(%d, %d) %f %f\n", vec_i, vec_j, c*dx, c*dy);
	//			printf("%f\n", dx);

			}

			__syncthreads();

			for(int half = blockDim.x/2; half != 0; half /= 2){
					if(tid < half){
						sum_x[tid] += sum_x[tid+half];
						sum_y[tid] += sum_y[tid+half];
					}
					__syncthreads();
				}

				if(tid == 0){
					d_gradient_x[vec_i] = sum_x[0];
					d_gradient_y[vec_i] = sum_y[0];
//					printf("%d %f\n", vec_i, sum_x[0]);
			//				printf("%f\n", sum[0]);
				}

}

void caculate_gradient(VALTUE_TYPE *d_gradient_x, VALTUE_TYPE *d_gradient_y, VALTUE_TYPE *d_x_arr, VALTUE_TYPE *d_y_arr, VALTUE_TYPE *d_tanimoto_dist, int n_vec){
	dim3 grid(n_vec);
	dim3 block(WORK_SIZE);

	kernel_calculate_gradient2 <<< grid, block >>>(d_gradient_x, d_gradient_y, d_x_arr, d_y_arr, d_tanimoto_dist, n_vec);
}

/*
 * add by row
 */

__global__ void kernel_row_acc(VALTUE_TYPE* d_arr, VALTUE_TYPE* d_sum, int dimension, int row_offset){
	unsigned int tid = threadIdx.x;
	unsigned int step = blockDim.x;
	unsigned int base =  blockIdx.x * dimension;
	int n = (dimension + blockDim.x - 1) / step;

//	for(int i=0; i<n; ++i){
//		unsigned int offset = tid + i * step;
//		if(offset < dimension){
//			float sum = 0;
//			for(int j=0; j<dimension; ++j){
//				sum += d_arr[offset + j*dimension];
//			}
//			d_arr[offset] = sum;
//		}
//	}


	__shared__ float sum[WORK_SIZE];

	sum[tid] = 0;
	for(int i=0; i<n; i += 1){
		int offset = tid + i * step;
		if(offset < dimension){
			sum[tid] += fabsf(d_arr[base + offset]);
		}

	}
	__syncthreads();

	for(int half = step/2; half != 0; half /= 2){
		if(tid < half){
			sum[tid] += sum[tid+half];
		}
		__syncthreads();
	}

	if(tid == 0){
		d_sum[row_offset+blockIdx.x] = sum[0];
		printf("%d %f\n", blockIdx.x, sum[0]);
//				printf("%f\n", sum[0]);
	}
}

void row_acc(VALTUE_TYPE* d_arr, VALTUE_TYPE* d_sum, int row, int dimension, int row_offset){

	int thread_num_per_block = WORK_SIZE;
	while(thread_num_per_block > dimension){
		thread_num_per_block /= 2;
	}

	dim3 grid(row);
	dim3 block(thread_num_per_block);

	kernel_row_acc<<< grid, block >>>(d_arr, d_sum, dimension, row_offset);
}


/*
 * add by row
 */

__global__ void kernel_row_square_acc(VALTUE_TYPE* d_arr, VALTUE_TYPE* d_sum, int dimension, int row_offset){
	unsigned int tid = threadIdx.x;
	unsigned int step = blockDim.x;
	unsigned int base =  blockIdx.x * dimension;
	int n = (dimension + blockDim.x - 1) / step;


	__shared__ float sum[WORK_SIZE];

	sum[tid] = 0;
	for(int i=0; i<n; i += 1){
		int offset = tid + i * step;
		if(offset < dimension){
			float v = d_arr[base + offset];
			sum[tid] += v * v;
		}

	}
	__syncthreads();

	for(int half = step/2; half != 0; half /= 2){
		if(tid < half){
			sum[tid] += sum[tid+half];
		}
		__syncthreads();
	}

	if(tid == 0){
		d_sum[row_offset+blockIdx.x] = sum[0];
//				printf("%f\n", sum[0]);
	}
}

void row_square_acc(VALTUE_TYPE* d_arr, VALTUE_TYPE* d_sum, int row, int dimension, int row_offset){

	int thread_num_per_block = WORK_SIZE;
	while(thread_num_per_block > dimension){
		thread_num_per_block /= 2;
	}

	dim3 grid(row);
	dim3 block(thread_num_per_block);

	kernel_row_square_acc<<< grid, block >>>(d_arr, d_sum, dimension, row_offset);
}
