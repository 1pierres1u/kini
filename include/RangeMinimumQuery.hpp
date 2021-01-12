#ifndef _RANGE_MINIMUM_QUERY_HPP
#define _RANGE_MINIMUM_QUERY_HPP

#include <vector>
#include <stdexcept>
using std::vector;
using std::out_of_range;

template<typename T>
void check_range(const vector<T>& V, size_t index_a,size_t index_b)
{ 
  if(index_a >= V.size()) throw std::out_of_range("index_a out of bound");
  if(index_b >= V.size()) throw std::out_of_range("index_b out of bound");
  if(index_a > index_b) throw std::out_of_range("index_a > index_b");
}

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
class RangeMinimumQuery 
{ 	
	public:
		virtual void build(const vector<T>& V)=0;
		virtual T range_minimum(size_t index_a, size_t index_b)const=0;

};
#endif

