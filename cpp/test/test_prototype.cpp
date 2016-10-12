//
// Created by clj on 2016/10/12.
//

#include "../prototype/prototype.hpp"

#include "test.hpp"
#include <unistd.h>

using namespace prototype;


void test_prototype(){
    MatrixRowLead *p = new MatrixRowLead(10, 20);
    MatrixRowLead *p2 = p->deep_clone();
    MatrixRowLead *p3 = p->shallow_clone();

    delete p;
    delete p2;
    delete p3;
}