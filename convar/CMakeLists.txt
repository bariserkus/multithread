cmake_minimum_required(VERSION 3.26)
project(convar)

set(CMAKE_CXX_STANDARD 23)

add_executable(convar main.cpp)

set(CMAKE_CXX_FLAGS "-pthread")