//
// Created by qli on 08/09/2021.
//

#include "catch2/catch.hpp"
#include "../containers/map.h"

TEST_CASE("coplien form - map", "[map]") {
	SECTION("constructor - empty") {
		std::map<int, int> std_map;
		ft::map<int, int> ft_map;

		REQUIRE(std_map.size() == ft_map.size());

		std_map.insert ( std::pair<int,int>(2, -999) );
		std_map.insert ( std::pair<int,int>(4, -999) );
		std_map.insert ( std::pair<int,int>(5, -999) );
		std_map.insert ( std::pair<int,int>(1, -999) );
		std_map.insert ( std::pair<int,int>(6, -999) );
		std_map.insert ( std::pair<int,int>(3, -999) );

		ft_map.insert ( ft::pair<int,int>(2, -999) );
		ft_map.insert ( ft::pair<int,int>(4, -999) );
		ft_map.insert ( ft::pair<int,int>(5, -999) );
		ft_map.insert ( ft::pair<int,int>(1, -999) );
		ft_map.insert ( ft::pair<int,int>(6, -999) );
		ft_map.insert ( ft::pair<int,int>(3, -999) );

		std::map<int,int>::iterator std = std_map.begin();
		for (ft::map<int,int>::iterator it = ft_map.begin(); it != ft_map.end(); ++it) {
			REQUIRE(it->first == std->first);
			REQUIRE(it->second == std->second);
			std++;
		}
	}

	SECTION("constructor - range") {
		ft::map<int, int> ft_map_1;

		ft_map_1.insert ( ft::pair<int,int>(2, -999) );
		ft_map_1.insert ( ft::pair<int,int>(4, -999) );
		ft_map_1.insert ( ft::pair<int,int>(5, -999) );
		ft_map_1.insert ( ft::pair<int,int>(1, -999) );
		ft_map_1.insert ( ft::pair<int,int>(6, -999) );
		ft_map_1.insert ( ft::pair<int,int>(3, -999) );

		ft_map_1.print_tree(ft_map_1.getRoot());

		ft::map<int, int> ft_map(ft_map_1.begin(), ft_map_1.end());
		REQUIRE(ft_map_1.size() == ft_map.size());

		ft::map<int,int>::iterator ft = ft_map_1.begin();
		for (ft::map<int,int>::iterator it = ft_map.begin(); it != ft_map.end(); ++it) {
			REQUIRE(it->first == ft->first);
			REQUIRE(it->second == ft->second);
			ft++;
		}

	}

	SECTION("constructor - copy") {
		ft::map<int, int> ft_map_1;

		ft_map_1.insert ( ft::pair<int,int>(2, -999) );
		ft_map_1.insert ( ft::pair<int,int>(4, -999) );
		ft_map_1.insert ( ft::pair<int,int>(5, -999) );
		ft_map_1.insert ( ft::pair<int,int>(1, -999) );
		ft_map_1.insert ( ft::pair<int,int>(6, -999) );
		ft_map_1.insert ( ft::pair<int,int>(3, -999) );

		ft::map<int, int> ft_map(ft_map_1);

		ft_map = ft_map_1;
		REQUIRE(ft_map_1.size() == ft_map.size());

		std::cout << "----------" << std::endl;
		ft::map<int,int>::iterator ft = ft_map_1.begin();
		for (ft::map<int,int>::iterator it = ft_map.begin(); it != ft_map.end(); ++it) {
			REQUIRE(it->first == ft->first);
			REQUIRE(it->second == ft->second);
			ft++;
		}
	}

	SECTION("map::operator=") {
		ft::map<int, int> ft_map_1;

		ft_map_1.insert ( ft::pair<int,int>(2, -999) );
		ft_map_1.insert ( ft::pair<int,int>(4, -999) );
		ft_map_1.insert ( ft::pair<int,int>(5, -999) );
		ft_map_1.insert ( ft::pair<int,int>(1, -999) );
		ft_map_1.insert ( ft::pair<int,int>(6, -999) );
		ft_map_1.insert ( ft::pair<int,int>(3, -999) );

		ft::map<int, int> ft_map = ft_map_1;
		REQUIRE(ft_map_1.size() == ft_map.size());

		ft::map<int,int>::iterator ft = ft_map_1.begin();
		for (ft::map<int,int>::iterator it = ft_map.begin(); it != ft_map.end(); ++it) {
			REQUIRE(it->first == ft->first);
			REQUIRE(it->second == ft->second);
			ft++;
		}
	}

}

