#ifndef SUFFIX_TREE_HPP 
#define SUFFIX_TREE_HPP

#include <string>
#include <vector>

class SuffixTree{
	public:
		struct Node{
			size_t pos;
			std::vector<Node*> children;	
			Node():pos(0){}
			Node(size_t posx):pos(posx){}
		};

	private:
		std::string s;
		Node* root;
	public:
		SuffixTree(const std::string& sx):s(sx){
		}
		void build(){
		}
};
#endif
