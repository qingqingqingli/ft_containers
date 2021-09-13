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

	mymap_std.insert ( std::pair<char,int>('a',100) );
	mymap_std.insert ( std::pair<char,int>('z',200) );

	std::pair<std::map<char,int>::iterator,bool> ret;
	ret = mymap_std.insert ( std::pair<char,int>('z',500) );
	if (ret.second==false) {
		std::cout << "element 'z' already existed";
		std::cout << " with a value of " << ret.first->second << '\n';
	}

	// second insert function version (with hint position):
	std::map<char,int>::iterator it = mymap_std.begin();
	mymap_std.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
	mymap_std.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

	// third insert function version (range insertion):
	std::map<char,int> anothermap_std;
	anothermap_std.insert(mymap_std.begin(),mymap_std.find('c'));

	// showing contents:
	std::cout << "mymap_std contains:\n";
	for (it=mymap_std.begin(); it!=mymap_std.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';

	std::cout << "anothermap_std contains:\n";
	for (it=anothermap_std.begin(); it!=anothermap_std.end(); ++it)
		std::cout << it->first << " => " << it->second << '\n';
}