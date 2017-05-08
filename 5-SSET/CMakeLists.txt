cmake_minimum_required(VERSION 3.6)
project(5_SSET)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DA/DA.h DA/DA.cpp DA/DAIterator.h DA/DAIterator.cpp SSET.cpp SSET.h SSETIterator.cpp SSETIterator.h)
add_executable(5_SSET ${SOURCE_FILES})