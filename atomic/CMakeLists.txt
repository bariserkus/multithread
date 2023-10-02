cmake_minimum_required(VERSION 3.25)
project(atomic)

set(CMAKE_CXX_STANDARD 23)

add_executable(atomic main.cpp)

set(CMAKE_CXX_FLAGS "-pthread")
