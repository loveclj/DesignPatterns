//
// Created by clj on 2016/10/13.
//

#include "../facade/Facade.hpp"
#include "test.hpp"


using namespace std;
using namespace facade;


void test_facade(){
    WaitorFacade *waitor = new WaitorFacade;
    waitor->serve_food();
}