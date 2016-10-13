//
// Created by lizhifeng on 10/13/16.
//

#include "test.hpp"
#include "../proxy/Proxy.hpp"


using namespace proxy;


void test_proxy(){

    Customer *c = new ChineseCustomerProxy();
    c->buy();
    delete(c);
}
