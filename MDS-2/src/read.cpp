#include "read.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <sstream>

#include "boost/algorithm/string/split.hpp"
#include "boost/algorithm/string.hpp"

using namespace std;
using namespace boost;

void read_matrix_from_file(string file_name, map<string, string> &name_smiles,
		map<string, string> &name_fingerprint) {

	string line;
	fstream fs(file_name.c_str());
	if (fs.is_open()) {
		set<string> fp_set;
		while (getline(fs, line)) {
			vector<string> vec;
			split(vec, line, boost::is_any_of(","));

			/*** change ****/

			if(fp_set.find(vec[2]) != fp_set.end()){
//			if(false){
				for(map<string, string>::iterator iter=name_fingerprint.begin(); iter != name_fingerprint.end(); iter++){
					if(iter->second == vec[2]){
						cout << "duplicated fingerprint: " << iter->first << " " << vec[0] << endl;
					}
				}

				continue;
			}else{
				fp_set.insert(vec[2]);
				name_smiles.insert(make_pair(vec[0], vec[1]));
				name_fingerprint.insert(make_pair(vec[0], vec[2]));
			}
		}
		fs.close();
	} else {
		cout << "Unable to open file";
	}
}


float* read_weight_from_file(string file_name){
	string line;
	fstream fs(file_name.c_str());
	if(!fs.is_open()){
		cout << "can't open file " << file_name << endl;
		return NULL;
	}

	map<int, float> id_weight;
	while(getline(fs, line)){

		vector<string> vec;
//		cout << line << endl;
		split(vec, line, boost::is_any_of(":"));

		stringstream ss;

		int id;
		ss << vec[0];
		ss >> id;

		char *pEnd;
		float w = strtof(vec[1].c_str(), &pEnd);

		id_weight.insert(make_pair(id, w));

	}

	int dimension = id_weight.size();
	float *weight = new float[dimension];

	for(map<int, float>::iterator iter = id_weight.begin(); iter != id_weight.end(); ++iter){
//		cout << iter->first <<" " << iter->second << endl;
		weight[iter->first] = iter->second;
	}

	return weight;


}
