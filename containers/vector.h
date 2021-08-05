//
// Created by qli on 25/02/2021.
//

#ifndef FT_CONTAINERS_VECTOR_H
# define FT_CONTAINERS_VECTOR_H
# include <iostream>
# include "../iterators/random_access_iterator.h"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {

public:
	typedef T										value_type;
	typedef Alloc									allocator_type;
	typedef T&										reference;
	typedef const T&								const_reference;
	typedef T*										pointer;
	typedef const T*								const_pointer;
	typedef random_access_iterator<T> 				iterator;
	typedef const random_access_iterator<T> 		const_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;

private:
	size_type				_size;
	size_type				_capacity;
	allocator_type		 	_alloc;
	pointer 				_array;

// helper function
private:
	void reallocation(size_type n)
	{
		value_type *new_array = new value_type [n];
		for (size_type i = 0; i < _size; i++)
			new_array[i] = _array[i];
		delete [] _array;
		_array = new_array;
		_capacity = n;
	}

	void reallocation_new_value(size_type n, value_type val)
	{
		value_type *new_array = new value_type [n];
		_capacity = n;
		for (size_type i = 0; i < _size; i++)
			new_array[i] = val;
		delete [] _array;
		_array = new_array;
	}

	void copy_vector_value(size_type n, value_type val)
	{
		while (_size < n)
		{
			_array[_size] = val;
			_size++;
		}
	}

	const 	std::string out_of_range_msg(size_type n) const
	{
		std::stringstream sstm;
		sstm << "vector::_M_range_check: __n (which is " << n << ") this->size() (which is " << _size << ")" << std::endl;
		std::string error_msg = sstm.str();
		return error_msg;
	}

public:
//-> Coplien form
	explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _array(NULL) {}

	explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
	{
		_array = new value_type [n];
		for (size_type i = 0; i < _size; i++)
			_array[i] = val;
	}

//	template <class InputIterator>
//	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc) {
//		for (iterator tmp = first; tmp != last; ++tmp)
//		{
//			_size++;
//			_capacity++;
//		}
//		_array = new value_type [_size];
//		for (iterator tmp = first; tmp != last; ++tmp)
//			_array = *tmp;
//	}

	vector& operator= (const vector& x) {
		if (this != &x)
		{
			_size = x._size;
			_capacity = x._capacity;
			_alloc = x._alloc;
			_array = new value_type [_size];
			for (size_type i = 0; i < _size; i++)
				_array[i] = x._array[i];
		}
		return *this;
	}

	// This one needs to be removed
	vector (const vector& x){ *this = x; }
	~vector() { delete [] _array; }

//-> Iterators

	iterator begin() { return iterator(&_array[0]); }

//	const_iterator begin() const;

	iterator end() { return iterator(&_array[_size]); }
//	const_iterator end() const;

	//** [iterator] rbegin (return a reverse iterator pointing to the last element in the vector)
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;

	//** [iterator] rend (return a reverse iterator pointing to the theoretical element preceding the first element in the vector)
	reverse_iterator rend();
	const_reverse_iterator rend() const;

//-> Capacity

	size_type size() const { return _size; }
	size_type max_size() const { return _alloc.max_size(); }
	size_type capacity() const { return _capacity; }

	void resize (size_type n, value_type val = value_type()) {
		if (n < _size)
			_size = n;
		else if (n > _capacity && n <= _capacity * 2) {
			reallocation(_capacity * 2);
			copy_vector_value(n, val);
		}
		else if (n > _capacity * 2) {
			reallocation(n);
			copy_vector_value(n, val);
		}
	}

	bool empty() const {
		if (!_size)
			return true;
		else
			return false;
	}

	void reserve (size_type n) {
		if (n > this->max_size())
			throw std::length_error("vector::reserve");
		if (n > _capacity)
			reallocation(n);
	}

//-> Element access

	reference operator[] (size_type n) {
		reference elem_ref = *(_array + n);
		return elem_ref;
	}

	const_reference operator[] (size_type n) const {
		const_reference elem_ref = *(_array + n);
		return elem_ref;
	}

	reference at (size_type n) {
		if (n > _size - 1)
			throw std::out_of_range(out_of_range_msg(n));
		reference elem_ref = *(_array + n);
		return elem_ref;
	}

	const_reference at (size_type n) const {
		if (n > _size - 1)
			throw std::out_of_range(out_of_range_msg(n));
		const_reference elem_ref = *(_array + n);
		return elem_ref;
	}

	reference front() {
		reference front_ref = _array[0];
		return front_ref;
	}

	const_reference front() const {
		const_reference front_ref = _array[0];
		return front_ref;
	}

	reference back() {
		reference back_ref = _array[_size - 1];
		return back_ref;
	}

	const_reference back() const {
		const_reference const_back_ref = _array[_size - 1];
		return const_back_ref;
	}

//-> Modifier

//	template <class InputIterator>
//	void assign (InputIterator first, InputIterator last);

	void assign (size_type n, const value_type& val) {
		_size = n;
		if (n <= _capacity)
			for (size_type i = 0; i < _size; i++)
				_array[i] = val;
		else
			reallocation_new_value(n, val);
	}

	void push_back (const value_type& val) {
		if (_size + 1 > _capacity)
		{
			if (!_size)
				reallocation(1);
			else
				reallocation(_size * 2);
		}
		_array[_size] = val;
		_size += 1;
	}

	void pop_back() { _size -= 1; }

	iterator insert (iterator position, const value_type& val);

	void insert (iterator position, size_type n, const value_type& val);

	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last);

	iterator erase (iterator position);

	iterator erase (iterator first, iterator last);

	void swap (vector& x) {

		value_type *array_swap = x._array;
		size_type size_swap = x._size;
		size_type capacity_swap = x._capacity;
		allocator_type alloc_swap = x._alloc;

		x._array = _array;
		x._size = _size;
		x._capacity = _capacity;
		x._alloc = _alloc;

		_array = array_swap;
		_size = size_swap;
		_capacity = capacity_swap;
		_alloc = alloc_swap;
	}

	void clear() { _size = 0; }

};
}

#endif //FT_CONTAINERS_VECTOR_H
