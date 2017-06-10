cmake_minimum_required(VERSION 3.7)
project(6_SIMPLIFIED)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PreRecursive.cpp PreRecursive.h PreIterative.cpp PreIterative.h InRecursive.cpp InRecursive.h InIterative.cpp InIterative.h PostRecursive.cpp PostRecursive.h PostIterative.cpp PostIterative.h)
add_executable(6_SIMPLIFIED ${SOURCE_FILES})