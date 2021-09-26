//
// Created by qli on 16/08/2021.
//
#include <iostream>
#include <sys/time.h>
#include <iomanip>
#if 1
	#include <vector>
	#include <stack>
	#include <map>
	namespace ft = std;
#else
	#include "../containers/vector.h"
	#include "../containers/map.h"
	#include "../containers/stack.h"
#endif

// helper function
void calc_time_taken(struct timeval start, struct timeval end, std::string function_name)
{
	double time_taken;

	time_taken = (end.tv_sec - start.tv_sec) * 1000000;
	time_taken = (time_taken + (end.tv_usec - start.tv_usec));
	std::cout << "--------------------" << std::endl;
	std::cout << function_name << " takes [" << std::fixed << time_taken << std::setprecision(1) << "] milli sec to complete." << std::endl;
	std::cout << "--------------------" << std::endl;
}

//************** Vector **************

void print_vector(ft::vector<int> vector)
{
	std::cout << "Vector content: ";
	for (unsigned int i=0; i<vector.size(); i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;
}

void vector_test_coplien_form() {

	std::cout << "***VECTOR - COPLIEN FORM***" << std::endl;

	ft::vector<int> vector_first;
	ft::vector<int> vector_first_copy(vector_first);
	ft::vector<int> vector_second(10);
	ft::vector<int> vector_third(10, 900);
	std::cout << "empty vector size: [" << vector_first.size() << "]" << std::endl;
	std::cout << "copied empty vector size: [" << vector_first_copy.size() << "]" << std::endl;
	std::cout << "non-empty vector size: [" << vector_second.size() << "]" << std::endl;
	std::cout << "non-empty vector size: [" << vector_third.size() << "]" << std::endl;

	std::cout << "empty vector capacity: [" << vector_first.capacity() << "]" << std::endl;
	std::cout << "copied empty vector capacity: [" << vector_first_copy.capacity() << "]" << std::endl;
	std::cout << "non-empty vector capacity: [" << vector_second.capacity() << "]" << std::endl;
	std::cout << "non-empty vector capacity: [" << vector_third.capacity() << "]" << std::endl;

}

void vector_test_iterator() {
	std::cout << std::endl << "***VECTOR - ITERATOR***" << std::endl;

	ft::vector<int> vector_first;
	for (int i=0; i<=10; i++) vector_first.push_back(i);

	ft::vector<int>::iterator begin = vector_first.begin();
	ft::vector<int>::iterator end = vector_first.end();
	ft::vector<int>::const_iterator begin_const = vector_first.begin();
	ft::vector<int>::const_iterator end_const = vector_first.end();
	ft::vector<int>::reverse_iterator reverse_begin = vector_first.rbegin();
	ft::vector<int>::reverse_iterator reverse_end = vector_first.rend();
	ft::vector<int>::const_reverse_iterator reverse_begin_const = vector_first.rbegin();
	ft::vector<int>::const_reverse_iterator reverse_end_const = vector_first.rend();


	std::cout << "Vector content: ";
	while (begin != end)
	{
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;

	std::cout << "Vector content: ";
	while (begin_const != end_const)
	{
		std::cout << *begin_const << " ";
		begin_const++;
	}
	std::cout << std::endl;

	std::cout << "Vector content: ";
	while (reverse_begin != reverse_end)
	{
		std::cout << *reverse_begin << " ";
		reverse_begin++;
	}
	std::cout << std::endl;

	std::cout << "Vector content: ";
	while (reverse_begin_const != reverse_end_const)
	{
		std::cout << *reverse_begin_const << " ";
		reverse_begin_const++;
	}
	std::cout << std::endl;
}

void vector_test_capacity() {

	std::cout << std::endl << "***VECTOR - CAPACITY***" << std::endl;

	ft::vector<int> vector;
	for (int i=0; i<=10; i++) vector.push_back(i);

	std::cout << "vector size: " << vector.size() << std::endl;
	std::cout << "vector max_size: " << vector.max_size() << std::endl;
	std::cout << "vector capacity: " << vector.capacity() << std::endl;

	vector.resize(50);
	std::cout << "vector size: " << vector.size() << std::endl;
	std::cout << "vector capacity: " << vector.capacity() << std::endl;

	if (vector.empty())
		std::cout << "vector is empty" << std::endl;
	else
		std::cout << "vector is not empty" << std::endl;

	vector.reserve(100);
	std::cout << "vector size: " << vector.size() << std::endl;
	std::cout << "vector capacity: " << vector.capacity() << std::endl;
}

void vector_test_element_access() {

	std::cout << std::endl << "***VECTOR - ELEMENT ACCESS***" << std::endl;

	ft::vector<int> vector;
	for (int i=0; i<=10; i++) vector.push_back(i);

	print_vector(vector);

	std::cout << "Vector content: ";
	for (int i=0; i<=10; i++)
		std::cout << vector.at(i) << " ";
	std::cout << std::endl;

	std::cout << "Vector front: " << vector.front() << std::endl;
	std::cout << "Vector back: " << vector.back() << std::endl;

}

void vector_test_modifier() {

	std::cout << std::endl << "***VECTOR - MODIFIER***" << std::endl;

	//******** push_back() ********

	ft::vector<int> vector;
	for (int i=0; i<=9; i++) vector.push_back(i);

	ft::vector<int> new_vector;
	new_vector.assign(vector.begin(), vector.end());

	print_vector(vector);
	print_vector(new_vector);

	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;

	//******** assign() ********
	ft::vector<int> new_vector_2;
	new_vector_2.assign(10, 10);

	print_vector(new_vector_2);

	std::cout << "vector size: " << new_vector_2.size() << std::endl;
	std::cout << "vector capacity: " << new_vector_2.capacity() << std::endl;

	//******** pop_back() ********
	new_vector.pop_back();
	new_vector.pop_back();

	print_vector(new_vector);

	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;

	//******** insert() ********

	ft::vector<int>::iterator begin = new_vector.begin();
	new_vector.insert(begin + 3, -222);

	print_vector(new_vector);

	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;

	ft::vector<int>::iterator begin_new = new_vector.begin();
	new_vector.insert(begin_new + 3, 3, -222);

	print_vector(new_vector);

	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;

	ft::vector<int>::iterator begin_new_2 = new_vector.begin();

	ft::vector<int>::iterator begin_2 = new_vector_2.begin();
	ft::vector<int>::iterator end_2 = new_vector_2.end();
	new_vector.insert(begin_new_2, begin_2, end_2);

	print_vector(new_vector);
	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;

	//******** erase() ********
	ft::vector<int>::iterator begin_new_3 = new_vector.begin();

	begin_new_3 = new_vector.erase(begin_new_3);
	print_vector(new_vector);
	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;

	new_vector.erase(begin_new_3, begin_new_3 + 3);
	print_vector(new_vector);
	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;

	//******** swap() ********

	ft::vector<int> ft_foo (3,100);
	ft::vector<int> ft_bar (5,200);

	print_vector(ft_foo);
	print_vector(ft_bar);
	ft_foo.swap(ft_bar);
	print_vector(ft_foo);
	print_vector(ft_bar);

	//******** clear() ********

	new_vector.clear();
	print_vector(new_vector);
	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;
}

void vector_test_relational_operators() {
	ft::vector<int> foo (2,200);
	ft::vector<int> foo_same (2,200);
	ft::vector<int> foo_bigger (3,200);

	if (foo == foo_same)
		std::cout << "foo == foo_same" << std::endl;
	if (foo != foo_bigger)
		std::cout << "foo != foo_bigger" << std::endl;
	if (foo < foo_bigger)
		std::cout << "foo < foo_bigger" << std::endl;
	if (foo <= foo_bigger)
		std::cout << "foo <= foo_bigger" << std::endl;
	if (foo_bigger > foo)
		std::cout << "foo_bigger > foo" << std::endl;
	if (foo_bigger >= foo)
		std::cout << "foo_bigger >= foo" << std::endl;
}

void vector_test_non_member_swap() {

	ft::vector<int> foo (3,-100);
	ft::vector<int> bar (5,200);
	print_vector(foo);
	print_vector(bar);
	foo.swap(bar);
	print_vector(foo);
	print_vector(bar);
}


//************** Stack **************

void stack_test_constructor() {
	ft::stack<int, ft::vector<int> > mystack;
	std::cout << "stack size: " << mystack.size() << std::endl;

	ft::vector<int> myvector(5, 10);
	ft::stack<int, ft::vector<int> > stack_new(myvector);
	std::cout << "stack size: " << stack_new.size() << std::endl;
}

void stack_test_empty() {
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

void stack_test_size() {

	ft::stack<int, ft::vector<int> > mystack;

	std::cout << "stack size: " << mystack.size() << std::endl;
	for (int i=1;i<=10;i++) mystack.push(i);
	std::cout << "stack size: " << mystack.size() << std::endl;

}

void stack_test_top() {
	ft::stack<int, ft::vector<int> > mystack;

	mystack.push(10);
	mystack.push(20);
	mystack.push(30);
	mystack.top() -= 5;

	std::cout << "stack top: " << mystack.top() << std::endl;

}

void stack_test_push_and_pop() {

	ft::stack<int, ft::vector<int> > mystack;
	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		std::cout << "stack top: " << mystack.top() << std::endl;
		mystack.pop();
	}
}

void stack_test_relational_operators() {

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

void stack_tester() {

	std::cout << "STACK TESTER" << std::endl;
	struct timeval	start, end;
	gettimeofday(&start, NULL);

	stack_test_constructor();
	stack_test_empty();
	stack_test_size();
	stack_test_top();
	stack_test_push_and_pop();
	stack_test_relational_operators();

	calc_time_taken(start, end, "Stack tester");
}

void vector_tester() {

	std::cout << "VECTOR TESTER" << std::endl;
	struct timeval	start, end;
	gettimeofday(&start, NULL);

	vector_test_coplien_form();
	vector_test_iterator();
	vector_test_capacity();
	vector_test_element_access();
	vector_test_modifier();
	vector_test_relational_operators();
	vector_test_non_member_swap();

	calc_time_taken(start, end, "Vector tester");
}

int main(void)
{
	vector_tester();
	stack_tester();
	return (0);
}
