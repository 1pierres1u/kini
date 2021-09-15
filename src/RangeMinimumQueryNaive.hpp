#ifndef RANGE_MINIMUM_QUERY_NAIVE_HPP
#define RANGE_MINIMUM_QUERY_NAIVE_HPP

#include "RangeMinimumQuery.hpp"

template<typename T>
class RangeMinimumQueryNaive : public RangeMinimumQuery<T>
{
	public:
		RangeMinimumQueryNaive():RangeMinimumQuery(nullptr)
	        {}
		explicit RangeMinimumQueryNaive(std::shared_ptr<const std::vector<T>> elements)
			:RangeMinimumQuery(elements)
		{}
		void preprocess(std::shared_ptr<const std::vector<T>> elements){
			this->setElements(elements);
		}
                size_t find_range_minimum(size_t index_a,size_t index_b)const{
			check_range(index_a, index_b);
			return min(index_a,index_b);
		}
};
#endif 

