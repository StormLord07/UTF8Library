cmake_minimum_required(VERSION 3.8)
project(UTF8Lib)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_library(UTF8Lib SHARED src/UTF8Char.cpp src/UTF8String.cpp)
target_include_directories(UTF8Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
