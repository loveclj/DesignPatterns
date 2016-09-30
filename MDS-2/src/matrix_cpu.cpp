/*
 * matrix_cpu.cpp
 *
 *  Created on: Aug 15, 2016
 *      Author: lizhifeng
 */

#include "matrix_cpu.hpp"

float* build_matrix(int dimension, int n_vec, float* weight, map<string, string> &name_fingerprint, vector<string> &label){

	int size = dimension * name_fingerprint.size();
	float *matrix = new float[size];

	int row = 0;
	for(map<string, string>::iterator iter = name_fingerprint.begin(); iter != name_fingerprint.end(); ++iter){
		label.push_back(iter->first);
		string fp = iter->second;
		for(int i=0; i<fp.length(); ++i){
			if(fp[i] == '1'){
				matrix[row*dimension + i] = weight[i];
			}else{
				matrix[row*dimension + i] = 0;
			}
		}
		row += 1;

		if(row == n_vec){
			break;
		}
	}

	return matrix;
}

float* create_random_vector(size_t size, unsigned int seed){
	float *vec = new float[size];
	srand(seed);

	for(size_t i=0; i<size; ++i){
		vec[i] = ((float) rand()) / RAND_MAX;
	}

	return vec;
}
