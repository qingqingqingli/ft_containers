//
// Created by qli on 10/08/2021.
//

#ifndef FT_CONTAINERS_UTILS_H
#define FT_CONTAINERS_UTILS_H
#include "iterator_traits.h"
#include "random_access_iterator.h"

namespace ft {

template<class InputIterator>
typename ft::iterator_traits<InputIterator>::difference_type
	distance (InputIterator first, InputIterator last)
	{ return last - first; }

template<class Vector>
void print_vector(Vector vector)
{
	typename Vector::iterator begin = vector.begin();
	typename Vector::iterator end = vector.end();

	while (begin != end) {
		std::cout << *begin << " ";
		begin++;
	}
	std::cout << std::endl;
}

}

#endif //FT_CONTAINERS_UTILS_H
