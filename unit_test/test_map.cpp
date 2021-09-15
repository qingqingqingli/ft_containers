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

TEST_CASE("default constructor")
{
	std::map<std::string, int> std_map;
	ft::map<std::string, int> ft_map;

	REQUIRE(std_map.size() == ft_map.size());
}

TEST_CASE("insert")
{
	std::map<char,int> mymap_std;
	ft::map<char,int> mymap_ft;

	mymap_std.insert ( std::pair<char,int>('a',100) );
	mymap_std.insert ( std::pair<char,int>('z',200) );

	mymap_ft.insert ( ft::pair<char,int>('a',100) );
	mymap_ft.insert ( ft::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> ret;


	ret = mymap_std.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

}