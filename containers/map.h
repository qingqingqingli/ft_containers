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
#include "../utils/type_traits.h"
#include "../utils/utils.h"

namespace ft {

template < 	class Key,
			class T,
			class Compare = std::less<Key>,
			class Alloc = std::allocator<pair<const Key,T> > >
class map {

public:
	typedef Key 																key_type;
	typedef T 																	mapped_type;
	typedef ft::pair<const key_type, mapped_type> 								value_type;
	typedef Compare 															key_compare;
	typedef Alloc 																allocator_type;
	typedef typename allocator_type::reference 									reference;
	typedef typename allocator_type::const_reference 							const_reference;
	typedef typename allocator_type::pointer 									pointer;
	typedef typename allocator_type::const_pointer 								const_pointer;
	typedef bidirectional_iterator<value_type, pointer, reference> 				iterator;
	typedef bidirectional_iterator<value_type, const_pointer, const_reference> 	const_iterator;
	typedef reverse_iterator<const_iterator> 									const_reverse_iterator;
	typedef reverse_iterator<iterator> 											reverse_iterator;
	typedef std::ptrdiff_t 														difference_type;
	typedef size_t 																size_type;
	typedef BSTNode<value_type> 												map_node;
	typedef typename Alloc::template rebind<map_node>::other					alloc_node;

//************************ Private attributes ************************

private:
// actual tree structure
	map_node 		*_root;
	map_node 		*_begin;
	map_node 		*_end;
	size_type 		_size;
	key_compare 	_compare;
	alloc_node 		_alloc;

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

public:
//************************ Coplien form ************************

// empty -> Constructs an empty container, with no elements.
	explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _root(new map_node), _begin(new map_node), _end(new map_node), _size(0), _compare(comp), _alloc(alloc) {
		_begin->parent = _root;
		_end->parent = _root;

		_root->left = _begin;
		_root->right = _end;
	}

// range -> Constructs a container with as many elements as the range [first,last)
	template<class InputIterator>
	map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _root(new map_node), _begin(new map_node), _end(new map_node), _size(0), _compare(comp), _alloc(alloc) {
		_begin->parent = _root;
		_end->parent = _root;

		_root->left = _begin;
		_root->right = _end;
		insert(first, last);
	}

// copy -> Constructs a container with a copy of each of the elements in x.
	map(const map &x) { *this = x; }

// destructor -> Destroys the container object.
	~map() {
		std::cout << "**** destructor ***" << std::endl;
		clearTree(_root);
	}

// assigment operator -> Assigns new contents to the container, replacing its current content.
	map& operator= (const map& x) {
		std::cout << "**** assignment ***" << std::endl;

		if (this != &x)
		{
			_root = new map_node;
			_begin = new map_node;
			_end = new map_node;
			_root->left = _begin;
			_root->right = _end;
			_begin->parent = _root;
			_end->parent = _root;
			_size = 0;
			_compare = x._compare;
			_alloc = x._alloc;
			insert(x.begin(), x.end());
		}
		return *this;
	}

//************************ Iterators ************************

//-> Returns an iterator referring to the first element in the map container.
	iterator begin() {
		if (!size())
			return end();
		else
			return iterator(_begin->parent);
	}

	const_iterator begin() const {
		if (!size())
			return end();
		else
			return const_iterator(_begin->parent);
	}

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

void removeTreeBeginEnd() {

	if (_begin->parent) {
		_begin->parent->left = NULL;
		_begin->parent = NULL;
	}
	if (_end->parent) {
		_end->parent->right = NULL;
		_end->parent = NULL;
	}
}

int max(int a, int b) {return (a > b) ? a : b; }

int height(map_node* node) {
	if (!node || node == _begin || node == _end || size() == 0)
		return 0;
	return node->height;
}

int getBalance(map_node *node) {
	if (!node || node == _begin || node == _end || size() == 0)
		return 0;
	return height(node->left) - height(node->right);
}

map_node* createNewNode(const value_type& val, map_node* parent, bool &found, map_node*& return_node) {
	map_node *newNode = new map_node(val);
	_size++;
	newNode->height = 1;
	newNode->parent = parent;
	found = false;
	return_node = newNode;
	return newNode;
}

map_node* rightRotate(map_node* node)
{
	map_node* tmp = node->left;
	if (tmp) {
		node->left = tmp->right;
		if (tmp->right && tmp->right != _end)
			tmp->right->parent = node;
		tmp->right = node;
		tmp->parent = node->parent;
		node->parent = tmp;
		if (tmp->parent && value_comp()(node->value, tmp->parent->value))
			tmp->parent->left = tmp;
		else if (tmp->parent)
			tmp->parent->right = tmp;
		node = tmp;
		if (node->left && node->left != _begin)
			node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
		if (node->right && node->right != _end)
			node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
		if (node && node != _end && node != _begin)
			node->height = max(height(node->left), height(node->right)) + 1;
		if (node->parent)
			node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
	}
	return node;
}

map_node* leftRotate(map_node* node)
{
	map_node* tmp = node->right;
	if (node->right) {
		node->right = tmp->left;
		if (tmp->left && node->left != _begin)
			tmp->left->parent = node;
		tmp->left = node;
		tmp->parent = node->parent;
		node->parent = tmp;
		if (tmp->parent && value_comp()(node->value, tmp->parent->value))
			tmp->parent->left = tmp;
		else if (tmp->parent)
			tmp->parent->right = tmp;
		node = tmp;

		if (node->left && node->left != _begin)
			node->left->height = max(height(node->left->left), height(node->left->right)) + 1;
		if (node->right && node->right != _end)
			node->right->height = max(height(node->right->left), height(node->right->right)) + 1;
		if (node && node != _end && node != _begin)
			node->height = max(height(node->left), height(node->right)) + 1;
		if (node->parent)
			node->parent->height = max(height(node->parent->left), height(node->parent->right)) + 1;
	}
	return node;
}

