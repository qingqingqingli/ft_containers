//
// Created by qli on 09/09/2021.
//

#ifndef FT_CONTAINERS_BSTNODE_H
#define FT_CONTAINERS_BSTNODE_H

#include <iostream>

namespace ft {
// BSTNode is any node in the tree
template<typename Key, typename T>
struct BSTNode {

	typedef Key		key_type;
	typedef T		mapped_type;

	key_type			key;
	mapped_type			value;
	BSTNode<key_type, mapped_type> *left;
	BSTNode<key_type, mapped_type> *right;

	BSTNode(){};

	BSTNode(const key_type &k, mapped_type v): key(k), value(v), left(NULL), right(NULL) {}

	~BSTNode(){};

};

// these functions will be transformed to functions in map.h
//bool isEmpty(BSTNode<Key, T> *tree)
//{
//	return tree == NULL;
//}
//
//bool isLeaf(BSTNode<Key, T> *tree)
//{
//	return tree->left == NULL && tree->right == NULL;
//}
//
//int size(BSTNode<Key, T> *tree)
//{
//	if (!isEmpty(tree))
//		return 1 + size(tree->left) + size(tree->right);
//	else
//		return 0;
//}
//
//// need to only insert unique value
//void insert(BSTNode<Key, T> *&tree, T data)
//{
//	if (isEmpty(tree))
//		tree = new BSTNode<Key, T>(data);
//	else
//	{
//		if (data < tree->data)
//			insert(tree->left, data);
//		else if (data > tree->data)
//			insert(tree->right, data);
//		// If data happens to equal tree->data, then we are not in business.
//		// So uniqueness is guaranteed here.
//	}
//}
//
//bool find(BSTNode<Key, T> *tree, T data)
//{
//	if (isEmpty(tree))
//		return false;
//	else
//	{
//		if (data == tree->data)
//			return true;
//		else if (data < tree->data)
//			return find(tree->left, data);
//		else
//			return find(tree->right, data);
//	}
//}
//
//// in-order traversal
//void inorder(BSTNode<Key, T> *tree)
//{
//	if (tree)
//	{
//		inorder(tree->left);
//		std::cout << "[" << tree->data << "]";
//		inorder(tree->right);
//	}
//}
//
//// pre-order traversal
//void preorder(BSTNode<Key, T> *tree)
//{
//	if (tree)
//	{
//		std::cout << "[" << tree->data << "]";
//		preorder(tree->left);
//		preorder(tree->right);
//	}
//}
//
//// pre-order traversal
//void postorder(BSTNode<Key, T> *tree)
//{
//	if (tree)
//	{
//		postorder(tree->left);
//		std::cout << "[" << tree->data << "]";
//		postorder(tree->right);
//	}
//}
//
//// clear the whole tree
//void clear(BSTNode<Key, T> *&tree)
//{
//	if (!isEmpty(tree))
//	{
//		clear(tree->left);
//		clear(tree->right);
//		delete tree;
//		tree = NULL;
//	}
//}
//
//// remove a node
//
//BSTNode<Key, T> *findMinNode(BSTNode<Key, T> *node)
//{
//	BSTNode<Key, T> *current = node;
//
//	// find the leftmost leaf
//	while (current && current->left)
//		current = current->left;
//	return current;
//}
//
//void remove(BSTNode<Key, T> *&tree, T data)
//{
//	if (isEmpty(tree))
//		return ;
//	if (data == tree->data)
//	{
//		// if the node has 2 children
//		if (!isEmpty(tree->left) && (!isEmpty(tree->right)))
//		{
//			// need to implement findMinNode
//			BSTNode<Key, T> *minRight = findMinNode(tree->right);
//			tree->data = minRight->data;
//			remove(tree->right, minRight->data);
//		}
//		else
//		{
//			BSTNode<Key, T> *toDelete = tree;
//			// if the node has 0 children
//			if (isLeaf(tree))
//				tree = NULL;
//				// if the node has 1 child
//			else if (!isEmpty(tree->left))
//				tree = tree->left;
//			else
//				tree = tree->right;
//
//			delete toDelete;
//		}
//	}
//	else if (data < tree->data)
//		remove(tree->left, data);
//	else
//		remove(tree->right, data);
//}

}

#endif //FT_CONTAINERS_BSTNODE_H
