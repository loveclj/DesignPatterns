//
// Created by clj on 2016/10/14.
//

//实现某一个功能有多条途径，每一条途径对应一种算法，此时我们可以使用一种设计模式来实现灵活地选择解决途径，
// 也能够方便地增加新的解决途径。

//策略模式的主要目的是将算法的定义与使用分开，也就是将算法的行为和环境分开，
// 将算法的定义放在专门的策略类中，每一个策略类封装了一种实现算法，使用算法的环境类针对抽象策略类进行编程，符合“依赖倒转原则”。

//策略模式(Strategy Pattern)：定义一系列算法类，将每一个算法封装起来，并让它们可以相互替换，
// 策略模式让算法独立于使用它的客户而变化，也称为政策模式(Policy)。策略模式是一种对象行为型模式。

//  Context（环境类）：环境类是使用算法的角色，它在解决某个问题（即实现某个方法）时可以采用多种策略。
// 在环境类中维持一个对抽象策略类的引用实例，用于定义所采用的策略。

// Strategy（抽象策略类）：它为所支持的算法声明了抽象方法，是所有策略类的父类，
// 它可以是抽象类或具体类，也可以是接口。环境类通过抽象策略类中声明的方法在运行时调用具体策略类中实现的算法。

// ConcreteStrategy（具体策略类）：它实现了在抽象策略类中声明的算法，在运行时，
// 具体策略类将覆盖在环境类中定义的抽象策略类对象，使用一种具体的算法实现某个业务处理。

#ifndef PATTERN_DESIGN_STRATEGY_HPP
#define PATTERN_DESIGN_STRATEGY_HPP

#include <iostream>

using namespace std;

namespace strategy{

    class Cook{
    public:
        Cook(){}
        ~Cook(){}

        virtual void method(string food) = 0;
    };  // end abstract base class Cook

    class Fry: public Cook{
    public:
        Fry(){}
        virtual ~Fry(){}

        virtual void method(string food){
            cout << "fry " << food << endl;
        }
    };  // end class Fry

    class Steam: public Cook{
    public:
        Steam(){}
        virtual ~Steam(){}

        virtual void method(string food){
            cout << "steam " << food << endl;
        }
    };  // end class Steam

    class Meat{
    public:
        Meat(){
            _name = "meat";
        }

        ~Meat(){}

        void set_cook(Cook *cook){
            _cook = cook;
        }

        void cook_meat(){
            _cook->method(_name);
        }

    private:
        string _name;
        Cook * _cook;
    };  // end class Meat

}  // end namespace strategy
#endif //PATTERN_DESIGN_STRATEGY_HPP
