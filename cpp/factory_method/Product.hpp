//
// Created by lizhifeng on 10/12/16.
//

#ifndef PATTERN_DESIGN_PRODUCT_HPP
#define PATTERN_DESIGN_PRODUCT_HPP

#include <iostream>


using namespace std;

namespace factory_method {


    class Product {

    public:
        Product() {
            cout << "Init Product" << endl;
        }

        virtual ~Product() {
            cout << "Destroy Product" << endl;
        }

    };

    class ProductA : public Product {

    public:
        ProductA() {
            cout << "Init Product A" << endl;
        }

        virtual ~ProductA() {
            cout << "Destroy Product A " << endl;
        }
    };


    class ProductB : public Product {

    public:
        ProductB() {
            cout << "Init Product B" << endl;
        }

        virtual ~ProductB() {
            cout << "Destroy Product B " << endl;
        }
    };

}  // end namespace factory_method

#endif //PATTERN_DESIGN_PRODUCT_HPP
