#ifndef _RANGE_MINIMUM_QUERY_FISCHER_HPP
#define _RANGE_MINIMUM_QUERY_FISCHER_HPP

#include "RangeMinimumQueryHybrid.hpp"
#include <stack>
#include <map>

using std::stack;
using std::string;
using std::map;

template<typename T>
class RangeMinimumQueryFischer : public RangeMinimumQueryHybrid<T>
{
protected:
	//for each block it tells which rmq_blocks[i] will give 
	//the position of the minimum.
	vector<size_t> block_structures;
	inline void find_cartesian_number(string& cartesian_no,size_t index_block);
public:
      RangeMinimumQueryFischer();
      RangeMinimumQueryFischer(const vector<T>& V);
      void build(const vector<T>& V);
      size_t range_minimum_position(size_t index_a,size_t index_b)const;
};
#include "../src/RangeMinimumQueryFischer.tpp"
#endif