TEST_CASE("iterators - map", "[map][iterators]") {
	std::map<int, int> std_map;

	std_map.insert ( std::pair<int,int>(2, -999) );
	std_map.insert ( std::pair<int,int>(4, -999) );
	std_map.insert ( std::pair<int,int>(5, -999) );
	std_map.insert ( std::pair<int,int>(1, -999) );
	std_map.insert ( std::pair<int,int>(6, -999) );
	std_map.insert ( std::pair<int,int>(3, -999) );

	ft::map<int, int> ft_map;

	ft_map.insert ( ft::pair<int,int>(2, -999) );
	ft_map.insert ( ft::pair<int,int>(4, -999) );
	ft_map.insert ( ft::pair<int,int>(5, -999) );
	ft_map.insert ( ft::pair<int,int>(1, -999) );
	ft_map.insert ( ft::pair<int,int>(6, -999) );
	ft_map.insert ( ft::pair<int,int>(3, -999) );

	SECTION("begin() & end()") {
		std::map<int, int>::iterator std_begin = std_map.begin();
		std::map<int, int>::iterator std_end = std_map.end();
		ft::map<int, int>::iterator ft_begin = ft_map.begin();
		ft::map<int, int>::iterator ft_end = ft_map.end();

		while(std_begin != std_end) {
			REQUIRE(std_begin->first == ft_begin->first);
			REQUIRE(std_begin->second == ft_begin->second);
			++ft_begin;
			++std_begin;
		}
	}

	SECTION("rbegin() && rend()") {
		std::map<int, int>::reverse_iterator std_begin = std_map.rbegin();
		std::map<int, int>::reverse_iterator std_end = std_map.rend();
		ft::map<int, int>::reverse_iterator ft_begin = ft_map.rbegin();
		ft::map<int, int>::reverse_iterator ft_end = ft_map.rend();

		while(std_begin != std_end) {
			REQUIRE(std_begin->first == ft_begin->first);
			REQUIRE(std_begin->second == ft_begin->second);
			++ft_begin;
			++std_begin;
		}
	}
}

