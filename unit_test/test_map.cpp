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

	}

	SECTION("insert unique element") {
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

	SECTION("insert duplicate element")	{
		std::pair<std::map<char,int>::iterator,bool> ret_std;
		ret_std = mymap_std.insert ( std::pair<char,int>('z',500) );

		ft::pair<ft::map<char,int>::iterator,bool> ret_ft;
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('z',500) );

		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);
		REQUIRE(mymap_ft.size() == mymap_std.size());
	}

//	SECTION("insert iterators")
//	{
//		ft::map<char,int> empty;
//		ft::map<char,int>::iterator begin_itr = mymap_ft.begin();
//		ft::map<char,int>::iterator end_itr = mymap_ft.end();
//		empty.insert(begin_itr, end_itr);
//		REQUIRE(mymap_ft == empty);
//	}
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

TEST_CASE("count()", "[map][operations]")
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

	REQUIRE(std_map.count(4) == ft_map.count(4));
	REQUIRE(std_map.count(2) == ft_map.count(2));
	REQUIRE(std_map.count(555) == ft_map.count(555));
}

TEST_CASE("bounds", "[map][operations]")
{
	std::map<char,int> mymap;
	std::map<char,int>::iterator itlow, itup;

	mymap['a']=20;
	mymap['b']=40;
	mymap['c']=60;
	mymap['d']=80;
	mymap['e']=100;

	itlow = mymap.lower_bound('b');
	itup = mymap.upper_bound('d');

	ft::map<char,int> mymap_ft;
	ft::map<char,int>::iterator itlow_ft, itup_ft;

	mymap_ft['a']=20;
	mymap_ft['b']=40;
	mymap_ft['c']=60;
	mymap_ft['d']=80;
	mymap_ft['e']=100;

	itlow_ft = mymap_ft.lower_bound('b');
	itup_ft = mymap_ft.upper_bound('d');

	SECTION ("lower_bound()") {
		REQUIRE(itlow->first == itlow_ft->first);
		REQUIRE(itlow->second == itlow_ft->second);
	}

	SECTION("upper_bound()"){
		REQUIRE(itup->first == itup_ft->first);
		REQUIRE(itup->second == itup_ft->second);
	}

	SECTION("equal_range()") {
		std::pair<std::map<char,int>::iterator, std::map<char,int>::iterator> equal = mymap.equal_range('c');
		ft::pair<ft::map<char,int>::iterator, ft::map<char,int>::iterator> equal_ft = mymap_ft.equal_range('c');
		REQUIRE(equal.first->first == equal_ft.first->first);
		REQUIRE(equal.first->second == equal_ft.first->second);
		REQUIRE(equal.second->first == equal_ft.second->first);
		REQUIRE(equal.second->second == equal_ft.second->second);
	}
}

TEST_CASE("erase()")
{
	ft::map<char,int> mymap_ft;
//	ft::map<char,int>::iterator itlow_ft, itup_ft;

	mymap_ft['a']=20;
	mymap_ft['d']=80;
	mymap_ft['b']=40;
	mymap_ft['c']=60;
	mymap_ft['e']=100;

	std::cout << "----------before------------" << std::endl;
	mymap_ft.inorder(mymap_ft.getRoot());
	std::cout << "----------------------" << std::endl;

	mymap_ft.erase('c');

	std::cout << "----------after------------" << std::endl;
	mymap_ft.inorder(mymap_ft.getRoot());


}

