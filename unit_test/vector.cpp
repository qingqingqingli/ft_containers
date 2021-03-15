//
// Created by qli on 25/02/2021.
//
#include "catch2/catch.hpp"
#include "../containers/vector.h"

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

//TEST_CASE("default constructor: vector with InputIterator", "[vector][coplien form]") {
//
//	std::vector<int> std_first(4, 100);
//	std::vector<int> std_second(std_first.begin(), std_first.end());
//
//	ft::vector<int> ft_first(4, 100);
//	ft::vector<int> ft_second(std_first.begin(), std_first.end());
//
//	for (unsigned i = 0; i < std_second.size(); i++)
//		REQUIRE(ft_first[i] == ft_second[i]);
//
//}

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

TEST_CASE("resize()", "[vector][capacity]")
{
	std::vector<int> first(5, 100);
	std::vector<char> second(5, 'a');
	ft::vector<int> ft_first(5, 100);
	ft::vector<char> ft_second(5, 'a');

	SECTION("int vector")
	{
		first.resize(10);
		ft_first.resize(10);
		REQUIRE(first.size() == ft_first.size());
		REQUIRE(first[9] == ft_first[9]);
		REQUIRE(first.capacity() == ft_first.capacity());

		for (size_t i=0;i<first.size();i++)
			REQUIRE(first[i] == ft_first[i]);

		first.resize(21, 456);
		ft_first.resize(21, 456);
		REQUIRE(first[4] == ft_first[4]);
		REQUIRE(first.size() == 21);
		REQUIRE(first.capacity() == 21);

		first.resize(47, 456);
		ft_first.resize(47, 456);
		REQUIRE(first[4] == ft_first[4]);
		REQUIRE(first.size() == 47);
		REQUIRE(first.capacity() == 47);

		for (size_t i=0;i<first.size();i++)
			REQUIRE(first[i] == ft_first[i]);

		first.resize(12);
		ft_first.resize(12);
		REQUIRE(first[11] == ft_first[11]);
		REQUIRE(first.size() == ft_first.size());
		REQUIRE(first.capacity() == ft_first.capacity());
		for (size_t i=0;i<first.size();i++)
			REQUIRE(first[i] == ft_first[i]);
	}

	SECTION("char_vector")
	{
		second.resize(10);
		ft_second.resize(10);
		REQUIRE(second.size() == ft_second.size());
		REQUIRE(second[9] == ft_second[9]);
		REQUIRE(second.capacity() == ft_second.capacity());

		for (size_t i=0;i<second.size();i++)
			REQUIRE(second[i] == ft_second[i]);

		second.resize(17, 'c');
		ft_second.resize(17, 'c');
		REQUIRE(second[4] == ft_second[4]);
		REQUIRE(second.size() == ft_second.size());
		REQUIRE(second.capacity() == ft_second.capacity());

		for (size_t i=0;i<second.size();i++)
			REQUIRE(second[i] == ft_second[i]);

		second.resize(12);
		ft_second.resize(12);
		REQUIRE(second[11] == ft_second[11]);
		REQUIRE(second.size() == ft_second.size());
		REQUIRE(second.capacity() == ft_second.capacity());
		for (size_t i=0;i<second.size();i++)
			REQUIRE(second[i] == ft_second[i]);
	}

//	100 100 100 100 100 0 0 0 0 0
//	100 100 100 100 100 0 0 0 0 0 456 456 456 456 456 456 456
//	100 100 100 100 100 0 0 0 0 0 456 456
//	a a a a a \x00 \x00 \x00 \x00 \x00
//	a a a a a \x00 \x00 \x00 \x00 \x00 c c c c c c c
//	a a a a a \x00 \x00 \x00 \x00 \x00 c c
}

TEST_CASE("capacity()", "[vector][capacity]") {
	std::vector<int> myvector(100, 100);
	ft::vector<int> ft_myvector(100, 100);

	REQUIRE(myvector.size() == ft_myvector.size());
	REQUIRE(myvector.capacity() == ft_myvector.capacity());
	REQUIRE(myvector.max_size() == ft_myvector.max_size());

	myvector.resize(345);
	ft_myvector.resize(345);
	REQUIRE(myvector.size() == ft_myvector.size());
	REQUIRE(myvector.capacity() == ft_myvector.capacity());
	REQUIRE(myvector.max_size() == ft_myvector.max_size());

	myvector.resize(10);
	ft_myvector.resize(10);
	REQUIRE(myvector.size() == ft_myvector.size());
	REQUIRE(myvector.capacity() == ft_myvector.capacity());
	REQUIRE(myvector.max_size() == ft_myvector.max_size());

	myvector.resize(0);
	ft_myvector.resize(0);
	REQUIRE(myvector.size() == ft_myvector.size());
	REQUIRE(myvector.capacity() == ft_myvector.capacity());
	REQUIRE(myvector.max_size() == ft_myvector.max_size());
}

