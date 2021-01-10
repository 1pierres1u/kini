#ifndef _RANGE_MINIMUM_QUERY_BLOCK_HPP
#define _RANGE_MINIMUM_QUERY_BLOCK_HPP

#include "RangeMinimumQuery.hpp"
#include <vector>
#include <cmath>
using std::vector;
#define is_a_block(i,j,b) ((j-i+1==b) && (i%b==0))  
#define minr(A,B) (A<B?A:B);

template<typename T>
size_t min_(const vector<T>& V, size_t i, size_t j)
{ size_t k = i;
  while(i<j+1)
  { if(V[k] > V[i])
	  k = i;
     i++;
  }
  return k;
}


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
};
#include "../src/RangeMinimumQueryBlock.tpp"
#endif 

