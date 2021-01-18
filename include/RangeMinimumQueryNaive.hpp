#ifndef _RANGE_MINIMUM_QUERY_NAIVE_HPP
#define _RANGE_MINIMUM_QUERY_NAIVE_HPP

#include "RangeMinimumQuery.hpp"

template<typename T>
class RangeMinimumQueryNaive : public RangeMinimumQuery<T>
{
	private:
		vector<T> elements;
	public:
		RangeMinimumQueryNaive();
		explicit RangeMinimumQueryNaive(const vector<T>& V);
		void build(const vector<T>& V);
		T range_minimum(size_t index_a, size_t index_b)const;
                size_t range_minimum_position(size_t index_a,size_t index_b)const;
};
#include "../src/RangeMinimumQueryNaive.tpp"
#endif 

