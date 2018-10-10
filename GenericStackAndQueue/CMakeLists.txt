cmake_minimum_required(VERSION 3.12)
project(GenericStackAndQueue)

set(CMAKE_CXX_STANDARD 14)

add_executable(GenericStackAndQueue main.cpp GenericStack.cpp GenericQueue.cpp)