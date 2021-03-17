//
// Created by qli on 15/03/2021.
//

#include "catch2/catch.hpp"
#include "../containers/vector.h"

TEST_CASE("coplien form", "[vector][iterator]")
{
	ft::vector<int> first(5, 100);
	ft::vector<int>::iterator itr = first.begin();
	ft::vector<int>::iterator itr_copy = itr;
	REQUIRE(itr == itr_copy);
	REQUIRE(*itr == *itr_copy);
	while (itr != first.end())
	{
		REQUIRE(*itr == 100);
		itr++;
	}
}

TEST_CASE("iterator a==b; a!= b", "[vector][iterator]")
{
	ft::vector<int> first(5, 100);
	ft::vector<int>::iterator itr = first.begin();
	ft::vector<int>::iterator itr_copy = itr;
	REQUIRE(itr == itr_copy);
	REQUIRE(*itr == *itr_copy);
	ft::vector<int>::iterator itr_copy_2 = first.end();
	REQUIRE(itr != itr_copy_2);
}

TEST_CASE("*a", "[vector][iterator]")
{
	ft::vector<int> first(5, 100);
	std::vector<int> std_first(5, 100);

	std::vector<int>::iterator std_itr = std_first.begin();
	for (ft::vector<int>::iterator itr = first.begin(); itr != first.end(); itr++)
	{
		REQUIRE(*itr == *std_itr);
		std_itr++;
	}
}

TEST_CASE("++a; a++; *a++;", "[vector][iterator]")
{
	ft::vector<int> first(5, 100);
	std::vector<int> std_first(5, 100);
	std::vector<int>::iterator std_itr = std_first.begin();
	ft::vector<int>::iterator itr = first.begin();

	SECTION("++a") {
		++std_itr;
		++itr;
		while (itr != first.end())
		{
			REQUIRE(*itr == *std_itr);
			++std_itr;
			++itr;
		}
	}

	SECTION("a++") {
		std_itr++;
		itr++;
		while (itr != first.end())
		{
			REQUIRE(*itr == *std_itr);
			std_itr++;
			itr++;
		}
	}

	SECTION("*a++") {
		std::vector<int> second;
		second.push_back(1);
		second.push_back(2);
		second.push_back(3);
		second.push_back(4);
		std::vector<int>::iterator second_itr = second.begin();
		*second_itr++;


		ft::vector<int> ft_second;
		ft_second.push_back(1);
		ft_second.push_back(2);
		ft_second.push_back(3);
		ft_second.push_back(4);

		ft::vector<int>::iterator ft_second_itr = ft_second.begin();
		*ft_second_itr++;

		while (ft_second_itr != ft_second.end())
		{
			REQUIRE(*ft_second_itr == *second_itr);
			REQUIRE(*second_itr++ == *ft_second_itr++);
		}
	}

}

TEST_CASE("--a; a--; *a--;", "[vector][iterator]")
{
	ft::vector<int> first(5, 100);
	std::vector<int> std_first(5, 100);
	std::vector<int>::iterator std_itr = std_first.end() - 1;
	ft::vector<int>::iterator itr = first.end() - 1;

	SECTION("--a") {
		--std_itr;
		--itr;
		while (itr != first.begin())
		{
			REQUIRE(*itr == *std_itr);
			--std_itr;
			--itr;
		}
	}

	SECTION("a--") {
		std_itr--;
		itr--;
		while (itr != first.begin())
		{
			REQUIRE(*itr == *std_itr);
			std_itr--;
			itr--;
		}
	}

	SECTION("*a--") {
		std::vector<int> second;
		second.push_back(1);
		second.push_back(2);
		second.push_back(3);
		second.push_back(4);
		std::vector<int>::iterator second_itr = second.end() - 1;
		*second_itr--;


		ft::vector<int> ft_second;
		ft_second.push_back(1);
		ft_second.push_back(2);
		ft_second.push_back(3);
		ft_second.push_back(4);

		ft::vector<int>::iterator ft_second_itr = ft_second.end() - 1;
		*ft_second_itr--;

		while (ft_second_itr != ft_second.begin())
		{
			REQUIRE(*ft_second_itr == *second_itr);
			REQUIRE(*second_itr-- == *ft_second_itr--);
		}
	}
}

