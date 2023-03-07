cmake_minimum_required(VERSION 3.10)
project(Lecture12)

add_executable(TaskScheduling TaskScheduling.cpp)
target_link_libraries(TaskScheduling PRIVATE compiler_flags)

# check if the executable runs well
include(CTest)
add_test(NAME Run_TaskScheduling COMMAND TaskScheduling)
