cmake_minimum_required(VERSION 3.12)
project(L7)

set(CMAKE_CXX_STANDARD 14)

add_executable(L7 Base.cpp Base.h Derived.cpp Derived.h main.cpp)