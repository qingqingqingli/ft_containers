//
// Created by qli on 16/08/2021.
//
#include <iostream>

#if 1 //CREATE A REAL STL EXAMPLE
	#include <map>
	#include <stack>
	#include <vector>

namespace ft = std;
#else
	#include "../containers/vector.h"
#endif

void test_coplien_form() {

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

void test_iterator() {
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

void test_capacity() {

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

void test_element_access() {

	std::cout << std::endl << "***VECTOR - ELEMENT ACCESS***" << std::endl;

	ft::vector<int> vector;
	for (int i=0; i<=10; i++) vector.push_back(i);

	std::cout << "Vector content: ";
	for (int i=0; i<=10; i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Vector content: ";
	for (int i=0; i<=10; i++)
		std::cout << vector.at(i) << " ";
	std::cout << std::endl;

	std::cout << "Vector front: " << vector.front() << std::endl;
	std::cout << "Vector back: " << vector.back() << std::endl;

}

//std::cout << std::endl << "***VECTOR - CAPACITY***" << std::endl;
//
//ft::vector<int> vector;
//for (int i=0; i<=10; i++) vector.push_back(i);

void test_modifier() {

	std::cout << std::endl << "***VECTOR - MODIFIER***" << std::endl;

	ft::vector<int> vector;
	for (int i=0; i<=9; i++) vector.push_back(i);

	ft::vector<int> new_vector;
	new_vector.assign(vector.begin(), vector.end());

	std::cout << "Vector content: ";
	for (int i=0; i<=9; i++)
		std::cout << vector[i] << " ";
	std::cout << std::endl;

	std::cout << "Vector content: ";
	for (int i=0; i<=9; i++)
		std::cout << new_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;

	ft::vector<int> new_vector_2;
	new_vector_2.assign(10, 10);

	std::cout << "Vector content: ";
	for (unsigned int i=0; i<new_vector_2.size(); i++)
		std::cout << new_vector_2[i] << " ";
	std::cout << std::endl;

	std::cout << "vector size: " << new_vector_2.size() << std::endl;
	std::cout << "vector capacity: " << new_vector_2.capacity() << std::endl;

	new_vector.pop_back();
	new_vector.pop_back();

	std::cout << "Vector content: ";
	for (unsigned int i=0; i<new_vector.size(); i++)
		std::cout << new_vector[i] << " ";
	std::cout << std::endl;

	std::cout << "vector size: " << new_vector.size() << std::endl;
	std::cout << "vector capacity: " << new_vector.capacity() << std::endl;


}

int main(void)
{
	test_coplien_form();
	test_iterator();
	test_capacity();
	test_element_access();
	test_modifier();
//	test_allocator();
//	test_relational_operators();
//	test_non_member_swap();

	return (0);
}
