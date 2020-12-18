#ifndef _RANGE_MINIMUM_HYBRID_H_
#define _RANGE_MINIMUM_HYBRID_H_

#include <memory>
#include <vector>

enum RMQStructureType
{ NAIVE = 0,
  PREPROCESS_NAIVE =1,
  BLOCK=2,
  SPARSE=3
};


template<class T>
class RangeMinimumHybrid: public RangeMinimumQuery<T>
{
private:
            vector<unique_ptr<RangeMinimumQuery<T>>> eachBlockRMQStructure;
            unique_ptr<RangeMinimumQuery<T>> blockMinimaRMQStructure;
            RMQStructureType blockMimimaRMQType; 
	    RMQStructureType eachBlockRMQType;
	    size_t blockSize;
	    void create_rmq_block_minima(const vector<T>& elements);
	    void create_rmq_each_block(const vector<T>& elements);
public:
	RangeMinimumHybrid();
	RangeMinimumHybrid(RMQStructureType rBlockMinimaRMQType, RMQStructureType rEachBlockRMQType);
	RangeMinimumHybrid(size_t sBlockSize,RMQStructureType rBlockMinimaRMQType, RMQStructureType rEachBlockRMQType, const vector<T>& elements);
	void build(size_t sBlockSize, const vector<T>& elements);
	void build(size_t sBlockSize, RMQStructureType rBlockMinimaRMQType, RMQStructureType rEachBlockRMQType, const vector<T>& elements);
	T range_minimum(size_t index_a, size_t index_b)const;
};

#endif

