#ifndef _RANGE_MINIMUM_BLOCK_H_
#define _RANGE_MINIMUM_BLOCK_H

#include <vector>
#include "RangeMinimumQuery.hpp"

using std::vector;

template<class T>
class RangeMinimumBlock : public RangeMinimumQuery<T>
{ 
private:
	vector<T> blockMinimum;
	vector<T> elements;
	size_t blockSize;
public:
	RangeMinimumBlock();
	RangeMinimumBlock(const vector<T>& vElements);
	RangeMinimumBlock(size_t sBlockSize, const vector<T>& vElements);
	void build(const vector<T>& vElements);
	void build(size_t sBlockSize, const vector<T>& vElements);
	T range_minimum(size_t index_a, size_t index_b)const;
};
#include "../src/RangeMinimumBlock.tpp"
#endif

