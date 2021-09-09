//
// Created by qli on 08/09/2021.
//

#include "catch2/catch.hpp"
#include "../containers/map.h"
#include <map>
#include <iostream>

TEST_CASE("test")
{
	std::map<std::string, int> Map;
	Map["C"] = 7;
	Map["B"] = 8;

	Map.insert(std::make_pair("A", 777));
	Map.insert(std::make_pair("a", 777));
	Map.insert(std::make_pair("1", 777));
	Map.insert(std::make_pair("1", -777));

	std::map<std::string, int>::iterator itr = Map.begin();

	while(itr != Map.end())
	{
		std::cout << itr->first << ": " << itr->second << std::endl;
		++itr;
	}

	std::cout << Map["a"] << std::endl;
	std::cout << Map["b"] << std::endl;
}