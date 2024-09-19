cmake_minimum_required(VERSION 3.27)
project(AVL_Project)

set(CMAKE_CXX_STANDARD 14)

include_directories(test-unit)

add_executable(AVL_Project
        src/main.cpp
        src/AVL.cpp
        src/AVL.h)

add_executable(AVL_Testing
        src/AVL.cpp
        src/AVL.h
        test-unit/test.cpp
        test-unit/catch.hpp)
