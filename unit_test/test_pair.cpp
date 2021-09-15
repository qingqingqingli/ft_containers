//
// Created by qli on 15/09/2021.
//

#include "catch2/catch.hpp"
#include "../utils/pair.h"

TEST_CASE("0. pair constructor", "[pair]")
{
	std::pair <std::string,double> product1;
	std::pair <std::string,double> product2 ("tomatoes",2.30);
	std::pair <std::string,double> product3 (product2);

	product1 = std::make_pair(std::string("lightbulbs"),0.99);

	product2.first = "shoes";
	product2.second = 39.90;

	ft::pair <std::string,double> product1_ft;
	ft::pair <std::string,double> product2_ft ("tomatoes",2.30);
	ft::pair <std::string,double> product3_ft (product2_ft);

	product1_ft = ft::make_pair(std::string("lightbulbs"),0.99);

	product2_ft.first = "shoes";
	product2_ft.second = 39.90;

	REQUIRE(product1.first == product1_ft.first);
	REQUIRE(product1.second == product1_ft.second);
	REQUIRE(product2.first == product2_ft.first);
	REQUIRE(product2.second == product2_ft.second);
	REQUIRE(product3.first == product3_ft.first);
	REQUIRE(product3.second == product3_ft.second);
}

TEST_CASE("1. pair::operator=", "[pair]")
{

	std::pair <std::string,int> planet, homeplanet;
	planet = std::make_pair("Earth",6371);
	homeplanet = planet;

	ft::pair <std::string,int> planet_ft, homeplanet_ft;
	planet_ft = ft::make_pair("Earth",6371);
	homeplanet_ft = planet_ft;

	REQUIRE(planet.first == planet_ft.first);
	REQUIRE(planet.second == planet_ft.second);
	REQUIRE(homeplanet.first == homeplanet_ft.first);
	REQUIRE(homeplanet.second == homeplanet_ft.second);
}

TEST_CASE("2. pair relational operations", "[pair]")
{
	std::pair<int,char> foo_std (10,'z');
	std::pair<int,char> bar_std (90,'a');

	ft::pair<int,char> foo_ft (10,'z');
	ft::pair<int,char> bar_ft (90,'a');

	REQUIRE((foo_std==bar_std) == (foo_ft==bar_ft));
	REQUIRE((foo_std!=bar_std) == (foo_ft!=bar_ft));
	REQUIRE((foo_std<bar_std) == (foo_ft<bar_ft));
	REQUIRE((foo_std>bar_std) == (foo_ft>bar_ft));
	REQUIRE((foo_std<bar_std) == (foo_ft<bar_ft));
	REQUIRE((foo_std>=bar_std) == (foo_ft>=bar_ft));
	REQUIRE((foo_std<=bar_std) == (foo_ft<=bar_ft));
}
