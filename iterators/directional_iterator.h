//
// Created by qli on 10/09/2021.
//

#ifndef FT_CONTAINERS_DIRECTIONAL_ITERATOR_H
#define FT_CONTAINERS_DIRECTIONAL_ITERATOR_H
#include "iterator_traits.h"

namespace ft {

template < typename T, typename Pointer, typename Reference >
class directional_iterator {

public:
	typedef std::bidirectional_iterator_tag	iterator_category;
	typedef Pointer							pointer;
	typedef Reference						reference;
	typedef std::ptrdiff_t					difference_type;
	typedef directional_iterator<T, Pointer, Reference>	iterator;
	typedef directional_iterator<T, const T*, const T&> if_const;
	typedef	T								value_type;

public:
	// X a; X b(a); b = a; ~X()
	directional_iterator(): _ptr(NULL) {}
	explicit directional_iterator(pointer ptr) : _node(ptr) {}
	directional_iterator(const directional_iterator& x) { *this = x; }
	directional_iterator& operator= (const directional_iterator& x) {
		if (this != &x)
			_node = x._node;
		return *this;
	}
	~directional_iterator(){}

	// const convert
	operator if_const() const { return if_const(_node); }

	// a==b; a!= b;
	bool operator== (const iterator& rhs) const { return _node == rhs._node; }
	bool operator!= (const iterator& rhs) const { return _node != rhs._node; }

	// dereference: *a, *a = t, a->m
	reference operator* () { return *_node; }
	pointer operator-> () { return _node; }

	//++a; a++; *a++;
	// next()

	//--a; a--; *a--;
	// prev()

protected:
	pointer _node;
};
}

#endif //FT_CONTAINERS_DIRECTIONAL_ITERATOR_H
