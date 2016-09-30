#include <iostream>
#include <map>
#include <vector>
#include <cuda.h>
#include <cuda_runtime.h>

#include <sys/time.h>

#include "read.hpp"
#include "matrix_cpu.hpp"
#include "train_gpu.hpp"
#include "comm.hpp"

#include "tclap/CmdLine.h"


using namespace std;
using namespace TCLAP;

string data_file_name;
string weight_file_name;
string out_file_name;
int n_vec;
int max_epoch;
int dimension;

/*
 * write mds coordinates into a file
 */
void output(const char *file_name, vector<string> label, float *x, float *y,  int N);

/*
 * set default values of parameters and parse
 */
void parse_arg(int argc, char **argv);

void sqrt(float *vec, int n);


int main(int argc, char **argv)
{


	parse_arg(argc, argv);

	map<string, string> name_smiles;
	map<string, string> name_fingerprint;

	struct timeval timerStart;
	struct timeval timerStop;

	gettimeofday(&timerStart, NULL);

	read_matrix_from_file(data_file_name, name_smiles, name_fingerprint);

	vector<string> vLabel;
	float *weight = read_weight_from_file(weight_file_name);

	/*
	 * a trick, to speed up computation of tanimoto distance
	 * Be careful, data_matrix is sqrt(feature_matrix)
	 */
	sqrt(weight, dimension);
	float *data_matrix = build_matrix(dimension, n_vec, weight, name_fingerprint, vLabel);

#ifdef DEBUG
	if(n_vec > vLabel.size()){
		cout << "[WARNING] number of input vector needed to read: " << n_vec << ", but only read : " << vLabel.size() << endl;
	}
#endif

	n_vec = vLabel.size();  // real size of input vector

	float *x_arr = create_random_vector(n_vec, 1);
	float *y_arr = create_random_vector(n_vec, 2);

	float learn_rate = 0.0001;
	int split_size = n_vec;

	train(max_epoch, split_size, learn_rate, data_matrix, x_arr, y_arr, dimension, n_vec);
	cudaThreadSynchronize();

	gettimeofday(&timerStop, NULL);

	float time_elapsed = timeval_sub(timerStop, timerStart);

	cout << "execution time is: " << time_elapsed << endl;

	output(out_file_name.c_str(), vLabel, x_arr, y_arr, n_vec);

	delete [] data_matrix;
	delete [] weight;
}



void parse_arg(int argc, char **argv){

		CmdLine cmd("Command description message", ' ', "1.0");

		string data_file_name_default = "name_formula_fingerprint_3k.text";
		string weight_file_name_default = "weight.txt";
		string out_file_name_default = "2D.text";
		int n_vec_default = 1000;
		int max_epoch_default = 20000;
		int dimension_default = 881;

		ValueArg<string> data_file_name_Arg("f", "data_file_name", "finger print file", false, data_file_name_default,  "file name");
		ValueArg<string> weight_file_name_Arg("w", "weight_file_name", "weight of each index of fingerprint", false, weight_file_name_default, "file name");
		ValueArg<string> out_file_name_Arg("o", "out_file_name", "mds result", false, out_file_name_default, "file name");

		ValueArg<int> n_vec_Arg("n", "n_vec", "number of input fingerprint", false, n_vec_default, "int, not more than 2k");
		ValueArg<int> max_epoch_Arg("e", "max_epoch", "max epoch of train", false, max_epoch_default, "int");
		ValueArg<int> dimension_Arg("d", "dimension", "dimension of fingerprint", false, dimension_default, "int");

		cmd.add(data_file_name_Arg);
		cmd.add(weight_file_name_Arg);
		cmd.add(out_file_name_Arg);

		cmd.add(n_vec_Arg);
		cmd.add(max_epoch_Arg);
		cmd.add(dimension_Arg);

		cmd.parse(argc, argv);

		data_file_name = data_file_name_Arg.getValue();
		weight_file_name = weight_file_name_Arg.getValue();
		out_file_name = out_file_name_Arg.getValue();

		n_vec = n_vec_Arg.getValue();
		max_epoch = max_epoch_Arg.getValue();
		dimension = dimension_Arg.getValue();


		cout << "====== PLEASE CHECK YOUR PATAMETERS ======" << endl;

		cout << "data file name: \t" << data_file_name << endl;
		cout << "output file name: \t" << out_file_name << endl;
		cout << "weight file name: \t" << weight_file_name << endl;

		cout << "number of vector: \t" << n_vec << endl;
		cout << "max train epoch: \t" << max_epoch << endl;
		cout << "dimension of fingerprint: \t" << dimension << endl;

}


void sqrt(float *vec, int n){

	for(int i=0; i<n; ++i){
		vec[i] = sqrtf(vec[i]);
	}

}


void output(const char *file_name, vector<string> label, float *x, float *y,  int N){
	fstream fs(file_name, ios::out);
	for(int i=0; i<N; ++i){
		fs << label[i] << "," << x[i] << "," << y[i] << "\n";
	}
	fs.close();
}
