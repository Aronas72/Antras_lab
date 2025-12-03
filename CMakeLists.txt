cmake_minimum_required(VERSION 3.16)
project(v2_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(.)

add_library(studentas_lib
    funkcijos.cpp
    generavimas.cpp
    studentas.cpp)

add_executable(studentas_program main.cpp)
target_link_libraries(studentas_program PRIVATE studentas_lib)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip)

FetchContent_MakeAvailable(googletest)
enable_testing();

add_executable(unit_tests test_studentas.cpp)
target_link_libraries(unit_tests PRIVATE studentas_lib gtest gtest_main)

add_test(NAME AllTests COMMAND unit_tests)

