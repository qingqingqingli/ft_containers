//
// Created by qli on 15/03/2021.
//

#include "catch2/catch.hpp"
#include "../containers/vector.h"

TEST_CASE("begin()", "[vector][iterator]")
{
	std::vector<int> myvector;
	for (int i=1; i<=5; i++) myvector.push_back(i);

	ft::vector<int> ft_myvector;
	for (int i=1; i<=5; i++) ft_myvector.push_back(i);

	std::vector<int>::iterator std = myvector.begin();
	for (ft::vector<int>::iterator it = ft_myvector.begin() ; it != ft_myvector.end(); ++it)
	{
		REQUIRE(*it == *std);
		++std;
	}
}

TEST_CASE("iterator a < b | a > b | a <= b | a >= b", "[vector][iterator]")
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

TEST_CASE("constructor iterator", "[vector][iterator]") {

	std::vector<int> myvector;
	for (int i=5; i>=0; i--) myvector.push_back(i);

	std::vector<int>::iterator begin(myvector.begin());
	std::cout << (*begin) << std::endl;
}