TEST_CASE("capacity", "[map][capacity]"){

	SECTION("empty()") {
		std::map<int, int> std_map;
		ft::map<int, int> ft_map;
		REQUIRE(std_map.empty() == ft_map.empty());

		std_map.insert ( std::pair<int,int>(1, -999) );
		ft_map.insert ( ft::pair<int,int>(1, -999) );
		REQUIRE(std_map.empty() == ft_map.empty());
	}

	SECTION("size()") {
		std::map<int, int> std_map;
		ft::map<int, int> ft_map;
		REQUIRE(std_map.size() == ft_map.size());

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

	SECTION("max_size()") {
		std::map<int, int> std_map;
		ft::map<int, int> ft_map;
		REQUIRE(std_map.max_size() == ft_map.max_size());

		std_map.insert ( std::pair<int,int>(1, -999) );
		ft_map.insert ( ft::pair<int,int>(1, -999) );
		REQUIRE(std_map.max_size() == ft_map.max_size());
	}
}

TEST_CASE("operator[]", "[map][element access]") {
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

	std_map.insert ( std::pair<int,int>(1, -123) );
	std_map.insert ( std::pair<int,int>(6, -999799) );
	std_map.insert ( std::pair<int,int>(2, -234) );
	std_map.insert ( std::pair<int,int>(4, -4599) );
	std_map.insert ( std::pair<int,int>(5, -9669) );
	std_map.insert ( std::pair<int,int>(3, -93) );

	ft_map.insert ( ft::pair<int,int>(1, -123) );
	ft_map.insert ( ft::pair<int,int>(6, -999799) );
	ft_map.insert ( ft::pair<int,int>(2, -234) );
	ft_map.insert ( ft::pair<int,int>(4, -4599) );
	ft_map.insert ( ft::pair<int,int>(5, -9669) );
	ft_map.insert ( ft::pair<int,int>(3, -93) );

	REQUIRE(std_map[1] == ft_map[1]);
	REQUIRE(std_map[2] == ft_map[2]);
	REQUIRE(std_map[3] == ft_map[3]);
	REQUIRE(std_map[4] == ft_map[4]);
	REQUIRE(std_map[5] == ft_map[5]);
	REQUIRE(std_map[6] == ft_map[6]);
	REQUIRE(std_map[7] == ft_map[7]);
	REQUIRE(std_map[8] == ft_map[8]);
	REQUIRE(std_map[9] == ft_map[9]);

}

TEST_CASE("insert()", "[map][modifiers]") {
	std::map<char,int> mymap_std;
	mymap_std.insert ( std::pair<char,int>('a',100) );
	mymap_std.insert ( std::pair<char,int>('z',200) );
	mymap_std.insert ( std::pair<char,int>('b',300) );

	ft::map<char,int> mymap_ft;
	mymap_ft.insert ( ft::pair<char,int>('a',100) );
	mymap_ft.insert ( ft::pair<char,int>('z',200) );
	mymap_ft.insert ( ft::pair<char,int>('b',300) );

	mymap_ft.print_tree(mymap_ft.getRoot());

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

	SECTION("insert duplicate element")	{
		std::pair<std::map<char,int>::iterator,bool> ret_std;
		ret_std = mymap_std.insert ( std::pair<char,int>('z',500) );

		ft::pair<ft::map<char,int>::iterator,bool> ret_ft;
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('z',500) );

		mymap_ft.print_tree(mymap_ft.getRoot());

		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);
		REQUIRE(mymap_ft.size() == mymap_std.size());
	}

	SECTION("insert iterators")	{
		ft::map<char,int> empty;
		ft::map<char,int>::iterator begin_itr = mymap_ft.begin();
		ft::map<char,int>::iterator end_itr = mymap_ft.end();
		mymap_ft.insert ( ft::pair<char,int>('f',-300) );
		mymap_ft.insert ( ft::pair<char,int>('s',777) );
		empty.insert(begin_itr, end_itr);

		ft::map<char,int>::iterator empty_begin = empty.begin();
		ft::map<char,int>::iterator empty_end = empty.end();

//		std::cout << "----------original------------" << std::endl;
//		mymap_ft.inorder(mymap_ft.getRoot());
//		std::cout << "----------------------" << std::endl;
//
//		std::cout << "----------copy------------" << std::endl;
//		empty.inorder(empty.getRoot());
//		std::cout << "----------------------" << std::endl;

		while (empty_begin != empty_end)
		{
			REQUIRE(empty_begin->first == begin_itr->first);
			REQUIRE(empty_begin->second == begin_itr->second);
			begin_itr++;
			empty_begin++;
		}
		REQUIRE(empty.size() == mymap_ft.size());
	}

	SECTION("insert hint")	{
		mymap_std.insert(mymap_std.begin(), std::pair<char,int>('d', -100));
		mymap_ft.insert(mymap_ft.begin(), ft::pair<char,int>('d', -100));

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
		REQUIRE(mymap_ft.size() == mymap_std.size());
	}

		SECTION("insert unique element") {
		std::pair<std::map<char,int>::iterator,bool> ret_std;
		ret_std = mymap_std.insert ( std::pair<char,int>('y', -999) );

		ft::pair<ft::map<char,int>::iterator,bool> ret_ft;
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('y', -999) );

		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);
		mymap_ft.print_tree(mymap_ft.getRoot());

		ret_std = mymap_std.insert ( std::pair<char,int>('t', 999) );
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('t', 999) );
		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);
		REQUIRE(mymap_ft.size() == mymap_std.size());
		mymap_ft.print_tree(mymap_ft.getRoot());

		ret_std = mymap_std.insert ( std::pair<char,int>('r', 123) );
		ret_ft = mymap_ft.insert ( ft::pair<char,int>('r', 123) );
		REQUIRE(ret_std.first->first == ret_ft.first->first);
		REQUIRE(ret_std.first->second == ret_ft.first->second);
		REQUIRE(ret_std.second == ret_ft.second);
		REQUIRE(mymap_ft.size() == mymap_std.size());
	}
}

