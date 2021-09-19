//
// Created by qli on 16/08/2021.
//

#ifndef FT_CONTAINERS_MAP_H
#define FT_CONTAINERS_MAP_H
#include <memory>
#include "../utils/pair.h"
#include "../utils/BSTNode.h"
#include "../iterators/bidirectional_iterator.h"
#include "../iterators/reverse_iterator.h"

namespace ft {

template < 	class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<pair<const Key,T> > >
class map {

public:
	typedef Key 										key_type;
	typedef T 											mapped_type;
	typedef ft::pair<const key_type, mapped_type> 		value_type;
	typedef Compare 									key_compare;
	typedef Alloc 										allocator_type;
	typedef typename allocator_type::reference 			reference;
	typedef typename allocator_type::const_reference 	const_reference;
	typedef typename allocator_type::pointer 			pointer;
	typedef typename allocator_type::const_pointer 		const_pointer;
	typedef bidirectional_iterator<value_type, pointer, reference> iterator;
	typedef bidirectional_iterator<value_type, const_pointer, const_reference> const_iterator;
	typedef reverse_iterator<const_iterator> 			const_reverse_iterator;
	typedef reverse_iterator<iterator> 					reverse_iterator;
	typedef std::ptrdiff_t 								difference_type;
	typedef size_t 										size_type;
	typedef BSTNode<value_type> 						map_node;

//************************ Private attributes ************************

private:
// actual tree structure
	map_node 		*_root;
	map_node 		*_begin;
	map_node 		*_end;
	size_type 		_size;
	key_compare 	_compare;
	allocator_type 	_alloc;

//************************ value_compare ************************

public:
	// follow the definitions from official documentation
	class value_compare {
		friend class map;

	protected:
		Compare comp;

		value_compare(Compare c) : comp(c) {}

	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;

		bool operator()(const value_type &x, const value_type &y) const {
			return comp(x.first, y.first);
		}
	};

//************************ Private helpers ************************
public:

	void inorder(map_node *node) {
		if (node && node != _begin && node != _end) {
			inorder(node->left);
			std::cout << node->value.first << "->" << node->value.second << std::endl;
			inorder(node->right);
		}
	}

	void clearTree() {
		if (_root) {
			clearTree(_root->left);
			clearTree(_root->right);
			delete _root;
			_root = NULL;
		}
	}

	map_node *getRoot() {
		map_node *copy = _root;

		return copy;
	}

	map_node *findLeftestNode(map_node *node) {
		map_node *current = node;
		while (current && current->left && current->left != _begin)
			current = current->left;
		return current;
	}

	map_node *findRightestNode(map_node *node) {
		map_node *current = node;
		while (current && current->right && current->right != _end)
			current = current->right;
		return current;
	}

	void setupTreeBeginEnd() {
		map_node *leftest = findLeftestNode(_root);
		map_node *rightest = findRightestNode(_root);

		_begin->parent = leftest;
		leftest->left = _begin;

		_end->parent = rightest;
		rightest->right = _end;
	}

public:
//************************ Coplien form ************************

// empty -> Constructs an empty container, with no elements.
	explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _root(new map_node), _begin(new map_node), _end(new map_node), _size(0), _compare(comp), _alloc(alloc) {

		// begin & end are empty nodes that signals the boundaries of the tree
//	_begin->parent = _root;
//	_end->parent = _root;
//
//	_root->left = _begin;
//	_root->right = _end;

		setupTreeBeginEnd();

	}

// range -> Constructs a container with as many elements as the range [first,last)
// *** insert(first, second)
	template<class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _root(new map_node), _begin(new map_node), _end(new map_node), _size(0), _compare(comp), _alloc(alloc) {
		setupTreeBeginEnd();
		insert(first, last);
	}

// copy -> Constructs a container with a copy of each of the elements in x.
	map(const map &x) { *this = x; }

// destructor -> Destroys the container object.
// *** clear()
	~map() {}

// assigment operator -> Assigns new contents to the container, replacing its current content.
//map& operator= (const map& x) {
//
//	this->clear();
//	this->swap(x);
//	return *this;
//}

//************************ Iterators ************************

//-> Returns an iterator referring to the first element in the map container.
	iterator begin() { return iterator(_begin->parent); }

	const_iterator begin() const { return const_iterator(_begin->parent); }

//-> Returns an iterator referring to the past-the-end element in the map container.
	iterator end() { return iterator(_end); }

