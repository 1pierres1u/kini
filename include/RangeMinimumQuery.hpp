#ifndef _RANGE_MINIMUM_QUERY_HPP
#define _RANGE_MINIMUM_QUERY_HPP

#include <vector>
#include <stdexcept>
using std::vector;
using std::out_of_range;

template<typename T>
class RangeMinimumQuery 
{
	public:
		virtual void build(const vector<T>& V)=0;
		virtual T range_minimum(size_t index_a, size_t index_b)const=0;

};
#endif

