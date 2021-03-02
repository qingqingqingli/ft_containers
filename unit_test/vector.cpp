//
// Created by qli on 25/02/2021.
//
#include "catch2/catch.hpp"
#include "../containers/vector.h"
#include <fstream>

TEST_CASE("1. default constructor: empty vector", "[vector]") {
	std::vector<char> std_first;
	ft::vector<int> ft_first;

	REQUIRE(ft_first.size() == std_first.size());
	REQUIRE(ft_first.capacity() == std_first.capacity());
}

TEST_CASE("2. default constructor: vector with size and val", "[vector]") {
	std::vector<int> std_first(99);
	ft::vector<int> ft_first(99);
	std::vector<char> std_second(123);
	ft::vector<char> ft_second(123);
	std::vector<int> std_third(9000, 99);
	ft::vector<int> ft_third(9000, 99);
	std::vector<float> std_fourth(45);
	ft::vector<float> ft_fourth(45);

	REQUIRE(ft_first.size() == std_first.size());
	REQUIRE(ft_first.capacity() == std_first.capacity());
	REQUIRE(ft_second.size() == std_second.size());
	REQUIRE(ft_second.capacity() == std_second.capacity());
	REQUIRE(ft_third.size() == std_third.size());
	REQUIRE(ft_third.capacity() == std_third.capacity());
	REQUIRE(ft_fourth.size() == std_fourth.size());
	REQUIRE(ft_fourth.capacity() == std_fourth.capacity());
}

TEST_CASE("3. default constructor: vector with InputIterator", "[vector]") {

	std::vector<int> std_first(4, 100);
	std::vector<int> std_second(std_first.begin(), std_first.end());

	int myints[] = {16,2,77,29};
	std::ofstream ofs;
	ofs.open("test.txt");
	std::ifstream ifs("test.txt");
	std::string str;
	std::vector<int> std_third(myints, myints + sizeof(myints) / sizeof(int) );
	for (std::vector<int>::iterator it = std_third.begin(); it != std_third.end(); ++it)
		ofs << ' ' << *it;
	ofs << std::endl;
	std::getline(ifs, str);

	REQUIRE(std_second.size() == 4);
	REQUIRE(std_second[0] == 100);
	REQUIRE(std_second[1] == 100);
	REQUIRE(std_second[2] == 100);
	REQUIRE(std_second[3] == 100);
	REQUIRE(str==" 16 2 77 29");
}

TEST_CASE("4. copy constructor", "vector"){

	SECTION("empty vector") {
		std::vector<int> std_first;
		std::vector<int> std_first_copy(std_first);
		std::vector<int> ft_first;
		std::vector<int> ft_first_copy(std_first);

		REQUIRE(std_first_copy.size() == std_first.size());
		REQUIRE(std_first_copy.capacity() == std_first.capacity());
		REQUIRE(ft_first_copy.size() == ft_first.size());
		REQUIRE(ft_first_copy.capacity() == ft_first.capacity());
		REQUIRE(ft_first_copy.size() == std_first_copy.size());
		REQUIRE(ft_first_copy.capacity() == std_first_copy.capacity());
	}
	SECTION("vector with size") {
		std::vector<int> std_first(10);
		std::vector<int> std_first_copy(std_first);

		REQUIRE(std_first_copy.size() == std_first.size());
		REQUIRE(std_first_copy.capacity() == std_first.capacity());
	}
	SECTION("vector with value") {
		std::vector<int> std_first(10, 900);
		std::vector<int> std_first_copy(std_first);

		REQUIRE(std_first_copy.size() == std_first.size());
		REQUIRE(std_first_copy.capacity() == std_first.capacity());
	}

}

TEST_CASE("copy & assignation operator: with value", "vector"){

	unsigned long int size = 10;
	std::vector<int> std_second(size, 10);
	std::vector<int> std_third = std_second;
	std_second[0] = 100;
	REQUIRE(std_third[0] == 10);

	SECTION("testing resize"){
		std_second.resize(88);
		REQUIRE(std_third.size() == 10);
		REQUIRE(std_second.size() == 88);
		REQUIRE(std_third.capacity() == 10);
		REQUIRE(std_second.capacity() == 88);
	}
}

TEST_CASE("test constructor with an array", "vector"){
	std::string arr[] = {"first", "second", "third", "fourth"};

	std::vector<std::string> vecOfStr1(arr, arr+sizeof(arr)/sizeof(std::string));
//	ft::vector<std::string> vecOfStr2(arr, arr+sizeof(arr)/sizeof(std::string));
	REQUIRE(vecOfStr1.size() == 4);
	REQUIRE(vecOfStr1[0] == "first");
	REQUIRE(vecOfStr1[1] == "second");
	REQUIRE(vecOfStr1[2] == "third");
	REQUIRE(vecOfStr1[3] == "fourth");
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