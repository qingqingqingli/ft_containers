//
// Created by qli on 10/09/2021.
//

#ifndef FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_H
#define FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_H
#include "iterator_traits.h"

namespace ft {

template < typename T >
class bidirectional_iterator {

public:
	typedef std::bidirectional_iterator_tag					iterator_category;
	typedef T												value_type;
	typedef T*												pointer;
	typedef T&												reference;
	typedef std::ptrdiff_t									difference_type;
	typedef bidirectional_iterator<value_type>				iterator;
	typedef bidirectional_iterator<const value_type> 		if_const;
	typedef BSTNode<value_type> 							Node;
	typedef Node*											iterator_type;

public:
	// X a; X b(a); b = a; ~X()
	bidirectional_iterator(): _ptr(NULL) {}
	explicit bidirectional_iterator(iterator_type ptr) : _ptr(ptr) {}
	bidirectional_iterator(const bidirectional_iterator& x) { *this = x; }
	bidirectional_iterator& operator= (const bidirectional_iterator& x) {
		if (this != &x)
			_ptr = x._ptr;
		return *this;
	}
	~bidirectional_iterator(){}

	// const convert
	operator if_const() const { return if_const(_ptr); }

	// a==b; a!= b;
	bool operator== (const iterator& rhs) const { return _ptr == rhs._ptr; }
	bool operator!= (const iterator& rhs) const { return _ptr != rhs._ptr; }

	// dereference: *a, *a = t, a->m
	reference operator* () { return _ptr->value; }
	pointer operator-> () { return &(_ptr->value); }

	//++a; a++; *a++;
	iterator& operator++ () { _ptr = _ptr->next(); return *this; }

	iterator operator++ (int) {
		iterator tmp = *this;
		_ptr = _ptr->next();
		return tmp;
	}

	//--a; a--; *a--;
	iterator& operator-- () { _ptr = _ptr->prev(); return *this; }

	iterator operator-- (int) {
		iterator tmp = *this;
		_ptr = _ptr->prev();
		return tmp;
	}

	iterator_type _ptr;
};
}

#endif //FT_CONTAINERS_BIDIRECTIONAL_ITERATOR_H
