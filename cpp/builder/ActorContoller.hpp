//
// Created by clj on 2016/10/13.
//

#ifndef DESIGNPATTERN_ACTORCONTOLLER_HPP
#define DESIGNPATTERN_ACTORCONTOLLER_HPP


#include "Actor.hpp"
#include "Builder.hpp"


namespace builder {

    class ActorContoller {

    public:
        Actor *construct(ActorBuilder *builder){
            builder->build_costume();
            builder->build_face();
            builder->build_hair_style();
            builder->build_sex();
            builder->build_type();

            return builder->get_actor();
        }


    };
}  // end namespace builder


#endif //DESIGNPATTERN_ACTORCONTOLLER_HPP
