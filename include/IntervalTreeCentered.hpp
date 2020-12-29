#ifndef _INTERVAL_TREE_CENTERED_H
#define _INTERVAL_TREE_CENTERED_H 

#include "IntervalTree.hpp"
#include <memory>
#include <vector>
using std::pair;
using std::vector;
using std::unique_ptr;

template<typename T>
class IntervalTreeCentered: public IntervalTree<T>
{
private:
	using interval = pair<T,T>;
	template<typename U=T>
	struct Node
	{
	  T center;
	  unique_ptr<Node> left;
	  unique_ptr<Node> right;
	  vector<interval> overlap_beginning;
	  vector<interval> overlap_ending;
	  Node(){}
	  void insert_overlapping_interval(const interval& I){}
	  void insert_interval(const interval& I){}
	};
	unique_ptr<Node<T>> root;
public:
        IntervalTreeCentered();
	explicit IntervalTreeCentered(const vector<interval>& V);
	void find_overlapping_interval(vector<interval>& V,
		              	        const interval& I)const;
};
#include "../src/IntervalTreeCentered.tpp"
#endif

