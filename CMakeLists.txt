cmake_minimum_required(VERSION 3.26)
project(todolist)

set(CMAKE_CXX_STANDARD 17)

add_executable(todolist main.cpp
        cParser.cpp
        date.cpp
        enumsParser.cpp
        todoItem.cpp
        todoList.cpp
        weather.cpp)
