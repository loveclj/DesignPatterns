/*
 * train_gpu.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: lizhifeng
 */

#include "train_gpu.hpp"
#include "comm.hpp"

#include <iostream>
using namespace std;


void init_gpu(VALTUE_TYPE *h_data_matrix, VALTUE_TYPE *h_x_arr, VALTUE_TYPE *h_y_arr,
		VALTUE_TYPE *&d_data_matrix, VALTUE_TYPE *&d_x_arr, VALTUE_TYPE *&d_y_arr, int dimension, int n_vec){

	d_data_matrix = gpu_alloc(n_vec*dimension);
	d_x_arr = gpu_alloc(n_vec);
	d_y_arr = gpu_alloc(n_vec);



	gpu_cpy(d_data_matrix, h_data_matrix, dimension*n_vec);
	gpu_cpy(d_x_arr, h_x_arr, n_vec);
	gpu_cpy(d_y_arr, h_y_arr, n_vec);

	/**
	 * test init & cpy
	 */
#if DEBUG
	VALTUE_TYPE *x = new VALTUE_TYPE[n_vec];
	VALTUE_TYPE *y = new VALTUE_TYPE[n_vec];
	VALTUE_TYPE *m = new VALTUE_TYPE[dimension*n_vec];

	gpu_cpy(x, d_x_arr, n_vec);
	gpu_cpy(y, d_y_arr, n_vec);
	gpu_cpy(m, d_data_matrix, dimension*n_vec);

	for(int i=0; i<n_vec; i++){
		if(h_x_arr[i] != x[i]){
			cout << "error cpy x" << endl;
		}

		if(h_y_arr[i] != y[i]){
			cout << "error cpy y" << endl;
		}
	}

	for(int i=0; i<dimension*n_vec; ++i){
		if(h_data_matrix[i] != m[i]){
			cout << "error cpy matrix " << endl;
		}
	}
#endif


}


