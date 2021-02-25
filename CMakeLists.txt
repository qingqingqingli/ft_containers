cmake_minimum_required(VERSION 3.17)

project(ft_containers)

set(SOURCES
        unit_test/catch2/catch.hpp
        unit_test/catch2/catch.cpp
        unit_test/vector.cpp
        containers/vector.h)

set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(UNIT_TEST ${SOURCES})