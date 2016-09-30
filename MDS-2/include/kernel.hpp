/*
 * kernel.hpp
 *
 *  Created on: Aug 16, 2016
 *      Author: lizhifeng
 */

#ifndef KERNEL_HPP_
#define KERNEL_HPP_

#include <stdio.h>
#include <stdlib.h>
#include <cuda.h>
#include <cublas_v2.h>
#include <cuda_runtime.h>

#include "comm.hpp"

static const int WORK_SIZE = 128;

/**
 * This macro checks return value of the CUDA runtime call and exits
 * the application if the call failed.
 *
 * See cuda.h for error code descriptions.
 */
#define CHECK_CUDA_RESULT(status) {											\
												\
	if (status != cudaSuccess) {													\
		printf("CUDA call on line %d returned error %d\n", __LINE__,	\
			status);													\
		exit(1);														\
	} }


void update_output(VALTUE_TYPE *X, VALTUE_TYPE *Y, VALTUE_TYPE *deltaX, VALTUE_TYPE *delataY, int dimension, float alpha);

void caculate_gradient(VALTUE_TYPE *d_tanimoto_dist, VALTUE_TYPE *d_x_arr, VALTUE_TYPE * d_y_arr,
		VALTUE_TYPE *d_gradient_x, VALTUE_TYPE *d_gradient_y,
		size_t start, size_t end, size_t n_vec);

void caculate_gradient(VALTUE_TYPE *d_gradient_x, VALTUE_TYPE *d_gradient_y, VALTUE_TYPE *d_x_arr, VALTUE_TYPE *d_y_arr, VALTUE_TYPE *d_tanimoto_dist, int n_vec);


void tanimoto_distance(VALTUE_TYPE *d_data_matrix, VALTUE_TYPE *d_weight_sum, VALTUE_TYPE* d_dist_matrix, size_t n_vec, int dimension);
void row_acc(VALTUE_TYPE* d_arr, VALTUE_TYPE* d_sum, int row, int dimension, int row_offset=0);
void row_square_acc(VALTUE_TYPE* d_arr, VALTUE_TYPE* d_sum, int row, int dimension, int row_offset=0);

#endif /* KERNEL_HPP_ */
