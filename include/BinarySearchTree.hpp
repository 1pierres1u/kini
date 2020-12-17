#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

#include "Tree.hpp"
#include <vector>

template<class T>
class BinarySearchTree:public Tree<Node<T>>
{
protected:
        vector<T> traversalStorage;
	void in_order_recursive()const;
	void post_order_recursive()const;
	void pre_order_recursive()const;
	void in_order_iterative()const;
	void post_order_iterative()const;
	void pre_order_iterative()const;
	bool duplicateAllowed;
public:
	BinarySearchTree();
	BinarySearchTree(vector<T>& valuesToInsert,bool allowDuplicate=true,bool random=false);
	BinarySearchTree(BinarySearchTree& bst);
	BinarySearchTree& operator+(const BinarySearchTree<T>& rh)const;
	BinarySearchTree& operator=(const BinarySearchTree& rh);
	~BinarySearchTree();
	void insert(T& x);
	void remove(T& x);
	size_t search(T& x,bool countDuplicate=false)const;
	size_t size()const;
	T find_min()const;
	T find_max()const;
	T find_predecessor(T& x)const;
	T find_successor(T& x)const;
	vector<T> traversal(string type,bool recursiveOrIterative=true)const;
};
#endif