TEST_CASE("erase()", "[map][modifiers]") {
	std::map<int,int> mymap_std;

	mymap_std[1]=20;
	mymap_std[4]=80;
	mymap_std[3]=40;
	mymap_std[2]=23;
	mymap_std[6]=23;
	mymap_std[5]=60;
	mymap_std[7]=100;
	mymap_std[8]=80;

	ft::map<int,int> mymap_ft;

	mymap_ft[1]=20;
	mymap_ft[4]=80;
	mymap_ft[3]=40;
	mymap_ft[2]=23;
	mymap_ft[6]=23;
	mymap_ft[5]=60;
	mymap_ft[7]=100;
	mymap_ft[8]=80;

	SECTION("remove")
	{
		mymap_ft.erase(3);
		mymap_std.erase(3);



		std::map<int,int>::iterator it_std = mymap_std.begin();

		for (ft::map<int,int>::iterator it = mymap_ft.begin(); it != mymap_ft.end(); ++it)
		{
			std::cout << it->first << std::endl;
//			REQUIRE(it_std->first == it->first);
//			REQUIRE(it_std->second == it->second);
			++it_std;
		}
		REQUIRE(mymap_ft.size() == mymap_std.size());
	}

//	SECTION("remove leaf node")
//	{
//		mymap_ft.erase(5);
//		mymap_std.erase(5);
//
//		std::map<int,int>::iterator it_std = mymap_std.begin();
//		for (ft::map<int,int>::iterator it = mymap_ft.begin(); it != mymap_ft.end(); ++it)
//		{
//			REQUIRE(it_std->first == it->first);
//			REQUIRE(it_std->second == it->second);
//			++it_std;
//		}
//		REQUIRE(mymap_ft.size() == mymap_std.size());
//	}
//
//	SECTION("remove node with one left child")
//	{
//		mymap_ft.erase(3);
//		mymap_std.erase(3);
//
//		std::map<int,int>::iterator it_std = mymap_std.begin();
//		for (ft::map<int,int>::iterator it = mymap_ft.begin(); it != mymap_ft.end(); ++it)
//		{
//			REQUIRE(it_std->first == it->first);
//			REQUIRE(it_std->second == it->second);
//			++it_std;
//		}
//		REQUIRE(mymap_ft.size() == mymap_std.size());
//	}
//
//	SECTION("remove node with one right child")
//	{
//		mymap_ft.erase(7);
//		mymap_std.erase(7);
//
//		std::map<int,int>::iterator it_std = mymap_std.begin();
//		for (ft::map<int,int>::iterator it = mymap_ft.begin(); it != mymap_ft.end(); ++it)
//		{
//			REQUIRE(it_std->first == it->first);
//			REQUIRE(it_std->second == it->second);
//			++it_std;
//		}
//		REQUIRE(mymap_ft.size() == mymap_std.size());
//	}
//
//	SECTION("remove node with two children")
//	{
//		mymap_ft.erase(2);
//		mymap_std.erase(2);
//
//		std::map<int,int>::iterator it_std = mymap_std.begin();
//		for (ft::map<int,int>::iterator it = mymap_ft.begin(); it != mymap_ft.end(); ++it)
//		{
//			REQUIRE(it_std->first == it->first);
//			REQUIRE(it_std->second == it->second);
//			++it_std;
//		}
//		REQUIRE(mymap_ft.size() == mymap_std.size());
//	}
//
//	SECTION("remove node with two children")
//	{
//		mymap_ft.erase(4);
//		mymap_std.erase(4);
//		std::map<int,int>::iterator it_std = mymap_std.begin();
//		for (ft::map<int,int>::iterator it = mymap_ft.begin(); it != mymap_ft.end(); ++it)
//		{
////			std::cout << "----------------------" << std::endl;
////			std::cout << it_std->first << "->" << it_std->second << std::endl;
////			std::cout << it->first << "->" << it->second << std::endl;
////			std::cout << "----------------------" << std::endl;
//			REQUIRE(it_std->first == it->first);
//			REQUIRE(it_std->second == it->second);
//			++it_std;
//		}
//		REQUIRE(mymap_ft.size() == mymap_std.size());
//
//
//	}

//	std::cout << "----------after------------" << std::endl;
//	mymap_ft.inorder(mymap_ft.getRoot());
//	std::cout << "----------------------" << std::endl;

}

