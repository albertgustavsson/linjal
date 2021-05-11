cmake_minimum_required(VERSION 3.0)

project(Matrix)
set(CMAKE_CXX_STANDARD 11)

add_library(Matrix Matrix.cpp)
target_include_directories(Matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})