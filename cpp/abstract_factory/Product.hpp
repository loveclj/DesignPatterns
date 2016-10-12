//
// Created by lizhifeng on 10/12/16.
//

#ifndef PATTERN_DESIGN_PRODUCT_HPP
#define PATTERN_DESIGN_PRODUCT_HPP

#include <iostream>
using namespace std;

namespace abstract_factory{

    class AbstractMeat{

    public:
        AbstractMeat(){}
        virtual ~AbstractMeat(){}

    };

    class MeatPork: public AbstractMeat{

    public:
        MeatPork(){
            cout << "add pork" << endl;
        }
        virtual ~MeatPork(){
            cout << "remove pork" << endl;
        }
    };

    class MeatBeef: public AbstractMeat{

    public:
        MeatBeef(){
            cout << "add beef" << endl;
        }

        virtual ~MeatBeef(){
            cout << "remove beef" << endl;
        }
    };

    class AbstractNoodle{

    public:
        AbstractNoodle(){}
        virtual ~AbstractNoodle(){}
    };

    class NoodleVermicelli: public AbstractNoodle{

    public:
        NoodleVermicelli(){
            cout << "add vermicelli" << endl;
        }

        virtual ~NoodleVermicelli(){
            cout << "remove vermicelli" << endl;
        }
    };

    class NoodlePotatoPowder: public AbstractNoodle{

    public:
        NoodlePotatoPowder(){
            cout << "add potato powder" << endl;
        }
        virtual ~NoodlePotatoPowder(){
            cout << "remove potato powder" << endl;
        }
    };

    class AbstractSnack{

    public:
        AbstractSnack(){}
        virtual ~AbstractSnack(){}
    };

    class SnackTeaEgg:public AbstractSnack{

    public:
        SnackTeaEgg(){
            cout << "add tea egg" << endl;
        }
        virtual ~SnackTeaEgg(){
            cout << "remove tea egg" << endl;
        }
    };

    class SnackDriedTofu: public AbstractSnack{

    public:
        SnackDriedTofu(){
            cout << "add dried tofu" << endl;
        }
        virtual ~SnackDriedTofu(){
            cout << "remove dried tofu" << endl;
        }
    };


} // end namespace abstract_factory



#endif //PATTERN_DESIGN_PRODUCT_HPP
