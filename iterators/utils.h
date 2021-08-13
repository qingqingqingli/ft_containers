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

//************************ lexicographical_compare ************************

template <class InputIterator1, class InputIterator2>
bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
{
	while (first1 != last1)
	{
		if (first2 == last2 || *first2 < *first1 )
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
}

}

#endif //FT_CONTAINERS_UTILS_H
