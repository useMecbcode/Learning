cmake_minimum_required(VERSION 3.21)
project(sort)

set(CMAKE_CXX_STANDARD 17)

add_executable(sort src/main.cpp includes/search.h src/search.cpp includes/tree.h src/tree.cpp)
