cmake_minimum_required(VERSION 3.7)
project(6_BinaryTree)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Node/Node.cpp Node/Node.h Heap/Heap.cpp Heap/Heap.h Iterators/PreOrder.cpp Iterators/PreOrder.h Iterators/InOrderRecursive.cpp Iterators/InOrderRecursive.h Iterators/PostOrder.cpp Iterators/PostOrder.h Tests/TestHeap.cpp Tests/TestHeap.h)
add_executable(6_BinaryTree ${SOURCE_FILES})