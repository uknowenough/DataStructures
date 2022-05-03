cmake_minimum_required(VERSION 3.5)

project(DataStructures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(DataStructures src/main.cpp
    include/Data.h
    include/Node.h
    include/SinglyLinkedList.h
    include/BinaryTree.h)

#add_subdirectory(tests)
