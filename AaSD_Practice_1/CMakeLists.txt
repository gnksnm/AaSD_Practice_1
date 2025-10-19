cmake_minimum_required(VERSION 4.0)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        darray.cpp
        darray.h
        list.cpp
        list.h
        stack.cpp
        stack.h)