int train(int total_epoch, int split_size, float learn_rate, VALTUE_TYPE *h_data_matrix, VALTUE_TYPE *&h_x_arr, VALTUE_TYPE *&h_y_arr, int dimension, int n_vec){

	VALTUE_TYPE *d_data_matrix;
	VALTUE_TYPE *d_x_arr;
	VALTUE_TYPE *d_y_arr;

	struct timeval timeStart,
				   timeStop;

	gettimeofday(&timeStart, NULL);
	/*
	 * alloc gpu memory & copy cpu memory to gpu memory
	 */
	init_gpu(h_data_matrix, h_x_arr, h_y_arr, d_data_matrix, d_x_arr, d_y_arr, dimension, n_vec);

	float *d_data_vec_sum = gpu_alloc(n_vec);
	row_square_acc(d_data_matrix, d_data_vec_sum, n_vec, dimension);


	float *d_deltaX = gpu_alloc(n_vec);
	float *d_deltaY = gpu_alloc(n_vec);

	gpu_memset_zero(d_deltaX, n_vec);
	gpu_memset_zero(d_deltaY, n_vec);

	float *d_tanimoto_dist_matrix = gpu_alloc(split_size*n_vec);
	float *d_gradient_x = gpu_alloc(split_size*n_vec);
	float *d_gradient_y = gpu_alloc(split_size*n_vec);



//
//	float *d_data_matrix_trans = gpu_alloc(n_vec*dimension);
//	float *h_data_matrix_trans = new float[n_vec*dimension];
//	for(int i=0; i<n_vec;++i){
//		for(int j=0; j<dimension; ++j){
//			h_data_matrix_trans[j*n_vec + i] = h_data_matrix[i*dimension + j];
//		}
//	}
//
//	gpu_cpy(d_data_matrix_trans, h_data_matrix_trans, n_vec * dimension);
//	cout << "dist " << endl;
//	tanimoto_distance(d_data_matrix_trans, d_data_vec_sum, d_tanimoto_dist_matrix , 0, n_vec, n_vec, dimension);





	float* h_dist_mat = new float[n_vec*n_vec];
//
//	for(int i=0;i<n_vec; i++){
//		for(int j=0; j<n_vec; ++j){
//			float sum1 = 0;
//			float sum2 = 0;
//			float comm = 0;
//			for(int k=0; k<dimension; ++k){
//				float a = h_data_matrix[i*dimension + k];
//				float b = h_data_matrix[j*dimension + k];
//
//				sum1 += a*a;
//				sum2 += b*b;
//
//				if(a == b){
//					comm += a*a;
//				}
//
//			}
//			float distance;
//
//			if(i == j){
//				distance = 0;
//			}
//			else{
//				distance = 1 - comm/(sum2+sum1-comm);
//				if(distance<0.001){
//					distance = 0.01;
//				}
//			}
//
//			h_dist_mat[i*n_vec + j] = distance;
////			cout << distance << endl;
//		}
//	}


//	gpu_cpy(d_tanimoto_dist_matrix, h_dist_mat, n_vec*n_vec);

	tanimoto_distance(d_data_matrix, d_data_vec_sum, d_tanimoto_dist_matrix, n_vec, dimension);


	gpu_cpy(h_dist_mat, d_tanimoto_dist_matrix, n_vec*n_vec);
	cudaThreadSynchronize();
//
//	for(int i=0; i<n_vec*n_vec; ++i){
//		if(fabsf(h2[i] - h_dist_mat[i]) > 0.01 ){
//			cout << h2[i] << " " << h_dist_mat[i] << endl;
//		}
//	}
//	cout << h2[1] << endl;


//	return 0;

	float err_h = 0;
	float err_low = 0;


	for(int epoch=0; epoch<total_epoch; ++epoch){
//		cout << epoch << endl;


		for(int start=0; start<n_vec; start += split_size){

			int end = start + split_size;

			caculate_gradient(d_deltaX, d_deltaY, d_x_arr, d_y_arr, d_tanimoto_dist_matrix, n_vec);



//			caculate_gradient(d_tanimoto_dist_matrix , d_x_arr, d_y_arr, d_gradient_x, d_gradient_y, start, end, n_vec);

//			row_acc(d_gradient_x, d_deltaX, split_size, n_vec, start);
//
//			row_acc(d_gradient_y, d_deltaY, split_size, n_vec, start);
//			cudaThreadSynchronize();


		}

		update_output(d_x_arr, d_y_arr, d_deltaX, d_deltaY, n_vec, learn_rate);
//		return 0;

		if(epoch % 1000 == 0){
			gpu_cpy(h_x_arr, d_x_arr, n_vec);
			gpu_cpy(h_y_arr, d_y_arr, n_vec);
			cudaThreadSynchronize();

			double stress = 0;
			double remain = 0;
			int k = 0;
			for(int i=0;i<n_vec; i++){
					for(int j=0; j<n_vec; ++j){
						if( i == j){
							continue;
						}
						float err = sqrt(pow(h_y_arr[i] - h_y_arr[j], 2) +  pow(h_x_arr[i] - h_x_arr[j], 2)) - h_dist_mat[i* n_vec + j];
//                        cout << err << endl;

						err = fabsf(err) / h_dist_mat[i* n_vec + j];
						float new_stress = stress + err + remain;
						remain = err + remain - (new_stress -stress);
						stress = new_stress;

						if (stress > 100){
							stress -= 100;
							k++;
						}

					}
				}
//			cout << "epoch: " << epoch << " " << "stress: " << k <<"*100 "<< stress << endl;

			float diff = fabsf((k - err_h)*100 - (stress - err_low));
			cout << diff << " " << k << " " << stress  << epoch <<  endl;
			if (diff < 0.1){
				break;
			}
			err_h = k;
			err_low = stress;
		}



	}

	cudaThreadSynchronize();
	gettimeofday(&timeStop, NULL);
		cout << timeval_sub(timeStop, timeStart) << endl;

	/*
	 * test  distance
	 */
#if 0

	float *h_dist_matrix = new float[split_size*n_vec];
	gpu_cpy(h_dist_matrix, d_tanimoto_dist_matrix, split_size*n_vec);

	float *h_dis = new float[split_size*n_vec];
	for(int i=0; i<split_size; ++i){
		for(int j=0; j<n_vec; ++j){
			float comm = 0;
			int offset1 = i * dimension;
			int offset2 = j * dimension;
			for(int k=0; k<dimension; ++k){
						float x = h_data_matrix[offset1 + k];
						float y = h_data_matrix[offset2 + k];
						if(x == y){
							comm += x;
						}
			}

			h_dis[i*n_vec +j] = 1 - comm / (h_data_vec_sum[i] + h_data_vec_sum[j] - comm);

		}

	}

//	for(int i=0; i<split_size*n_vec; ++i){
//		cout << h_dist_matrix[i] - h_dis[i]<< endl;
//	}

	float *h_x_gradient_cpu = new float[split_size*n_vec];
	for(int i=0; i<split_size; ++i){
		for(int j=0; j<n_vec; ++j){

			if(i == j){
				h_x_gradient_cpu[i*n_vec+j] = 0;
				continue;
			}
			float tani = h_dist_matrix[i*n_vec+j];
			float x1 = h_x_arr[i];
			float x2 = h_x_arr[j];
			float y1 = h_y_arr[i];
			float y2 = h_y_arr[j];

			float d = sqrt(pow(x1-x2, 2) + pow(y1-y2, 2));

			h_x_gradient_cpu[i*n_vec+j] = (d - tani)/(d*tani) *(x1-x2);
		}
	}

	float *h_x_gradient = new float[split_size*n_vec];
	gpu_cpy(h_x_gradient, d_gradient_x, split_size*n_vec);
	for(int i=0; i<split_size*n_vec; ++i){
		cout << h_x_gradient[i] - h_x_gradient_cpu[i]<< endl;
	}


#endif


//	for(int i=0; i<total_epoch; ++i){
//		update_output(d_x_arr, d_y_arr, deltaX, deltaY, n_vec, 0.1);
//	}

	gpu_cpy(h_x_arr, d_x_arr, n_vec);
	gpu_cpy(h_y_arr, d_y_arr, n_vec);

//	for(int i=0; i<n_vec; ++i){
//		cout << h_x_arr[i] << endl;
//	}

}



































