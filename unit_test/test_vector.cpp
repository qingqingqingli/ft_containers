//
// Created by qli on 25/02/2021.
//
#include "catch2/catch.hpp"
#include "../containers/vector.h"

TEST_CASE("0. copy & assignation constructor", "[vector][coplien form]")
{

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

//****************** iterator **************

TEST_CASE("1. begin() ", "[vector][iterator]")
{
	std::vector<int> std_myvector;
	for (int i=1; i<=5; i++) std_myvector.push_back(i);

	ft::vector<int> ft_myvector;
	for (int i=1; i<=5; i++) ft_myvector.push_back(i);

	ft::vector<int> const vector(2, 3);

	SECTION("non-const") {
		std::vector<int>::iterator std_begin = std_myvector.begin();
		ft::vector<int>::iterator ft_begin = ft_myvector.begin();
		REQUIRE(*std_begin == *ft_begin);
		REQUIRE(*(std_begin + 1) == *(ft_begin + 1));
		REQUIRE(*(std_begin + 2) == *(ft_begin + 2));
		REQUIRE(*(std_begin + 3) == *(ft_begin + 3));
		REQUIRE(*(std_begin + 4) == *(ft_begin + 4));
	}

	SECTION("const") {
		std::vector<int>::const_iterator std_begin_const = std_myvector.begin();
		ft::vector<int>::const_iterator ft_begin_const = ft_myvector.begin();
		REQUIRE(*std_begin_const == *ft_begin_const);
	}
}

TEST_CASE("1. end() ", "[vector][iterator]")
{
	std::vector<int> std_myvector;
	for (int i=1; i<=5; i++) std_myvector.push_back(i);

	ft::vector<int> ft_myvector;
	for (int i=1; i<=5; i++) ft_myvector.push_back(i);

	SECTION("non-const") {
		std::vector<int>::iterator std_end = std_myvector.end();
		ft::vector<int>::iterator ft_end = ft_myvector.end();
		REQUIRE(*(std_end - 1) == *(ft_end - 1));
		REQUIRE(*(std_end - 2) == *(ft_end - 2));
		REQUIRE(*(std_end - 3) == *(ft_end - 3));
		REQUIRE(*(std_end - 4) == *(ft_end - 4));
	}

	SECTION("const") {
		std::vector<int>::const_iterator std_end_const = std_myvector.end();
		ft::vector<int>::const_iterator ft_end_const = ft_myvector.end();
		REQUIRE(*(std_end_const - 1) == *(ft_end_const - 1));
		REQUIRE(*(std_end_const - 2) == *(ft_end_const - 2));
		REQUIRE(*(std_end_const - 3) == *(ft_end_const - 3));
		REQUIRE(*(std_end_const - 4) == *(ft_end_const - 4));
	}
}

TEST_CASE("1. rbegin() ", "[vector][iterator]")
{
	std::vector<int> std_myvector;
	for (int i=1; i<=5; i++) std_myvector.push_back(i);

	ft::vector<int> ft_myvector;
	for (int i=1; i<=5; i++) ft_myvector.push_back(i);

	SECTION("non-const") {
		std::vector<int>::reverse_iterator std_begin = std_myvector.rbegin();
		ft::vector<int>::reverse_iterator ft_begin = ft_myvector.rbegin();
		REQUIRE(*std_begin == *ft_begin);
		REQUIRE(*(std_begin + 1) == *(ft_begin + 1));
		REQUIRE(*(std_begin + 2) == *(ft_begin + 2));
		REQUIRE(*(std_begin + 3) == *(ft_begin + 3));
		REQUIRE(*(std_begin + 4) == *(ft_begin + 4));
	}

	SECTION("const") {
		std::vector<int>::const_reverse_iterator std_begin_const = std_myvector.rbegin();
		ft::vector<int>::const_reverse_iterator ft_begin_const = ft_myvector.rbegin();
		REQUIRE(*std_begin_const == *ft_begin_const);
		REQUIRE(*(std_begin_const + 1) == *(ft_begin_const + 1));
		REQUIRE(*(std_begin_const + 2) == *(ft_begin_const + 2));
		REQUIRE(*(std_begin_const + 3) == *(ft_begin_const + 3));
		REQUIRE(*(std_begin_const + 4) == *(ft_begin_const + 4));
	}
}

TEST_CASE("1. rend() ", "[vector][iterator]")
{
	std::vector<int> std_myvector;
	for (int i=1; i<=5; i++) std_myvector.push_back(i);

	ft::vector<int> ft_myvector;
	for (int i=1; i<=5; i++) ft_myvector.push_back(i);

	SECTION("non-const") {
		std::vector<int>::reverse_iterator std_end = std_myvector.rend();
		ft::vector<int>::reverse_iterator ft_end = ft_myvector.rend();
		REQUIRE(*(std_end - 1) == *(ft_end - 1));
		REQUIRE(*(std_end - 2) == *(ft_end - 2));
		REQUIRE(*(std_end - 3) == *(ft_end - 3));
		REQUIRE(*(std_end - 4) == *(ft_end - 4));
	}

	SECTION("const") {
		std::vector<int>::const_reverse_iterator std_end_const = std_myvector.rend();
		ft::vector<int>::const_reverse_iterator ft_end_const = ft_myvector.rend();
		REQUIRE(*(std_end_const - 1) == *(ft_end_const - 1));
		REQUIRE(*(std_end_const - 2) == *(ft_end_const - 2));
		REQUIRE(*(std_end_const - 3) == *(ft_end_const - 3));
		REQUIRE(*(std_end_const - 4) == *(ft_end_const - 4));

	}
}

//****************** capacity **************

TEST_CASE("2. size()", "[vector][capacity]")
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

TEST_CASE("2. max_size()", "[vector][capacity]")
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

TEST_CASE("2. resize()", "[vector][capacity]")
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
}

