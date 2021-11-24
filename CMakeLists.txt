cmake_minimum_required(VERSION 3.16)
project(linked_list)

set(CMAKE_CXX_STANDARD 20)

add_executable(linked_list main.cpp)

target_include_directories(linked_list PRIVATE src)