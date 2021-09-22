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
	// AVL tree: A type of balanced tree, where the AVL balance factor of each node is limited to -1, 0, or +1.
	// balance factor: For any node in an AVL tree, the difference between the height of the node's right subtree and left subtree.
	// height: The maximum number of nodes that can be visited starting at the tree's root and moving only downward. An an empty tree has height 0.
	int			height;

	explicit BSTNode() : parent(NULL), left(NULL), right(NULL), value(), height(0) {};

	explicit BSTNode(const Pair &data): parent(NULL), left(NULL), right(NULL), value(data), height(0) {}

	~BSTNode(){};

	BSTNode(const BSTNode &x) { *this = x;	}

	BSTNode& operator=(const BSTNode& x) {
		if (this != &x)
		{
			parent = x.parent;
			left = x.left;
			right = x.right;
			value = x.value;
			height = x.height;
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
		return p;
	}

};

}

#endif //FT_CONTAINERS_BSTNODE_H
