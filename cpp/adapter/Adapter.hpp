//
// Created by lizhifeng on 10/13/16.
//


//  适配器模式(Adapter Pattern)：将一个接口转换成客户希望的另一个接口，
// 使接口不兼容的那些类可以一起工作，其别名为包装器(Wrapper)。
// 适配器模式既可以作为类结构型模式，也可以作为对象结构型模式。

#ifndef PATTERN_DESIGN_ADAPTER_HPP
#define PATTERN_DESIGN_ADAPTER_HPP

#include <iostream>


using namespace std;

namespace adapter{

    class Drink{  //喝

    public:
        Drink(){}
        ~Drink(){}

        void drink(){
            cout << "drink water" << endl;
        }

    };

    class Eat{  //　吃饭

    public:
        Eat(){}
        virtual ~Eat(){}

        virtual void eat(){
            cout << "eat" << endl;
        }
    };


    class EatWineAdpter: public Eat{  //吃酒

    public:
        EatWineAdpter(){
            _drink = new Drink;
        }

        virtual ~EatWineAdpter(){
            delete(_drink);
        }

        virtual void eat(){
            cout << "call Drink.drink" << endl;
            _drink->drink();
        }

    private:
        Drink *_drink;
    };



} // end namespace adapter
#endif //PATTERN_DESIGN_ADAPTER_HPP
