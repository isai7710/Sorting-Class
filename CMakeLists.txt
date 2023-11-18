cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_STANDARD 17)

project(sorter LANGUAGES CXX)

add_subdirectory(lib)
add_subdirectory(sorter_unittests)
add_subdirectory(external)