#ifndef _RANGE_MINIMUM_QUERY_FISCHER_HPP
#define _RANGE_MINIMUM_QUERY_FISCHER_HPP

#include "RangeMinimumQueryHybrid.hpp"

template<typename T>
class RangeMinimumQueryFischer : public RangeMinimumQueryHybrid<T>
{
private:
	//for each block it tells which rmq_blocks[i] will give 
	//the position of the minimum.
	vector<int> block_structures;
        int build_block_number(const vector<T>& V);
public:
      RangeMinimumQueryFischer();
      RangeMinimumQueryFischer(const vector<T>& V);
      void build(const vector<T>& V);
      T range_minimum(size_t index_a, size_t index_b)const;
      size_t range_minimum_position(size_t index_a,size_t index_b)const;
};
#include "../src/RangeMinimumQueryFischer.tpp"
#endif
