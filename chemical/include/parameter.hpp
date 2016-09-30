//
// Created by lizhifeng on 9/30/16.
//

#ifndef CHEMICAL_PARAMETER_HPP
#define CHEMICAL_PARAMETER_HPP

#include <iostream>
#include <string>

#include <pthread.h>

#include "tclap/CmdLine.h"

#include "common.hpp"

using namespace std;


namespace chemical {

// singleton
class Parameter{

public:

    ~Parameter();

    static Parameter *get_instance();

    void parse(int argc, char ** argv);

    std::string get_data_file_name();
    std::string get_weight_file_name();
    std::string get_output_file_name();

    unsigned int get_max_epoch();
    unsigned int get_dimension();
    unsigned int get_vec_count();


private:

    class GarbageCollection{
    public:
        ~GarbageCollection(){
            if(Parameter::_instance != NULL){
                delete Parameter::_instance;
//                std::cout << "delete instance" << std::endl;
            }
        }
    };



private:

    static Parameter * _instance;// = NULL;
    static pthread_mutex_t _mutex;// = PTHREAD_MUTEX_INITIALIZER;
    static GarbageCollection _gc;


    std::string _data_file_name;  // feature data files
    std::string _weight_file_name;  // weight of every index in feature
    std::string _output_file_name;  // record the result

    unsigned int _nvec;    // row of feature matrix, number of feature items
    unsigned int _max_epoch;  // max epoch of train
    unsigned int _dimension;  // column of feature matrix, dimensionality of feature



private:
    Parameter();

//DISABLE_COPY_AND_ASSIGN(Parameter);

};//class Parameter


} // namespace chemical

#endif //CHEMICAL_PARAMETER_HPP
