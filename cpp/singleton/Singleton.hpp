//
// Created by lizhifeng on 10/12/16.
//

#ifndef PATTERN_DESIGN_SINGLETON_HPP
#define PATTERN_DESIGN_SINGLETON_HPP

#include <iostream>
#include <pthread.h>

using namespace std;

namespace singleton {


    class Singleton {

    public:
        ~Singleton() {
            delete _data;
            cout << "Destroy Singleton" << endl;
        };

        static Singleton *get_instance() {
            if (_instance == NULL) {
                pthread_mutex_lock(&_mutex);
                if (_instance == NULL) {
                    _instance = new Singleton;
                }
                pthread_mutex_unlock(&_mutex);
            }
            return _instance;

        }

    private:
        class GarbageCollect {
        public:
            GarbageCollect() {
                cout << "Init GarbageCollect" << endl;
            }

            ~GarbageCollect() {
                cout << "Destroy GarbageCollect" << endl;
                if (Singleton::_instance != NULL) {
                    delete Singleton::_instance;
                }
            }

        };

    private:
        string _name;
        int *_data;

        static Singleton *_instance;

        static pthread_mutex_t _mutex;

        static GarbageCollect gc;

        Singleton() : _name("Singleton") {
            _data = new int;
            cout << "Init Singleton" << endl;
        };


        Singleton(const Singleton &);

        Singleton &operator=(const Singleton &);

    };

}  // end namespace singleton


#endif //PATTERN_DESIGN_SINGLETON_HPP
