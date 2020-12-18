#ifndef _NODE_H_
#define _NODE_H_

#include <memory>

template<class T>
class Node
{
 T key;
 shared_ptr<Node<T>> parent;
 vector<unique_ptr<Node<T>>> children;
 Node();
 explicit Node(T& x);	
};
#endif
