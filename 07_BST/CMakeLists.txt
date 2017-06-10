cmake_minimum_required(VERSION 3.7)
project(07_BST)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node/Node.cpp Node/Node.h BST/BST.cpp BST/BST.h Iterator/Iterator.cpp Iterator/Iterator.h)
add_executable(07_BST ${SOURCE_FILES})