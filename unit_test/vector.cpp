//
// Created by qli on 25/02/2021.
//
#include "catch2/catch.hpp"
#include "../containers/vector.h"
#include <fstream>

TEST_CASE("default constructor: empty vector", "[vector][coplien form]") {
	std::vector<char> std_first;
	ft::vector<int> ft_first;

	REQUIRE(ft_first.size() == std_first.size());
	REQUIRE(ft_first.capacity() == std_first.capacity());
}

TEST_CASE("default constructor: vector with size and val", "[vector][coplien form]") {
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

TEST_CASE("default constructor: vector with InputIterator", "[vector][coplien form]") {

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

TEST_CASE("copy & assignation constructor", "[vector][coplien form]"){

	SECTION("empty vector") {
		std::vector<int> std_first;
		std::vector<int> std_first_copy(std_first);
		ft::vector<int> ft_first;
		ft::vector<int> ft_first_copy(ft_first);

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
		ft::vector<int> ft_first(10);
		ft::vector<int> ft_first_copy(ft_first);

		REQUIRE(std_first_copy.size() == std_first.size());
		REQUIRE(std_first_copy.capacity() == std_first.capacity());
		REQUIRE(ft_first_copy.size() == ft_first.size());
		REQUIRE(ft_first_copy.capacity() == ft_first.capacity());
		REQUIRE(ft_first_copy.size() == std_first_copy.size());
		REQUIRE(ft_first_copy.capacity() == std_first_copy.capacity());
	}
	SECTION("vector with value") {
		std::vector<int> std_first(10, 900);
		std::vector<int> std_first_copy(std_first);
		ft::vector<int> ft_first(10, 900);
		ft::vector<int> ft_first_copy(ft_first);

		REQUIRE(std_first_copy.size() == std_first.size());
		REQUIRE(std_first_copy.capacity() == std_first.capacity());
		REQUIRE(ft_first_copy.size() == ft_first.size());
		REQUIRE(ft_first_copy.capacity() == ft_first.capacity());
		REQUIRE(ft_first_copy.size() == std_first_copy.size());
		REQUIRE(ft_first_copy.capacity() == std_first_copy.capacity());
	}

	SECTION("update vector with value") {
		std::vector<int> std_first(10, 900);
		std::vector<int> std_first_copy(std_first);
		std_first_copy[1] = 777;
		std_first_copy[8] = 99;

		ft::vector<int> ft_first(10, 900);
		ft::vector<int> ft_first_copy(ft_first);
		ft::vector<int> ft_second_copy = ft_first_copy;

		ft_first_copy[1] = 777;
		ft_first_copy[8] = 99;
		ft_second_copy[7] = 88;

		REQUIRE(std_first_copy[1] == ft_first_copy[1]);
		REQUIRE(std_first_copy[8] == ft_first_copy[8]);
		REQUIRE(ft_first[1] == 900);
		REQUIRE(ft_first[8] == 900);
		REQUIRE(ft_second_copy.size() == ft_first_copy.size());
		REQUIRE(ft_second_copy.capacity() == ft_first_copy.capacity());
		REQUIRE(ft_second_copy[7] != ft_first_copy[7]);
	}
}

TEST_CASE("size()", "[vector][capacity]")
{
	std::vector<int> empty;
	ft::vector<int> ft_empty;
	std::vector<int> small(5);
	ft::vector<int> ft_small(5);
	std::vector<int> big(555, 555);
	ft::vector<int> ft_big(555, 555);

	REQUIRE(ft_empty.size() == empty.size());
	REQUIRE(ft_small.size() == small.size());
	REQUIRE(ft_big.size() == big.size());
}

TEST_CASE("max_size()", "[vector][capacity]")
{
	std::vector<int> empty;
	ft::vector<int> ft_empty;
	std::vector<int> small(5);
	ft::vector<int> ft_small(5);
	std::vector<int> big(555, 555);
	ft::vector<int> ft_big(555, 555);

	REQUIRE(ft_empty.max_size() == empty.max_size());
	REQUIRE(ft_small.max_size() == small.max_size());
	REQUIRE(ft_big.max_size() == big.max_size());
}

TEST_CASE("assign()", "[vector][element access]")
{
	SECTION("assign value to empty vector")
	{
		std::vector<int> first;

		first.assign(5, 100);
		REQUIRE(first.size() == 5);
		REQUIRE(first.capacity() == 5);
		REQUIRE(first[0] == 100);
	}
	SECTION("assign value to bigger vector")
	{
		std::vector<int> second(25);

		REQUIRE(second.size() == 25);
		REQUIRE(second.capacity() == 25);
		second.assign(5, 100);
		// size changed
		REQUIRE(second.size() == 5);
		REQUIRE(second.capacity() == 25);
		REQUIRE(second[0] == 100);
		REQUIRE(second[5] == 0);
		REQUIRE(second[6] == 0);
	}
	SECTION("assign value to bigger vector")
	{
		std::vector<int> second(3);

		REQUIRE(second.size() == 3);
		REQUIRE(second.capacity() == 3);
		second.assign(5, 100);
		// size changed
		REQUIRE(second.size() == 5);
		REQUIRE(second.capacity() == 5);
		REQUIRE(second[0] == 100);
		REQUIRE(second[1] == 100);
		REQUIRE(second[2] == 100);
		REQUIRE(second[3] == 100);
	}
}

TEST_CASE("8. at()", "[vector]"){

	SECTION("non-const type")
	{
		int num = 10;
		std::vector<int> myvector (num);
		ft::vector<int> ft_myvector (num);

		for (unsigned i=0; i<myvector.size(); i++)
		{
			myvector.at(i) = i;
			ft_myvector.at(i) = i;
		}
		for (unsigned i=0; i<ft_myvector.size(); i++)
		{
			REQUIRE(ft_myvector.at(i) == myvector.at(i));
			REQUIRE(ft_myvector.at(i) == ft_myvector[i]);
		}
		// -> same exception message
		//	ft_myvector.at(16);
		//	myvector.at(16);
	}
	SECTION("const type")
	{
		int num = 10;
		int val = 20;
		const std::vector<int> const_vec(num, val);
		const ft::vector<int> ft_const_vec(num, val);
		for (unsigned i = 0; i < ft_const_vec.size(); i++)
		{
			REQUIRE(ft_const_vec.at(i) == const_vec.at(i));
			REQUIRE(ft_const_vec.at(i) == ft_const_vec[i]);
		}
	}
}

TEST_CASE("back()", "[vector]")
{
	std::vector<int> first(10);
	std::vector<int> second(10, 30);
	ft::vector<int> ft_first(10);
	ft::vector<int> ft_second(10, 30);
	REQUIRE(first.back() == ft_first.back());
	REQUIRE(second.back() == ft_second.back());
}

TEST_CASE("empty()", "[vector][capacity]")
{
	std::vector<int> first(0);
	std::vector<int> second;
	ft::vector<int> ft_first(0);
	ft::vector<int> ft_second;
	REQUIRE(first.empty() == ft_first.empty());
	REQUIRE(second.empty() == ft_second.empty());
}
