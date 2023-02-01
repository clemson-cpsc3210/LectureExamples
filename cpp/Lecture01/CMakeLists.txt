cmake_minimum_required(VERSION 3.10)
project(Lecture01)

add_executable(Factorial Factorial.cpp)
add_executable(Fibonacci Fibonacci.cpp)

# # check if the executable runs well
# include(CTest)
# add_test(NAME Run_Factorial COMMAND Factorial)
# add_test(NAME Run_Fibonacci COMMAND Fibonacci)
