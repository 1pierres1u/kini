#ifndef _RANGE_MINIMUM_QUERY_H_
#define _RANGE_MINIMUM_QUERY_H_

#include <vector>

template<class T>
class RangeMinimumQuery
{
public:
	virtual void build(const std::vector<T>& vElements)=0;
	virtual T range_minimum(size_t index_a, size_t index_b)const=0;
};
#endif




