//
// Created by qli on 08/09/2021.
//

#include "catch2/catch.hpp"
#include "../containers/map.h"

TEST_CASE("size()", "[map][capacity]")
{
	std::map<std::string, int> std_map;
	ft::map<std::string, int> ft_map;

	REQUIRE(std_map.size() == ft_map.size());
}

TEST_CASE("insert()", "[map][modifiers]")
{
	std::map<char,int> mymap_std;
	std::pair<std::map<char,int>::iterator,bool> ret_std_1 = mymap_std.insert ( std::pair<char,int>('a',100) );
//	mymap_std.insert ( std::pair<char,int>('z',200) );

	ft::map<char,int> mymap_ft;
	ft::pair<ft::map<char,int>::iterator,bool> ret_ft_1 = mymap_ft.insert ( ft::pair<char,int>('a',100) );
//	mymap_ft.insert ( ft::pair<char,int>('z',200) );

	REQUIRE(ret_std_1.first->first == ret_ft_1.first->first);
	REQUIRE(ret_std_1.first->second == ret_ft_1.first->second);
	REQUIRE(ret_std_1.second == ret_ft_1.second);

	SECTION("insert unique element")
	{
		std::pair<std::map<char,int>::iterator,bool> ret_std;
		ret_std = mymap_std.insert ( std::pair<char,int>('y', -999) );

		ft::pair<ft::map<char,int>::iterator,bool> ret_ft;
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('y', -999) );

		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);
	}

	SECTION("insert duplicate element")
	{
		std::pair<std::map<char,int>::iterator,bool> ret_std;
		ret_std = mymap_std.insert ( std::pair<char,int>('z',500) );

		ft::pair<ft::map<char,int>::iterator,bool> ret_ft;
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('z',500) );

		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);
	}

}

