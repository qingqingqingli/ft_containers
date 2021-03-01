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
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()
	//**  ()

private:
	size_type				_size; // the number of elements a vector contains
	size_type				_capacity; // the maximum number of elements a vector can contain
	const allocator_type& 	_alloc;
	const value_type&		_value_type;
};
}

#endif //FT_CONTAINERS_VECTOR_H
