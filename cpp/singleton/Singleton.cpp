//
// Created by lizhifeng on 10/12/16.
//

#include "Singleton.hpp"

namespace singleton {


    Singleton *Singleton::_instance = NULL;
    Singleton::GarbageCollect Singleton::gc;
    pthread_mutex_t Singleton::_mutex = PTHREAD_MUTEX_INITIALIZER;

}  // end namespace singleton