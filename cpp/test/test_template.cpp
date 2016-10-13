//
// Created by clj on 2016/10/14.
//

#include "test.hpp"
#include "../template/Template.hpp"


using namespace Template;

void test_template(){

    Cook * cook = new CookFish;

    cook->cook_a_dish();

    delete(cook);

    cout << "======================" << endl;
    cook = new  CookPork;

    cook->cook_a_dish();
    delete(cook);
}