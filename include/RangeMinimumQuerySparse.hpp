#ifndef _RANGE_MINIMUM_QUERY_SPARSE_HPP
#define _RANGE_MINIMUM_QUERY_SPARSE_HPP

#include "RangeMinimumQuery.hpp"
#include <cmath>


template<typename T>
class RangeMinimumQuerySparse : public RangeMinimumQuery<T>
{
private:
	//Build sparse table only if size of vector
	//is greater or equal to MIN_SIZE_VECTOR
        const int MIN_SIZE_VECTOR = 8; 
	vector<vector<size_t>> sparseTable;
public:
	RangeMinimumQuerySparse();
	explicit RangeMinimumQuerySparse(const vector<T>& V);
	void build(const vector<T>& V);
        size_t range_minimum_position(size_t index_a,size_t index_b)const;
};
#include "../src/RangeMinimumQuerySparse.tpp"
#endif 

