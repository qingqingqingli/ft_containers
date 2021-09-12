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
			class Alloc = std::allocator<ft::pair<const Key,T> > >
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
	typedef BSTNode<T>								map_node;
	typedef BSTNode<T>*								map_node_pointer;

//************************ Private attributes ************************

private:
// actual tree structure
	map_node_pointer 		_root;
	map_node_pointer 		_first;
	map_node_pointer 		_last;
	size_type		_size;
	key_compare		_compare;
	allocator_type	_alloc;

//************************ value_compare ************************

// update this prototype against the official documentation
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
			  const allocator_type& alloc = allocator_type()) : _root(new map_node), _first(new map_node), _last(new map_node), _size(0), _compare(comp), _alloc(alloc) {}

//range
//template <class InputIterator>
//map (InputIterator first, InputIterator last,
//	const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());

// copy
map (const map& x) { *this = x; }

// destructor
~map() {}

// assignation operator
map& operator= (const map& x) {

	// official implementation
//	this->clear();
//	this->swap(__x);
//	return *this;
}

//************************ Iterators ************************

//-> return iterator to beginning
//iterator begin();
//const_iterator begin() const;

//-> return iterator to end
//iterator end();
//const_iterator end() const;

//-> return reverse iterator to reverse beginning
//reverse_iterator rbegin();
//const_reverse_iterator rbegin() const;

//-> return reverse iterator to reverse end
//everse_iterator rend();
//const_reverse_iterator rend() const;

//************************ Capacity ************************

//-> test whether container is empty
bool empty() const {}

//-> return container size
size_type size() const {}

//-> return maximum size
size_type max_size() const { return _alloc.max_size(); }

//************************ Element access ************************

//-> access element
mapped_type& operator[] (const key_type& k);

//************************ Modifier ************************

//-> insert elements

// single element
//pair<iterator,bool> insert (const value_type& val);

// with hint
//iterator insert (iterator position, const value_type& val);

// range
//template <class InputIterator>
//void insert (InputIterator first, InputIterator last);

//-> erase element
//void erase (iterator position);
//size_type erase (const key_type& k);
//void erase (iterator first, iterator last);

//-> swap content
void swap (map& x);

//-> clear content
void clear();

//************************ Observers ************************
//-> return key comparison object
key_compare key_comp() const;

//-> return value compare object
//value_compare value_comp() const;

//************************ Operations ************************

//-> get iterator to element
//iterator find (const key_type& k);
//const_iterator find (const key_type& k) const;

//-> count elements with a specific key
size_type count (const key_type& k) const;

//-> return iterator to lower bound
//iterator lower_bound (const key_type& k);
//const_iterator lower_bound (const key_type& k) const;

//-> return iterator to upper bound
//iterator upper_bound (const key_type& k);
//const_iterator upper_bound (const key_type& k) const;

//-> get range of equal elements
//pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
//pair<iterator,iterator>             equal_range (const key_type& k);


//************************ get_allocator ************************
//-> get allocator
allocator_type get_allocator() const { return _alloc; }

//************************ private helpers ************************

//size_type tree_size(BSTNode<mapped_type> *tree) const
//{
//	if (tree->root)
//		return 1 + tree_size(tree->left) + tree_size(tree->right);
//	else
//		return 0;
//}

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