//TEST_CASE("swap()", "[map][modifiers]")
//{
//	std::map<int,int> std_map_1;
//	std_map_1.insert (std::pair<int,int>(66, 100) );
//	std_map_1.insert (std::pair<int,int>(77, 200) );
//	std_map_1.insert (std::pair<int,int>(88, 300) );
//
//	std::map<int, int> std_map_2;
//	std_map_2.insert (std::pair<int,int>(1, -999) );
//	std_map_2.insert (std::pair<int,int>(2, -999) );
//	std_map_2.insert (std::pair<int,int>(3, -999) );
//	std_map_2.insert (std::pair<int,int>(4, -999) );
//	std_map_2.insert (std::pair<int,int>(5, -999) );
//	std_map_2.insert (std::pair<int,int>(6, -999) );
//
//	std::map<int,int>::iterator itr_begin_1 = std_map_1.begin();
//	std::map<int,int>::iterator itr_end_1 = std_map_1.end();
//	std::map<int,int>::iterator itr_begin_2 = std_map_2.begin();
//	std::map<int,int>::iterator itr_end_2 = std_map_2.end();
//
//	for (; itr_begin_1 != itr_end_1; ++itr_begin_1)
//		std::cout << itr_begin_1->first << "->" << itr_begin_1->second << std::endl;
//
//	for (; itr_begin_2 != itr_end_2; ++itr_begin_2)
//		std::cout << itr_begin_2->first << "->" << itr_begin_2->second << std::endl;
//
//	std_map_1.swap(std_map_2);
//
//	itr_begin_1 = std_map_1.begin();
//	itr_end_1 = std_map_1.end();
//	itr_begin_2 = std_map_2.begin();
//	itr_end_2 = std_map_2.end();
//
//	std::cout << "--------" << std::endl;
//
//	for (; itr_begin_1 != itr_end_1; ++itr_begin_1)
//		std::cout << itr_begin_1->first << "->" << itr_begin_1->second << std::endl;
//
//	for (; itr_begin_2 != itr_end_2; ++itr_begin_2)
//		std::cout << itr_begin_2->first << "->" << itr_begin_2->second << std::endl;
//
//	ft::map<int,int> ft_map_1;
//	ft_map_1.insert (ft::pair<int,int>(66, 100) );
//	ft_map_1.insert (ft::pair<int,int>(77, 200) );
//	ft_map_1.insert (ft::pair<int,int>(88, 300) );
//
//	ft::map<int, int> ft_map_2;
//	ft_map_2.insert (ft::pair<int,int>(1, -999) );
//	ft_map_2.insert (ft::pair<int,int>(2, -999) );
//	ft_map_2.insert (ft::pair<int,int>(3, -999) );
//	ft_map_2.insert (ft::pair<int,int>(4, -999) );
//	ft_map_2.insert (ft::pair<int,int>(5, -999) );
//	ft_map_2.insert (ft::pair<int,int>(6, -999) );
//
//	ft::map<int,int>::iterator ft_itr_begin_1 = ft_map_1.begin();
//	ft::map<int,int>::iterator ft_itr_end_1 = ft_map_1.end();
//	ft::map<int,int>::iterator ft_itr_begin_2 = ft_map_2.begin();
//	ft::map<int,int>::iterator ft_itr_end_2 = ft_map_2.end();
//
//	for (; ft_itr_begin_1 != ft_itr_end_1; ++ft_itr_begin_1)
//		std::cout << ft_itr_begin_1->first << "->" << ft_itr_begin_1->second << std::endl;
//
//	for (; ft_itr_begin_2 != ft_itr_end_2; ++ft_itr_begin_2)
//		std::cout << ft_itr_begin_2->first << "->" << ft_itr_begin_2->second << std::endl;
//
//	ft_map_1.swap(ft_map_2);
//
//	ft_itr_begin_1 = ft_map_1.begin();
//	ft_itr_end_1 = ft_map_1.end();
//	ft_itr_begin_2 = ft_map_2.begin();
//	ft_itr_end_2 = ft_map_2.end();
//
//	std::cout << "--------" << std::endl;
//
//	for (; ft_itr_begin_1 != ft_itr_end_1; ++ft_itr_begin_1)
//		std::cout << ft_itr_begin_1->first << "->" << ft_itr_begin_1->second << std::endl;
//
//	for (; ft_itr_begin_2 != ft_itr_end_2; ++ft_itr_begin_2)
//		std::cout << ft_itr_begin_2->first << "->" << ft_itr_begin_2->second << std::endl;
//}


