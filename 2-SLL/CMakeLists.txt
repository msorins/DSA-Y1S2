cmake_minimum_required(VERSION 3.6)
project(2_SLL)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp SSLNode.cpp SSLNode.h SSL.cpp SSL.h SSLIterator.cpp SSLIterator.h)
add_executable(2_SLL ${SOURCE_FILES})