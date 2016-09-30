//
// Created by lizhifeng on 9/30/16.
//

#ifndef CHEMICAL_COMMON_HPP
#define CHEMICAL_COMMON_HPP

#include <iostream>


// Disable copy and assignment operator for a class
#define DISABLE_COPY_AND_ASSIGN(ClassName) \
private:\
  ClassName(const ClassName  &); \
  ClassName & operator=(const ClassName &)


#endif //CHEMICAL_COMMON_HPP
