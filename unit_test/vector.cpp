//
// Created by qli on 25/02/2021.
//
#include "catch2/catch.hpp"
#include "../containers/vector.h"

TEST_CASE("vector empty constructor", "[vector]") {
	std::vector<char> original0;
	ft::vector<int> custom0;
//	std::vector<char> original1(123);
//	ft::vector<char> custom1(123);
//	std::vector<int> original2(0);
//	ft::vector<int> custom2(0);
//	std::vector<float> original3(45);
//	ft::vector<float> custom3(45);

	SECTION("test initialised value") {
		REQUIRE(custom0.size() == original0.size());
		REQUIRE(custom0.capacity() == original0.capacity());
//		REQUIRE(custom1.size() == original1.size());
//		REQUIRE(custom1.capacity() == original1.capacity());
//		REQUIRE(custom2.size() == original2.size());
//		REQUIRE(custom2.capacity() == original2.capacity());
//		REQUIRE(custom3.size() == original3.size());
//		REQUIRE(custom3.capacity() == original3.capacity());
	}
}

TEST_CASE("test constructor with ints", "vector"){
	std::vector<int> vecOfInts(5);
	for(int i : vecOfInts)
		REQUIRE(i == 0);
	REQUIRE(vecOfInts.size() == 5);
}

TEST_CASE("test constructor with an array", "vector"){
	std::string arr[] = {"first", "second", "third", "fourth"};

	std::vector<std::string> vecOfStr(arr, arr+sizeof(arr)/sizeof(std::string));
	REQUIRE(vecOfStr.size() == 4);
	REQUIRE(vecOfStr[0] == "first");
	REQUIRE(vecOfStr[1] == "second");
	REQUIRE(vecOfStr[2] == "third");
	REQUIRE(vecOfStr[3] == "fourth");
}

TEST_CASE("test copy constructor", "vector") {
	std::vector<std::string> vecOfStr;
	vecOfStr.push_back("first");
	vecOfStr.push_back("second");
	vecOfStr.push_back("third");
	vecOfStr.push_back("fourth");
	std::vector<std::string> vecOfStr2(vecOfStr);
	REQUIRE(vecOfStr2[0] == "first");
	REQUIRE(vecOfStr2[1] == "second");
	REQUIRE(vecOfStr2[2] == "third");
	REQUIRE(vecOfStr2[3] == "fourth");


}