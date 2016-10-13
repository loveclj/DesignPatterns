//
// Created by lizhifeng on 10/13/16.
//

// 装饰模式可以在不改变一个对象本身功能的基础上给对象增加额外的新行为

//在装饰模式结构图中包含如下几个角色：
// Component（抽象构件）：它是具体构件和抽象装饰类的共同父类，声明了在具体构件中实现的业务方法，
// 它的引入可以使客户端以一致的方式处理未被装饰的对象以及装饰之后的对象，实现客户端的透明操作。

//ConcreteComponent（具体构件）：它是抽象构件类的子类，用于定义具体的构件对象，
// 实现了在抽象构件中声明的方法，装饰器可以给它增加额外的职责（方法）。

//Decorator（抽象装饰类）：它也是抽象构件类的子类，用于给具体构件增加职责，
// 但是具体职责在其子类中实现。它维护一个指向抽象构件对象的引用，
// 通过该引用可以调用装饰之前构件对象的方法，并通过其子类扩展该方法，以达到装饰的目的。

//ConcreteDecorator（具体装饰类）：它是抽象装饰类的子类，负责向构件添加新的职责。
// 每一个具体装饰类都定义了一些新的行为，它可以调用在抽象装饰类中定义的方法，并可以增加新的方法用以扩充对象的行为。


//对装饰器模式来说，装饰者（decorator）和被装饰者（decoratee）都实现同一个 接口。
// 对代理模式来说，代理类（proxy class）和真实处理的类（real class）都实现同一个接口。
// 此外，不论我们使用哪一个模式，都可以很容易地在真实对象的方法前面或者后面加上自定义的方法。

//然而，实际上，在装饰器模式和代理模式之间还是有很多差别的。
// 装饰器模式关注于在一个对象上动态的添加方法，然而代理模式关注于控制对对象的访问。
// 换句话 说，用代理模式，代理类（proxy class）可以对它的客户隐藏一个对象的具体信息。
// 因此，当使用代理模式的时候，我们常常在一个代理类中创建一个对象的实例。
// 并且，当我们使用装饰器模 式的时候，我们通常的做法是将原始对象作为一个参数传给装饰者的构造器。



#ifndef PATTERN_DESIGN_DOCORATOR_HPP
#define PATTERN_DESIGN_DOCORATOR_HPP

#include <iostream>


using namespace std;

namespace  decorator {

    class CookComponent {

    public:
        CookComponent() { }

        ~CookComponent() { }

        virtual  void operation(){
            cout << _name << endl;
        };

        virtual void set_component(CookComponent *){}

    private:
        string _name;
    };

    class CookFoodConcreteComponent: public CookComponent{

    public:
        CookFoodConcreteComponent(){
            _name = "菜";
        }
        virtual ~CookFoodConcreteComponent(){}

        virtual void operation(){
            cout << _name << endl;
        }

    private:
        string _name;
    };

    class CookDecorator: public CookComponent{

    public:
        CookDecorator(){}
        virtual ~CookDecorator(){}

        virtual void set_component(CookComponent *component){
            _component = component;
        }
        virtual void operation(){

        };

    private:
        string _name;
        CookComponent *_component;

    };




    class CookAddSaltConcreteDecorator: public CookDecorator{

    public:
        CookAddSaltConcreteDecorator(){
            _name = "add salt";
        }
        virtual ~CookAddSaltConcreteDecorator(){}

        virtual void set_component(CookComponent *component){
            _component = component;
        }

        virtual void operation(){
            _component->operation();
            cout << _name << endl;
        }
    private:
        string _name;
        CookComponent *_component;
    };

    class CookAddAginomotoConcreteDecorator: public CookDecorator{

    public:
        CookAddAginomotoConcreteDecorator(){
            _name = "add aginomoto";
        }
        virtual ~CookAddAginomotoConcreteDecorator(){}

        virtual void set_component(CookComponent *component){
            _component = component;
        }

        virtual void operation(){
            _component->operation();
            cout << _name << endl;
        }
    private:
        string _name;
        CookComponent *_component;
    };

    class CookAddPepperConcreteDecorator: public CookDecorator{

    public:
        CookAddPepperConcreteDecorator(){
            _name = "add pepper";
        }
        virtual ~CookAddPepperConcreteDecorator(){}

        virtual void set_component(CookComponent *component){
            _component = component;
        }

        virtual void operation(){
            _component->operation();
            cout << _name << endl;
        }
    private:
        string _name;
        CookComponent *_component;
    };

}  // end namespace decorator
#endif //PATTERN_DESIGN_DOCORATOR_HPP
