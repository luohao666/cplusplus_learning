cmake_minimum_required(VERSION 2.8)
project(cpp_demo)

# 添加c++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11 -pthread" )

add_executable(main main.cpp)
