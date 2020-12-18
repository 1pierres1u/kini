#ifndef _TREE_H_
#define _TREE_H_

#include "Node.hpp"
#include <memory>


template<class NodeType,class NodeBase=Node>
requires std::derived_from<NodeType,NodeBase>
class Tree
{
protected:
	unique_ptr<NodeType> root;
public:
	Tree();
	int height()const;
	int diameter()const;
	bool empty()const;
	bool complete()const;
};
#endif

