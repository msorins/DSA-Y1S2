cmake_minimum_required(VERSION 3.6)
project(DSA_4MAP)

set(CMAKE_CXX_STANDARD 11)
set(SOURCE_FILES main.cpp Map.cpp Map.h Elem.cpp Elem.h DA/DA.cpp DA/DA.h DA/DAIterator.cpp DA/DAIterator.h MapIterator.cpp MapIterator.h)

add_executable(DSA_4MAP ${SOURCE_FILES})