//
// Created by qli on 16/08/2021.
//

#ifndef FT_CONTAINERS_MAP_H
#define FT_CONTAINERS_MAP_H
#include <memory>
#include "../utils/pair.h"
#include "../utils/BSTNode.h"

namespace ft {

template < 	class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<pair<const Key,T> > >
class map {

public:
	typedef Key											key_type;
	typedef T											mapped_type;
	typedef ft::pair<const key_type, mapped_type>		value_type;
	typedef Compare										key_compare;
	typedef Alloc										allocator_type;
	typedef typename allocator_type::reference			reference;
	typedef typename allocator_type::const_reference	const_reference;
	typedef typename allocator_type::pointer			pointer;
	typedef typename allocator_type::const_pointer		const_pointer;
//	typedef directional_iterator<value_type>		iterator;
//	typedef directional_iterator<const value_type>	const_iterator;
//	typedef reverse_iterator<iterator>				reverse_iterator;
//	typedef reverse_iterator<const_iterator>		const_reverse_iterator;
	typedef std::ptrdiff_t							difference_type;
	typedef size_t									size_type;

//************************ Private attributes ************************

private:
// actual tree structure
	BSTNode<Key, T> 	*_root;
	key_compare			_compare;
	allocator_type		_alloc;

//************************ value_compare ************************

public:
	class value_compare
	{
		friend class map;

	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}

	public:
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

public:
//************************ Coplien form ************************

// empty
explicit map (const key_compare& comp = key_compare(),
			  const allocator_type& alloc = allocator_type()) : _root(new BSTNode<Key, T>), _compare(comp), _alloc(alloc) {
}

//range
//template <class InputIterator>
//map (InputIterator first, InputIterator last,
//	const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());

// copy
map (const map& x) { *this = x; }

// destructor
~map()
{
	// potentially need to remove all nodes in the tree
	delete _root;
}

// assignation operator
map& operator= (const map& x) {
	if (this != &x)
	{
		// potentially need to change to deep copy
		_root = x._root;
		_compare = x._compare;
		_alloc = x._alloc;
	}
	return *this;
}

//************************ Iterators ************************

//iterator begin();
//const_iterator begin() const;
//
//iterator end();
//const_iterator end() const;
//
//reverse_iterator rbegin();
//const_reverse_iterator rbegin() const;
//
//everse_iterator rend();
//const_reverse_iterator rend() const;

//************************ Capacity ************************

bool empty() const
{
	return _root == NULL;
}

static size_type tree_size(BSTNode<Key, T> *tree)
{
	if (tree)
		return 1 + tree_size(tree->left) + tree_size(tree->right);
	else
		return 0;
}

size_type size() const
{
	return tree_size(_root);
}

size_type max_size() const;

//************************ Element access ************************

mapped_type& operator[] (const key_type& k);

//************************ Modifier ************************

// single element
//pair<iterator,bool> insert (const value_type& val);

// with hint
//iterator insert (iterator position, const value_type& val);

// range
//template <class InputIterator>
//void insert (InputIterator first, InputIterator last);

// erase
//void erase (iterator position);
size_type erase (const key_type& k);
//void erase (iterator first, iterator last);

void swap (map& x);

void clear();

//************************ Observers ************************
key_compare key_comp() const;

//value_compare value_comp() const;

//************************ Operations ************************
//iterator find (const key_type& k);
//const_iterator find (const key_type& k) const;

size_type count (const key_type& k) const;

//iterator lower_bound (const key_type& k);
//const_iterator lower_bound (const key_type& k) const;
//
//iterator upper_bound (const key_type& k);
//const_iterator upper_bound (const key_type& k) const;
//
//pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
//pair<iterator,iterator>             equal_range (const key_type& k);


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
