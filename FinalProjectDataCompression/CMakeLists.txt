cmake_minimum_required(VERSION 3.12)
project(FinalProjectDataCompression)

set(CMAKE_CXX_STANDARD 14)

add_executable(FinalProjectDataCompression main.cpp Huffman.cpp Huffman.h LZW.cpp LZW.h RunLength.cpp RunLength.h Util.cpp)