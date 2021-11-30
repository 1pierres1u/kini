#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP


class BinarySearchTree{
	public:
		struct Node{
			int key;
			Node* left;
			Node* right;
			Node():left(nullptr),right(nullptr),key(0){}
		};
	private:
		Node* root;
	public:
		BinarySearchTree():root(nullptr){}
		void insert(int kx){}
		bool search(int kx){
			return false;
		}
		

};
#endif
