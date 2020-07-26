cmake_minimum_required(VERSION 2.8)
project(demo)

set(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(
    include
)

add_executable(client client.cpp)
add_executable(server server.cpp)