TEST_CASE("swap()", "[map][modifiers]") {
	std::cout << "--------" << std::endl;

	ft::map<int,int> ft_map_1;
	ft_map_1.insert (ft::pair<int,int>(66, 100) );
	ft_map_1.insert (ft::pair<int,int>(77, 200) );
	ft_map_1.insert (ft::pair<int,int>(88, 300) );
	ft::map<int,int> map_copy_1;
	map_copy_1 = ft_map_1;

	ft::map<int, int> ft_map_2;
	ft_map_2.insert (ft::pair<int,int>(1, -999) );
	ft_map_2.insert (ft::pair<int,int>(2, -999) );
	ft_map_2.insert (ft::pair<int,int>(3, -999) );
	ft_map_2.insert (ft::pair<int,int>(4, -999) );
	ft_map_2.insert (ft::pair<int,int>(5, -999) );
	ft_map_2.insert (ft::pair<int,int>(6, -999) );
	ft::map<int,int> map_copy_2;
	map_copy_2 = ft_map_2;

//	ft_map_1.print_tree_utils(ft_map_1.getRoot(), 0);
//	ft_map_2.print_tree_utils(ft_map_2.getRoot(), 0);

	ft_map_1.swap(ft_map_2);

//	ft_map_1.print_tree_utils(ft_map_1.getRoot(), 0);
//	ft_map_2.print_tree_utils(ft_map_2.getRoot(), 0);

	ft::map<int,int>::iterator itr_copy_2;
	itr_copy_2 = map_copy_2.begin();
	for (ft::map<int,int>::iterator itr_1 = ft_map_1.begin(); itr_1 != ft_map_1.end(); itr_1++)
	{
		REQUIRE(itr_1->first == itr_copy_2->first);
		REQUIRE(itr_1->second == itr_copy_2->second);
		itr_copy_2++;
	}

	//	ft_map_1.print_tree_utils(ft_map_1.getRoot(), 0);
}

