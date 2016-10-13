//
// Created by lizhifeng on 10/13/16.
//

#include "test.hpp"
#include "../bridge/Bridge.hpp"

using namespace bridge;

void test_bridge(){


    Food *food = new Noodle;
    Taste *taste = new HotTaste;

    food->set_taste(taste);

    food->show_food();

    delete(food);
    delete(taste);


    food = new Bread;
    taste = new SweetTaste;
    food->set_taste(taste);
    food->show_food();

    delete(taste);
    delete(food);



}