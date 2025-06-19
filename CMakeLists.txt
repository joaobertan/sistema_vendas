cmake_minimum_required(VERSION 3.31)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled src/main.c
        src/actions.h
        src/actions.c
        src/utils.h
        src/utils.c
        src/structs.h)