TEST_CASE("clear()", "[map][modifiers]") {

	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

	std_map.insert ( std::pair<int,int>(1, -123) );
	std_map.insert ( std::pair<int,int>(6, -999799) );
	std_map.insert ( std::pair<int,int>(2, -234) );
	std_map.insert ( std::pair<int,int>(4, -4599) );
	std_map.insert ( std::pair<int,int>(5, -9669) );
	std_map.insert ( std::pair<int,int>(3, -93) );

	ft_map.insert ( ft::pair<int,int>(1, -123) );
	ft_map.insert ( ft::pair<int,int>(6, -999799) );
	ft_map.insert ( ft::pair<int,int>(2, -234) );
	ft_map.insert ( ft::pair<int,int>(4, -4599) );
	ft_map.insert ( ft::pair<int,int>(5, -9669) );
	ft_map.insert ( ft::pair<int,int>(3, -93) );

	std_map.clear();
	ft_map.clear();

	REQUIRE(std_map.size() == ft_map.size());

	REQUIRE(std_map[1] == ft_map[1]);
	REQUIRE(std_map[2] == ft_map[2]);
	REQUIRE(std_map[3] == ft_map[3]);
	REQUIRE(std_map[4] == ft_map[4]);
	REQUIRE(std_map[5] == ft_map[5]);
	REQUIRE(std_map[6] == ft_map[6]);
	REQUIRE(std_map[7] == ft_map[7]);
	REQUIRE(std_map[8] == ft_map[8]);
	REQUIRE(std_map[9] == ft_map[9]);

	std_map.insert ( std::pair<int,int>(1, -123) );
	std_map.insert ( std::pair<int,int>(6, -999799) );
	std_map.insert ( std::pair<int,int>(2, -234) );
	std_map.insert ( std::pair<int,int>(4, -4599) );
	std_map.insert ( std::pair<int,int>(5, -9669) );
	std_map.insert ( std::pair<int,int>(3, -93) );

	ft_map.insert ( ft::pair<int,int>(1, -123) );
	ft_map.insert ( ft::pair<int,int>(6, -999799) );
	ft_map.insert ( ft::pair<int,int>(2, -234) );
	ft_map.insert ( ft::pair<int,int>(4, -4599) );
	ft_map.insert ( ft::pair<int,int>(5, -9669) );
	ft_map.insert ( ft::pair<int,int>(3, -93) );

	REQUIRE(std_map[1] == ft_map[1]);
	REQUIRE(std_map[2] == ft_map[2]);
	REQUIRE(std_map[3] == ft_map[3]);
	REQUIRE(std_map[4] == ft_map[4]);
	REQUIRE(std_map[5] == ft_map[5]);
	REQUIRE(std_map[6] == ft_map[6]);
	REQUIRE(std_map[7] == ft_map[7]);
	REQUIRE(std_map[8] == ft_map[8]);
	REQUIRE(std_map[9] == ft_map[9]);

	REQUIRE(std_map.size() == ft_map.size());
}

TEST_CASE("observers", "[map][observers]") {
	std::map<int, int> std_map;
	ft::map<int, int> ft_map;

	std_map.insert ( std::pair<int,int>(1, -123) );
	std_map.insert ( std::pair<int,int>(6, -999799) );
	std_map.insert ( std::pair<int,int>(2, -234) );
	std_map.insert ( std::pair<int,int>(4, -4599) );
	std_map.insert ( std::pair<int,int>(5, -9669) );
	std_map.insert ( std::pair<int,int>(3, -93) );

	ft_map.insert ( ft::pair<int,int>(1, -123) );
	ft_map.insert ( ft::pair<int,int>(6, -999799) );
	ft_map.insert ( ft::pair<int,int>(2, -234) );
	ft_map.insert ( ft::pair<int,int>(4, -4599) );
	ft_map.insert ( ft::pair<int,int>(5, -9669) );
	ft_map.insert ( ft::pair<int,int>(3, -93) );

	SECTION("key_comp") {
		ft::map<int, int>::key_compare ft_comp = ft_map.key_comp();
		int highest_ft = ft_map.rbegin()->first;
		std::map<int, int>::iterator std_it = std_map.begin();

		ft::map<int, int>::iterator ft_it = ft_map.begin();
		while(ft_comp((*ft_it).first, highest_ft)) {
			REQUIRE(ft_it->first == std_it->first);
			REQUIRE(ft_it->second == std_it->second);
			std_it++;
			ft_it++;
		}
	}

	SECTION("value_comp") {
		ft::pair<int, int> highest_ft = *ft_map.rbegin();
		std::map<int, int>::iterator std_it = std_map.begin();

		ft::map<int, int>::iterator ft_it = ft_map.begin();
		while(ft_map.value_comp()((*ft_it), highest_ft)) {
			REQUIRE(ft_it->first == std_it->first);
			REQUIRE(ft_it->second == std_it->second);
			std_it++;
			ft_it++;
		}
	}
}

