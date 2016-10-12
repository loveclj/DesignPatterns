//
// Created by lizhifeng on 10/12/16.
//

#include "test.hpp"
#include "../abstract_factory/Factory.hpp"

using namespace abstract_factory;

void test_abstract_factory(){
    AbstractMealFactory *factory = new MealFactoryA;

    AbstractSnack *snack = factory->create_snack();
    AbstractNoodle *noodle = factory->create_noodle();

    delete  snack;
    delete  noodle;
    delete  factory;
}