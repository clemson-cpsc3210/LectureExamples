cmake_minimum_required(VERSION 3.10)
project(Lecture07)

add_executable(BinarySearchTree BinarySearchTree.cpp)
target_link_libraries(BinarySearchTree PRIVATE compiler_flags)

# check if the executable runs well
include(CTest)
add_test(NAME Run_BinarySearchTree COMMAND BinarySearchTree)
