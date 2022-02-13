cmake_minimum_required(VERSION 3.21)
project(DNS)

set(CMAKE_CXX_STANDARD 14)
find_package(Threads REQUIRED)
add_executable(DNS main.cpp)
target_link_libraries(DNS Threads::Threads)