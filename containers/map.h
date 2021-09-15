//
// Created by qli on 16/08/2021.
//

#ifndef FT_CONTAINERS_MAP_H
#define FT_CONTAINERS_MAP_H
#include <memory>
#include "../utils/pair.h"
#include "../utils/make_pair.h"
#include "../utils/BSTNode.h"
#include "../iterators/bidirectional_iterator.h"
#include "../iterators/reverse_iterator.h"

namespace ft {

template < 	class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<ft::pair<const Key,T> > >
class map  {

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
	typedef bidirectional_iterator<value_type>			iterator;
	typedef bidirectional_iterator<const value_type>	const_iterator;
	typedef reverse_iterator<const_iterator>			const_reverse_iterator;
	typedef reverse_iterator<iterator>					reverse_iterator;
	typedef std::ptrdiff_t								difference_type;
	typedef size_t										size_type;
	typedef BSTNode<value_type>							map_node;
	typedef BSTNode<value_type>*						map_node_pointer;

//************************ Private attributes ************************

private:
// actual tree structure
	map_node_pointer 		_root;
	map_node_pointer 		_first;
	map_node_pointer 		_last;
	size_type				_size;
	key_compare				_compare;
	allocator_type			_alloc;

//************************ value_compare ************************

public:
	class value_compare
	{
		friend class map;

	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}

	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_type& x, const value_type& y) const
		{
			return comp(x.first, y.first);
		}
	};

public:
//************************ Coplien form ************************

// empty -> Constructs an empty container, with no elements.
explicit map (const key_compare& comp = key_compare(),
			  const allocator_type& alloc = allocator_type())
			  : _root(new map_node), _first(new map_node), _last(new map_node), _size(0), _compare(comp), _alloc(alloc) {

	// setting up the initial connection between the three nodes
	_first->parent = _root;
	_last->parent = _root;

	_root->left = _first;
	_root->right = _last;

}

// range -> Constructs a container with as many elements as the range [first,last)
// *** insert(first, second)
//template <class InputIterator>
//map (InputIterator first, InputIterator last,
//	const key_compare& comp = key_compare(),
//	const allocator_type& alloc = allocator_type());

// copy -> Constructs a container with a copy of each of the elements in x.
map (const map& x) { *this = x; }

// destructor -> Destroys the container object.
// *** clear()
~map() {}

// assignation operator -> Assigns new contents to the container, replacing its current content.
// *** clear()
// *** swap()

//map& operator= (const map& x) {
//
//	this->clear();
//	this->swap(__x);
//	return *this;
//}

//************************ Iterators ************************

//-> Returns an iterator referring to the first element in the map container.
iterator begin() { return iterator(*_first); }
const_iterator begin() const { return const_iterator(*_first); }

//-> Returns an iterator referring to the past-the-end element in the map container.
iterator end() { return iterator(*_last); }
const_iterator end() const { return const_iterator(*_last); }

//-> Returns a reverse iterator pointing to the last element in the container (its reverse beginning).
reverse_iterator rbegin() { return reverse_iterator(end()); }
const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

//-> Returns a reverse iterator pointing to the theoretical element right before the first element in the map container (its reverse beginning).
reverse_iterator rend() { return reverse_iterator(begin()); }
const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }

//************************ Capacity ************************

//-> test whether container is empty
bool empty() const { return _size == 0; }

//-> Returns the number of elements in the map container.
size_type size() const { return _size; }

//-> return maximum size
size_type max_size() const { return _alloc.max_size(); }

//************************ Element access ************************

//-> If k matches the key of an element in the container, the function returns a reference to its mapped value.
// insert
//mapped_type& operator[] (const key_type& k) {

//	(*((insert(make_pair(k , mapped_type()))).first)).second;
//}

//************************ Modifier ************************

//-> insert elements

// single element
// -> increase size
// -> checks whether inserted elements has a key that already exists
// -> The single element versions (1) return a pair, with its member pair::first set to an iterator pointing to either the newly inserted element or to the element with an equivalent key in the map. The pair::second element in the pair is set to true if a new element was inserted or false if an equivalent key already existed.


ft::pair<iterator,bool> insert_value(map_node *&node, const value_type &val)
{
	if (!node)
	{
		node = new map_node(val);
		_size++;
		return ft::make_pair(iterator(node), true);
	}
	else
	{
		if (val < node->value)
			insert_value(node->left, val);
		else if (val > node->value)
			insert_value(node->right, val);
	}
	return ft::make_pair(iterator(node), false);
}

ft::pair<iterator,bool> insert (const value_type& val)
{
	return insert_value(_root, val);
}

// with hint
// -> it is only a hint and does not force the new element to be inserted at that position
// -> return an iterator pointing to either the newly inserted element or to the element that already had an equivalent key in the map.

//iterator insert (iterator position, const value_type& val);

// range
// -> Copies of the elements in the range [first,last) are inserted in the container (include first but not last).
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

//-> count elements with a specific key (only 1 or 0)
size_type count (const key_type& k) const;

//-> return iterator to lower bound
iterator lower_bound (const key_type& k);
//const_iterator lower_bound (const key_type& k) const;

//-> return iterator to upper bound
//iterator upper_bound (const key_type& k);
//const_iterator upper_bound (const key_type& k) const;

//-> get range of equal elements (returns a single element at most)
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

map_node* search(map_node* root, value_type val)
{
	if (!root || root->value == val)
		return root;
	if (root->value < val)
		return search(root->right, val);
	return search(root->left, val);
}

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
