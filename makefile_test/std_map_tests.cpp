//
// Created by Qing Li on 9/22/21.
//

// map_tests.cpp

#include <iostream>
#include <sys/time.h>
#include <iomanip>
#include <cstdlib>

#include <map>

typedef std::map<int, char>			int_char_map;
typedef std::map<int, int>			int_int_map;
typedef std::map<int, std::string>	int_string_map;
typedef std::pair<int, char>		int_char_pair;
typedef std::pair<int, int>			int_int_pair;
typedef std::pair<int, std::string>	int_string_pair;

void calc_time_taken(struct timeval start, struct timeval end, std::string function_name)
{
	double time_taken;

	time_taken = (end.tv_sec - start.tv_sec) * 1e6;
	time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
	std::cout << "--------------------" << std::endl;
	std::cout << function_name << "-> time taken = " << std::fixed << time_taken << std::setprecision(6) << " sec" << std::endl;
	std::cout << "--------------------" << std::endl;
}

void map_constructor_1()
{
	int_char_map test_one;

	for (int i = 0; i < 10; i++) {
		test_one.insert(int_char_pair(i, 'a'));
	}

	int_char_map test_two(test_one);
	for (int_char_map::iterator it = test_one.begin(); it != test_one.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
	for (int_char_map::iterator it = test_two.begin(); it != test_two.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_constructor_2()
{
	int_char_map test_one;

	for (int i = 0; i < 10; i++)
		test_one.insert(int_char_pair(i, 'a'));

	int_char_map test_two(test_one.begin(), test_one.end());
	for (int_char_map::iterator it = test_one.begin(); it != test_one.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
	for (int_char_map::iterator it = test_two.begin(); it != test_two.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_equals_overload_1()
{
	int_char_map test_one;

	for (int i = 0; i < 10; i++)
		test_one.insert(int_char_pair(i, 'a'));

	int_char_map test_two = test_one;
	for (int_char_map::iterator it = test_one.begin(); it != test_one.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
	for (int_char_map::iterator it = test_two.begin(); it != test_two.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_constructors()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_constructor_1();
	map_constructor_2();
	map_equals_overload_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_map.constructor()");
}

void map_begin_1()
{
	int_char_map test;

	test.insert(int_char_pair(100, 'a'));
	int_char_map::iterator it = test.begin();
	std::cout << it->first << std::endl;
	std::cout << it->second << std::endl;
}

void map_end_1()
{
	int_int_map test;

	for (int i = 0; i < 10; i++)
		test.insert(int_int_pair(i, i + 100));
	for (int_int_map::iterator it = test.begin(); it != test.end(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_end_2()
{
	int_int_map test;

	for (int i = 0; i < 10; i++)
		test.insert(int_int_pair(i, i + 100));
	int_int_map::iterator it = test.end();
	it--;
	for (; it != test.begin(); it--)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_rbegin_1()
{
	int_int_map test;

	for (int i = 0; i < 10; i++)
		test.insert(int_int_pair(i, i + 100));
	for (int_int_map::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;
}

void map_rend_1()
{
	int_int_map test;

	for (int i = 0; i < 10; i++)
		test.insert(int_int_pair(i, i + 100));
	int_int_map::reverse_iterator it = test.rend();
	it--;
	for (; it != test.rbegin(); it--)
		std::cout << it->first << " -> " << it->second << " ";
	std::cout << std::endl;

}

void map_iterators()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_begin_1();
	map_end_1();
	map_end_2();
	map_rbegin_1();
	map_rend_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_map.iterators()");
}

void map_empty_1()
{
	int_int_map test;

	std::cout << "test.empty() = " << test.empty() << std::endl;
	test.insert(int_int_pair(100, 100));
	std::cout << "test.empty() = " << test.empty() << std::endl;
}

void map_size_1()
{
	int_int_map test;

	std::cout << "test.size() = " << test.size() << std::endl;
	for (int i = 0; i < 1000; i++)
		test.insert(int_int_pair(i, 100));
	std::cout << "test.size() = " << test.size() << std::endl;
}

void map_max_size_1()
{
	int_int_map		test_one;
	int_char_map	test_two;

	std::cout << "test_one.max_size() = " << test_one.max_size() << std::endl;
	std::cout << "test_two.max_size() = " << test_two.max_size() << std::endl;
}

void map_capacity()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_empty_1();
	map_size_1();
	map_max_size_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_map.capacity()");
}

void map_brackets_1()
{
	int_char_map test;

	for (int i = 0 ; i < 100; i++)
		test.insert(int_char_pair(i, 'a'));
	std::cout << "test.size() = " << test.size() << std::endl;
	std::cout << "test[5] = " << test[5] << std::endl;
	std::cout << "test[50] = " << test[50] << std::endl;
	std::cout << "test[200] = " << test[200] << std::endl;
	std::cout << "test.size() = " << test.size() << std::endl;
}

void map_element_access()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_brackets_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_map.capacity()");
}


void map_insert_1()
{
	int_int_map test;

	for (int i = 0; i < 1000000; i++) {
		test.insert(int_int_pair(i, i + 1));
	}
	std::pair<int_int_map::iterator, bool> pair = test.insert(int_int_pair(10, 0));
	std::cout << pair.first->first << " = " << pair.second << std::endl;
	pair = test.insert(int_int_pair(123456789, 0));
	std::cout << pair.first->first << " = " << pair.second << std::endl;
	std::cout << "map.size() = " << test.size() << std::endl;
	std::cout << "test[1] = " << test[1] << std::endl;
	std::cout << "test[10] = " << test[10] << std::endl;
	std::cout << "test[100] = " << test[100] << std::endl;
}

void map_insert_2()
{
	int_int_map test;

	for (int i = 0; i < 1000000; i++) {
		test.insert(int_int_pair(1000000 - i, i));
	}
	std::cout << "map.size() = " << test.size() << std::endl;
	std::cout << "test[1] = " << test[1] << std::endl;
	std::cout << "test[10] = " << test[10] << std::endl;
	std::cout << "test[100] = " << test[100] << std::endl;
}

void map_insert_3()
{
	int_int_map test;
	int_int_map test_two;

	for (int i = 0; i < 1000000; i++) {
		int x = rand() % 1000000;
		test.insert(int_int_pair(x, i));
	}
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

void map_erase_1()
{
int_int_map test;

for (int i = 0; i < 1000000; i++) {
test.insert(int_int_pair(i, i + 1));
}
test.erase(1000);
test.erase(1000);
test.erase(900);
test.erase(400);
test.erase(10);
test.erase(9000);
}

void map_erase_2()
{
int_int_map test;

for (int i = 0; i < 1000000; i++) {
test.insert(int_int_pair(i, i + 1));
}
std::cout << test.size() << std::endl;
test.erase(test.begin(), test.end());
std::cout << test.size() << std::endl;
}

//void map_erase_3()
//{
//int_int_map test;

//for (int i = 0; i < 30000; i++) {
//test.insert(int_int_pair(i, i + 1));
//}
//for (int i = 0; i < 30000; i++) {
//int x = rand() % 30000;
//test.erase(x);
//}
//}

void map_swap_1()
{
	int_int_map test;
	int_int_map	test_two;

	for (int i = 0; i < 10; i++) {
		test.insert(int_int_pair(i, i + 1));
	}
	for (int i = 0; i < 10; i++) {
		test_two.insert(int_int_pair(i + 1, i + 1));
	}
	int_int_map::iterator it_one = test.begin();
	for (; it_one != test.end(); it_one++) {
		std::cout << it_one->first;
	}
	std::cout << std::endl;
	it_one = test.begin();

	int_int_map::iterator it_two = test_two.begin();
	for (; it_two != test_two.end(); it_two++) {
		std::cout << it_two->first;
	}
	std::cout << std::endl;
	it_two = test_two.begin();

	std::cout << it_one->first << std::endl;
	std::cout << it_two->first << std::endl;
	test.swap(test_two);
	//std::cout << it_one->first << std::endl;
	/*std::cout << it_two->first << std::endl;*/
}

void map_modifiers()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
//	map_insert_1();
//	map_insert_2();
//	map_insert_3();
	map_erase_1();
//	map_erase_2();
	/*map_erase_3();*/
	//map_swap_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_map.modifiers()");
}

void map_find_1()
{
	int_int_map test;

	for (int i = 0; i < 100; i++) {
		test.insert(int_int_pair(i, i + 100));
	}
	int_int_map::iterator it = test.find(50);
	std::cout << it->first << "->" << it->second << std::endl;
	it = test.find(700);
	if (it == test.end())
		std::cout << "it == test.end()" << std::endl;
}

void map_count_1()
{
	int_int_map test;

	for (int i = 0; i < 100; i++) {
		test.insert(int_int_pair(i, i + 100));
	}
	size_t c = test.count(50);
	std::cout << c << std::endl;
	c = test.count(1000);
	std::cout << c << std::endl;
}

void map_lower_bound_1()
{
	int_int_map test;

	for (int i = 0; i < 100; i++) {
		test.insert(int_int_pair(i, i + 100));
	}
	int_int_map::iterator it = test.lower_bound(40);
	std::cout << it->first << "->" << it->second << std::endl;
	it = test.lower_bound(500);
	if (it == test.end())
		std::cout << "it == test.end()" << std::endl;
}

void map_upper_bound_1()
{
	int_int_map test;

	for (int i = 0; i < 100; i++) {
		test.insert(int_int_pair(i, i + 100));
	}
	int_int_map::iterator it = test.upper_bound(40);
	std::cout << it->first << "->" << it->second << std::endl;
	it = test.upper_bound(500);
	if (it == test.end())
		std::cout << "it == test.end()" << std::endl;
}

void map_equal_range_1()
{
	int_int_map test;

	for (int i = 0; i < 100; i++) {
		test.insert(int_int_pair(i, i + 100));
	}
	std::pair<int_int_map::iterator, int_int_map::iterator> it_pair = test.equal_range(5);
	std::cout << it_pair.first->first << "->" << it_pair.first->second << std::endl;
	std::cout << it_pair.second->first << "->" << it_pair.second->second << std::endl;
	it_pair = test.equal_range(1000);
	if (it_pair.first == test.end())
		std::cout << "it_pair.first == test.end()" << std::endl;
	if (it_pair.second == test.end())
		std::cout << "it_pair.second == test.second()" << std::endl;
}

void map_operations()
{
	struct timeval	start, end;

	gettimeofday(&start, NULL);
	map_find_1();
	map_count_1();
	map_lower_bound_1();
	map_upper_bound_1();
	map_equal_range_1();
	gettimeofday(&end, NULL);
	calc_time_taken(start, end, "my_map.operations()");
}

void map_main(void)
{
//	map_constructors();
//	map_iterators();
//	map_capacity();
//	map_element_access();
	map_modifiers();
//	map_operations();
}

int main(void)
{
	map_main();
	return (0);
}
