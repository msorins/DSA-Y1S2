cmake_minimum_required(VERSION 3.6)
project(3_DLL_Vector)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp DLLNode.cpp DLLNode.h DLL.cpp DLL.h DA/DA.cpp DA/DA.h DA/DAIterator.cpp DA/DAIterator.h)
add_executable(3_DLL_Vector ${SOURCE_FILES})