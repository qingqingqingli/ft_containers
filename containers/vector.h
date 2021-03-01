//
// Created by qli on 25/02/2021.
//

#ifndef FT_CONTAINERS_VECTOR_H
#define FT_CONTAINERS_VECTOR_H
#include <iostream>

namespace ft
{

template < class T, class Alloc = std::allocator<T> >
class vector {

//nested member type
public:
	//** nested type names
	typedef T					value_type;
	typedef Alloc				allocator_type;
	typedef value_type&			reference;
	typedef const value_type&	const_reference;
	typedef value_type*			pointer;
	typedef const value_type*	const_pointer;
	typedef ptrdiff_t			difference_type;
	typedef size_t				size_type;

public:
	//** coplien form
	explicit vector(const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _value_type(0){
	}

	explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _value_type(val), _alloc(alloc){
	}
//
//	template <class InputIterator>
//	vector (InputIterator first, InputIterator last,
//			const allocator_type& alloc = allocator_type());

//	vector (const vector& x) {
//		*this = x;
//	}
//
//	~vector() {
//		delete this->_array;
//	}

//	vector& operator= (const vector& x) {
//		if (this != x)
//		{
//			this->_size = x.size();
//			this->_capacity = x.capacity();
//			this->_array = x._array;
//		}
//		return this;
//	}

	//-> member functions

	size_type capacity() const {
		return this->_capacity;
	}

	size_type size() const {
		return this->_size;

	//** iterators
	// vector::beging()
	// vector::end()

	//** modifiers
	// vector::push_back()
	// vector::insert()
	// vector::pop_back()
	// vector::erase()
	// vector::clear()
	}

private:
	size_type				_size;
	size_type				_capacity;
	const allocator_type& 	_alloc;
	const value_type&		_value_type;
};
}

#endif //FT_CONTAINERS_VECTOR_H
