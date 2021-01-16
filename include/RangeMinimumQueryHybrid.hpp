#ifndef _RANGE_MINIMUM_HYBRID_HPP
#define _RANGE_MINIMUM_HYBRID_HPP

#include "RangeMinimumQuery.hpp"
#include "RangeMinimumQueryNaive.hpp"
#include "RangeMinimumQuerySparse.hpp"
#include "RangeMinimumQueryBlock.hpp"
#include "memory"
#include <cmath>

using std::unique_ptr;
using std::make_unique;

enum RMQType
{ naive  = 0,
  block  = 1,
  sparse = 2, 
  hybrid = 3
};

template<typename T>
class RangeMinimumQueryHybrid : public RangeMinimumQuery<T>
{
private:
	const int MIN_SIZE_VECTOR = 40;
	size_t block_size;
	size_t no_elem;
	vector<T> elements;
	//The summary block will be at the end of the vector
	vector<unique_ptr<RangeMinimumQuery<T>>> rmq_blocks;

protected:
	void find_block_size();
public:
	RangeMinimumQueryHybrid();
	explicit RangeMinimumQueryHybrid(const vector<T>& V);
	void build(const vector<T>& V);
	T range_minimum(size_t index_a, size_t index_b)const;
};
#include "../src/RangeMinimumQueryHybrid.tpp"
#endif 

