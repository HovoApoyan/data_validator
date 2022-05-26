cmake_minimum_required(VERSION 3.22)
project(data_validator)

set(CMAKE_CXX_STANDARD 17)



option(VALIDATION_AS_LIB "Enable if you want to use it as a library" ON)

if (VALIDATION_AS_LIB)
    add_library(data_validator STATIC main.cpp types.cpp types.h visitor.h)
else ()
    add_executable(data_validator main.cpp types.cpp types.h visitor.h)
endif (VALIDATION_AS_LIB)

