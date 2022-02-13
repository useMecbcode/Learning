cmake_minimum_required(VERSION 3.21)
project(threads)

set(CMAKE_CXX_STANDARD 14)
# package
find_package(Threads REQUIRED)

add_executable(threads main.cpp)
# libraries
target_link_libraries(threads Threads::Threads)

