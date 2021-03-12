//
// Created by qli on 12/03/2021.
//

#ifndef FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_H
#define FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_H

namespace ft {

template < class T>
class random_access_iterator {

public:
	typedef T										value_type;
	typedef T&										reference;
	typedef const T&								const_reference;
	typedef T*										pointer;
	typedef const T*								const_pointer;
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;


private:
	pointer ptr;

};
}

#endif //FT_CONTAINERS_RANDOM_ACCESS_ITERATOR_H
