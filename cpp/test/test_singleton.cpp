//
// Created by lizhifeng on 10/12/16.
//

#include "test.hpp"

#include "../singleton/Singleton.hpp"

using namespace singleton;


void test_singleton(){
    Singleton *s1 = Singleton::get_instance();
    Singleton *s2 = Singleton::get_instance();

    cout << "s1 == s2 is " << (s1 == s2) << endl;
}