//
// Created by lizhifeng on 10/13/16.
//

#include "test.hpp"
#include "../decorator/Docorator.hpp"


using namespace decorator;


void test_decorator(){

    CookComponent *food = new CookFoodConcreteComponent;

    CookComponent *salt = new CookAddSaltConcreteDecorator;
    CookComponent *pepper = new CookAddPepperConcreteDecorator;
    CookComponent *aginomoto = new CookAddAginomotoConcreteDecorator;

    salt->set_component(food);
    pepper->set_component(salt);
    aginomoto->set_component(pepper);

    aginomoto->operation();
}