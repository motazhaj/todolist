cmake_minimum_required(VERSION 3.26)
project(todolist)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(todolist
        cParser.cpp
        cParser.h
        main.cpp
        todoListHeaders.h)
