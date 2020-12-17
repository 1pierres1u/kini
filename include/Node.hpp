#ifndef _NODE_H_
#define _NODE_H_

#include <memory>

template<class T>
struct Node
{
 T key;
 shared_ptr<Node<T>> parent;
 vector<unique_ptr<T>> children;
 Node();
 Node(T& x);	
};
#endif
