#ifndef _RANGE_MINIMUM_PREPROCESS_NAIVE_H_
#define _RANGE_MINIMUM_PREPROCESS_NAIVE_H_

#include <map>

template<class T>
class RangeMinimumPreprocessNaive:public RangeMinimumQuery<T>
{
private:
	vector<vector<T>> minimumOfAllRanges; 
public:
	RangeMinimumPreprocessNaive();
	RangeMinimumPreprocessNaive(const vector<T>& elements);
        void build(const vector<T>& elements);
	T range_minimum(size_t index_a, size_t index_b)const;
};
#endif 
