//
// Created by lizhifeng on 9/30/16.
//


#include "parameter.hpp"


using namespace chemical;
using namespace std;
using namespace TCLAP;



namespace chemical{

    pthread_mutex_t Parameter::_mutex = PTHREAD_MUTEX_INITIALIZER;
    Parameter* Parameter::_instance = NULL;
    Parameter::GarbageCollection Parameter::_gc;

    Parameter::Parameter() :_data_file_name(""){

    }

    Parameter::~Parameter() {

    }

    void Parameter::parse(int argc, char **argv) {


        string data_file_name_default = "name_formula_fingerprint_3k.text";
        string weight_file_name_default = "weight.txt";
        string out_file_name_default = "2D.text";
        int n_vec_default = 1000;
        int max_epoch_default = 20000;
        int dimension_default = 881;

        CmdLine cmd("Command description message", ' ', "1.0");

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

       _data_file_name = data_file_name_Arg.getValue();
        _weight_file_name = weight_file_name_Arg.getValue();
        _output_file_name = out_file_name_Arg.getValue();

        _nvec = n_vec_Arg.getValue();
        _max_epoch = max_epoch_Arg.getValue();
        _dimension = dimension_Arg.getValue();

    }

    Parameter* Parameter::get_instance() {

        if(_instance == NULL){

            pthread_mutex_lock(&_mutex);

            if(_instance == NULL){
                _instance = new Parameter();
            }

            return _instance;

            pthread_mutex_unlock(&_mutex);
        }
    }



    std::string Parameter::get_data_file_name(){
        return _data_file_name;
    }

    std::string Parameter::get_weight_file_name(){
        return _weight_file_name;
    }

    std::string Parameter::get_output_file_name(){
        return _output_file_name;
    }

    unsigned int Parameter::get_max_epoch(){
        return _max_epoch;
    }

    unsigned int Parameter::get_dimension(){
        return _dimension;
    }

    unsigned int Parameter::get_vec_count(){
        return _nvec;
    }

}  // namespace chemical