//
// Created by clj on 2016/10/14.
//

#include "test.hpp"
#include "../strategy/Strategy.hpp"

using namespace strategy;


void test_strategy(){

    Meat * meat = new  Meat;

    Cook * cook = new Fry;

    meat->set_cook(cook);
    meat->cook_meat();

    delete cook;

    cook = new Steam;

    meat->set_cook(cook);
    meat->cook_meat();

    delete cook;
    delete meat;
}

