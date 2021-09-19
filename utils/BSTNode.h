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

	BSTNode() : parent(NULL), left(NULL), right(NULL), value() {};

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

	BSTNode* findMin(BSTNode* node)
	{
		if (!node)
			return NULL;
		while (node->left)
			node = node->left;
		return node;
	}

	BSTNode* findMax(BSTNode* node)
	{
		if (!node)
			return NULL;
		while (node->right)
			node = node->right;
		return node;
	}

	// next node in inorder traversal
	BSTNode *next() {
		BSTNode* tmp = this;
		BSTNode* p = tmp->parent;

		// case 1: Node has right subtree
		if (tmp->right)
			return findMin(tmp->right);

		// case 2: no right subtree. Walk from the root to find the deepest ancestor for which the current node will be in its left subtree
		while (p && tmp == p->right) {
			tmp = p;
			p = p->parent;
		}
		if (!p)
		{
			while (tmp->left)
				tmp = tmp->left;
			p = tmp->left;
		}
		return p;
	}

	// prev node in inorder traversal
	BSTNode *prev() {
		BSTNode* tmp = this;
		BSTNode* p = tmp->parent;

		// case 1: Node has left subtree
		if (tmp->left)
			return findMax(tmp->left);

		// case 2: no left subtree
		while (p && tmp == p->left) {
			tmp = p;
			p = p->parent;
		}
		if (!p)
		{
			while (tmp->right)
				tmp = tmp->right;
			p = tmp->right;
		}
		return p;
	}

};

}

#endif //FT_CONTAINERS_BSTNODE_H
