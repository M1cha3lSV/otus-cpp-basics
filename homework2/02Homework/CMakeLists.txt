cmake_minimum_required(VERSION 3.12)

project(01.hello_world)

add_executable(02Homework
    hello_world.cpp
    example.cpp
    example.h
    move_me_out.cpp
    move_me_out.h
)

set_target_properties(02Homework PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)