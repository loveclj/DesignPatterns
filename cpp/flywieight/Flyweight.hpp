//
// Created by lizhifeng on 10/13/16.
//


//享元模式(Flyweight Pattern)：运用共享技术有效地支持大量细粒度对象的复用。
// 系统只使用少量的对象，而这些对象都很相似，状态变化很小，可以实现对象的多次复用。
// 由于享元模式要求能够共享的对象必须是细粒度对象，因此它又称为轻量级模式，它是一种对象结构型模式。



// 享元模式以共享的方式高效地支持大量细粒度对象的重用，
// 享元对象能做到共享的关键是区分了内部状态(Intrinsic State)和外部状态(Extrinsic State)。
// 下面将对享元的内部状态和外部状态进行简单的介绍：

//(1)  内部状态是存储在享元对象内部并且不会随环境改变而改变的状态，内部状态可以共享。
// 如字符的内容，不会随外部环境的变化而变化，无论在任何环境下字符“a”始终是“a”，都不会变成“b”。

//(2)  外部状态是随环境改变而改变的、不可以共享的状态。享元对象的外部状态通常由客户端保存，
// 并在享元对象被创建之后，需要使用的时候再传入到享元对象内部。
// 一个外部状态与另一个外部状态之间是相互独立的。
// 如字符的颜色，可以在不同的地方有不同的颜色，例如有的“a”是红色的，有的“a”是绿色的，字符的大小也是如此，
// 有的“a”是五号字，有的“a”是四号字。而且字符的颜色和大小是两个独立的外部状态，
// 它们可以独立变化，相互之间没有影响，客户端可以在使用时将外部状态注入享元对象中。

//正因为区分了内部状态和外部状态，我们可以将具有相同内部状态的对象存储在享元池中，
// 享元池中的对象是可以实现共享的，需要的时候就将对象从享元池中取出，实现对象的复用。
// 通过向取出的对象注入不同的外部状态，可以得到一系列相似的对象，而这些对象在内存中实际上只存储一份。


#ifndef PATTERN_DESIGN_FLYWEIGHT_HPP
#define PATTERN_DESIGN_FLYWEIGHT_HPP

#include <iostream>
#include <map>

using namespace std;

namespace flyweight{

    class IgoChessman;  // pre statement


    class Coordinate{  // external status

    public:
        Coordinate(int x, int y){
            _x = x;
            _y = y;
        }

        friend class IgoChessman;
        friend class BlackIgoChessman;
        friend class WhiteIgoChessman;

    private:
        int _x;
        int _y;
    }; // end class Coordinate


    class  IgoChessman{

    public:
        IgoChessman(){}
        virtual ~IgoChessman(){}
        virtual string get_color() = 0;
        virtual void display(Coordinate &coord) = 0;

    private:
        string _color;  // inner status of flyweight

    };  // end class IgoChessman

    class  BlackIgoChessman: public IgoChessman{

    public:
        BlackIgoChessman(){
            _color = "black";
        }
        virtual ~BlackIgoChessman(){}
        virtual string get_color(){
            return _color;
        }

        virtual void display(Coordinate &coord){
            cout << _color << " " << coord._x << " " << coord._y << endl;
        }
    private:
        string _color;
    };  // end class BlackIgoChessman

    class  WhiteIgoChessman: public IgoChessman{

    public:
        WhiteIgoChessman(){
            _color = "white";
        }
        virtual ~WhiteIgoChessman(){}
        virtual string get_color(){
            return _color;
        }
        virtual void display(Coordinate &coord){
            cout << _color << " " << coord._x << " " << coord._y << endl;
        }

    private:
        string _color;
    };  // end class WhiteIgoChessman


    class IgoChessmanFactory{

    public:
        IgoChessmanFactory():_hs(){
            IgoChessman *instance = new BlackIgoChessman;
            _hs.insert(make_pair("B", instance));

            instance = new WhiteIgoChessman;
            _hs.insert(make_pair("W", instance));
        }

        ~IgoChessmanFactory(){}

        IgoChessman *get_igoChessman(string color){
            return _hs[color];
        }

    private:
        map<string, IgoChessman*> _hs;  // 享元池

    };  // end class IgoChessmanFactory


}  // end namespace flyweight
#endif //PATTERN_DESIGN_FLYWEIGHT_HPP