	const_iterator end() const { return const_iterator(_end); }

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

	mapped_type &operator[](const key_type &k) {
		return (*((insert(make_pair(k, mapped_type()))).first)).second;
	}

//************************ Modifier ************************

//-> insert elements

// single
// !!! need to add balancing option
	ft::pair<iterator, bool> insert(const value_type &val) {
		map_node *newNode = new map_node(val);
		map_node *tmp = _root;
		map_node *p = NULL;

		// empty root
		if (empty()) {
			_root = newNode;
			_size++;
			setupTreeBeginEnd();
			return ft::make_pair(iterator(_root), true);
		}
		// start traversing from root downward the path to search where the new node to be inserted
		while (tmp && tmp != _begin && tmp != _end) {
			p = tmp;
			// if the value is found, return false
			if (val.first == p->value.first) {
				delete newNode;
				return ft::make_pair(iterator(p), false);
			} else if (value_comp()(val, p->value))
				tmp = tmp->left;
			else if (value_comp()(p->value, val))
				tmp = tmp->right;
		}
		// insert left if the key value is smaller than the parent
		if (value_comp()(val, p->value)) {
			p->left = newNode;
			newNode->parent = p;
			_size++;
			setupTreeBeginEnd();
		}
			// insert right if the key value is bigger than the parent
		else if (value_comp()(p->value, val)) {
			p->right = newNode;
			newNode->parent = p;
			_size++;
			setupTreeBeginEnd();
		}
		return ft::make_pair(iterator(newNode), true);

	}

// with hint
// -> it is only a hint and does not force the new element to be inserted at that position
// -> return an iterator pointing to either the newly inserted element or to the element that already had an equivalent key in the map.

	iterator insert(iterator position, const value_type &val) {
		(void) position;
		return insert(val).first;
	}

// range
// -> Copies of the elements in the range [first,last) are inserted in the container (include first but not last).
	template<class InputIterator>
	void insert(InputIterator first, InputIterator last, typename iterator_traits<InputIterator>::type * = 0) {
		while (first != last) {
			insert(*first);
			first++;
		}
	}

	map_node *searchKey(const key_type &key) {
		map_node *tmp = _root;
		while (tmp && tmp != _begin && tmp != _end) {
			if (key == tmp->value.first)
			{
				std::cout << "searched & found: " << tmp->value.first << "->" << tmp->value.second << std::endl;
				return tmp;
			}
			else if (_compare(key, tmp->value.first))
				tmp = tmp->left;
			else if (_compare(tmp->value.first, key))
				tmp = tmp->right;
		}
		std::cout << "does not find node" << std::endl;
		return NULL;
	}

	bool nodeIsLeaf(map_node *node) {
		if ((node->left == NULL || node->left == _begin) && (node->right == NULL || node->right == _end))
			return true;
		else
			return false;
	}

	bool nodeWithOneLeftLeaf(map_node *node) {
		if (node->left && (node->right == NULL || node->right == _end))
			return true;
		return false;
	}

	bool nodeWithOneRightLeaf(map_node *node) {
		if (node->right && (node->left == NULL || node->left == _begin))
			return true;
		return false;
	}

	bool nodeWithTwoLeaves(map_node *node) {
		if (node->left && node->left != _begin && node->right && node->right != _end)
			return true;
		else
			return false;
	}

	void removeRoot(map_node *root)	{
		std::cout << "removeRoot" << std::endl;
		if (size() == 1) {
			delete _root;
			_size--;
		}
		else {
			if (nodeWithOneRightLeaf(root)) {
				map_node *tmp = _root;
				_root = _root->right;
				_root->parent = NULL;
				delete tmp;
				_size--;
			}
			else if (nodeWithOneLeftLeaf(root)) {
				map_node *tmp = _root;
				_root = _root->left;
				_root->parent = NULL;
				delete tmp;
				_size--;
			}
			else if (nodeWithTwoLeaves(root)) {
				std::cout << "root with two leaves" << std::endl;

			}
		}
	}

	void removeLeaf(map_node *node) {
		std::cout << "removeLeaf" << std::endl;
		if (node->parent->left == node)
			node->parent->left = NULL;
		else if (node->parent->right == node)
			node->parent->right = NULL;
		delete node;
		_size--;
	}

