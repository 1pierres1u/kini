#ifndef RANGE_MINIMUM_QUERY_BLOCK_HPP
#define RANGE_MINIMUM_QUERY_BLOCK_HPP

#include "RangeMinimumQuery.hpp"
#include <cmath>

#define is_a_block(i,j,b) ((j-i+1==b) && (i%b==0))  
#define pminu(A,B) ((*pElements)[A]>(*pElements)[B]?B:A)
#define minu(A,B) (elements[A]>elements[B]?B:A)

template<typename T>
class PRangeMinimumQueryBlock : public PRangeMinimumQuery<T>
{
private:
	std::vector<size_t> block_minimum; //indices of the minimum
	size_t block_size;
public:
	PRangeMinimumQueryBlock():PRangeMinimumQuery(),block_size(0)
	{}
	explicit PRangeMinimumQueryBlock(const std::vector<T>* V)
	  :PRangeMinimumQuery(V)
	{
		if(pElements->size()>3)
			preprocess(V);
		else
			block_size=0;
	}
	void preprocess(const std::vector<T>* V){
	   setElements(V);
	   block_size = 0;
	   size_t N = pElements->size();
	   block_minimum.clear();
	   if(pElements->size()>3){
		   block_size = std::sqrt(N);
		   size_t num_blocks = N/block_size + (N%block_size==0?0:1);
		   block_minimum = vector<size_t>(num_blocks);
		   size_t i = 0;
		   while(i < N){
			   size_t j = i/block_size;
			   j = std::min(N-1,(j+1)*block_size-1);
			   block_minimum[i/block_size] = min(i,j);
			   i = j + 1;
	           } 
	   }
	}
	size_t find_range_minimum(size_t index_a,size_t index_b)const{
	   check_range(index_a,index_b);
	   size_t min_i = index_a;
           if(block_size==0 || (index_b-index_a+1<block_size))
		min_i = min(index_a,index_b);
	   else{
	   	while(index_a < index_b+1){
			size_t k = index_a/block_size;
			k = std::min(index_b, (k+1)*block_size-1);
			if(is_a_block(index_a,k,block_size))
				min_i = pminu(min_i,block_minimum[index_a/block_size]);
	   		else
				min_i = pminu(min_i,min(index_a,k));
			
			index_a = k + 1;
	   	}	   
	   }
	   return min_i;
        }
};


template<typename T>
class RangeMinimumQueryBlock : public RangeMinimumQuery<T>
{
private:
	std::vector<size_t> block_minimum; //indices of the minimum
	size_t block_size;
public:
	RangeMinimumQueryBlock():RangeMinimumQuery(),block_size(0)
	{}
	explicit RangeMinimumQueryBlock(const std::vector<T>& V):RangeMinimumQuery(V){
		if(V.size()>3)
			preprocess(V);
		else
			block_size =0;
	}
	void preprocess(const std::vector<T>& V){
             setElements(V);
     	     block_size = 0;
	     size_t N = elements.size();
	     block_minimum.clear();
	     if(elements.size() > 3){
		block_size = std::sqrt(N);
                size_t num_blocks = N/block_size + (N%block_size==0?0:1);
		block_minimum = vector<size_t>(num_blocks);
		size_t i=0;
		while(i < N){
			size_t j = i/block_size;
			j = std::min(N-1,(j+1)*block_size-1);
			block_minimum[i/block_size] = min(i,j);
			i = j + 1;
		}		
	     }
	}
	size_t find_range_minimum(size_t index_a,size_t index_b)const{
	     check_range(index_a,index_b);
	     size_t min_i = index_a;
	     if(block_size==0 || (index_b-index_a+1<block_size))
		min_i = min(index_a,index_b);
	     else{
	     	while(index_a < index_b+1){
			size_t k = index_a/block_size;
			k = std::min(index_b, (k+1)*block_size-1);
			if(is_a_block(index_a,k,block_size))
				min_i = minu(min_i,block_minimum[index_a/block_size]);
			else
				min_i = minu(min_i,min(index_a,k));

			index_a = k+1;
		
		}
	     }
	     return min_i;	     
	}
};
#endif 

