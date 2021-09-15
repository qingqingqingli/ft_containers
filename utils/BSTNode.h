//
// Created by qli on 09/09/2021.
//

#ifndef FT_CONTAINERS_BSTNODE_H
#define FT_CONTAINERS_BSTNODE_H

#include <iostream>

namespace ft {

template<class T>
struct BSTNode {

	BSTNode* 	parent;
	BSTNode* 	left;
	BSTNode* 	right;
	T			value;

	BSTNode() : parent(NULL), left(NULL), right(NULL), value(){};

	explicit BSTNode(const T &data): parent(NULL), left(NULL), right(NULL), value(data) {}

	~BSTNode(){};

	BSTNode(const BSTNode &x) { *this = x;	}

	BSTNode& operator=(const BSTNode& x) {
		if (this != &x)
		{
			parent = x.parent;
			left = x.left;
			right = x.right;
			value = x.value;
		}
		return *this;
	}

	// next node in inorder traversal (Left, Root, Right)
	BSTNode *next() {
		BSTNode* current = this;

		// if there is a right subtree, find the min value
		if (right) {
			while (current->left)
				current = current->left;
			return current;
		}
		// if right subtree is NULL, next one is one of the ancestors
		BSTNode* tmp_parent;
		tmp_parent = this->parent;
		while (tmp_parent && current == tmp_parent->right) {
			current = tmp_parent;
			tmp_parent = tmp_parent->parent;
		}
		return tmp_parent;
	}

	// prev node in inorder traversal (Left, Root, Right)
	BSTNode *prev() {}

};

}

#endif //FT_CONTAINERS_BSTNODE_H
