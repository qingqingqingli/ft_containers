//
// Created by qli on 10/08/2021.
//

#ifndef FT_CONTAINERS_ITERATOR_H
#define FT_CONTAINERS_ITERATOR_H
#include "iterator_traits.h"

namespace ft {

template<class InputIterator>
		typename ft::iterator_traits<InputIterator>::difference_type
		distance (InputIterator first, InputIterator last){
			return last - first;
		}
}

#endif //FT_CONTAINERS_ITERATOR_H
