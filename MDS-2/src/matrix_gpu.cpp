/*
 * matrix_gpu.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: lizhifeng
 */

#include "matrix_gpu.hpp"
#include "comm.hpp"

VALTUE_TYPE* gpu_alloc(size_t size){

	VALTUE_TYPE *mem;
	cudaError_t status = cudaMalloc((void **)&mem, size * sizeof(VALTUE_TYPE));
	CHECK_CUDA_RESULT(status);
	return mem;
}

int gpu_cpy(VALTUE_TYPE *dst, VALTUE_TYPE *src, size_t size){
	cudaError_t status = cudaMemcpy(dst, src, size*sizeof(VALTUE_TYPE), cudaMemcpyDefault);
	CHECK_CUDA_RESULT(status);
	return 0;
}

int gpu_memset_zero(VALTUE_TYPE *mem, size_t size){

	cudaError_t status = cudaMemset(mem, 0, size*sizeof(VALTUE_TYPE));
	CHECK_CUDA_RESULT(status);
	return 0;

}



