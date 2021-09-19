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
	std::map<char,int> mymap_std;
	mymap_std.insert ( std::pair<char,int>('a',100) );
	mymap_std.insert ( std::pair<char,int>('z',200) );
	mymap_std.insert ( std::pair<char,int>('b',300) );

	ft::map<char,int> mymap_ft;
	mymap_ft.insert ( ft::pair<char,int>('a',100) );
	mymap_ft.insert ( ft::pair<char,int>('z',200) );
	mymap_ft.insert ( ft::pair<char,int>('b',300) );

	REQUIRE(mymap_ft.size() == mymap_std.size());

	SECTION("traverse") {

		std::map<char,int>::iterator begin_std = mymap_std.begin();
		ft::map<char,int>::iterator begin_ft = mymap_ft.begin();
		std::map<char,int>::iterator end_std = mymap_std.end();
		ft::map<char,int>::iterator end_ft = mymap_ft.end();

		while (begin_std != end_std && begin_ft != end_ft)
		{
			REQUIRE(begin_std->first == begin_ft->first);
			REQUIRE(begin_std->second == begin_ft->second);
			++begin_std;
			++begin_ft;
		}
		//	std::cout << "----------inorder traverse------------" << std::endl;
		//	mymap_ft.inorder(mymap_ft.getRoot());
	}

	SECTION("insert unique element")
	{
		std::pair<std::map<char,int>::iterator,bool> ret_std;
		ret_std = mymap_std.insert ( std::pair<char,int>('y', -999) );

		ft::pair<ft::map<char,int>::iterator,bool> ret_ft;
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('y', -999) );

		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);

		ret_std = mymap_std.insert ( std::pair<char,int>('t', 999) );
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('t', 999) );
		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);
		REQUIRE(mymap_ft.size() == mymap_std.size());

		ret_std = mymap_std.insert ( std::pair<char,int>('r', 123) );
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('r', 123) );
		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);
		REQUIRE(mymap_ft.size() == mymap_std.size());
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
		REQUIRE(mymap_ft.size() == mymap_std.size());
	}
}

TEST_CASE("find()", "[map][operations]")
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

	std::map<int, int>::iterator std_itr = std_map.find(1);
	ft::map<int, int>::iterator ft_itr = ft_map.find(1);

	REQUIRE(std_itr->first == ft_itr->first);
	REQUIRE(std_itr->second == ft_itr->second);

	std_itr = std_map.find(5);
	ft_itr = ft_map.find(5);

	REQUIRE(std_itr->first == ft_itr->first);
	REQUIRE(std_itr->second == ft_itr->second);

	ft_itr = ft_map.find(88);
	REQUIRE(ft_itr == ft_map.end());
}

