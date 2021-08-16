//
// Created by qli on 16/08/2021.
//

#include "catch2/catch.hpp"
#include "../containers/stack.h"
#include "../containers/vector.h"
#include <stack>

TEST_CASE("0. constructor - stack", "[stack]")
{
	std::vector<int> myvector_std (2,200);
	std::stack<int> first_std;
	std::stack<int, std::vector<int> > third_std;
	std::stack<int, std::vector<int> > fourth_std (myvector_std);

	ft::vector<int> myvector_ft (2,200);
	ft::stack<int> first_ft;
	ft::stack<int, ft::vector<int> > third_ft;
	ft::stack<int, ft::vector<int> > fourth_ft (myvector_ft);

	REQUIRE(myvector_std.size() == myvector_ft.size());
	REQUIRE(first_std.size() == first_ft.size());
	REQUIRE(third_std.size() == third_ft.size());
	REQUIRE(fourth_std.size() == fourth_ft.size());
}

TEST_CASE("1. empty() - stack", "[stack]")
{
	std::stack<int> mystack_std;
	int sum_std = 0;

	for (int i=1;i<=10;i++) mystack_std.push(i);
	while (!mystack_std.empty())
	{
		sum_std += mystack_std.top();
		mystack_std.pop();
	}

	ft::stack<int> mystack_ft;
	int sum_ft = 0;

	for (int i=1;i<=10;i++) mystack_ft.push(i);
	while (!mystack_ft.empty())
	{
		sum_ft += mystack_ft.top();
		mystack_ft.pop();
	}

	REQUIRE(sum_std == sum_ft);
}

TEST_CASE("2. size() - stack", "[stack]")
{
	std::stack<int, std::vector<int>> mystack_std;
	ft::stack<int, ft::vector<int>> mystack_ft;

	REQUIRE(mystack_std.size() == mystack_ft.size());

	for (int i=1;i<=10;i++) mystack_std.push(i);
	for (int i=1;i<=10;i++) mystack_ft.push(i);

	REQUIRE(mystack_std.size() == mystack_ft.size());

	mystack_std.pop();
	mystack_ft.pop();

	REQUIRE(mystack_std.size() == mystack_ft.size());
}

TEST_CASE("3. top() - stack", "[stack]")
{
	std::stack<int, std::vector<int>> mystack_std;

	mystack_std.push(10);
	mystack_std.push(20);
	mystack_std.push(30);
	mystack_std.top() -= 5;

	ft::stack<int, ft::vector<int>> mystack_ft;

	mystack_ft.push(10);
	mystack_ft.push(20);
	mystack_ft.push(30);
	mystack_ft.top() -= 5;

	REQUIRE(mystack_std.top() == mystack_ft.top());
}

TEST_CASE("4. push() - stack", "[stack]")
{
	std::stack<int, std::vector<int>> mystack_std;
	for (int i=1;i<=10;i++) mystack_std.push(i);

	ft::stack<int, ft::vector<int>> mystack_ft;
	for (int i=1;i<=10;i++) mystack_ft.push(i);

	while (!mystack_ft.empty())
	{
		REQUIRE(mystack_std.top() == mystack_ft.top());
		mystack_std.pop();
		mystack_ft.pop();
	}
	REQUIRE(mystack_std.size() == mystack_ft.size());
}

TEST_CASE("5. pop() - stack", "[stack]")
{
	std::stack<int, std::vector<int>> mystack_std;
	for (int i=1;i<=10;i++) mystack_std.push(i);

	ft::stack<int, ft::vector<int>> mystack_ft;
	for (int i=1;i<=10;i++) mystack_ft.push(i);

	while (!mystack_ft.empty())
	{
		REQUIRE(mystack_std.top() == mystack_ft.top());
		mystack_std.pop();
		mystack_ft.pop();
	}
	REQUIRE(mystack_std.size() == mystack_ft.size());
}

