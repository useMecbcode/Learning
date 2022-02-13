cmake_minimum_required(VERSION 3.21)
project(op_net)

set(CMAKE_CXX_STANDARD 20)

add_executable(op_server main.cpp common.h common.cpp)
add_executable(op_client op_client.cpp common.h common.cpp)
