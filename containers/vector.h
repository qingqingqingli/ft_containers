//
// Created by qli on 25/02/2021.
//

#ifndef FT_CONTAINERS_VECTOR_H
# define FT_CONTAINERS_VECTOR_H
# include <iostream>
# include <sstream>
# include "../iterators/random_access_iterator.h"
# include "../iterators/reverse_iterator.h"
# include "../utils/type_traits.h"
# include "../utils/utils.h"

namespace ft {

template < class T, class Alloc = std::allocator<T> >
class vector {

public:
	typedef T												value_type;
	typedef Alloc											allocator_type;
	typedef T&												reference;
	typedef const T&										const_reference;
	typedef T*												pointer;
	typedef const T*										const_pointer;
	typedef random_access_iterator<T>		 				iterator;
	typedef random_access_iterator<const T> 				const_iterator;
	typedef reverse_iterator<const_iterator>				const_reverse_iterator;
	typedef reverse_iterator<iterator>						reverse_iterator;
	typedef std::ptrdiff_t									difference_type;
	typedef size_t											size_type;

//************************ Private attributes ************************

private:
	size_type				_size;
	size_type				_capacity;
	allocator_type		 	_alloc;
	pointer 				_array;

//************************ Private helper functions ************************

private:
	void reallocation(size_type n)
	{
		value_type *new_array = _alloc.allocate(n, &_array);
		for (size_type i = 0; i < _size; i++)
			new_array[i] = _array[i];
		_alloc.deallocate(_array, _size);
		_array = new_array;
		_capacity = n;
	}

	void reallocation_new_value(size_type n, value_type val)
	{
		value_type *new_array = _alloc.allocate(n);
		for (size_type i = 0; i < _size; i++)
			new_array[i] = val;
		_alloc.deallocate(_array, _size);
		_array = new_array;
		_capacity = n;

	}

	void copy_vector_value(size_type n, value_type val)
	{
		while (_size < n) {
			_array[_size] = val;
			_size++;
		}
	}

	std::string out_of_range_msg(size_type n) const
	{
		std::stringstream sstm;
		sstm << "vector::_M_range_check: __n (which is " << n << ") this->size() (which is " << _size << ")" << std::endl;
		return sstm.str();
	}

public:
//************************ Coplien form ************************
	// default
	explicit vector (const allocator_type& alloc = allocator_type()) : _size(0), _capacity(0), _alloc(alloc), _array(NULL) {}

	// fill
	explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _size(n), _capacity(n), _alloc(alloc)
	{
		_array = _alloc.allocate(n);
		for (size_type i = 0; i < _size; i++)
			_array[i] = val;
	}

	// range
	template <class InputIterator>
	vector (InputIterator first, InputIterator last,
			const allocator_type& alloc = allocator_type(),
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = 0) : _size(0), _capacity(0), _alloc(alloc)
	{
		_size = _capacity = last - first;
		_array = _alloc.allocate(_size);
		for (size_type i = 0; i < _size; i++)
			_array[i] = *(first + i);
	}

	// copy
	vector (const vector& x){ *this = x; }

	// destructor
	~vector() { _alloc.deallocate(_array, _size); }

	// assignation operator
	vector& operator= (const vector& x) {
		if (this != &x)
		{
			_size = x._size;
			_capacity = x._capacity;
			_alloc = x._alloc;
			_array = _alloc.allocate(_size, &x._array);
			for (size_type i = 0; i < _size; i++)
				_array[i] = x._array[i];
		}
		return *this;
	}

//************************ Iterators ************************
	iterator begin() { return iterator(&_array[0]); }
	const_iterator begin() const { return const_iterator(&_array[0]); }

	iterator end() { return iterator(&_array[_size]); }
	const_iterator end() const { return const_iterator(&_array[_size]); }

	reverse_iterator rbegin() { return reverse_iterator(end()); }
	const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

	reverse_iterator rend() { return reverse_iterator(begin()); }
	const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

//************************ Capacity ************************

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

//************************ Element access ************************

	reference operator[] (size_type n) {
		reference elem_ref = *(_array + n);
		return elem_ref;
	}

	const_reference operator[] (size_type n) const {
		const_reference elem_ref = *(_array + n);
		return elem_ref;
	}

	reference at (size_type n) {
		if (n >= _size)
			throw std::out_of_range(out_of_range_msg(n));
		reference elem_ref = *(_array + n);
		return elem_ref;
	}

	const_reference at (size_type n) const {
		if (n >= _size)
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

//************************ Modifier ************************

	// range
	template <class InputIterator>
	void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = 0) {
		size_type n = last - first;
		if (n <= _capacity)
		{
			_size = last - first;
			for (size_type i = 0; i < _size; i++)
				_array[i] = *(first + i);
		}
		else {
			value_type *new_array = _alloc.allocate(n, &_array);
			for (size_type i = 0; i < n; i++)
				new_array[i] = *(first + i);
			_alloc.deallocate(_array, _size);
			_array = new_array;
			_size = n;
			_capacity = n;
		}
	}

	// fill
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

	void pop_back()
	{
		_alloc.destroy(&_array[_size - 1]);
		_size -= 1;
	}

	// single element
	iterator insert (iterator position, const value_type& val)
	{
		size_type n = position - begin();
		if (_size == _capacity)
			reallocation(_size * 2);

		_size += 1;
		for (size_type i = _size - 1; i > n; i--)
			_array[i] = _array[i - 1];
		_array[n] = val;
		return iterator(begin() + n);
	}

	// fill
	void insert (iterator position, size_type n, const value_type& val) {
		size_type pos = position - begin();
		if (_size + n > _capacity) {
			if (n > _size)
				reallocation(_size + n);
			else
				reallocation(_capacity * 2);
		}
		_size += n;
		for (size_type i = _size - 1; i > pos + n - 1; i--)
			_array[i] = _array[i - n];
		for (size_type i = pos; i < n; i++)
			_array[i] = val;
	}

	// range
	template <class InputIterator>
	void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, int>::type* = 0)
	{
		size_type pos = position - begin();
		size_type n = last - first;
		if (_size + n > _capacity) {
			if (n > _size)
				reallocation(_size + n);
			else
				reallocation(_capacity * 2);
		}
		_size += n;
		for (size_type i = _size - 1; i > pos + n - 1; i--)
			_array[i] = _array[i - n];
		for (size_type i = pos; i < n; i++)
			_array[i] = *(first + i);
	}

	// single
	iterator erase (iterator position) {
		size_type n = position - begin();
		_size -= 1;
		for (size_type i = n; i < _size; i++)
			_array[i] = _array[i + 1];
		return iterator(begin() + n);
	}

	// range
	iterator erase (iterator first, iterator last)
	{
		size_type pos = first - begin();
		size_type n = last - first;
		_size -= n;
		for (size_type i = pos; i < _size; i++)
			_array[i] = _array[i + n];
		return iterator(begin() + pos);
	}

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

	void clear()
	{
		_alloc.destroy(_array);
		_size = 0;
	}

//************************ get_allocator ************************

	allocator_type get_allocator() const
	{
		allocator_type copy_allocator(_alloc);
		return copy_allocator;
	}
};

//*************** Non-member function overloads ***************

	// Relational operators
	template <class T, class Alloc>
	bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
	{ return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin())); }

	template <class T, class Alloc>
	bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return (! (lhs == rhs)); }

	// implement the compare function
	template <class T, class Alloc>
	bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template <class T, class Alloc>
	bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return rhs < lhs; }

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs > rhs); }

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs < rhs); }

	// swap function template
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }
}

#endif //FT_CONTAINERS_VECTOR_H
