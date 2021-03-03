//
// Created by qli on 25/02/2021.
//
#include "catch2/catch.hpp"
#include "../containers/vector.h"
#include <fstream>

TEST_CASE("1. default constructor: empty vector", "[vector]") {
	std::vector<char> std_first;
	ft::vector<int> ft_first;

	REQUIRE(ft_first.size() == std_first.size());
	REQUIRE(ft_first.capacity() == std_first.capacity());
}

TEST_CASE("2. default constructor: vector with size and val", "[vector]") {
	std::vector<int> std_first(99);
	ft::vector<int> ft_first(99);
	std::vector<char> std_second(123);
	ft::vector<char> ft_second(123);
	std::vector<int> std_third(9000, 99);
	ft::vector<int> ft_third(9000, 99);
	std::vector<float> std_fourth(45);
	ft::vector<float> ft_fourth(45);

	REQUIRE(ft_first.size() == std_first.size());
	REQUIRE(ft_first.capacity() == std_first.capacity());
	REQUIRE(ft_second.size() == std_second.size());
	REQUIRE(ft_second.capacity() == std_second.capacity());
	REQUIRE(ft_third.size() == std_third.size());
	REQUIRE(ft_third.capacity() == std_third.capacity());
	REQUIRE(ft_fourth.size() == std_fourth.size());
	REQUIRE(ft_fourth.capacity() == std_fourth.capacity());
}

TEST_CASE("3. default constructor: vector with InputIterator", "[vector]") {

	std::vector<int> std_first(4, 100);
	std::vector<int> std_second(std_first.begin(), std_first.end());

	int myints[] = {16,2,77,29};
	std::ofstream ofs;
	ofs.open("test.txt");
	std::ifstream ifs("test.txt");
	std::string str;
	std::vector<int> std_third(myints, myints + sizeof(myints) / sizeof(int) );
	for (std::vector<int>::iterator it = std_third.begin(); it != std_third.end(); ++it)
		ofs << ' ' << *it;
	ofs << std::endl;
	std::getline(ifs, str);

	REQUIRE(std_second.size() == 4);
	REQUIRE(std_second[0] == 100);
	REQUIRE(std_second[1] == 100);
	REQUIRE(std_second[2] == 100);
	REQUIRE(std_second[3] == 100);
	REQUIRE(str==" 16 2 77 29");
}

TEST_CASE("4 & 5. copy & assignation constructor", "vector"){

	SECTION("empty vector") {
		std::vector<int> std_first;
		std::vector<int> std_first_copy(std_first);
		ft::vector<int> ft_first;
		ft::vector<int> ft_first_copy(ft_first);

		REQUIRE(std_first_copy.size() == std_first.size());
		REQUIRE(std_first_copy.capacity() == std_first.capacity());
		REQUIRE(ft_first_copy.size() == ft_first.size());
		REQUIRE(ft_first_copy.capacity() == ft_first.capacity());
		REQUIRE(ft_first_copy.size() == std_first_copy.size());
		REQUIRE(ft_first_copy.capacity() == std_first_copy.capacity());
	}
	SECTION("vector with size") {
		std::vector<int> std_first(10);
		std::vector<int> std_first_copy(std_first);
		ft::vector<int> ft_first(10);
		ft::vector<int> ft_first_copy(ft_first);

		REQUIRE(std_first_copy.size() == std_first.size());
		REQUIRE(std_first_copy.capacity() == std_first.capacity());
		REQUIRE(ft_first_copy.size() == ft_first.size());
		REQUIRE(ft_first_copy.capacity() == ft_first.capacity());
		REQUIRE(ft_first_copy.size() == std_first_copy.size());
		REQUIRE(ft_first_copy.capacity() == std_first_copy.capacity());
	}
	SECTION("vector with value") {
		std::vector<int> std_first(10, 900);
		std::vector<int> std_first_copy(std_first);
		ft::vector<int> ft_first(10, 900);
		ft::vector<int> ft_first_copy(ft_first);

		REQUIRE(std_first_copy.size() == std_first.size());
		REQUIRE(std_first_copy.capacity() == std_first.capacity());
		REQUIRE(ft_first_copy.size() == ft_first.size());
		REQUIRE(ft_first_copy.capacity() == ft_first.capacity());
		REQUIRE(ft_first_copy.size() == std_first_copy.size());
		REQUIRE(ft_first_copy.capacity() == std_first_copy.capacity());
	}

//	SECTION("update vector with value") {
//		std::vector<int> std_first(10, 900);
//		std::vector<int> std_first_copy(std_first);
////		std_first_copy.resize(20);
//		std_first_copy[1] = 777;
//		std_first_copy[8] = 99;
//
//		ft::vector<int> ft_first(10, 900);
//		ft::vector<int> ft_first_copy(ft_first);
//		ft::vector<int> ft_second_copy = ft_first_copy;
//
////		ft_first_copy.resize(20);
//		ft_first_copy[1] = 777;
//		ft_first_copy[8] = 99;
//		ft_second_copy[7] = 88;
//
//		REQUIRE(std_first_copy[1] == ft_first_copy[1]);
//		REQUIRE(std_first_copy[8] == ft_first_copy[8]);
//		REQUIRE(ft_first[1] == 900);
//		REQUIRE(ft_first[8] == 900);
//		REQUIRE(ft_second_copy.size() == ft_first_copy.size());
//		REQUIRE(ft_second_copy.capacity() == ft_first_copy.capacity());
//		REQUIRE(ft_second_copy[7] != ft_first_copy[7]);
//	}
}

