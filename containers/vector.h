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
	//typedef	existing_type						new_type_name
	typedef T										value_type;
	typedef Alloc									allocator_type;
	typedef value_type&								reference;
	typedef const value_type&						const_reference;
	typedef value_type*								pointer;
	typedef const value_type*						const_pointer;
	typedef std::random_access_iterator_tag			iterator;
	typedef const std::random_access_iterator_tag	const_iterator;
	typedef std::reverse_iterator<iterator>			reverse_iterator;
	typedef std::reverse_iterator<const_iterator>	const_reverse_iterator;
	typedef ptrdiff_t								difference_type;
	typedef size_t									size_type;

public:

//-> coplien form

	//** default constructor
	explicit vector (const allocator_type& alloc = allocator_type());

	explicit vector (size_type n, const value_type& val = value_type(),const allocator_type& alloc = allocator_type());

	template <class InputIterator>	vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());

	//** copy constructor
	vector (const vector& x);

	//** default destructor
	~vector();

	//** assignation operator
	vector& operator= (const vector& x);

//-> member functions

	//** assign (assign new contents to the vector)

	template <class InputIterator> void assign (InputIterator first, InputIterator last);
	void assign (size_type n, const value_type& val);

	//** at (returns a reference to the element at position n in the vector)

	reference at (size_type n);
	const_reference at (size_type n) const;

	//** back (returns a reference to the last element in the vector)
	reference back();
	const_reference back() const;

	//** begin (returns an iterator pointing to the first element in the vector)
	iterator begin();
	const_iterator begin() const;

	//** capacity (return the size of the storage space)
	size_type capacity() const;

	//** clear (remove all elements from the vector)
	void clear();

	//** empty (test whether the vector is empty)
	bool empty() const;

	//** end (return iterator to end)
	iterator end();
	const_iterator end() const;

	//** erase (erase element(s) from the vector)
	iterator erase (iterator position);
	iterator erase (iterator first, iterator last);

	//** front (return a reference to the first element)
	reference front();
	const_reference front() const;

	//** insert (insert new elements to the vector)
	iterator insert (iterator position, const value_type& val);

	void insert (iterator position, size_type n, const value_type& val);

	template <class InputIterator> void insert (iterator position, InputIterator first, InputIterator last);

	//** max_size (return the max number of elements)
	// to understand the difference between capacity and max_size
	size_type max_size() const;

	//** operator[] (return a reference to the element at position n)
	reference operator[] (size_type n);
	const_reference operator[] (size_type n) const;

	//** pop_back (removes the last element in the vector)
	void pop_back();

	//** push_back (add a new element at the end of the vector)
	void push_back (const value_type& val);

	//** rbegin (return a reverse iterator pointing to the last element in the vector)
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;

	//** rend (return a reverse iterator pointing to the theoretical element preceding the first element in the vector)
	reverse_iterator rend();
	const_reverse_iterator rend() const;

	//** reverse (request that the vector capacity be at least enough to contain n elements)
	void reserve (size_type n);

	//** resize (resize the container so that it contains n elements)
	void resize (size_type n, value_type val = value_type());

	//** size (return the number of elements in the vector)
	size_type size() const;

	//** swap (exchange the content of the container by the content of another container)
	void swap (vector& x);

private:
	size_type				_size; // the number of elements a vector contains
	size_type				_capacity; // the maximum number of elements a vector can contain
	const allocator_type& 	_alloc;
	const value_type&		_value_type;
};
}

#endif //FT_CONTAINERS_VECTOR_H
