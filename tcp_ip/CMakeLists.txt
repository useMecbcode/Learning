cmake_minimum_required(VERSION 3.21)
project(tcp_ip)

set(CMAKE_CXX_STANDARD 14)

add_executable(server server.cpp my_socket_header.h my_socket_header.cpp)
add_executable(client my_socket_header.h my_socket_header.cpp client.cpp echo_server.cpp echo_client.cpp)
add_executable(low_open low_open.cpp)
add_executable(echo_server echo_server.cpp)
add_executable(echo_client echo_client.cpp)
