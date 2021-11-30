#ifndef TRIE_HPP
#define TRIE_HPP

#include <vector>
#include <string>

class Trie{
	public:
		struct Node{
			std::string s;
			std::vector<Node*> children;
			Node():s(""){}
			Node(const std::string& sx):s(sx){}
		};

	private:
		Node* root;
	public:
		Trie():root(nullptr){
		}
		bool insert(const std::string& sx){
			return false;
		}
};
#endif
