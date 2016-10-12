//
// Created by clj on 2016/10/13.
//

#include "../builder/ActorContoller.hpp"
#include "../builder/Actor.hpp"
#include "../builder/Builder.hpp"

#include "test.hpp"

using namespace builder;


void test_builder(){

    ActorContoller *contoller = new ActorContoller();
    ActorBuilder * b = new BeautyBuilder();

    Actor *actor = contoller->construct(b);

    cout << "actor sex: " <<  actor->get_sex() << endl;
    cout << "actor type: " << actor->get_type() << endl;




}