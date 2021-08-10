//
// Created by qli on 12/03/2021.
//

#ifndef RANDOM_ACCESS_ITERATOR_H
#define RANDOM_ACCESS_ITERATOR_H
#include "iterator_traits.h"

namespace ft {

template < class T >
class random_access_iterator {

public:
	typedef std::random_access_iterator_tag			iterator_category;
	typedef T&										reference;
	typedef T*										pointer;
	typedef std::ptrdiff_t							difference_type;
	typedef random_access_iterator<T> 				iterator;

public:
	// X a; X b(a); b = a; ~X()
	explicit random_access_iterator(pointer ptr = NULL) : _ptr(ptr) {}
	random_access_iterator(const random_access_iterator& x) { *this = x; }
	random_access_iterator& operator= (const random_access_iterator& x) {
		if (this != &x)
			_ptr = x._ptr;
		return *this;
	}
	~random_access_iterator() = default;

	// a==b; a!= b;
	bool operator== (const iterator& rhs) const { return _ptr == rhs._ptr; }
	bool operator!= (const iterator& rhs) const { return _ptr != rhs._ptr; }

	// dereference: *a, *a = t, a->m
	reference operator* () { return *_ptr; }
	pointer operator-> () { return _ptr; }

	//++a; a++; *a++;
	iterator& operator++ () { ++_ptr; return *this; }

	iterator operator++ (int) {
		iterator tmp = *this;
		++_ptr;
		return tmp;
	}

	//--a; a--; *a--;
	iterator& operator-- () { --_ptr; return *this; }

	iterator operator-- (int) {
		iterator tmp = *this;
		--_ptr;
		return tmp;
	}

	// a - n | a - b | a + n | n + a
	iterator operator- (const difference_type& x) { return iterator(_ptr - x); }
	difference_type operator-(const iterator& rhs) const { return _ptr - rhs._ptr;	}
	friend iterator operator+ (int n, iterator itr) { return iterator(itr._ptr + n); }
	iterator operator+ (const int n) { return iterator(_ptr + n); }

	// a < b | a > b | a <= b | a >= b
	bool operator > (const iterator& rhs) const { return _ptr > rhs._ptr; }
	bool operator < (const iterator& rhs) const { return _ptr < rhs._ptr; }
	bool operator >= (const iterator& rhs) const { return _ptr >= rhs._ptr; }
	bool operator <= (const iterator& rhs) const { return _ptr <= rhs._ptr; }

	// a += n | a -= n
	iterator& operator += (int n) { _ptr += n; return *this; }
	iterator& operator -= (int n) { _ptr -= n; return *this; }

	// a[n]
	reference operator[](const difference_type n) const {return _ptr[n];}

protected:
	pointer _ptr;

};
}

#endif //RANDOM_ACCESS_ITERATOR_H