TEST_CASE("a + n | n + a | a - n | a - b", "[vector][iterator]")
{
//	std::vector<int> first;
//	first.push_back(1);
//	first.push_back(2);
//	first.push_back(3);
//	first.push_back(4);
//	first.push_back(5);
//	std::vector<int>::iterator first_itr = first.begin();
//
//	ft::vector<int> ft_first;
//	ft_first.push_back(1);
//	ft_first.push_back(2);
//	ft_first.push_back(3);
//	ft_first.push_back(4);
//	ft_first.push_back(5);
//	ft::vector<int>::iterator ft_first_itr = ft_first.begin();
//
//	for (size_t i = 0; i < ft_first.size(); i++)
//		REQUIRE(first[i] == ft_first[i]);
//
//	SECTION("a + n") {
//
//		for
//		REQUIRE(*(first_itr) == *(ft_first_itr));
//		REQUIRE(*(first_itr + 1) == *(ft_first_itr + 1));
//		REQUIRE(*(first_itr + 2) == *(ft_first_itr + 2));
//		REQUIRE(*(first_itr + 3) == *(ft_first_itr + 3));
//		REQUIRE(*(first_itr + 4) == *(ft_first_itr + 4));
//	}

	ft::vector<std::string> ft_vector;
	std::vector<std::string> std_vector;

	ft_vector.push_back("hallo");
	std_vector.push_back("hallo");
	ft_vector.push_back("world");
	std_vector.push_back("world");
	ft_vector.push_back("here");
	std_vector.push_back("here");
	ft_vector.push_back("there");
	std_vector.push_back("there");

	ft::vector<std::string>::iterator ft_it = ft_vector.begin();
	std::vector<std::string>::iterator std_it = std_vector.begin();

	ft::vector<std::string>::iterator ft_it_end = ft_vector.end();
	std::vector<std::string>::iterator std_it_end = std_vector.end();

	ft::vector<int> ft_vector_int;
	ft_vector_int.push_back(2);
	ft_vector_int.push_back(4);

	ft::vector<int>::iterator ft_two = ft_vector_int.begin();
	ft::vector<int>::iterator ft_four = ft_vector_int.begin() + 1;

	SECTION("+ overload") {
		ft_it = ft_it + 2;
		std_it = std_it + 2;
		REQUIRE(*ft_it == *std_it);
		int res = *ft_two + *ft_two;
		REQUIRE(res == 4);
	}
	SECTION("- overload") {
		ft_it_end = ft_it_end - 3;
		std_it_end = std_it_end - 3;
		REQUIRE(*ft_it_end == *std_it_end);
		int res = *ft_four - *ft_two;
		REQUIRE(res == 2);
	}
}

TEST_CASE("a < b | a > b | a <= b | a >= b", "[vector][iterator]")
{
	ft::vector<int> ft_myvector;
	for (int i=5; i>=0; i--) ft_myvector.push_back(i);

	ft::vector<int>::iterator ft_it = ft_myvector.begin();
	ft::vector<int>::iterator ft_it_1 = ft_myvector.begin() + 1;
	REQUIRE(ft_it < ft_it_1);
	REQUIRE(ft_it <= ft_it_1);
	REQUIRE(ft_it_1 == ft_it_1);
	REQUIRE(ft_it_1 >= ft_it);
	REQUIRE(ft_it_1 > ft_it);
	REQUIRE(ft_it == ft_it);
	REQUIRE(*ft_it == 5);
	REQUIRE(*ft_it_1 == 4);
}
