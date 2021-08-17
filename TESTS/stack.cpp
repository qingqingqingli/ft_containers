//
// Created by qli on 17/08/2021.
//
#include <iostream>

#if 1
	#include <stack>
	#include <vector>
	namespace ft = std;
#else
	#include "../containers/stack.h"
	#include "../containers/vector.h"
#endif

void test_constructor() {
	ft::stack<int, ft::vector<int> > mystack;
	std::cout << "stack size: " << mystack.size() << std::endl;

	ft::vector<int> myvector(5, 10);
	ft::stack<int, ft::vector<int> > stack_new(myvector);
	std::cout << "stack size: " << stack_new.size() << std::endl;
}

void test_empty() {
	ft::stack<int> mystack;
	int sum = 0;

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	std::cout << "stack sum: " << sum << std::endl;
}

void test_size() {

	ft::stack<int, ft::vector<int> > mystack;

	std::cout << "stack size: " << mystack.size() << std::endl;
	for (int i=1;i<=10;i++) mystack.push(i);
	std::cout << "stack size: " << mystack.size() << std::endl;

}

void test_top() {
	ft::stack<int, ft::vector<int> > mystack;

	mystack.push(10);
	mystack.push(20);
	mystack.push(30);
	mystack.top() -= 5;

	std::cout << "stack top: " << mystack.top() << std::endl;

}

void test_push_and_pop() {

	ft::stack<int, ft::vector<int> > mystack;
	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		std::cout << "stack top: " << mystack.top() << std::endl;
		mystack.pop();
	}
}

void test_relational_operators() {

	ft::stack<int, ft::vector<int> > mystack_small;
	for (int i=1;i<=10;i++) mystack_small.push(i);

	ft::stack<int, ft::vector<int> > mystack_big;
	for (int i=1;i<=20;i++) mystack_big.push(i);

	if (mystack_small == mystack_big)
		std::cout << "mystack_small == mystack_big" << std::endl;
	if (mystack_small != mystack_big)
		std::cout << "mystack_small != mystack_big" << std::endl;
	if (mystack_small < mystack_big)
		std::cout << "mystack_small < mystack_big" << std::endl;
	if (mystack_small <= mystack_big)
		std::cout << "mystack_small <= mystack_big" << std::endl;
	if (mystack_big > mystack_small)
		std::cout << "mystack_big > mystack_small" << std::endl;
	if (mystack_big >= mystack_small)
		std::cout << "mystack_big >= mystack_small" << std::endl;
}

int main(void)
{
	test_constructor();
	test_empty();
	test_size();
	test_top();
	test_push_and_pop();
	test_relational_operators();
	return (0);
}