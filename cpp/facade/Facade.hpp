//
// Created by clj on 2016/10/13.
//

//外观模式：为子系统中的一组接口提供一个统一的入口。外观模式定义了一个高层接口，这个接口使得这一子系统更加容易使用。

//在软件开发中，有时候为了完成一项较为复杂的功能，一个客户类需要和多个业务类交互，
// 而这些需要交互的业务类经常会作为一个整体出现，由于涉及到的类比较多，导致使用时代码较为复杂.
// 此时，特别需要一个类似服务员一样的角色，由它来负责和多个业务类进行交互，而客户类只需与该类交互。
// 外观模式通过引入一个新的外观类(Facade)来实现该功能，外观类充当了软件系统中的“服务员”，
// 它为多个业务类的调用提供了一个统一的入口，简化了类与类之间的交互。
// 在外观模式中，那些需要交互的业务类被称为子系统(Subsystem)。
// 如果没有外观类，那么每个客户类需要和多个子系统之间进行复杂的交互，系统的耦合度将很大;
// 而引入外观类之后，客户类只需要直接与外观类交互，客户类与子系统之间原有的复杂引用关系由外观类来实现，从而降低了系统的耦合度，

#ifndef DESIGNPATTERN_FACADE_HPP
#define DESIGNPATTERN_FACADE_HPP

#include <iostream>

using namespace std;

namespace facade {

    class Cleaner{

    public:
        void clean(){
            cout << "clean plate" << endl;
        }
    };

    class Cooker{

    public:
        void cook(){
            cout << "cook" << endl;
        }
    };

    class Informer{

    public:
        void inform(){
            cout << "dish is okay" << endl;
        }
    };

    class WaitorFacade {
    public:
        WaitorFacade(){
            _cleaner = new Cleaner;
            _cooker = new Cooker;
            _informer =  new Informer;
        }
        ~WaitorFacade(){}

        void serve_food(){

            _cleaner->clean();
            _cooker->cook();
            _informer->inform();

            cout << "enjoy your meal" << endl;

        }

    private:
        Cleaner *_cleaner;
        Cooker *_cooker;
        Informer *_informer;
    };
}  // end namespace facade


#endif //DESIGNPATTERN_FACADE_HPP
