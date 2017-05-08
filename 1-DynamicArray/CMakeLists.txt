cmake_minimum_required(VERSION 3.6)
project(1_SinglyLinkedListDynamic)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DA.cpp DA.h DAIterator.cpp DAIterator.h)
add_executable(1_SinglyLinkedListDynamic ${SOURCE_FILES})