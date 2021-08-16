cmake_minimum_required(VERSION 3.17)

project(ft_containers)

set(SOURCES
        unit_test/catch2/catch.hpp
        unit_test/catch2/catch.cpp
        unit_test/test_vector.cpp
        containers/vector.h
        iterators/random_access_iterator.h
        iterators/iterator_traits.h
        iterators/reverse_iterator.h
        iterators/utils.h
        unit_test/test_vector_iterator.cpp
        unit_test/test_reverse_vector_iterator.cpp
        iterators/type_traits.h
        containers/stack.h
        unit_test/test_stack.cpp
        containers/map.h
        iterators/value_compare.h
        iterators/pair.h
        iterators/make_pair.h)

set(CMAKE_CXX_COMPILER clang++)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -std=c++98")

add_executable(UNIT_TEST ${SOURCES})