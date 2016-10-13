//
// Created by lizhifeng on 10/13/16.
//


//　代理模式可实现类似智能指针
//　代理模式和适配器模式很像，一般代理模式的目的是为了实现统一的接口。而
//　代理模式是为了对访问进行控制
//　其实设计模式都非常相似，要从本质上去分析模式的目的，另外即使从本质上来看，也非常相似


#ifndef PATTERN_DESIGN_PROXY_HPP
#define PATTERN_DESIGN_PROXY_HPP

#include <iostream>

using namespace std;

namespace proxy {


    class Customer {

    public:
        Customer(){}
        virtual ~Customer(){};

        virtual void buy() = 0;

    };

    class AmericaCustomer: public Customer{

    public:
        AmericaCustomer(){}
        virtual ~AmericaCustomer(){}

        virtual void buy(){
            cout << "buy in America" << endl;
        }


    };
    class ChineseCustomerProxy: public Customer{

    public:
        ChineseCustomerProxy(): _ac(NULL){
//            _ac = new AmericaCustomer;
        }
        virtual ~ChineseCustomerProxy(){
            if(_ac != NULL){
                delete(_ac);
            }
        }

        virtual void buy(){
            if(_ac == NULL){
                _ac = new AmericaCustomer;
            }

            _ac->buy();

        }

    private:
        AmericaCustomer *_ac;

    };



}  // end namespace proxy


#endif //PATTERN_DESIGN_PROXY_HPP
