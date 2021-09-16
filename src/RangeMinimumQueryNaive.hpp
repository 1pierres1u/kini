#ifndef RANGE_MINIMUM_QUERY_NAIVE_HPP
#define RANGE_MINIMUM_QUERY_NAIVE_HPP

#include "RangeMinimumQuery.hpp"

template<typename T>
class PRangeMinimumQueryNaive : public PRangeMinimumQuery<T>
{
	public:
		PRangeMinimumQueryNaive()
	        {}
		explicit PRangeMinimumQueryNaive(const std::vector<T>* elements)
			:PRangeMinimumQuery(elements)
		{}
		void preprocess(const std::vector<T>* elements){
			this->setElements(elements);
		}
                size_t find_range_minimum(size_t index_a,size_t index_b)const{
			check_range(index_a, index_b);
			return min(index_a,index_b);
		}
};



template<typename T>
class RangeMinimumQueryNaive : public RangeMinimumQuery<T>
{
	public:
		RangeMinimumQueryNaive()
	        {}
		explicit RangeMinimumQueryNaive(const std::vector<T>& elements)
			:RangeMinimumQueryP(elements)
		{}
		void preprocess(const std::vector<T>& elements){
			this->setElements(elements);
		}
                size_t find_range_minimum(size_t index_a,size_t index_b)const{
			check_range(index_a, index_b);
			return min(index_a,index_b);
		}
};
#endif 

