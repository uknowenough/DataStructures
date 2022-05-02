cmake_minimum_required(VERSION 3.5)

project(data-structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(binary-tree src/main.cpp
    include/Data.h
    include/Node.h
    include/BinaryTree.h)
