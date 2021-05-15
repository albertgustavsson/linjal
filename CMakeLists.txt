cmake_minimum_required(VERSION 3.0)

project(Linjal)
set(CMAKE_CXX_STANDARD 11)

add_library(Linjal Matrix.cpp)
target_include_directories(Linjal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(examples)