cmake_minimum_required(VERSION 3.10)
project(Lecture04)

add_executable(TreeBasedUnionFind UnionFind.cpp)
target_link_libraries(TreeBasedUnionFind PRIVATE compiler_flags)

# check if the executable runs well
include(CTest)
add_test(NAME Run_TreeBasedUnionFind COMMAND TreeBasedUnionFind)
