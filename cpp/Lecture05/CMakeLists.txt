cmake_minimum_required(VERSION 3.10)
project(Lecture04)

add_executable(ListBasedUnionFind UnionFind.cpp)
target_link_libraries(ListBasedUnionFind PRIVATE compiler_flags)

# check if the executable runs well
include(CTest)
add_test(NAME Run_ListBasedUnionFind COMMAND ListBasedUnionFind)
