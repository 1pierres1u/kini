#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP



class RedBlackTree{
	public:
		enum Color{red,black};
		struct Node{
			int key;
			Color col;
			Node* left;
			Node* right;
			Node():left(nullptr),right(nullptr),col(black),key(-1){}
		};

	private:
		Node* root;
	public:
		RedBlackTree():root(nullptr){}
		void insert(int kx){}
		bool search(int kx){
			return false;
		}
};
#endif

