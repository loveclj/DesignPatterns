//
// Created by clj on 2016/10/13.
//


//建造者模式是较为复杂的创建型模式，它将客户端与包含多个组成部分（或部件）
// 的复杂对象的创建过程分离，客户端无须知道复杂对象的内部组成部分与装配方式，
// 只需要知道所需建造者的类型即可。它关注如何一步一步创建一个的复杂对象，
// 不同的具体建造者定义了不同的创建过程，且具体建造者相互独立，
// 增加新的建造者非常方便，无须修改已有代码，系统具有较好的扩展性。

//建造者模式(Builder Pattern),将一个复杂对象的构建与它的表示分离，使得同样的构建过程可以创建不同的表示。
// 建造者模式是一种对象创建型模式。


#ifndef DESIGNPATTERN_BUILDER_HPP
#define DESIGNPATTERN_BUILDER_HPP

#include <iostream>

#include "Actor.hpp"

using namespace std;

namespace builder{

    class ActorBuilder {

    public:
        ActorBuilder(){}
        virtual ~ActorBuilder(){}

        virtual void build_type() = 0;
        virtual void build_sex() = 0;
        virtual void build_face() = 0;
        virtual void build_costume() = 0;
        virtual void build_hair_style() = 0;

        virtual Actor *get_actor(){
            return _actor;
        }
    private:
        Actor *_actor;

    };


    class BeastBuilder: public ActorBuilder{

    public:
        BeastBuilder(){
            _actor = new Actor;
        }
        virtual ~BeastBuilder(){
            delete(_actor);
        }

        virtual void build_type(){
            _actor->set_type("Beast");
        }

        virtual void build_sex(){
            _actor->set_sex("male");
        }

        virtual void build_face(){
            _actor->set_face("ugly");
        }

        virtual void build_costume(){
            _actor->set_costume("black");
        }

        virtual void build_hair_style(){
            _actor->set_hair_style("short");
        }

        virtual Actor *get_actor(){
            return _actor;
        }
    private:
        Actor *_actor;
    };

    class BeautyBuilder: public ActorBuilder{

    public:
        BeautyBuilder(){
            _actor = new Actor;
        }
        virtual ~BeautyBuilder(){
            delete(_actor);
        }

        virtual void build_type(){
            _actor->set_type("Beauty");
        }

        virtual void build_sex(){
            _actor->set_sex("female");
        }

        virtual void build_face(){
            _actor->set_face("beautiful");
        }

        virtual void build_costume(){
            _actor->set_costume("white");
        }

        virtual void build_hair_style(){
            _actor->set_hair_style("long");
        }

        virtual Actor *get_actor(){
            return _actor;
        }
    private:
        Actor *_actor;
    };
}  // end namespace  builder



#endif //DESIGNPATTERN_BUILDER_HPP
