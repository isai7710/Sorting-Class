cmake_minimum_required(VERSION 3.10)
project(Sorter)

add_library(${PROJECT_NAME} Sorter.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
