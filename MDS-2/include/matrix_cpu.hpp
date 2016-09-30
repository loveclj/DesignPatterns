/*
 * matrix_cpu.hpp
 *
 *  Created on: Aug 15, 2016
 *      Author: lizhifeng
 */

#ifndef MATRIX_CPU_HPP_
#define MATRIX_CPU_HPP_


#include <iostream>
#include <map>
#include <vector>
#include <cstdlib>

using namespace  std;

//float*
float* build_matrix(int dimension, int n_vec, float* weight, map<string, string> &name_fingerprint, vector<string> &label);

float* create_random_vector(size_t size, unsigned int seed);

#endif /* MATRIX_CPU_HPP_ */
