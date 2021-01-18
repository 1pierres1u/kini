#ifndef _RANGE_MINIMUM_QUERY_BLOCK_HPP
#define _RANGE_MINIMUM_QUERY_BLOCK_HPP

#include "RangeMinimumQuery.hpp"
#include <cmath>
#define is_a_block(i,j,b) ((j-i+1==b) && (i%b==0))  
#define minr(A,B) (A<B?A:B);
#define minu(A,B,V) (V[A]>V[B]?B:A)

template<typename T>
class RangeMinimumQueryBlock : public RangeMinimumQuery<T>
{
private:
	vector<T> elements;
	vector<size_t> block_minimum;
	size_t block_size;
public:
	RangeMinimumQueryBlock();
	explicit RangeMinimumQueryBlock(const vector<T>& V);
	void build(const vector<T>& V);
	T range_minimum(size_t index_a, size_t index_b) const;
	size_t range_minimum_position(size_t index_a,size_t index_b)const;
};
#include "../src/RangeMinimumQueryBlock.tpp"
#endif 

