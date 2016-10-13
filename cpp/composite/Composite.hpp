//
// Created by lizhifeng on 10/13/16.
//


// 在组合模式结构图中包含如下几个角色：

//Component（抽象构件）：它可以是接口或抽象类，为叶子构件和容器构件对象声明接口，
// 在该角色中可以包含所有子类共有行为的声明和实现。在抽象构件中定义了访问及管理它的子构件的方法，
// 如增加子构件、删除子构件、获取子构件等。

//Leaf（叶子构件）：它在组合结构中表示叶子节点对象，叶子节点没有子节点，
// 它实现了在抽象构件中定义的行为。对于那些访问及管理子构件的方法，
// 可以通过异常等方式进行处理。

//Composite（容器构件）：它在组合结构中表示容器节点对象，容器节点包含子节点，
// 其子节点可以是叶子节点，也可以是容器节点，它提供一个集合用于存储子节点，
// 实现了在抽象构件中定义的行为，包括那些访问及管理子构件的方法，
// 在其业务方法中可以递归调用其子节点的业务方法。

// 组合模式的关键是定义了一个抽象构件类，
// 它既可以代表叶子，又可以代表容器，而客户端针对该抽象构件类进行编程，
// 无须知道它到底表示的是叶子还是容器，可以对其进行统一处理。
// 同时容器对象与抽象构件类之间还建立一个聚合关联关系，在容器对象中既可以包含叶子，
// 也可以包含容器，以此实现递归组合，形成一个树形结构。
// 如果不使用组合模式，客户端代码将过多地依赖于容器对象复杂的内部实现结构，
// 容器对象内部实现结构的变化将引起客户代码的频繁变化，
// 带来了代码维护复杂、可扩展性差等弊端。组合模式的引入将在一定程度上解决这些问题。


#ifndef PATTERN_DESIGN_COMPOSITE_HPP
#define PATTERN_DESIGN_COMPOSITE_HPP

#endif //PATTERN_DESIGN_COMPOSITE_HPP

#include <iostream>
#include <vector>

using namespace std;


namespace composite{

    class File{

    public:
        File(){

        }
        virtual ~File(){}

        virtual string get_name() = 0;
        virtual void add_file(File *) = 0;
        virtual void get_child_name() = 0;


    private:
        string _name;
        string _type;
        vector<File*> _file_list;
    };  // end class File


    class Image: public File{  //leaf

    public:
        Image(string name){
            _name = name;
            _type = "image";
        }
        virtual ~Image(){}

        virtual string get_name(){
            return _name;
        }

        virtual void add_file(File *f){
            cout << _name  << " is not a fold, can't add a file" << endl;
        }

        virtual void get_child_name(){
            cout << _name << " is nto a fold, can't have child file" << endl;
        }

    private:
        string _name;
        string _type;

    };  // end class Image


    class Text: public File{  //leaf

    public:
        Text(string name){
            _name = name;
            _type = "text";
        }
        virtual ~Text(){}

        virtual string get_name(){
            return _name;
        }

        virtual void add_file(File *f){
            cout << _name  << " is not a fold, can't add a file" << endl;
        }

        virtual void get_child_name(){
            cout << _name << " is nto a fold, can't have child file" << endl;
        }

    private:
        string _name;
        string _type;

    };  // end class Text

    class Binary: public File{  //leaf

    public:
        Binary(string name){
            _name = name;
            _type = "binary";
        }
        virtual ~Binary(){
        }

        virtual string get_name(){
            return _name;
        }

        virtual void add_file(File *f){
            cout << _name  << " is not a fold, can't add a file" << endl;
        }

        virtual void get_child_name(){
            cout << _name << " is nto a fold, can't have child file" << endl;
        }

    private:
        string _name;
        string _type;

    };  // end class Binary


    class Folder: public File{

    public:
        Folder(string name): _file_list(){
            _name = name;
            _type = "folder";
        }
        virtual ~Folder(){}

        virtual string get_name(){
            return _name;
        };
        virtual void add_file(File *f){
            _file_list.push_back(f);
        };
        virtual void get_child_name(){
            cout << " ========= child file name ======="  << endl;
            for(auto e: _file_list){
                cout << e->get_name() << endl;
                if(Folder *f = dynamic_cast<Folder*>(e)){
                    e->get_child_name();
                }
            }
            cout << " ==================================" << endl;
        };

    private:
        string _name;
        string _type;
        vector<File*> _file_list;
    };  // end class Folder


}  // end namescpace composite