//
// Created by qli on 08/09/2021.
//

#include "catch2/catch.hpp"
#include "../containers/map.h"

TEST_CASE("size()", "[map][capacity]")
{
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

	std_map.insert ( std::pair<int,int>(1, -999) );
	std_map.insert ( std::pair<int,int>(2, -999) );
	std_map.insert ( std::pair<int,int>(3, -999) );
	std_map.insert ( std::pair<int,int>(4, -999) );
	std_map.insert ( std::pair<int,int>(5, -999) );
	std_map.insert ( std::pair<int,int>(6, -999) );

	ft_map.insert ( ft::pair<int,int>(1, -999) );
	ft_map.insert ( ft::pair<int,int>(2, -999) );
	ft_map.insert ( ft::pair<int,int>(3, -999) );
	ft_map.insert ( ft::pair<int,int>(4, -999) );
	ft_map.insert ( ft::pair<int,int>(5, -999) );
	ft_map.insert ( ft::pair<int,int>(6, -999) );
	REQUIRE(std_map.size() == ft_map.size());
}

TEST_CASE("insert()", "[map][modifiers]")
{
//	std::map<char,int> mymap_std;
//	mymap_std.insert ( std::pair<char,int>('a',100) );
//	mymap_std.insert ( std::pair<char,int>('z',200) );

	ft::map<char,int> mymap_ft;
	std::cout << "0---\n";

	mymap_ft.insert ( ft::pair<char,int>('a',100) );
	std::cout << "1---\n";
	mymap_ft.insert ( ft::pair<char,int>('z',200) );
	std::cout << "2---\n";

	mymap_ft.insert ( ft::pair<char,int>('g',200) );
	std::cout << "3---\n";


//	for (std::map<char,int>::iterator begin_std = mymap_std.begin(); begin_std != mymap_std.end(); begin_std++)
//	{
//		std::cout << begin_std->first << "->" << begin_std->second << std::endl;
//	}

//	for (ft::map<char,int>::iterator begin_ft = mymap_ft.begin(); begin_ft != mymap_ft.end(); ++begin_ft)
//	{
//		std::cout << begin_ft->first << "->" << begin_ft->second << std::endl;
//	}

//	ft::map<char,int>::iterator begin_ft = mymap_ft.begin();
//	std::cout << begin_ft->first << "->" << begin_ft->second << std::endl;

	mymap_ft.inorder(mymap_ft.getRoot());


//	SECTION("insert unique element")
//	{
//		std::pair<std::map<char,int>::iterator,bool> ret_std;
//		ret_std = mymap_std.insert ( std::pair<char,int>('y', -999) );
//
//		ft::pair<ft::map<char,int>::iterator,bool> ret_ft;
//		ret_ft = mymap_ft.insert ( ft::pair<char,int>('y', -999) );
//
//		REQUIRE(ret_std.first->first == ret_ft.first->first);
//		REQUIRE(ret_std.first->second == ret_ft.first->second);
//		REQUIRE(ret_std.second == ret_ft.second);
//
//		ret_std = mymap_std.insert ( std::pair<char,int>('t', 999) );
//		ret_ft = mymap_ft.insert ( ft::pair<char,int>('t', 999) );
//		REQUIRE(ret_std.first->first == ret_ft.first->first);
//		REQUIRE(ret_std.first->second == ret_ft.first->second);
//		REQUIRE(ret_std.second == ret_ft.second);
//		REQUIRE(mymap_ft.size() == mymap_std.size());
//
//		ret_std = mymap_std.insert ( std::pair<char,int>('r', 123) );
//		ret_ft = mymap_ft.insert ( ft::pair<char,int>('r', 123) );
//		REQUIRE(ret_std.first->first == ret_ft.first->first);
//		REQUIRE(ret_std.first->second == ret_ft.first->second);
//		REQUIRE(ret_std.second == ret_ft.second);
//		REQUIRE(mymap_ft.size() == mymap_std.size());
//	}
//
//	SECTION("insert duplicate element")
//	{
//		std::pair<std::map<char,int>::iterator,bool> ret_std;
//		ret_std = mymap_std.insert ( std::pair<char,int>('z',500) );
//
//		std::cout << "--------------" << std::endl;
//		ft::pair<ft::map<char,int>::iterator,bool> ret_ft;
//		ret_ft = mymap_ft.insert ( ft::pair<char,int>('z',500) );
//
//		REQUIRE(ret_std.first->first == ret_ft.first->first);
//		REQUIRE(ret_std.first->second == ret_ft.first->second);
//		REQUIRE(ret_std.second == ret_ft.second);
//		REQUIRE(mymap_ft.size() == mymap_std.size());
//	}

}

