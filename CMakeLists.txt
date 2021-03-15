cmake_minimum_required(VERSION 3.17)

project(ft_containers)

set(SOURCES
        unit_test/catch2/catch.hpp
        unit_test/catch2/catch.cpp
        unit_test/vector.cpp
        containers/vector.h
        iterators/random_access_iterator.h unit_test/random_access_iterator.cpp)

set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(UNIT_TEST ${SOURCES})