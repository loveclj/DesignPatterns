//
// Created by lizhifeng on 10/12/16.
//

#ifndef PATTERN_DESIGN_FACTORY_HPP
#define PATTERN_DESIGN_FACTORY_HPP

#include "Product.hpp"

namespace factory_method {

    class AbstractFactory {
    public:
        AbstractFactory() {
            cout << "Init Abstract Factory" << endl;
        }

        virtual ~AbstractFactory() {
            cout << "Destroy Abstract Factory" << endl;
        }

        virtual Product *create_product() = 0;
    };


    class FactoryA : public AbstractFactory {
    public:
        FactoryA() {
            cout << "Init Factory A" << endl;
        }

        virtual ~FactoryA() {
            cout << "Destroy Factory A" << endl;
        }

        virtual Product *create_product() {
            Product *p = new ProductA;
            return p;
        }
    };

    class FactoryB : public AbstractFactory {
    public:
        FactoryB() {
            cout << "Init Factory B" << endl;
        }

        virtual ~FactoryB() {
            cout << "Destroy Factory B" << endl;
        }

        virtual Product *create_product() {
            Product *p = new ProductB;
            return p;
        }
    };
}  // end namespace factory_method

#endif //PATTERN_DESIGN_FACTORY_HPP