	void removeNodeWithOneLeftChild(map_node *node) {
		std::cout << "removeNodeWithOneLeftChild" << std::endl;
		if (node->parent->left == node)
			node->parent->left = node->left;
		else if (node->parent->right == node)
			node->parent->right = node->left;
		node->left->parent = node->parent;
		delete node;
		_size--;
	}

	void removeNodeWithOneRightChild(map_node *node) {
		std::cout << "removeNodeWithOneRightChild" << std::endl;
		if (node->parent->right == node)
			node->parent->right = node->right;
		else if (node->parent->left == node)
			node->parent->left = node->right;
		node->right->parent = node->parent;
		delete node;
		_size--;
	}

	void removeNodeWithTwoChildren(map_node *node) {
		std::cout << "removeNodeWithTwoChildren" << std::endl;
		(void)node;
		return ;
	}

	void erase_node(map_node *node)	{
		if (node == _root)
			removeRoot(node);
		else if (nodeIsLeaf(node))
			removeLeaf(node);
		else if (nodeWithOneLeftLeaf(node))
			removeNodeWithOneLeftChild(node);
		else if (nodeWithOneRightLeaf(node))
			removeNodeWithOneRightChild(node);
		else if (nodeWithTwoLeaves(node))
			removeNodeWithTwoChildren(node);
	}

//-> erase element
//	void erase(iterator position) {}

// return how many elements are removed
	size_type erase (const key_type& k) {
		map_node *node = searchKey(k);
		if (!node)
			return 0;
		erase_node(node);
		setupTreeBeginEnd();
		return 1;
	}


//void erase (iterator first, iterator last);

//-> swap content
	void swap(map &x);

//-> clear content
	void clear();

//************************ Observers ************************
//-> return key comparison object
	key_compare key_comp() const { return _compare; }

//-> return value compare object
	value_compare value_comp() const { return value_compare(_compare); }

//************************ Operations ************************

//-> searches the container for an element with a key equivalent to k and returns an iterator to it if found, otherwise it returns an iterator to map::end.
	iterator find(const key_type &k) {
	for (iterator begin_itr = begin(); begin_itr != end(); ++begin_itr) {
		if (begin_itr->first == k)
			return begin_itr;
	}
	return end();
}

	const_iterator find (const key_type& k) const {
	for (const_iterator begin_itr = begin(); begin_itr != end(); ++begin_itr) {
		if (begin_itr->first == k)
			return begin_itr;
	}
	return end();
}

//-> count elements with a specific key (only 1 or 0)
	size_type count (const key_type& k) const {
		if (find(k) != end())
			return 1;
		else
			return 0;
	}

//-> lower_bound: returns an iterator pointing to the first element in the container whose key is not considered to go before k (i.e., either it is equivalent or goes after).
	iterator lower_bound (const key_type& k) {
		iterator begin_itr = begin();
		while (begin_itr != end()) {
			if (!_compare(begin_itr->first, k))
				break;
			++begin_itr;
		}
		return begin_itr;
	}

	const_iterator lower_bound (const key_type& k) const {
		const_iterator begin_itr = begin();
		while (begin_itr != end()) {
			if (!_compare(begin_itr->first, k))
				break;
			++begin_itr;
		}
		return begin_itr;
	}

//-> upper_bound: returns an iterator pointing to the first element in the container whose key is considered to go after k.
	iterator upper_bound (const key_type& k) {
		iterator begin_itr = begin();
		while (begin_itr != end()) {
			if (_compare(k, begin_itr->first))
				break;
			++begin_itr;
		}
		return begin_itr;
	}

	const_iterator upper_bound (const key_type& k) const {
		const_iterator begin_itr = begin();
		while (begin_itr != end()) {
			if (_compare(k, begin_itr->first))
				break;
			++begin_itr;
		}
		return begin_itr;
	}

//-> get range of equal elements (returns a single element at most): returns the bounds of a range that includes all the elements in the container which have a key equivalent to k.

	pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
		const_iterator lower = lower_bound(k);
		const_iterator upper = upper_bound(k);
		return make_pair(lower, upper);
	}

	pair<iterator,iterator>             equal_range (const key_type& k) {
		iterator lower = lower_bound(k);
		iterator upper = upper_bound(k);
		return make_pair(lower, upper);
	}


//************************ get_allocator ************************
//-> get allocator
allocator_type get_allocator() const { return _alloc; }

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
