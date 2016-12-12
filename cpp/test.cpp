/*************************************************************************
	> File Name: test.cpp
	> Author: Arcs
	> Mail: lizhifeng2009@126.com
	> Created Time: Fri 14 Oct 2016 12:03:29 PM CST
 ************************************************************************/

#include<iostream>
#include<vector>
using namespace std;


class Base{
    public:
    void print(){
        cout << "I am base" << endl;
    }

    virtual void test(){
        cout << "Base test" << endl;
        print();
    }
};

class Child: public Base{
    public:
    void print(){
        cout << "I am child" << endl;
    }

    void virtual test(){
        cout << "Child Test" << endl;
        print();
        Base::print();
    }
    
};

int main(int argc, char **argv)
{
    Base * p = new Child;
    p->test();
    vector<string> *t = new vector<string>;
    t->push_back("t");
    cout << (*t)[0] << endl;
}
