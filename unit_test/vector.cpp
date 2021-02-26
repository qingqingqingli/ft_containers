//
// Created by qli on 25/02/2021.
//
#include "catch2/catch.hpp"
#include "../containers/vector.h"

TEST_CASE("vector empty constructor", "[vector]") {
	std::vector<char> original1(123);
	ft::vector<char> custom1(123);
	std::vector<int> original2(0);
	ft::vector<int> custom2(0);

	SECTION("test initialised value") {
		REQUIRE(custom1.size() == original1.size());
		REQUIRE(custom1.capacity() == original1.capacity());
		REQUIRE(custom2.size() == original2.size());
		REQUIRE(custom2.capacity() == original2.capacity());
	}
}


//TEST_CASE( "test vector constructors", "[vector]" ) {
//	// initialization block
//	std::vector<int> first;
//	std::vector<int> second (4,100);
//	std::vector<int> third (second.begin(),second.end());
//	std::vector<int> fourth (third);
//
//	// check initial size & capacity
//	REQUIRE(first.size() == 0);
//	REQUIRE(first.capacity() == 0);
//	REQUIRE(second.size() == 4);
//	REQUIRE(second.capacity() == 4);
//	REQUIRE(third.size() == 4);
//	REQUIRE(third.capacity() == 4);
//	REQUIRE(fourth.size() == 4);
//	REQUIRE(fourth.capacity() == 4);
//
//	SECTION("resize vector") {
//		// increase to 250 -> size and capacity change to 250
//		second.resize(250);
//		REQUIRE(second.size() == 250);
//		REQUIRE(second.capacity() == 250);
//		// resize to 0 -> size changes to 0 and capacity remains
//		second.resize(0);
//		REQUIRE(second.size() == 0);
//		REQUIRE(second.capacity() == 250);
//		// increase to 1024 -> size && capacity == 1024
//		second.resize(1024);
//		REQUIRE(second.size() == 1024);
//		REQUIRE(second.capacity() == 1024);
//		// pushback an element -> size += 1 & capacity *= 2
//		second.push_back(80);
//		REQUIRE(second.size() == 1025);
//		REQUIRE(second.capacity() == 2048);
//		// pushback an element -> size == 20 & capacity remains
//		second.resize(20);
//		REQUIRE(second.size() == 20);
//		REQUIRE(second.capacity() == 2048);
//	}
//}
