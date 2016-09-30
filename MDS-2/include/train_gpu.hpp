/*
 * train_gpu.hpp
 *
 *  Created on: Aug 16, 2016
 *      Author: lizhifeng
 */

#ifndef TRAIN_GPU_HPP_
#define TRAIN_GPU_HPP_

#include "kernel.hpp"
#include "matrix_gpu.hpp"

void init_gpu(VALTUE_TYPE *h_data_matrix, VALTUE_TYPE *h_x_arr, VALTUE_TYPE *h_y_arr,
		VALTUE_TYPE *&d_data_matrix, VALTUE_TYPE *&d_x_arr, VALTUE_TYPE *&d_y_arr, int dimension, int n_vec);

int train(int total_epoch, int split_size, float learn_rate, VALTUE_TYPE *h_data_matrix, VALTUE_TYPE *&h_x_arr, VALTUE_TYPE *&h_y_arr, int dimension, int n_vec);
#endif /* TRAIN_GPU_HPP_ */
