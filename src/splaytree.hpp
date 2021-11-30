#ifndef SPLAY_TREE_HPP
#define SPLAY_TREE_HPP


class SplayTree{
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
		SplayTree():root(nullptr){}
		bool insert(int kx){
			return false;
		}
		bool search(int kx){
			return false;
		}
};
#endif