TEST_CASE("8. at", "vector"){

	SECTION("non-const type")
	{
		int num = 10;
		std::vector<int> myvector (num);
		ft::vector<int> ft_myvector (num);

		for (unsigned i=0; i<myvector.size(); i++)
		{
			myvector.at(i) = i;
			ft_myvector.at(i) = i;
		}
		for (unsigned i=0; i<ft_myvector.size(); i++)
		{
			REQUIRE(ft_myvector.at(i) == myvector.at(i));
			REQUIRE(ft_myvector.at(i) == ft_myvector[i]);
		}
		// -> same exception message
		//	ft_myvector.at(16);
		//	myvector.at(16);
	}
	SECTION("const type")
	{
		int num = 10;
		int val = 20;
		const std::vector<int> const_vec(num, val);
		const ft::vector<int> ft_const_vec(num, val);
		for (unsigned i = 0; i < ft_const_vec.size(); i++)
		{
			REQUIRE(ft_const_vec.at(i) == const_vec.at(i));
			REQUIRE(ft_const_vec.at(i) == ft_const_vec[i]);
		}
	}
}

TEST_CASE("21. pop_back", "vector") {

	SECTION("check initial list end")
	{
		std::vector<int> myvector(5, 10);
		std::vector<int> ft_myvector(5, 10);
		REQUIRE(myvector[4] == 10);
		REQUIRE(ft_myvector[4] == 10);
	}

	SECTION("increase size")
	{
		std::vector<int> myvector(5);
		ft::vector<int> ft_myvector(5);
		myvector.push_back(6);
		myvector.push_back(6);
		ft_myvector.push_back(6);
		ft_myvector.push_back(6);

		REQUIRE(myvector.size() == ft_myvector.size());
		REQUIRE(myvector.capacity() == ft_myvector.capacity());

		REQUIRE(myvector[0] == ft_myvector[0]);
		REQUIRE(myvector[1] == ft_myvector[1]);
		REQUIRE(myvector[2] == ft_myvector[2]);
		REQUIRE(myvector[3] == ft_myvector[3]);
		REQUIRE(myvector[4] == ft_myvector[4]);
		//invalid read
		REQUIRE(myvector[5] == ft_myvector[5]);
		REQUIRE(myvector[6] == ft_myvector[6]);
		REQUIRE(myvector[9] == 0);
//		REQUIRE(myvector[9] == ft_myvector[9]);
	}
}

TEST_CASE("copy & assignation operator: with value", "vector"){

	unsigned long int size = 10;
	std::vector<int> std_second(size, 10);
	std::vector<int> std_third = std_second;
	std_second[0] = 100;
	REQUIRE(std_third[0] == 10);

	SECTION("testing resize"){
		std_second.resize(88);
		REQUIRE(std_third.size() == 10);
		REQUIRE(std_second.size() == 88);
		REQUIRE(std_third.capacity() == 10);
		REQUIRE(std_second.capacity() == 88);
	}
}

TEST_CASE("test constructor with an array", "vector"){
	std::string arr[] = {"first", "second", "third", "fourth"};

	std::vector<std::string> vecOfStr1(arr, arr+sizeof(arr)/sizeof(std::string));
//	ft::vector<std::string> vecOfStr2(arr, arr+sizeof(arr)/sizeof(std::string));
	REQUIRE(vecOfStr1.size() == 4);
	REQUIRE(vecOfStr1[0] == "first");
	REQUIRE(vecOfStr1[1] == "second");
	REQUIRE(vecOfStr1[2] == "third");
	REQUIRE(vecOfStr1[3] == "fourth");
}

TEST_CASE("test copy constructor", "vector") {
	std::vector<std::string> vecOfStr;
	vecOfStr.push_back("first");
	vecOfStr.push_back("second");
	vecOfStr.push_back("third");
	vecOfStr.push_back("fourth");
	std::vector<std::string> vecOfStr2(vecOfStr);
	REQUIRE(vecOfStr2[0] == "first");
	REQUIRE(vecOfStr2[1] == "second");
	REQUIRE(vecOfStr2[2] == "third");
	REQUIRE(vecOfStr2[3] == "fourth");


}