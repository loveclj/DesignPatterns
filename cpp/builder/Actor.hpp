//
// Created by clj on 2016/10/13.
//

#ifndef DESIGNPATTERN_ACTOR_HPP
#define DESIGNPATTERN_ACTOR_HPP

#include <iostream>

using namespace std;

namespace builder {

    class Actor {

    public:
        void set_type(string type){
            _type = type;
        }
        void set_sex(string sex){
            _sex = sex;
        }
        void set_face(string face){
            _face = face;
        }

        void set_costume(string costume){
            _costume = costume;
        }

        void set_hair_style(string hair_style){
            _hair_style = hair_style;
        }

        string get_sex(){
            return _sex;
        }

        string get_type(){
            return _type;
        }
    private:
        string _type;
        string _sex;
        string _face;
        string _costume;
        string _hair_style;
    };
}  // end namespace builder


#endif //DESIGNPATTERN_ACTOR_HPP
