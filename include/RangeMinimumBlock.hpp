#ifndef _RANGE_MINIMUM_BLOCK_H_
#define _RANGE_MINIMUM_BLOCK_H_

#include <vector>
#include "RangeMinimumQuery.hpp"

using std::vector;

template<class T>
class RangeMinimumBlock : public RangeMinimumQuery<T>
{ 
private:
	vector<T> blockOfMinima;
	vector<T> elements;
	size_t blockSize;
	void build_block_of_minima();
public:
	RangeMinimumBlock();
	RangeMinimumBlock(const RangeMinimumBlock& r);
	RangeMinimumBlock(RangeMinimumBlock&& r);
	explicit RangeMinimumBlock(const vector<T>& vElements);
	RangeMinimumBlock(size_t sBlockSize, const vector<T>& vElements);
	void build(const vector<T>& vElements);
	void build(size_t sBlockSize, const vector<T>& vElements);
	T range_minimum(size_t index_a, size_t index_b)const;
	size_t blockSize_()const noexcept;
	vector<T> blockOfMinima_()const noexcept;
};
#include "../src/RangeMinimumBlock.tpp"
#endif


