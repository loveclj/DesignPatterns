//
// Created by lizhifeng on 10/12/16.
//
//工厂方法模式通过引入工厂等级结构，解决了简单工厂模式中工厂类职责太重的问题，
// 但由于工厂方法模式中的每个工厂只生产一类产品，可能会导致系统中存在大量的工厂类，
// 势必会增加系统的开销。此时，我们可以考虑将一些相关的产品组成一个“产品族”，
// 由同一个工厂来统一生产，这就是抽象工厂模式的基本思想。


//(1) 产品等级结构：产品等级结构即产品的继承结构，如一个抽象类是电视机，
// 其子类有海尔电视机、海信电视机、TCL 电视机，则抽象电视机与具体品牌
// 的电视机之间构成了一个产品等级结构，抽象电视机是父类，而具体品牌的电视机是其子类。

//(2) 产品族：在抽象工厂模式中，产品族是指由同一个工厂生产的，
// 位于不同产品等级结构中的一组产品，如海尔电器工厂生产的海尔电视机、
// 海尔电冰箱，海尔电视机位于电视机产品等级结构中，海尔电冰箱位于电冰箱产品等级结构中
// ，海尔电视机、海尔电冰箱构成了一个产品族。


//(1) 增加产品族：对于增加新的产品族，抽象工厂模式很好地支持了“开闭原则”，
// 只需要增加具体产品并对应增加一个新的具体工厂，对已有代码无须做任何修改。

//(2) 增加新的产品等级结构：对于增加新的产品等级结构，需要修改所有的工厂角色，
// 包括抽象工厂类，在所有的工厂类中都需要增加生产新产品的方法，违背了“开闭原则”。

#ifndef PATTERN_DESIGN_FACTORY_HPP
#define PATTERN_DESIGN_FACTORY_HPP

#include "Product.hpp"

namespace abstract_factory{



    class AbstractMealFactory{
    public:
        AbstractMealFactory(){}
        virtual ~AbstractMealFactory(){};

        virtual AbstractMeat *create_meat() = 0;
        virtual AbstractNoodle *create_noodle() = 0;
        virtual AbstractSnack *create_snack() = 0;

    };


    class MealFactoryA: public AbstractMealFactory{

    public:
        MealFactoryA(){
            cout << "init meal factory A" << endl;
        }
        virtual ~MealFactoryA(){
            cout << "destroy meal factory A" << endl;
        }

        virtual AbstractMeat *create_meat(){
            AbstractMeat * m = new MeatPork;
            return m;
        }
        virtual AbstractNoodle *create_noodle(){
            AbstractNoodle *noodle = new NoodleVermicelli;
            return noodle;
        }

        virtual AbstractSnack *create_snack(){
            AbstractSnack *snack = new SnackTeaEgg;
            return snack;
        }
    };

    class MealFactoryB: public AbstractMealFactory{

    public:
        MealFactoryB(){
            cout << "init meal factory B" << endl;
        }
        virtual ~MealFactoryB(){
            cout << "destroy meal factory B" << endl;
        }

        virtual AbstractMeat *create_meat(){
            AbstractMeat * m = new MeatBeef;
            return m;
        }
        virtual AbstractNoodle *create_noodle(){
            AbstractNoodle *noodle = new NoodlePotatoPowder;
            return noodle;
        }

        virtual AbstractSnack *create_snack(){
            AbstractSnack *snack = new SnackDriedTofu;
            return snack;
        }
    };

} // end abstract_factory


#endif //PATTERN_DESIGN_FACTORY_HPP