TEST_CASE("2. capacity()", "[vector][capacity]")
{
	std::vector<int> myvector(1, 100);
	ft::vector<int> ft_myvector(1, 100);

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

	SECTION("resize & capacity") {
		myvector.push_back(22);
		ft_myvector.push_back(22);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(2, 300);
		ft_myvector.resize(2, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(3, 300);
		ft_myvector.resize(3, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(4, 300);
		ft_myvector.resize(4, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(5, 300);
		ft_myvector.resize(5, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(6, 300);
		ft_myvector.resize(6, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(10, 300);
		ft_myvector.resize(10, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(15, 300);
		ft_myvector.resize(15, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(29, 300);
		ft_myvector.resize(29, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(50, 300);
		ft_myvector.resize(50, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(100, 300);
		ft_myvector.resize(100, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(199, 300);
		ft_myvector.resize(199, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.resize(400, 300);
		ft_myvector.resize(400, 300);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		myvector.push_back(22);
		ft_myvector.push_back(22);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());
	}
}

TEST_CASE("2. empty()", "[vector][capacity]")
{
	std::vector<int> first(0);
	std::vector<int> second;
	ft::vector<int> ft_first(0);
	ft::vector<int> ft_second;
	REQUIRE(first.empty() == ft_first.empty());
	REQUIRE(second.empty() == ft_second.empty());
}

TEST_CASE("2. reserve()", "[vector][capacity]")
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

//****************** element access **************

TEST_CASE("3. operator[]", "[vector][element access]")
{
	std::vector<int> std_vec;
	std_vec.push_back(1);
	std_vec.push_back(2);
	std_vec.push_back(3);
	std_vec.push_back(4);
	std_vec.push_back(5);

	ft::vector<int> ft_vec;
	ft_vec.push_back(1);
	ft_vec.push_back(2);
	ft_vec.push_back(3);
	ft_vec.push_back(4);
	ft_vec.push_back(5);

	REQUIRE(std_vec[0] == ft_vec[0]);
	REQUIRE(std_vec[1] == ft_vec[1]);
	REQUIRE(std_vec[2] == ft_vec[2]);
	REQUIRE(std_vec[3] == ft_vec[3]);
	REQUIRE(std_vec[4] == ft_vec[4]);

}

TEST_CASE("3. at()", "[vector][element access]")
{

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

TEST_CASE("3. front()", "[vector][element access]")
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

TEST_CASE("3. back()", "[vector][element access]")
{
	std::vector<int> first(10);
	std::vector<int> second(10, 30);
	ft::vector<int> ft_first(10);
	ft::vector<int> ft_second(10, 30);
	REQUIRE(first.back() == ft_first.back());
	REQUIRE(second.back() == ft_second.back());
}

//****************** modifier **************

TEST_CASE("4. assign()", "[vector][modifier]")
{
	SECTION("range")
	{
		std::vector<int> std_fill;
		for (int i=1; i<=5; i++) std_fill.push_back(i);
		std::vector<int> std_range;
		std_range.assign(std_fill.begin(), std_fill.end());

		ft::vector<int> ft_fill;
		for (int i=1; i<=5; i++) ft_fill.push_back(i);
		ft::vector<int> ft_range;
		ft_range.assign(ft_fill.begin(), ft_fill.end());

		for (unsigned i=0; i < std_fill.size(); i++)
			REQUIRE(std_fill[i] == ft_fill[i]);

		REQUIRE(ft_fill.size() == std_fill.size());
		REQUIRE(ft_fill.capacity() == std_fill.capacity());

		std_fill.assign(500, -888);
		std_range.assign(std_fill.begin(), std_fill.end());

		ft_fill.assign(500, -888);
		ft_range.assign(ft_fill.begin(), ft_fill.end());

		REQUIRE(ft_fill.size() == std_fill.size());
		REQUIRE(ft_fill.capacity() == std_fill.capacity());
	}

	SECTION("fill")
	{
		std::vector<int> first;
		first.assign (7,100);
		std::vector<int> second(39, 200);
		second.assign (777,100);

		ft::vector<int> ft_first;
		ft_first.assign (7,100);
		ft::vector<int> ft_second(39, 200);
		ft_second.assign (777,100);

		for (unsigned i=0; i<first.size(); i++)
		{
			REQUIRE(first[i] == ft_first[i]);
			REQUIRE(second[i] == ft_second[i]);
		}

		REQUIRE(ft_first.size() == first.size());
		REQUIRE(ft_first.capacity() == first.capacity());
		REQUIRE(ft_second.size() == second.size());
		REQUIRE(ft_second.capacity() == second.capacity());
	}

}

TEST_CASE("4. push_back()", "[vector][modifier]")
{
	std::vector<int> myvector;
	ft::vector<int> ft_myvector;
	for (int i = 0; i < 200; i++)
	{
		myvector.push_back(i);
		ft_myvector.push_back(i);
		REQUIRE(myvector[i] == ft_myvector[i]);
		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());
		REQUIRE(myvector.max_size() == ft_myvector.max_size());
	}
}

TEST_CASE("4. pop_back()", "[vector][modifier]")
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

TEST_CASE("4. insert()", "[vector][modifier]")
{

	SECTION("new test") {
		std::vector<int> vct(10);
		std::vector<int> vct2;

		ft::vector<int> ft_vct(10);
		ft::vector<int> ft_vct2;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = (vct.size() - i) * 3;

		for (unsigned long int i = 0; i < ft_vct.size(); ++i)
			ft_vct[i] = (ft_vct.size() - i) * 3;

		REQUIRE(vct.size() == ft_vct.size());
		REQUIRE(vct.capacity() == ft_vct.capacity());

		ft::vector<int>::iterator end = ft_vct2.end();

		vct2.insert(vct2.end(), 42);
		vct2.insert(vct2.begin(), 2, 21);
		ft_vct2.insert(ft_vct2.end(), 42);
		ft_vct2.insert(ft_vct2.begin(), 2, 21);

		REQUIRE(vct.size() == ft_vct.size());
		REQUIRE(vct.capacity() == ft_vct.capacity());
		REQUIRE(vct2.size() == ft_vct2.size());
		REQUIRE(vct2.capacity() == ft_vct2.capacity());

		vct2.insert(vct2.end() - 2, 42);
		ft_vct2.insert(ft_vct2.end() - 2, 42);
		REQUIRE(vct.size() == ft_vct.size());
		REQUIRE(vct.capacity() == ft_vct.capacity());
		REQUIRE(vct2.size() == ft_vct2.size());
		REQUIRE(vct2.capacity() == ft_vct2.capacity());

		vct2.insert(vct2.end(), 2, 84);
		ft_vct2.insert(ft_vct2.end(), 2, 84);
		REQUIRE(vct.size() == ft_vct.size());
		REQUIRE(vct.capacity() == ft_vct.capacity());
		REQUIRE(vct2.size() == ft_vct2.size());
		REQUIRE(vct2.capacity() == ft_vct2.capacity());

		vct2.resize(4);
		ft_vct2.resize(4);
		REQUIRE(vct.size() == ft_vct.size());
		REQUIRE(vct.capacity() == ft_vct.capacity());
		REQUIRE(vct2.size() == ft_vct2.size());
		REQUIRE(vct2.capacity() == ft_vct2.capacity());

		vct2.insert(vct2.begin() + 2, vct.begin(), vct.end());
		ft_vct2.insert(ft_vct2.begin() + 2, ft_vct.begin(), ft_vct.end());
		REQUIRE(vct.size() == ft_vct.size());
		REQUIRE(vct.capacity() == ft_vct.capacity());
		REQUIRE(vct2.size() == ft_vct2.size());
		REQUIRE(vct2.capacity() == ft_vct2.capacity());

		vct.clear();
		ft_vct.clear();
		REQUIRE(vct.size() == ft_vct.size());
		REQUIRE(vct.capacity() == ft_vct.capacity());
		REQUIRE(vct2.size() == ft_vct2.size());
		REQUIRE(vct2.capacity() == ft_vct2.capacity());
	}

	std::vector<int> std_myvector;
	for (int i=1; i<=5; i++) std_myvector.push_back(i);

	ft::vector<int> ft_myvector;
	for (int i=1; i<=5; i++) ft_myvector.push_back(i);

	std::vector<int>::iterator std_it = std_myvector.begin();
	ft::vector<int>::iterator ft_it = ft_myvector.begin();

	SECTION("single element")
	{
		std_it = std_myvector.insert ( std_it , 123 );
		ft_it = ft_myvector.insert ( ft_it , 123 );

		REQUIRE(*std_it == *ft_it);
		REQUIRE(*(std_it + 1) == *(ft_it + 1));
		REQUIRE(*(std_it + 2) == *(ft_it + 2));
		REQUIRE(*(std_it + 3) == *(ft_it + 3));

		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_it = std_myvector.begin();
		ft_it = ft_myvector.begin();

		std_it = std_myvector.insert ( std_it , -88 );
		ft_it = ft_myvector.insert ( ft_it , -88 );

		REQUIRE(*std_it == *ft_it);
		REQUIRE(*(std_it + 1) == *(ft_it + 1));
		REQUIRE(*(std_it + 2) == *(ft_it + 2));
		REQUIRE(*(std_it + 3) == *(ft_it + 3));

		std_it = std_myvector.insert ( std_it , 22 );
		ft_it = ft_myvector.insert ( ft_it , 22 );
		std_it = std_myvector.insert ( std_it , 678 );
		ft_it = ft_myvector.insert ( ft_it , 678 );
		std_it = std_myvector.insert ( std_it , 678 );
		ft_it = ft_myvector.insert ( ft_it , 678 );
		std_it = std_myvector.insert ( std_it , 56 );
		ft_it = ft_myvector.insert ( ft_it , 56 );
		std_it = std_myvector.insert ( std_it , 678 );
		ft_it = ft_myvector.insert ( ft_it , 678 );
		std_it = std_myvector.insert ( std_it , 678 );
		ft_it = ft_myvector.insert ( ft_it , 678 );

		REQUIRE(*std_it == *ft_it);
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());
	}

	SECTION("fill")
	{
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_myvector.insert ( std_it , 3, 123 );
		ft_myvector.insert ( ft_it , 3, 123 );

		std_it = std_myvector.begin();
		ft_it = ft_myvector.begin();

		REQUIRE(*std_it == *ft_it);
		REQUIRE(*(std_it + 1) == *(ft_it + 1));
		REQUIRE(*(std_it + 2) == *(ft_it + 2));
		REQUIRE(*(std_it + 3) == *(ft_it + 3));

		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_it = std_myvector.begin();
		ft_it = ft_myvector.begin();

		std_myvector.insert ( std_it , 2000, 123 );
		ft_myvector.insert ( ft_it , 2000, 123 );

		std_it = std_myvector.begin();
		ft_it = ft_myvector.begin();

		REQUIRE(*std_it == *ft_it);
		REQUIRE(*(std_it + 1) == *(ft_it + 1));
		REQUIRE(*(std_it + 2) == *(ft_it + 2));
		REQUIRE(*(std_it + 3) == *(ft_it + 3));

		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());
	}

	SECTION("range")
	{
		std::vector<int> std_base;
		std_base.push_back(1);
		std_base.push_back(2);
		std_base.push_back(3);
		std_base.push_back(4);
		std_base.push_back(5);
		std::vector<int>::iterator std_base_begin = std_base.begin();

		ft::vector<int> ft_base;
		ft_base.push_back(1);
		ft_base.push_back(2);
		ft_base.push_back(3);
		ft_base.push_back(4);
		ft_base.push_back(5);
		ft::vector<int>::iterator ft_base_begin = ft_base.begin();

		std_it = std_myvector.begin();
		ft_it = ft_myvector.begin();

		std_myvector.insert(std_it, std_base_begin, std_base_begin + 1);
		ft_myvector.insert(ft_it, ft_base_begin, ft_base_begin + 1);

		std_it = std_myvector.begin();
		ft_it = ft_myvector.begin();

		std_base_begin = std_base.begin();
		ft_base_begin = ft_base.begin();

		REQUIRE(*std_it == *ft_it);
		REQUIRE(*(std_it + 1) == *(ft_it + 1));
		REQUIRE(*(std_it + 2) == *(ft_it + 2));
		REQUIRE(*(std_it + 3) == *(ft_it + 3));
		REQUIRE(*(std_it + 4) == *(ft_it + 4));

		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_myvector.insert(std_it, std_base_begin, std_base_begin + 4);
		ft_myvector.insert(ft_it, ft_base_begin, ft_base_begin + 4);

		std_it = std_myvector.begin();
		ft_it = ft_myvector.begin();

		REQUIRE(*std_it == *ft_it);
		REQUIRE(*(std_it + 1) == *(ft_it + 1));
		REQUIRE(*(std_it + 2) == *(ft_it + 2));
		REQUIRE(*(std_it + 3) == *(ft_it + 3));
		REQUIRE(*(std_it + 4) == *(ft_it + 4));

		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_myvector.resize(10, 89);
		ft_myvector.resize(10, 89);
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_myvector.resize(11, 89);
		ft_myvector.resize(11, 89);
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_myvector.resize(12, 89);
		ft_myvector.resize(12, 89);
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_myvector.resize(13, 89);
		ft_myvector.resize(13, 89);
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_myvector.resize(13, 89);
		ft_myvector.resize(13, 89);
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_myvector.resize(25, 89);
		ft_myvector.resize(25, 89);
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());
	}
}

TEST_CASE("4. erase()", "[vector][modifier]")
{
	std::vector<int> std_myvector;
	for (int i=1; i<=10; i++) std_myvector.push_back(i);

	ft::vector<int> ft_myvector;
	for (int i=1; i<=10; i++) ft_myvector.push_back(i);

	std::vector<int>::iterator std_it = std_myvector.begin();
	ft::vector<int>::iterator ft_it = ft_myvector.begin();

	SECTION("single") {
		std_it = std_myvector.erase (std_myvector.begin()+3);
		ft_it = ft_myvector.erase (ft_myvector.begin()+3);

		while (std_it != std_myvector.end())
		{
			REQUIRE(*std_it == *ft_it);
			std_it++;
			ft_it++;
		}

		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_it = std_myvector.erase (std_myvector.begin() + 2);
		ft_it = ft_myvector.erase (ft_myvector.begin() + 2);

		while (std_it != std_myvector.end())
		{
			REQUIRE(*std_it == *ft_it);
			std_it++;
			ft_it++;
		}

		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());
	}

	SECTION("range") {
		std_it = std_myvector.erase (std_myvector.begin(), std_myvector.begin()+3);
		ft_it = ft_myvector.erase (ft_myvector.begin(), ft_myvector.begin()+3);

		while (std_it != std_myvector.end())
		{
			REQUIRE(*std_it == *ft_it);
			std_it++;
			ft_it++;
		}
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());

		std_it = std_myvector.erase (std_myvector.begin() + 2, std_myvector.begin()+3);
		ft_it = ft_myvector.erase (ft_myvector.begin() + 2, ft_myvector.begin()+3);

		while (std_it != std_myvector.end())
		{
			REQUIRE(*std_it == *ft_it);
			std_it++;
			ft_it++;
		}
		REQUIRE(std_myvector.size() == ft_myvector.size());
		REQUIRE(std_myvector.capacity() == ft_myvector.capacity());
	}

}

TEST_CASE("4. swap()", "[vector][modifier]")
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

TEST_CASE("4. clearTree()", "[vector][modifier]")
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

//****************** allocator **************

TEST_CASE("5. get_allocator()", "[vector][allocator]")
{
	ft::vector<int> ft_myvector(5, 10);
	std::vector<int> myvector(5, 10);

	REQUIRE(ft_myvector.get_allocator() == myvector.get_allocator());
}

//****************** relational operators **************

TEST_CASE("6. relational operators", "[vector][relational]")
{
	ft::vector<int> ft_foo (2,200);
	ft::vector<int> ft_foo_2 (2,200);
	ft::vector<int> ft_bar (300,200);

	SECTION("a == b")
	{
		REQUIRE((ft_foo == ft_foo_2) == true);
		REQUIRE((ft_foo == ft_foo) == true);
		REQUIRE((ft_bar == ft_bar) == true);
	}

	SECTION("a != b")
	{
		REQUIRE((ft_foo != ft_bar) == true);
		REQUIRE((ft_bar != ft_foo) == true);
	}

	SECTION("a < b && a <= b")
	{
		REQUIRE((ft_foo < ft_bar) == true);
		REQUIRE((ft_foo <= ft_bar) == true);
	}

	SECTION("a > b && a >= b")
	{
		REQUIRE((ft_bar > ft_foo) == true);
		REQUIRE((ft_bar >= ft_foo) == true);
	}
}

//****************** swap **************

TEST_CASE("7. non-member function swap()", "[vector][swap]")
{
	std::vector<int> std_foo (3,-100);
	std::vector<int> std_bar (5,200);
	std_foo.swap(std_bar);
	std::vector<int>::iterator std_it_foo = std_foo.begin();
	std::vector<int>::iterator std_it_bar = std_bar.begin();

	ft::vector<int> ft_foo (3,-100);
	ft::vector<int> ft_bar (5,200);
	ft_foo.swap(ft_bar);
	ft::vector<int>::iterator ft_it_foo = ft_foo.begin();
	ft::vector<int>::iterator ft_it_bar = ft_bar.begin();

	while(std_it_foo != std_foo.end())
	{
		REQUIRE(*std_it_foo == *ft_it_foo);
		std_it_foo++;
		ft_it_foo++;
	}

	while(std_it_bar != std_bar.end())
	{
		REQUIRE(*std_it_bar == *ft_it_bar);
		std_it_bar++;
		ft_it_bar++;
	}

	REQUIRE(std_foo.size() == ft_foo.size());
	REQUIRE(std_foo.capacity() == ft_foo.capacity());
	REQUIRE(std_bar.size() == ft_bar.size());
	REQUIRE(std_bar.capacity() == ft_bar.capacity());
}