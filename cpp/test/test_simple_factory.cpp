//
// Created by lizhifeng on 10/12/16.
//
#include "test.hpp"
#include "../simple_factory/Product.hpp"
#include "../simple_factory/Factory.hpp"

using namespace std;
using namespace simple_factory;

void test_simple_factory(){
    Product *p;
    p = Factory::create_product("A");

    cout << "name: " << p->get_name() << endl;
    cout << "class name: " << p->get_class_name() << endl;
    delete p;

    cout << "+++++++++++++++++" << endl;
    p = Factory::create_product("B");
    cout << "name: " << p->get_name() << endl;
    cout << "class name: " << p->get_class_name() << endl;
    delete p;

}