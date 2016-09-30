#include <iostream>

#include "common.hpp"

#include "parameter.hpp"


using namespace std;
using namespace chemical;



int main(int argc, char **argv) {

    Parameter *parameter = Parameter::get_instance();
//    Parameter *parameter1 = parameter;
    parameter->parse(argc, argv);
//    cout << parameter->get_data_file_name() << endl;

    return 0;
}