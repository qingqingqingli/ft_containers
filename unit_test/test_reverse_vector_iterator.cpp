//
// Created by qli on 10/08/2021.
//

#include "catch2/catch.hpp"
#include "../containers/vector.h"

TEST_CASE("coplien form", "[vector_reverse_iterator]")
{
	std::vector<int> first_std;
	first_std.push_back(100);
	first_std.push_back(200);
	first_std.push_back(300);
	std::vector<int>::reverse_iterator itr_std = first_std.rbegin();
	std::vector<int>::reverse_iterator itr_copy_std = itr_std;
	REQUIRE(itr_copy_std.base() == itr_std.base());

	ft::vector<int> first;
	first.push_back(100);
	first.push_back(200);
	first.push_back(300);
	ft::vector<int>::reverse_iterator itr = first.rbegin();
	ft::vector<int>::reverse_iterator itr_copy = itr;
	REQUIRE(itr == itr_copy);
	REQUIRE(*itr == *itr_std);
//	REQUIRE(*itr == *itr_copy);
}