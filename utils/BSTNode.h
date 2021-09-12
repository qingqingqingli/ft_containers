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

	BSTNode *next() {}

	BSTNode *prev() {}

//private:
//	// clear the whole tree
//	void clear(node* tree)
//	{
//		if (!isEmpty(tree))
//		{
//			clearTree(tree->left);
//			clearTree(tree->right);
//			delete tree;
//			tree = NULL;
//		}
//	}
//
//	// need to only insert unique value
//	void insert(node *&tree, T data)
//	{
//		if (isEmpty(tree))
//			tree = new node(data);
//		else
//		{
//			if (data < tree->data)
//				insert(tree->left, data);
//			else if (data > tree->data)
//				insert(tree->right, data);
//			// If data happens to equal tree->data, then we are not in business.
//			// So uniqueness is guaranteed here.
//		}
//	}
//
//	bool isEmpty(node *tree)
//	{
//		return tree == NULL;
//	}
//
//	bool isLeaf(node *tree)
//	{
//		return tree->left == NULL && tree->right == NULL;
//	}
//
//	int size(node *tree)
//	{
//		if (!isEmpty(tree))
//			return 1 + size(tree->left) + size(tree->right);
//		else
//			return 0;
//	}
//
//	bool find(node *tree, T data)
//	{
//		if (isEmpty(tree))
//			return false;
//		else
//		{
//			if (data == tree->data)
//				return true;
//			else if (data < tree->data)
//				return find(tree->left, data);
//			else
//				return find(tree->right, data);
//		}
//	}
//
//// in-order traversal
//	void inorder(node *tree)
//	{
//		if (tree)
//		{
//			inorder(tree->left);
//			std::cout << "[" << tree->data << "]";
//			inorder(tree->right);
//		}
//	}
//
//// pre-order traversal
//	void preorder(node *tree)
//	{
//		if (tree)
//		{
//			std::cout << "[" << tree->data << "]";
//			preorder(tree->left);
//			preorder(tree->right);
//		}
//	}
//
//// pre-order traversal
//	void postorder(node *tree)
//	{
//		if (tree)
//		{
//			postorder(tree->left);
//			std::cout << "[" << tree->data << "]";
//			postorder(tree->right);
//		}
//	}
//
//// clear the whole tree
//	void clearTree(node *&tree)
//	{
//		if (!isEmpty(tree))
//		{
//			clearTree(tree->left);
//			clearTree(tree->right);
//			delete tree;
//			tree = NULL;
//		}
//	}
//
//// remove a node
//
//	node *findMinNode(node *node)
//	{
//		BSTNode::node *current = node;
//
//		// find the leftmost leaf
//		while (current && current->left)
//			current = current->left;
//		return current;
//	}
//
//	void remove(node *&tree, T data)
//	{
//		if (isEmpty(tree))
//			return ;
//		if (data == tree->data)
//		{
//			// if the node has 2 children
//			if (!isEmpty(tree->left) && (!isEmpty(tree->right)))
//			{
//				// need to implement findMinNode
//				node *minRight = findMinNode(tree->right);
//				tree->data = minRight->data;
//				remove(tree->right, minRight->data);
//			}
//			else
//			{
//				node *toDelete = tree;
//				// if the node has 0 children
//				if (isLeaf(tree))
//					tree = NULL;
//					// if the node has 1 child
//				else if (!isEmpty(tree->left))
//					tree = tree->left;
//				else
//					tree = tree->right;
//
//				delete toDelete;
//			}
//		}
//		else if (data < tree->data)
//			remove(tree->left, data);
//		else
//			remove(tree->right, data);
//	}
};

// these functions will be transformed to functions in map.h


}

#endif //FT_CONTAINERS_BSTNODE_H
