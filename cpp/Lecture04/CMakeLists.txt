cmake_minimum_required(VERSION 3.10)
project(Lecture04)

add_executable(ClearableTable ClearableTable.cpp)
add_executable(QueueWithStacks QueueWithStacks.cpp)
add_executable(QueueWithStacksAlt QueueWithStacksAlt.cpp)

# check if the executable runs well
include(CTest)
add_test(NAME Run_ClearableTable COMMAND ClearableTable)
add_test(NAME Run_QueueWithStacks COMMAND QueueWithStacks)
add_test(NAME Run_QueueWithStacksAlt COMMAND QueueWithStacksAlt)
