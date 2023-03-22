cmake_minimum_required(VERSION 3.26.0)
project(DataStructures VERSION 0.1.0)

add_executable(main src/main.cpp)
include_directories("include")

include(CTest)
enable_testing()
add_subdirectory("tests")