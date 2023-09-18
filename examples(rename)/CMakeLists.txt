cmake_minimum_required(VERSION 3.8)
project(main)

set(CMAKE_CXX_STANDARD 23)

add_executable(main src/main.cpp)
target_link_libraries(main PUBLIC UTF8Lib)

