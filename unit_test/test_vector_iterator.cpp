//
// Created by qli on 10/08/2021.
//

#include "catch2/catch.hpp"
#include "../containers/vector.h"

TEST_CASE("coplien form", "[vector_iterator]")
{
	std::vector<int> first_std;
	first_std.push_back(100);
	first_std.push_back(200);
	first_std.push_back(300);
	std::vector<int>::iterator itr_std = first_std.begin();
	std::vector<int>::iterator itr_copy_std = itr_std;

	ft::vector<int> first;
	first.push_back(100);
	first.push_back(200);
	first.push_back(300);
	ft::vector<int>::iterator itr = first.begin();
	ft::vector<int>::iterator itr_copy = itr;
	REQUIRE(itr == itr_copy);
	REQUIRE(*itr == *itr_std);
	REQUIRE(*itr == *itr_copy);
	while (itr != first.end())
	{
		REQUIRE(*itr == *itr_copy_std);
		itr++;
		itr_copy_std++;
	}
}

TEST_CASE("iterator a==b; a!= b", "[vector_iterator]")
{
	ft::vector<int> first(5, 100);
	ft::vector<int>::iterator itr = first.begin();
	ft::vector<int>::iterator itr_copy = itr;
	REQUIRE(itr == itr_copy);
	REQUIRE(*itr == *itr_copy);
	ft::vector<int>::iterator itr_copy_2 = first.end();
	REQUIRE(itr != itr_copy_2);
}

TEST_CASE("*a", "[vector_iterator]")
{
	ft::vector<int> first(5, 100);
	std::vector<int> std_first(5, 100);

	std::vector<int>::iterator std_itr = std_first.begin();
	ft::vector<int>::iterator itr = first.begin();
	while (itr != first.end())
	{
		REQUIRE(*itr == *std_itr);
		itr++;
		std_itr++;
	}

	SECTION("*a = t")
	{
		*std_itr = -666;
		*itr = -666;
		REQUIRE(*itr == *std_itr);
		*itr = 777;
		REQUIRE(*itr != *std_itr);
	}
}

TEST_CASE("++a; a++; *a++;", "[vector_iterator]")
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

TEST_CASE("--a; a--; *a--;", "[vector_iterator]")
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

TEST_CASE("a + n | n + a | a - n | a - b", "[vector_iterator]")
{
	std::vector<int> first;
	first.push_back(1);
	first.push_back(2);
	first.push_back(3);
	first.push_back(4);
	first.push_back(5);
	std::vector<int>::iterator first_itr = first.begin();
	std::vector<int>::iterator end_itr = first.end();

	ft::vector<int> ft_first;
	ft_first.push_back(1);
	ft_first.push_back(2);
	ft_first.push_back(3);
	ft_first.push_back(4);
	ft_first.push_back(5);
	ft::vector<int>::iterator ft_first_itr = ft_first.begin();
	ft::vector<int>::iterator ft_end_itr = ft_first.end();

	SECTION("a + n & a - n")
	{
		REQUIRE(*(first_itr) == *(ft_first_itr));
		REQUIRE(*(first_itr + 1) == *(ft_first_itr + 1));
		REQUIRE(*(first_itr + 2) == *(ft_first_itr + 2));
		REQUIRE(*(first_itr + 3) == *(ft_first_itr + 3));
		REQUIRE(*(first_itr + 4) == *(ft_first_itr + 4));
		REQUIRE(*(end_itr - 1) == *(ft_end_itr - 1));
		REQUIRE(*(end_itr - 2) == *(ft_end_itr - 2));
		REQUIRE(*(end_itr - 3) == *(ft_end_itr - 3));
		REQUIRE(*(end_itr - 4) == *(ft_end_itr - 4));
	}

	SECTION("n + a & a - b")
	{
		REQUIRE(*(first_itr) == *(ft_first_itr));
		REQUIRE(*(1 + first_itr) == *(1 + ft_first_itr));
		REQUIRE(*(2 + first_itr) == *(2 + ft_first_itr));
		REQUIRE(*(3 + first_itr) == *(3 + ft_first_itr));
		REQUIRE(end_itr - first_itr == ft_end_itr - ft_first_itr);
	}

	SECTION ("a+=n")
	{
		first_itr += 1;
		ft_first_itr += 1;
		REQUIRE(*(first_itr) == *(ft_first_itr));
		first_itr += 3;
		ft_first_itr += 3;
		REQUIRE(*(first_itr) == *(ft_first_itr));
	}

	SECTION("a -= n")
	{
		end_itr -= 1;
		ft_end_itr -= 1;
		REQUIRE(*(end_itr) == *(ft_end_itr));
		end_itr -= 3;
		ft_end_itr -= 3;
		REQUIRE(*(end_itr) == *(ft_end_itr));
	}

}

TEST_CASE("a < b | a > b | a <= b | a >= b", "[vector_iterator]")
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

TEST_CASE("a[n]", "[vector_iterator]")
{
	ft::vector<int> ft_myvector;
	ft::vector<int>::iterator ft_it = ft_myvector.begin();
	for (int i=5; i>=0; i--) ft_myvector.push_back(i);

	std::vector<int> std_myvector;
	std::vector<int>::iterator std_it = std_myvector.begin();
	for (int i=5; i>=0; i--) std_myvector.push_back(i);

	REQUIRE(&ft_it[1] == &std_it[1]);
	REQUIRE(&ft_it[2] == &std_it[2]);
	REQUIRE(&ft_it[3] == &std_it[3]);
	REQUIRE(&ft_it[4] == &std_it[4]);
}