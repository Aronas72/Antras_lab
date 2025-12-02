cmake_minimum_required(VERSION 3.10)

project(Studentai VERSION 2.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCES
    main.cpp
    funkcijos.cpp
    generavimas.cpp
    studentas.cpp)

include_directories(include)

add_executable(studentai ${SOURCES})
