cmake_minimum_required(VERSION 3.3)
project(chemical)

include_directories(
        "include"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp include/common.hpp include/tclap/parameter.h include/parameter.hpp src/parameter.cpp)
add_executable(chemical ${SOURCE_FILES})