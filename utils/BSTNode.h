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
	BSTNode *next() {}

	// prev node in inorder traversal (Left, Root, Right)
	BSTNode *prev() {}

};

}

#endif //FT_CONTAINERS_BSTNODE_H
