//
// Created by lizhifeng on 10/12/16.
//

#ifndef PATTERN_DESIGN_PRODUCT_HPP
#define PATTERN_DESIGN_PRODUCT_HPP

#include <iostream>

using namespace std;

namespace simple_factory {

    class Product {

    public:
        Product() : _class_name("Product"), _name("abstract") {
            cout << "Init " << _class_name << endl;
        };

        Product(string A) { }

        virtual ~Product() {
            cout << "Destroy " << _class_name << endl;
        };

        virtual string get_name() {
            return _name;
        }

        string get_class_name() {
            return _class_name;
        }

    public:
        string _name;

    private:
        string _class_name;

    };

    class ProductA : public Product {
    public:
        ProductA() : _class_name("ProductA") {

            _name = "concrete A";
            cout << "Init" << _class_name << endl;
        };

        virtual  ~ProductA() {
            cout << "Destroy " << _class_name << endl;
        };

    private:
        string _class_name;
    };

    class ProductB : public Product {
    public:
        ProductB() : _class_name("ProductB") {
            _name = "concrete B";
            cout << "Init" << _class_name << endl;
        };

        virtual  ~ProductB() {
            cout << "Destroy " << _class_name << endl;
        };

    private:
        string _class_name;
    };
}  // end namespace simple_factory

#endif //PATTERN_DESIGN_PRODUCT_HPP
