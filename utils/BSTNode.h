//
// Created by qli on 09/09/2021.
//

#ifndef FT_CONTAINERS_BSTNODE_H
#define FT_CONTAINERS_BSTNODE_H

#include <iostream>

namespace ft {

template<class Pair>
struct BSTNode {

	BSTNode* 	parent;
	BSTNode* 	left;
	BSTNode* 	right;
	Pair		value;

	explicit BSTNode() : parent(NULL), left(NULL), right(NULL), value() {};

	explicit BSTNode(const Pair &data): parent(NULL), left(NULL), right(NULL), value(data) {}

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

		// case 1: Node has right subtree
		if (tmp->right)
			return findMin(tmp->right);

		// case 2: no right subtree
		// travel up using its parent pointer, until you see a node which is the left child of its parent
		// the parent of that node is the successor

		BSTNode* p = tmp->parent;
		while (p && tmp == p->right) {
			tmp = p;
			p = p->parent;
		}
		// not sure if needed
//		if (!p) {
//			while (tmp->left)
//				tmp = tmp->left;
//			p = tmp->left;
//		}
		return p;
	}

	// prev node in inorder traversal
	BSTNode *prev() {
		BSTNode* tmp = this;

		// case 1: Node has left subtree
		if (tmp->left)
			return findMax(tmp->left);

		// case 2: no left subtree
		// travel up using its parent pointer, until you see a node which is the right child of its parent
		// the parent of that node is the successor
		BSTNode* p = tmp->parent;
		while (p && tmp == p->left) {
			tmp = p;
			p = p->parent;
		}
		// not sure if needed
//		if (!p)	{
//			while (tmp->right)
//				tmp = tmp->right;
//			p = tmp->right;
//		}
		return p;
	}

};

}

#endif //FT_CONTAINERS_BSTNODE_H