TEST_CASE("find()", "[map][operations]") {
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

TEST_CASE("count()", "[map][operations]") {
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

TEST_CASE("bounds", "[map][operations]") {
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

TEST_CASE("non-member", "[map][non-member]") {

	std::map<int, int> std_left;
	ft::map<int, int> ft_left;

	std_left.insert ( std::pair<int,int>(1, -123) );
	std_left.insert ( std::pair<int,int>(6, -999799) );
	std_left.insert ( std::pair<int,int>(2, -234) );
	std_left.insert ( std::pair<int,int>(4, -4599) );
	std_left.insert ( std::pair<int,int>(5, -9669) );
	std_left.insert ( std::pair<int,int>(3, -93) );

	ft_left.insert ( ft::pair<int,int>(1, -123) );
	ft_left.insert ( ft::pair<int,int>(6, -999799) );
	ft_left.insert ( ft::pair<int,int>(2, -234) );
	ft_left.insert ( ft::pair<int,int>(4, -4599) );
	ft_left.insert ( ft::pair<int,int>(5, -9669) );
	ft_left.insert ( ft::pair<int,int>(3, -93) );


	std::map<int, int> std_right;
	ft::map<int, int> ft_right;

	std_right.insert ( std::pair<int,int>(10, -123) );
	std_right.insert ( std::pair<int,int>(60, -999799) );
	std_right.insert ( std::pair<int,int>(20, -234) );
	std_right.insert ( std::pair<int,int>(40, -4599) );
	std_right.insert ( std::pair<int,int>(50, -9669) );
	std_right.insert ( std::pair<int,int>(30, -93) );

	ft_right.insert ( ft::pair<int,int>(10, -123) );
	ft_right.insert ( ft::pair<int,int>(60, -999799) );
	ft_right.insert ( ft::pair<int,int>(20, -234) );
	ft_right.insert ( ft::pair<int,int>(40, -4599) );
	ft_right.insert ( ft::pair<int,int>(50, -9669) );
	ft_right.insert ( ft::pair<int,int>(30, -93) );

	REQUIRE(std_left != std_right);
	REQUIRE(std_left == std_left);
	REQUIRE(std_right == std_right);
	REQUIRE(std_left < std_right);
	REQUIRE(std_left <= std_right);
	REQUIRE(std_right > std_left);
	REQUIRE(std_right >= std_left);

	REQUIRE(ft_left != ft_right);
	REQUIRE(ft_left == ft_left);
	REQUIRE(ft_right == ft_right);
	REQUIRE(ft_left < ft_right);
	REQUIRE(ft_left <= ft_right);
	REQUIRE(ft_right > ft_left);
	REQUIRE(ft_right >= ft_left);

}

TEST_CASE("balancing") {
	ft::map<int, int> map;
	map.print_tree(map.getRoot());

	for (int i = 1; i <= 8; i++)
	{
		map.insert(ft::make_pair(i, i));
		map.print_tree(map.getRoot());
		std::cout << "---------------" << std::endl;
	}
	map.insert(ft::make_pair(8, 8));
	std::cout << "---------------" << std::endl;

}

TEST_CASE("big insert test") {
	ft::map<int, int> test;
	ft::map<int, int> test_two;

	for (int i = 0; i < 1000000; i++) {
		int x = rand() % 1000000;
		test.insert(ft::pair<int, int>(x, i));
	}
	std::cout << "segfault" << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test[1] = " << test[1] << std::endl;
	std::cout << "test[10] = " << test[10] << std::endl;
	std::cout << "test[100] = " << test[100] << std::endl;
	test_two.insert(test.begin(), test.end());
	std::cout << "test_two.size() = " << test_two.size() << std::endl;
	std::cout << "test[1] = " << test_two[1] << std::endl;
	std::cout << "test[10] = " << test_two[10] << std::endl;
	std::cout << "test[100] = " << test_two[100] << std::endl;
}





