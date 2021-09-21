#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <vector>
#include <memory>

template<typename T>
class BinarySearchTree{ 
 public:
   struct Node{
	T key;
	Node* left;
	Node* right;
	Node* parent;

	Node():left(nullptr),right(nullptr),parent(nullptr){
	}
	Node(T k):key(k),left(nullptr),right(nullptr),parent(nullptr){
	}
   };
 public:
	 virtual bool search(const T& x)const=0;
	 virtual bool remove(const T& x)=0;
	 virtual bool insert(const T& x)=0;
	 virtual size_t size()const=0;
	 //size of the subtree rooted at the element x
	 virtual size_t size(const T& x)const=0;
	 virtual int height()const=0;
	 //height of the subtree rooted at the element x
	 virtual int height(const T& x)const=0;
};

template<typename T>
class RegularBinarySearchTree : public BinarySearchTree<T>{
		typedef typename BinarySearchTree<T>::Node Node;
	private:
		Node* root;
	public:
	  bool remove(const T& x){
	  	return false;
	  }
	  bool insert(const T& x){
	  	return false;
	  }
	  size_t size()const{
		return 0;
	  }
	  size_t size(const T& x){
	  	return 0;
	  }
	  int height()const{
		return -1;
	  }
	  int height(const T& x)const{
	  	return -1;
	  }


};

template<typename T>
class RedBlackTree: public BinarySearchTree<T>{
	public:
	  enum Color{red,black};
	  struct Node : public BinarySearchTree<T>::Node{
	    Color color;
	  };
	private:
	  Node* root;
	public:
	  bool remove(const T& x){
	  	return false;
	  }
	  bool insert(const T& x){
	  	return false;
	  }
	  size_t size()const{
		return 0;
	  }
	  size_t size(const T& x){
	  	return 0;
	  }
	  int height()const{
		return -1;
	  }
	  int height(const T& x)const{
	  	return -1;
	  }

};

template<typename T>
class AVLTree : public BinarySearchTree<T>{
	public:
	 enum BalanceFactor{left_heavy,right_heavy,balanced};
	   struct Node: public BinarySearchTree<T>::Node{
	     BalanceFactor balance_factor; 
	   };
	private:
	   Node* root;
	public:
	  bool remove(const T& x){
	  	return false;
	  }
	  bool insert(const T& x){
	  	return false;
	  }
	  size_t size()const{
		return 0;
	  }
	  size_t size(const T& x){
	  	return 0;
	  }
	  int height()const{
		return -1;
	  }
	  int height(const T& x)const{
	  	return -1;
	  }
};

template<typename T>
class LevelLinkedRedBlackTree : public BinarySearchTree<T>{
	public:
		enum Color{red,black};
		struct Node : public BinarySearchTree<T>::Node{
			Color color;
			Node* next;
		};
	private:
		Node* root;
	public:
	  bool remove(const T& x){
	  	return false;
	  }
	  bool insert(const T& x){
	  	return false;
	  }
	  size_t size()const{
		return 0;
	  }
	  size_t size(const T& x){
	  	return 0;
	  }
	  int height()const{
		return -1;
	  }
	  int height(const T& x)const{
	  	return -1;
	  }
};

template<typename T>
class SplayTree : public BinarySearchTree<T>{
	typedef typename BinarySearchTree<T>::Node Node;
	private:
	  Node* root;
	public:
	  bool remove(const T& x){
	  	return false;
	  }
	  bool insert(const T& x){
	  	return false;
	  }
	  size_t size()const{
		return 0;
	  }
	  size_t size(const T& x){
	  	return 0;
	  }
	  int height()const{
		return -1;
	  }
	  int height(const T& x)const{
	  	return -1;
	  }
};
#endif

