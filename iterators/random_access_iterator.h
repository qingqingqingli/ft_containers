//
// Created by qli on 12/03/2021.
//

#ifndef RANDOM_ACCESS_ITERATOR_H
#define RANDOM_ACCESS_ITERATOR_H

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
	typedef ft::random_access_iterator<T> 		iterator;
	typedef const ft::random_access_iterator<T> const_iterator;

public:
	// X a; X b(a); b = a;
	random_access_iterator(pointer ptr) : _ptr(ptr) {}
	~random_access_iterator() {}

	// a==b; a!= b;
	friend bool operator==(const iterator& a, const iterator& b)
	{ return a._ptr == b._ptr; }

	friend bool operator!=(const iterator& a, const iterator& b)
	{ return a._ptr != b._ptr; }

	// dereference: *a, a->m
	pointer operator->() { return _ptr; }
	reference operator*() { return *_ptr; }

	// for mutable iterators: *a = t

	//++a; a++; *a++;
	iterator& operator++() {_ptr++; return *this; }

	iterator operator++(T) {
		iterator tmp = *this;
		++(*this);
		return tmp;
	}

	//--a; a--; *a--;
	iterator& operator--() {_ptr--; return *this; }

	iterator operator--(T) {
		iterator tmp = *this;
		--(*this);
		return tmp;
	}

	// a + n | n + a | a - n | a - b

	// a < b | b < a | a <= b | a >= b

	// a += n | a -= n

	// a[n]

private:
	pointer _ptr;

};
}

#endif //RANDOM_ACCESS_ITERATOR_H
