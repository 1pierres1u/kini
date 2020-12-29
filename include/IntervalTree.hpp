#ifndef _INTERVAL_TREE_H
#define _INTERVAL_TREE_H

#include <utility>
#include <vector>
using std::vector;
using std::pair;

template<typename T>
class IntervalTree
{
    using interval = pair<T,T>;
public:
     void find_overlapping_interval(vector<interval>& V, const interval& I)const=0;
};
#endif


