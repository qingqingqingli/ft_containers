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
	std::vector<float> original3(45);
	ft::vector<float> custom3(45);

	SECTION("test initialised value") {
		REQUIRE(custom1.size() == original1.size());
		REQUIRE(custom1.capacity() == original1.capacity());
		REQUIRE(custom2.size() == original2.size());
		REQUIRE(custom2.capacity() == original2.capacity());
		REQUIRE(custom3.size() == original3.size());
		REQUIRE(custom3.capacity() == original3.capacity());
	}
}
