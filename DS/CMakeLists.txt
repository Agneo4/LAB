cmake_minimum_required(VERSION 3.6)
project(DS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        LAB_12/Sorts.cpp)
add_executable(DS ${SOURCE_FILES})