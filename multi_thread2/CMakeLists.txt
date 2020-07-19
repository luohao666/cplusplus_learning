cmake_minimum_required(VERSION 2.8)

project(cpp_demo)

set(CMAKE_CXX_FLAGS "-std=c++11 -pthread")

include_directories(
    include
)

add_executable(main main.cpp)
add_executable(test test.cpp)