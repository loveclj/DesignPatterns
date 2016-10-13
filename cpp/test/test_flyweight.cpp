//
// Created by lizhifeng on 10/13/16.
//

#include "test.hpp"
#include "../flywieight/Flyweight.hpp"

using namespace flyweight;


void test_flyweight(){

    IgoChessmanFactory factory = IgoChessmanFactory();

    Coordinate coord = Coordinate(1, 2);

    IgoChessman *instance = factory.get_igoChessman("B");
    instance->display(coord);

    instance = factory.get_igoChessman("W");
    instance->display(coord);


}