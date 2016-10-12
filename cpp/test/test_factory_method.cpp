//
// Created by lizhifeng on 10/12/16.
//

#include "test.hpp"
#include "../factory_method/Product.hpp"
#include "../factory_method/Factory.hpp"

using namespace factory_method;

void test_factory_method(){
    AbstractFactory *factory = new FactoryA;
    Product *p = factory->create_product();

//    delete p;
//    delete factory;

//    factory = new FactoryB;
//    p = factory->create_product();
//    delete p;
//    delete factory;
}