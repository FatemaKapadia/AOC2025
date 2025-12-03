cmake_minimum_required(VERSION 3.31)
project(AdventOfCode2025)

set(CMAKE_CXX_STANDARD 20)

add_executable(AdventOfCode2025 main.cpp
        Day1.cpp
        Day1.h
        Day2.cpp
        Day2.h
        Day.cpp
        Day.h
        utils.cpp
        utils.h
        Day3.cpp
        Day3.h
)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input1.1.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/input3.1.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/example.txt ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)

