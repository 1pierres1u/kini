#ifndef _RANGE_MINIMUM_SPARSE_H_
#define _RANGE_MINIMUM_SPARSE_H_

#include <vector>

template<class T>
class RangeMinimumSparse: public RangeMinimumQuery<T>
{
private:
	vector<vector<T>> sparseTable;
public:
	RangeMinimumSparse();
        RangeMinimumSparse(const vector<T>& elements);
	void build(const vector<T>& elements);
	T range_minimum(size_t index_a, size_t index_b)const;
};
#endif
