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
	// whether a node is first and end boundary signal of a tree
	bool 		boundary;

	BSTNode() : parent(NULL), left(NULL), right(NULL), value(), boundary(true) {};

	explicit BSTNode(const T &data): parent(NULL), left(NULL), right(NULL), value(data), boundary(false) {}

	~BSTNode(){};

	BSTNode(const BSTNode &x) { *this = x;	}

	BSTNode& operator=(const BSTNode& x) {
		if (this != &x)
		{
			parent = x.parent;
			left = x.left;
			right = x.right;
			value = x.value;
			boundary = x.boundary;
		}
		return *this;
	}

	// next node in inorder traversal (Left, Root, Right)
	BSTNode *next() {
		BSTNode* tmp = this;
		if (!tmp)
		{
			while (tmp->left)
				tmp = tmp->left;
			return tmp;
		}
		// if there is a right subtree, find the min value
		if (tmp->right) {
			while (tmp->left)
				tmp = tmp->left;
			return tmp;
		}
		// if right subtree is NULL, next one is one of the ancestors
		BSTNode* p = tmp->parent;
		while (p && tmp == p->right) {
			tmp = p;
			p = p->parent;
		}
		return p;
	}

	// prev node in inorder traversal (Left, Root, Right)
	BSTNode *prev() {}

};

}

#endif //FT_CONTAINERS_BSTNODE_H
