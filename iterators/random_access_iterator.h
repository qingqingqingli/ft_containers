//
// Created by qli on 12/03/2021.
//

#ifndef RANDOM_ACCESS_ITERATOR_H
#define RANDOM_ACCESS_ITERATOR_H

namespace ft {

template < class T >
class random_access_iterator {

public:
	typedef T										value_type;
	typedef T&										reference;
	typedef const T&								const_reference;
	typedef T*										pointer;
	typedef const T*								const_pointer;
	typedef std::ptrdiff_t								difference_type;
	typedef size_t									size_type;
	typedef random_access_iterator<T> 				iterator;
	typedef const random_access_iterator<T> 	const_iterator;

public:
	// X a; X b(a); b = a; [Finished]
	random_access_iterator(pointer ptr = NULL) : _ptr(ptr) {}
	random_access_iterator(const random_access_iterator& x) { *this = x; }
	random_access_iterator& operator= (const random_access_iterator& x) {
		if (this != &x)
			this->_ptr = x._ptr;
		return *this;
	}
	~random_access_iterator() {}

	// a==b; a!= b; [Finished]
	bool operator== (const iterator& rhs) const
	{ return this->_ptr == rhs._ptr; }

	bool operator!= (const iterator& rhs) const
	{ return this->_ptr != rhs._ptr; }

	// dereference: *a, a->m, *a = t
	reference operator* () { return *this->_ptr; }
	pointer operator-> () { return this->_ptr; }

	//++a; a++; *a++;
	iterator& operator++ () { ++this->_ptr; return *this; }

	iterator operator++ (int) {
		iterator tmp = *this;
		++(this->_ptr);
		return tmp;
	}

	//--a; a--; *a--;
	iterator& operator-- () { --this->_ptr; return *this; }

	iterator operator-- (int) {
		iterator tmp = *this;
		--(this->_ptr);
		return tmp;
	}

	// a + n | n + a | a - n | a - b
	iterator operator- (const difference_type& x) {
		iterator tmp = this->_ptr - x;
		return tmp;
	}

	iterator operator+ (const difference_type& x) {
		iterator tmp = this->_ptr + x;
		return tmp;
	}

	// a < b | a > b | a <= b | a >= b [Finished]
	bool operator > (const iterator& rhs) const
	{ return this->_ptr > rhs._ptr; }

	bool operator < (const iterator& rhs) const
	{ return this->_ptr < rhs._ptr; }

	bool operator >= (const iterator& rhs) const
	{ return this->_ptr >= rhs._ptr; }

	bool operator <= (const iterator& rhs) const
	{ return this->_ptr <= rhs._ptr; }

	// a += n | a -= n [Finished]
	iterator& operator += (difference_type& n) { this->_ptr += n; return *this; }
	iterator& operator -= (difference_type& n) { this->_ptr -= n; return *this; }

	// a[n]


private:
	pointer _ptr;

};
}

#endif //RANDOM_ACCESS_ITERATOR_H
