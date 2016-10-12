//
// Created by lizhifeng on 10/12/16.
//

#ifndef PATTERN_DESIGN_FACTORY_HPP
#define PATTERN_DESIGN_FACTORY_HPP

#include "Product.hpp"

namespace simple_factory {

    class Factory {
    public:
        Factory() { }

        ~Factory() { }

        static Product *create_product(string product_type) {
            Product *p;
            if (product_type == "A") {
                p = new ProductA;
            } else if (product_type == "B") {
                p = new ProductB;
            } else {
                cout << "[ERROR]:unknown product type" << endl;
            }

            return p;
        }
    };

} // end namespace simple_factory

#endif //PATTERN_DESIGN_FACTORY_HPP
