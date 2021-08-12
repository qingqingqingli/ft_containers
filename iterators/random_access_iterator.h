//
// Created by qli on 12/03/2021.
//

#ifndef RANDOM_ACCESS_ITERATOR_H
#define RANDOM_ACCESS_ITERATOR_H
#include "iterator_traits.h"

namespace ft {

template < typename T, typename Pointer, typename Reference >
class random_access_iterator {

public:
	typedef std::random_access_iterator_tag					iterator_category;
	typedef Pointer											pointer;
	typedef Reference										reference;
	typedef std::ptrdiff_t									difference_type;
	typedef random_access_iterator<T, Pointer, Reference>	iterator;
	typedef random_access_iterator<T, const T*, const T&> 	if_const;
	typedef T												value_type;

public:
	// X a; X b(a); b = a; ~X()
	random_access_iterator(): _ptr(NULL) {}
	explicit random_access_iterator(pointer ptr) : _ptr(ptr) {}
	random_access_iterator(const random_access_iterator& x) { *this = x; }
	random_access_iterator& operator= (const random_access_iterator& x) {
		if (this != &x)
			_ptr = x._ptr;
		return *this;
	}
	~random_access_iterator() = default;

	// const convert
	operator if_const() const { return if_const(_ptr); }

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
	iterator operator- (const difference_type& x) const { return iterator(_ptr - x); }
	difference_type operator-(const iterator& rhs) const { return _ptr - rhs._ptr;	}
	friend iterator operator+ (int n, iterator itr) { return iterator(itr._ptr + n); }
	iterator operator+ (const int n) const { return iterator(_ptr + n); }

	// a < b | a > b | a <= b | a >= b
	bool operator > (const iterator& rhs) const { return _ptr > rhs._ptr; }
	bool operator < (const iterator& rhs) const { return _ptr < rhs._ptr; }
	bool operator >= (const iterator& rhs) const { return _ptr >= rhs._ptr; }
	bool operator <= (const iterator& rhs) const { return _ptr <= rhs._ptr; }

	// a += n | a -= n
	iterator& operator += (int n) { _ptr += n; return *this; }
	iterator& operator -= (int n) { _ptr -= n; return *this; }

	// a[n]
	reference operator[](const difference_type n) const { return _ptr[n]; }

protected:
	pointer _ptr;

};
}

#endif //RANDOM_ACCESS_ITERATOR_H
