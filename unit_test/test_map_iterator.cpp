//
// Created by qli on 17/09/2021.
//

#include "catch2/catch.hpp"
#include "../containers/map.h"

TEST_CASE("map iterator", "[map_iterator]")
{
	std::map<std::string, int> std_map;
	std_map.insert(std::pair<std::string, int>("hello", 0));
	std_map.insert(std::pair<std::string, int>("how", 1));
	std_map.insert(std::pair<std::string, int>("are", 2));
	std_map.insert(std::pair<std::string, int>("you", 3));
	std_map.insert(std::pair<std::string, int>("?", 4));
	std_map.insert(std::pair<std::string, int>("you", 5));

	std::map<std::string, int>::iterator begin_std = std_map.begin();
	std::map<std::string, int>::iterator begin_std_copy = begin_std;
	std::map<std::string, int>::iterator begin_std_copy_2(begin_std_copy);

	ft::map<std::string, int> ft_map;
	ft_map.insert(ft::pair<std::string, int>("hello", 0));
	ft_map.insert(ft::pair<std::string, int>("how", 1));
	ft_map.insert(ft::pair<std::string, int>("are", 2));
	ft_map.insert(ft::pair<std::string, int>("you", 3));
	ft_map.insert(ft::pair<std::string, int>("?", 4));
	ft_map.insert(ft::pair<std::string, int>("you", 5));

	ft::map<std::string, int>::iterator begin_ft = ft_map.begin();
	ft::map<std::string, int>::iterator begin_ft_copy = begin_ft;
	ft::map<std::string, int>::iterator begin_ft_copy_2(begin_ft_copy);

	SECTION("0. coplien form")
	{
		REQUIRE(begin_ft == begin_ft_copy);
		REQUIRE(begin_ft_copy == begin_ft_copy_2);
		REQUIRE(begin_ft_copy_2->first == begin_std_copy_2->first);
		REQUIRE(begin_ft_copy_2->second == begin_std_copy_2->second);

		while (begin_std != std_map.end())
		{
			REQUIRE(begin_std->first == begin_ft->first);
			REQUIRE(begin_std->second == begin_ft->second);
			begin_std++;
			begin_ft++;
		}
	}

	SECTION("1. a==b; a!= b")
	{
		ft::map<std::string, int>::iterator end_ft = ft_map.end();

		REQUIRE(begin_std->first == begin_ft->first);
		REQUIRE(begin_std->second == begin_ft->second);
		REQUIRE(begin_ft != end_ft);
		REQUIRE(begin_ft == begin_ft_copy);
	}

	SECTION("2. *a, a->m")
	{
		REQUIRE(*begin_ft == *begin_ft_copy);
		REQUIRE(*begin_ft == *begin_ft_copy_2);
		REQUIRE(*begin_ft_copy == *begin_ft_copy_2);

		while (begin_std != std_map.end())
		{
			REQUIRE(begin_std->first == begin_ft->first);
			REQUIRE(begin_std->second == begin_ft->second);
			begin_std++;
			begin_ft++;
		}
	}

	SECTION("3. ++a")
	{
		while (begin_std != std_map.end())
		{
			REQUIRE(begin_std->first == begin_ft->first);
			REQUIRE(begin_std->second == begin_ft->second);
			++begin_std;
			++begin_ft;
		}
	}

	SECTION("3. a++")
	{
		while (begin_std != std_map.end())
		{
			REQUIRE(begin_std->first == begin_ft->first);
			REQUIRE(begin_std->second == begin_ft->second);
			begin_std++;
			begin_ft++;
		}
	}

	SECTION("4. --a")
	{
		std::map<std::string, int>::iterator end_std = std_map.end();
		end_std--;

		ft::map<std::string, int>::iterator end_ft = ft_map.end();
		end_ft--;

		while (end_std != begin_std)
		{
			REQUIRE(end_std->first == end_ft->first);
			REQUIRE(end_std->second == end_ft->second);
			--end_std;
			--end_ft;
		}
	}

	SECTION("4. a--")
	{
		std::map<std::string, int>::iterator end_std = std_map.end();
		end_std--;

		ft::map<std::string, int>::iterator end_ft = ft_map.end();
		end_ft--;

		while (end_std != begin_std)
		{
			REQUIRE(end_std->first == end_ft->first);
			REQUIRE(end_std->second == end_ft->second);
			end_std--;
			end_ft--;
		}
	}

	SECTION("4. *a--")
	{
		std::map<std::string, int>::iterator end_std = std_map.end();
		*end_std--;

		ft::map<std::string, int>::iterator end_ft = ft_map.end();
		*end_ft--;

		while (end_std != begin_std)
		{
			REQUIRE(end_std->first == end_ft->first);
			REQUIRE(end_std->second == end_ft->second);
			*end_std--;
			*end_ft--;
		}
	}
}
