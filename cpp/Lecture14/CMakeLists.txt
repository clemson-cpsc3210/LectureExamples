cmake_minimum_required(VERSION 3.10)
project(Lecture14)

add_executable(CountInversions CountInversions.cpp)
target_link_libraries(CountInversions PRIVATE compiler_flags)

# check if the executable runs well
include(CTest)
add_test(NAME Run_CountInversions COMMAND CountInversions)
