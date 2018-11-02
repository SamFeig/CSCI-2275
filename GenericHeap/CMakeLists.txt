cmake_minimum_required(VERSION 3.12)
project(GenericHeap)

set(CMAKE_CXX_STANDARD 14)

add_executable(GenericHeap  GenericHeap.cpp heapsTests.cpp)#main.cpp