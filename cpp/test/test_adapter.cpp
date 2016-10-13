//
// Created by lizhifeng on 10/13/16.
//

#include "test.hpp"
#include "../adapter/Adapter.hpp"

using namespace adapter;


void test_adapter(){
    Eat *eat = new Eat;
    eat->eat();

    delete(eat);

    eat = new EatWineAdpter;
    eat->eat();
    delete(eat);
}