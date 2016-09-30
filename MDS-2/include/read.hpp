/*
 * read.hpp
 *
 *  Created on: Aug 15, 2016
 *      Author: lizhifeng
 */

#ifndef READ_HPP_
#define READ_HPP_

#include <map>
#include <fstream>
using namespace std;


void read_matrix_from_file(string file_name, map<string, string> &name_smiles, map<string, string> &name_fingerprint);

float* read_weight_from_file(string file_name);

#endif /* READ_HPP_ */
