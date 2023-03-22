cmake_minimum_required(VERSION 3.26.0)
project(DataStructures VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options($<$<CONFIG:Debug>:-Wsign-conversion>)
add_compile_options($<$<CONFIG:Debug>:-Wall>)
add_compile_options($<$<CONFIG:Debug>:-Wextra>)
add_compile_options($<$<CONFIG:Debug>:-Wpedantic>)

add_executable(main src/main.cpp)
include_directories("include")

include(CTest)
enable_testing()
add_subdirectory("tests")