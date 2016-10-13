//
// Created by clj on 2016/10/14.
//

// 某个方法的实现需要多个步骤（类似“请客”），其中有些步骤是固定的（类似“点单”和“买单”），
// 而有些步骤并不固定，存在可变性（类似“吃东西”）

//模板方法模式：定义一个操作中算法的框架，而将一些步骤延迟到子类中。
// 模板方法模式使得子类可以不改变一个算法的结构即可重定义该算法的某些特定步骤。

// 模板方法模式是一种基于继承的代码复用技术，它是一种类行为型模式


#ifndef PATTERN_DESIGN_TEMPLATE_HPP
#define PATTERN_DESIGN_TEMPLATE_HPP

#include <iostream>

using namespace std;

namespace Template{

    class Cook {

    public:
        Cook(){}
        virtual ~Cook(){}

        void clean_wok(){
            cout << " clean wok" << endl;
        }

        void open_fire(){
            cout << "open fire" << endl;
        }

        virtual void cook(){
            cout << "cook nothing" << endl;
        }

        virtual void smell(){
            cout << "smell" << endl;
        }

        void close_fire(){
            cout << "close fire" << endl;
        }

        void cook_a_dish(){  // template method, this method is not virtual

            clean_wok();  // not virtual
            open_fire();  // not virtual
            cook();   // virtual, override by child class
            smell();  // virtual
            close_fire();  // not virtual

        }


    };// end class Cook


    class CookFish: public Cook{

    public:
        CookFish(){}
        virtual ~CookFish(){}

        virtual void cook(){
            cout << "cook fish" << endl;
        }
    };  // end class CookFish

    class CookPork: public Cook{

    public:
        CookPork(){}
        virtual ~CookPork(){}

        virtual void cook(){
            cout << "cook pork" << endl;
        }

        virtual void smell(){
            // override Cook::smell, do nothing, skip this step
        }
    };

}  // end namespace template
#endif //PATTERN_DESIGN_TEMPLATE_HPP
