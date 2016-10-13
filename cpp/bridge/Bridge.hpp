//
// Created by lizhifeng on 10/13/16.
//


//桥接模式(Bridge Pattern)：将抽象部分与它的实现部分分离，使它们都可以独立地变化。
// 它是一种对象结构型模式，又称为柄体(Handle and Body)模式或接口(Interface)模式。

// 桥接模式是一种很实用的结构型设计模式，如果软件系统中某个类存在两个独立变化的维度，
// 通过该模式可以将这两个维度分离出来，使两者可以独立扩展，让系统更加符合“单一职责原则”。
// 与多层继承方案不同，它将两个独立变化的维度设计为两个独立的继承等级结构，
// 并且在抽象层建立一个抽象关联，该关联关系类似一条连接两个独立继承结构的桥，故名桥接模式。


#ifndef PATTERN_DESIGN_BRIDGE_HPP
#define PATTERN_DESIGN_BRIDGE_HPP

#include <iostream>

using namespace std;

namespace bridge{

    class Taste{

    public:
        Taste(){
            _taste = "None";
        }
        virtual ~Taste(){}

        virtual void get_taste(){
            cout << _taste << endl;
        }

    private:
        string _taste;
    };  // end class Taste

    class HotTaste: public Taste{

    public:
        HotTaste(){
            _taste = "Hot";
        }

        virtual ~HotTaste(){}

        virtual void get_taste(){
            cout << _taste << endl;
        }

    private:
        string _taste;

    };  // end class HotTaste

    class SweetTaste: public Taste{

    public:
        SweetTaste(){
            _taste = "sweet";
        }

        virtual ~SweetTaste(){}

        virtual void get_taste(){
            cout << _taste << endl;
        }

    private:
        string _taste;
    };  // end class SweetTaste

    class AcidTaste: public Taste{

    public:
        AcidTaste(){
            _taste = "acid";
        }

        virtual ~AcidTaste(){}

        virtual void get_taste(){
            cout << _taste << endl;
        }
    private:
        string _taste;
    };  // end class AciTaste


    class Food{

    public:
        Food(){}
        virtual ~Food(){}

        virtual void set_taste(Taste *taste){
            _taste = taste;
        }

        virtual void show_food() = 0;

    private:
        Taste *_taste;
        string _name;

    };

    class Noodle: public Food{

    public:
        Noodle(){
            _name = "noodle";
        }
        virtual ~Noodle(){}

        virtual void set_taste(Taste *taste){
            _taste = taste;
        }

        virtual void show_food(){
            _taste->get_taste();
            cout << _name << endl;
        }

    private:
        Taste *_taste;
        string _name;

    };  // end class Noodle


    class Bread: public Food{

    public:
        Bread(){
            _name = "bread";
        }
        virtual ~Bread(){}

        virtual void set_taste(Taste *taste){
            _taste = taste;
        }

        virtual void show_food(){
            _taste->get_taste();
            cout << _name << endl;
        }

    private:
        Taste *_taste;
        string _name;

    };  // end class Bread

    class Meat: public Food{

    public:
        Meat(){
            _name = "meat";
        }
        virtual ~Meat(){}

        virtual void set_taste(Taste *taste){
            _taste = taste;
        }

        virtual void show_food(){
            _taste->get_taste();
            cout << _name << endl;
        }

    private:
        Taste *_taste;
        string _name;

    };  // end class Meat

}  // end bridge

#endif //PATTERN_DESIGN_BRIDGE_HPP
