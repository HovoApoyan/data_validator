cmake_minimum_required(VERSION 3.22)
project(data_validator)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_validator main.cpp types.cpp types.h visitor.h)