	// the recursion will travel up to visit all the ancestors of the newly inserted node
map_node* newInsert(map_node* node, map_node* parent, const value_type &val, bool &found, map_node*& return_node) {
	// 1. BST insertion
	if (size() == 0 || !node || node == _begin || node == _end)
		return createNewNode(val, parent, found, return_node);
	if (value_comp()(val, node->value))
		node->left = newInsert(node->left, node, val, found, return_node);
	else if (value_comp()(node->value, val))
		node->right = newInsert(node->right, node, val, found, return_node);
	else {
		found = true;
		return_node = node;
		return node;
	}

	// 2. update height of this ancestor node
	node->height = 1 + max(height(node->left), height(node->right));

	// 3. get balance factor of this ancestor node & check whether this node became unbalanced
	int balance = getBalance(node);
	if (balance > 1 && node && node->left && node->left != _begin && value_comp()(val, node->left->value))
		return rightRotate(node);
	if (balance < -1 && node && node->right && node->right != _end && value_comp()(node->right->value, val))
		return leftRotate(node);
	if (balance > 1 && node && node->right && node->right != _end && value_comp()(node->right->value, val)) {
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if (balance < -1 && node && node->left && node->left != _begin && value_comp()(val, node->left->value)) {
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}

//-> insert single
	ft::pair<iterator, bool> insert(const value_type &val) {

		bool 		found = false;
		map_node* 	return_node = NULL;

		_root = newInsert(_root, NULL, val, found, return_node);
		setupTreeBeginEnd();

		if (found)
			return ft::make_pair(iterator(return_node), false);
		else
			return ft::make_pair(iterator(return_node), true);
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
	void insert(InputIterator first, InputIterator last) {
		while (first != last) {
			insert(*first);
			++first;
		}
	}

//-> erase element
	void erase(iterator position) {
		erase(position->first);
	}

// return how many elements are removed
	size_type erase (const key_type& k) {
		map_node *node = searchKey(k);
		if (!node || node == _begin || node == _end)
			return 0;
		erase_node(node);
		setupTreeBeginEnd();
		return 1;
	}

	void erase (iterator first, iterator last) {
		while (first != last)
		{
			iterator tmp(first);
			++first;
			erase(tmp->first);
		}
	}

// -> swap content
	void swap(map &x) {
		map tmp;
		tmp = *this;
		*this = x;
		x = tmp;
	}

//-> clear content
	void clear() {
		erase(begin(), end());
	}

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

//************************ Private helpers ************************
public:

	void inorder(map_node *node) {
		if (node && node != _begin && node != _end) {
			inorder(node->left);
			std::cout << node->value.first << "->" << node->value.second << std::endl;
			inorder(node->right);
		}
	}

	map_node *getRoot() { return _root; }

	void clearTree(map_node *node) {
		if (node) {
			clearTree(node->left);
			clearTree(node->right);
			delete node;
		}
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
		if (leftest)
			leftest->left = _begin;

		_end->parent = rightest;
		if (rightest)
			rightest->right = _end;
	}

	map_node *searchKey(const key_type &key) {
		map_node* tmp = _root;
		while (tmp && tmp != _begin && tmp != _end) {
			if (key == tmp->value.first)
				return tmp;
			else if (_compare(key, tmp->value.first))
				tmp = tmp->left;
			else if (_compare(tmp->value.first, key))
				tmp = tmp->right;
		}
		return NULL;
	}

	bool nodeIsLeaf(map_node *node) {
		if ((node->left == NULL || node->left == _begin) && (node->right == NULL || node->right == _end))
			return true;
		else
			return false;
	}

	bool nodeWithOneLeftChild(map_node *node) {
		if (node->left && (node->right == NULL || node->right == _end))
			return true;
		return false;
	}

	bool nodeWithOneRightChild(map_node *node) {
		if (node->right && (node->left == NULL || node->left == _begin))
			return true;
		return false;
	}

	bool nodeWithTwoChildren(map_node *node) {
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
		else if (size() > 1) {
			if (nodeWithOneRightChild(root)) {
				map_node *tmp = _root;
				_root = _root->right;
				_root->parent = NULL;
				delete tmp;
				_size--;
			}
			else if (nodeWithOneLeftChild(root)) {
				map_node *tmp = _root;
				_root = _root->left;
				_root->parent = NULL;
				delete tmp;
				_size--;
			}
			else if (nodeWithTwoChildren(root)) {
				std::cout << "root with two leaves" << std::endl;
				// find min of right subtree
				map_node *rightMin = findLeftestNode(root->right);

				// copy the value in targeted node
				map_node *toAdd = new map_node(rightMin->value);

				// copy connection of node to new node
				toAdd->right = root->right;
				toAdd->left= root->left;

				// connect node's children to new node
				root->left->parent = toAdd;
				root->right->parent = toAdd;

				// delete original node & duplicate node from right_subtree
				delete root;
				_root = toAdd;
				erase_node(rightMin);
			}
		}
	}

	void removeLeaf(map_node *node) {
//		std::cout << "removeLeaf" << std::endl;
		if (node->parent->left == node)
			node->parent->left = NULL;
		else if (node->parent->right == node)
			node->parent->right = NULL;
		delete node;
		_size--;
	}

	void removeNodeWithOneLeftChild(map_node *node) {
//		std::cout << "removeNodeWithOneLeftChild" << std::endl;
		// finding out whether the deleted node is on the right or left of the parent
		if (node->parent->left == node)
			node->parent->left = node->left;
		else if (node->parent->right == node)
			node->parent->right = node->left;
		node->left->parent = node->parent;
		delete node;
		_size--;
	}

	void removeNodeWithOneRightChild(map_node *node) {
//		std::cout << "removeNodeWithOneRightChild" << std::endl;
		// finding out whether the deleted node is on the right or left of the parent
		if (node->parent->right == node)
			node->parent->right = node->right;
		else if (node->parent->left == node)
			node->parent->left = node->right;
		node->right->parent = node->parent;
		delete node;
		_size--;
	}

	void removeNodeWithTwoChildren(map_node *node) {
//		std::cout << "removeNodeWithTwoChildren" << std::endl;
//		std::cout << "delete: " << node->value.first << std::endl;
//		std::cout << "parent of delete: " << node->parent->value.first << std::endl;
//		std::cout << "left of delete: " << node->left->value.first << std::endl;
//		std::cout << "left of left delete: " << node->left->left->value.first << std::endl;
//		std::cout << "right of delete: " << node->right->value.first << std::endl;

		// find minimal in right subtree
		map_node *rightMin = findLeftestNode(node->right);

		// copy the value in targeted node
		map_node *toAdd = new map_node(rightMin->value);

		// copy connection of node to new node
		toAdd->parent = node->parent;
		toAdd->right = node->right;
		toAdd->left= node->left;

		// connect node's parent to new node
		if (node->parent->left == node)
			node->parent->left = toAdd;
		else
			node->parent->right = toAdd;

		// connect node's children to new node
		node->left->parent = toAdd;
		node->right->parent = toAdd;

		// delete original node & duplicate node from right_subtree
		delete node;
		erase_node(rightMin);
	}

	void erase_node(map_node *node)	{
		if (node == _root)
			removeRoot(node);
		else if (nodeIsLeaf(node))
			removeLeaf(node);
		else if (nodeWithOneLeftChild(node))
			removeNodeWithOneLeftChild(node);
		else if (nodeWithOneRightChild(node))
			removeNodeWithOneRightChild(node);
		else if (nodeWithTwoChildren(node))
			removeNodeWithTwoChildren(node);
	}

	void	print_tree(map_node* root) const
	{
		print_tree_utils(root, 0);
	}

	void	print_tree_utils(map_node *root, int space) const {
		int count = 5;
		if (root == NULL)
			return;
		space += count;
		print_tree_utils(root->right, space);
		std::cout << std::endl;
		for (int i = count; i < space; i++)
			std::cout << " ";
		std::cout << root->value.first << "(h=" << root->height << ")" << std::endl;
		print_tree_utils(root->left, space);
	}

	//************************ For balancing ************************

};

//*************** Non-member function overloads ***************

template <class Key, class T, class Compare, class Alloc>
bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	if (lhs.size() != rhs.size())
		return false;

	typename ft::map<Key,T>::const_iterator lhs_begin = lhs.begin();
	typename ft::map<Key,T>::const_iterator rhs_begin = rhs.begin();

	while (lhs_begin != lhs.end() && rhs_begin != rhs.end())
	{
		if (lhs_begin->first != rhs_begin->first || lhs_begin->second != rhs_begin->second)
			return false;
		++lhs_begin;
		++rhs_begin;
	}
	return true;
}

template <class Key, class T, class Compare, class Alloc>
bool operator!= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs == rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator<  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
}

template <class Key, class T, class Compare, class Alloc>
bool operator>  ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return rhs < lhs;
}

template <class Key, class T, class Compare, class Alloc>
bool operator<= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs > rhs);
}

template <class Key, class T, class Compare, class Alloc>
bool operator>= ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ) {
	return !(lhs < rhs);
}

template <class Key, class T, class Compare, class Alloc>
void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y) {
	x.swap(y);
}

}

#endif //FT_CONTAINERS_MAP_H
