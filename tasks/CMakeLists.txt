cmake_minimum_required(VERSION 3.26)
project(tasks)

set(CMAKE_CXX_STANDARD 23)

add_executable(tasks main.cpp)

set(CMAKE_CXX_FLAGS "-pthread")