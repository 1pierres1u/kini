#ifndef RANGE_MINIMUM_QUERY_HPP
#define RANGE_MINIMUM_QUERY_HPP

#include <vector>
#include <memory>
#include <stdexcept>

template<typename T>
class RangeMinimumQuery 
{ 	
        protected:
		 std::unique_ptr<const vector<T>> elements;

		 size_t min(size_t i, size_t j)const{
			 size_t k = i;
			 while(i<j+1){
				 if((*elements)[k] > (*elements)[i])
					 k =i;
				 i++;
			 }
			 return k;
		 }
		 void check_range(size_t index_a,size_t index_b)const{
                    if(index_a >= (*elements).size()) throw std::out_of_range("index_a out of bound");
                    if(index_b >= (*elements).size()) throw std::out_of_range("index_b out of bound");
                    if(index_a > index_b) throw std::out_of_range("index_a > index_b");
		 }
	public:
		virtual void preprocess(std::unique<const vector<T>> _elements)=0;
		size_t rmq(size_t index_a, size_t index_b)const=0;
};
#endif

