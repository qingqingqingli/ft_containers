//
// Created by qli on 16/08/2021.
//

#ifndef FT_CONTAINERS_MAP_H
#define FT_CONTAINERS_MAP_H
#include <memory>
#include "../iterators/value_compare.h"

namespace ft {

template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key,T> > >
class map {

public:
	typedef Key										key_type;
	typedef T										mapped_type;
	typedef std::pair<const key_type, mapped_type>	value_type;
	typedef Compare									key_compare;
	typedef ft::value_compare<Key,T,Compare,Alloc>	value_compare; // Nested function class to compare elements
	typedef Alloc									allocator_type;
	typedef allocator_type::reference				reference;
	typedef allocator_type::const_reference			const_reference;
	typedef allocator_type::pointer					pointer;
	typedef allocator_type::const_pointer			const_pointer;
	typedef directional_iterator<value_type>		iterator;
	typedef directional_iterator<const value_type>	const_iterator;
	typedef reverse_iterator<iterator>				reverse_iterator;
	typedef reverse_iterator<const_iterator>		const_reverse_iterator;
	typedef std::ptrdiff_t							difference_type;
	typedef size_t									size_type;

//************************ Private attributes ************************

public:
//************************ Coplien form ************************

// empty
explicit map (const key_compare& comp = key_compare(),
			  const allocator_type& alloc = allocator_type());

//range
template <class InputIterator>
map (InputIterator first, InputIterator last,
	const key_compare& comp = key_compare(),
	const allocator_type& alloc = allocator_type());

// copy
map (const map& x);

// destructor
~map();

// assignation operator
map& operator= (const map& x);

//************************ Iterators ************************

iterator begin();
const_iterator begin() const;

iterator end();
const_iterator end() const;

reverse_iterator rbegin();
const_reverse_iterator rbegin() const;

everse_iterator rend();
const_reverse_iterator rend() const;

//************************ Capacity ************************

bool empty() const;

size_type size() const;

size_type max_size() const;

//************************ Element access ************************

mapped_type& operator[] (const key_type& k);

//************************ Modifier ************************

// single element
pair<iterator,bool> insert (const value_type& val);

// with hint
iterator insert (iterator position, const value_type& val);

// range
template <class InputIterator>
void insert (InputIterator first, InputIterator last);

// erase
void erase (iterator position);
size_type erase (const key_type& k);
void erase (iterator first, iterator last);

void swap (map& x);

void clear();

//************************ Observers ************************
key_compare key_comp() const;

value_compare value_comp() const;

//************************ Operations ************************
iterator find (const key_type& k);
const_iterator find (const key_type& k) const;

size_type count (const key_type& k) const;

iterator lower_bound (const key_type& k);
const_iterator lower_bound (const key_type& k) const;

iterator upper_bound (const key_type& k);
const_iterator upper_bound (const key_type& k) const;

pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
pair<iterator,iterator>             equal_range (const key_type& k);


//************************ get_allocator ************************
allocator_type get_allocator() const;
};

//*************** Non-member function overloads ***************

template <class Key, class T, class Compare, class Alloc>
bool operator== ( const map<Key,T,Compare,Alloc>& lhs,
				const map<Key,T,Compare,Alloc>& rhs );

template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
				const map<Key,T,Compare,Alloc>& rhs );

template <class Key, class T, class Compare, class Alloc>
bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
				const map<Key,T,Compare,Alloc>& rhs );

template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
				const map<Key,T,Compare,Alloc>& rhs );

template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
						  const map<Key,T,Compare,Alloc>& rhs );

template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
				const map<Key,T,Compare,Alloc>& rhs );

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y);

}


#endif //FT_CONTAINERS_MAP_H