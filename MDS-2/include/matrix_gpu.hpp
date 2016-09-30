/*
 * matrix_gpu.hpp
 *
 *  Created on: Aug 16, 2016
 *      Author: lizhifeng
 */

#ifndef MATRIX_GPU_HPP_
#define MATRIX_GPU_HPP_

#include <cusparse.h>
#include <cuda_runtime.h>

#include <cublas_v2.h>

#include "kernel.hpp"

#define VALTUE_TYPE float


VALTUE_TYPE* gpu_alloc(size_t size);
int gpu_cpy(VALTUE_TYPE *dst, VALTUE_TYPE *src, size_t size);
int gpu_memset_zero(VALTUE_TYPE *mem, size_t size);

#endif /* MATRIX_GPU_HPP_ */