TEST_CASE("reserve()", "[vector][capacity]")
{
	std::vector<int> foo;
	ft::vector<int> ft_foo;
	for (int i=0; i<100; ++i) {
		foo.push_back(i);
		ft_foo.push_back(i);
		REQUIRE(foo.capacity() == ft_foo.capacity());
	}

	std::vector<int> bar;
	ft::vector<int> ft_bar;
	bar.reserve(100);
	ft_bar.reserve(100);
	for (int i=0; i<100; ++i) {
		bar.push_back(i);
		ft_bar.push_back(i);
		REQUIRE(bar.capacity() == ft_bar.capacity());
	}
}

TEST_CASE("at()", "[vector][element access]"){

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

TEST_CASE("front()", "[vector][element access]")
{
	std::vector<int> first(10);
	std::vector<int> second(10, 30);
	ft::vector<int> ft_first(10);
	ft::vector<int> ft_second(10, 30);
	REQUIRE(first.front() == ft_first.front());
	REQUIRE(second.front() == ft_second.front());

	std::vector<int> myvector;
	ft::vector<int> ft_myvector;

	myvector.push_back(78);
	myvector.push_back(16);
	ft_myvector.push_back(78);
	ft_myvector.push_back(16);

	myvector.front() -= myvector.back();
	ft_myvector.front() -= ft_myvector.back();

	REQUIRE(myvector.front() == ft_myvector.front());
}

TEST_CASE("back()", "[vector][element access]")
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

TEST_CASE("assign()", "[vector][modifier]")
{
	std::vector<int> first;
	std::vector<int> second(39, 200);
	first.assign (7,100);
	second.assign (7,100);

	ft::vector<int> ft_first;
	ft::vector<int> ft_second(39, 200);
	ft_first.assign (7,100);
	ft_second.assign (7,100);

	for (unsigned i=0; i<first.size(); i++)
	{
		REQUIRE(first[i] == ft_first[i]);
		REQUIRE(second[i] == ft_second[i]);
	}
}

TEST_CASE("push_back()", "[vector][modifier]")
{
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;
	for (unsigned i = 0; i < 200; i++)
	{
		myvector.push_back(i);
		ft_myvector.push_back(i);
		REQUIRE(myvector[i] == ft_myvector[i]);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());
		REQUIRE(myvector.max_size() == ft_myvector.max_size());
	}
}

TEST_CASE("pop_back()", "[vector][modifier]")
{
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;
	int sum = 0;
	int ft_sum = 0;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	ft_myvector.push_back (100);
	ft_myvector.push_back (200);
	ft_myvector.push_back (300);

	while (!myvector.empty())
	{
		sum+=myvector.back();
		ft_sum+=ft_myvector.back();
		myvector.pop_back();
		ft_myvector.pop_back();
		REQUIRE(sum == ft_sum);
	}
}

TEST_CASE("clear()", "[vector][modifier]")
{
	std::vector<int> myvector;
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	myvector.clear();
	myvector.push_back (1101);
	myvector.push_back (2202);

	ft::vector<int> ft_myvector;
	ft_myvector.push_back (100);
	ft_myvector.push_back (200);
	ft_myvector.push_back (300);

	ft_myvector.clear();
	ft_myvector.push_back (1101);
	ft_myvector.push_back (2202);

	for (unsigned i=0; i<myvector.size(); i++)
	{
		REQUIRE(myvector[i] == ft_myvector[i]);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());
	}
}

TEST_CASE("swap()", "[vector][modifier]")
{
	std::vector<int> foo (3,100);
	std::vector<int> bar (5,200);
	ft::vector<int> ft_foo (3,100);
	ft::vector<int> ft_bar (5,200);

	foo.swap(bar);
	ft_foo.swap(ft_bar);

	for (unsigned i=0; i<foo.size(); i++)
		REQUIRE(foo[i] == ft_foo[i]);

	for (unsigned i=0; i<bar.size(); i++)
		REQUIRE(bar[i] == ft_bar[i]);
}
