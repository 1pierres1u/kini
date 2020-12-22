#ifndef _RANGE_MINIMUM_NAIVE_H_
#define _RANGE_MINIMUM_NAIVE_H_

#include <vector>
#include "RangeMinimumQuery.hpp"

template<class T>
class RangeMinimumNaive: public RangeMinimumQuery<T>
{
private:
	std::vector<T> elements;
public:
	RangeMinimumNaive();
	RangeMinimumNaive(const std::vector<T>& vElements);
	void build(const std::vector<T>& vElements);
        T range_minimum(size_t index_a, size_t index_b)const;   
};

#include "../src/RangeMinimumNaive.tpp"
#endif
