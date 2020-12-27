#include <iostream>
#include <gtest/gtest.h>
#include "../include/RangeMinimumQuery.hpp"
#include "../include/RangeMinimumNaive.hpp"
#include "../include/RangeMinimumPreprocessNaive.hpp"
#include "../include/RangeMinimumSparse.hpp"
#include "../include/RangeMinimumBlock.hpp"
#include "../include/RangeMinimumHybrid.hpp"
#include <vector>
#include <algorithm>
#include <numeric>
#include <memory>
using namespace std;


template<class T>
void minimum_start_interval(const vector<T>& V, shared_ptr<RangeMinimumQuery<T>> R)
{size_t N = V.size();
 for(size_t i=0; i<N; i++)
	for(size_t j=i; j<N;j++)
		EXPECT_EQ(V[i],R->range_minimum(i,j));
}
template<class T>
void test_start_interval(const vector<vector<T>>& V, shared_ptr<RangeMinimumQuery<T>> R)
{ for(auto& v: V)
  { R->build(v);
    minimum_start_interval(v,R);
  }
}


/**
 * QUERY TEST
 * The query method of the 5 implementations of the abstract class RangeMinimumQuery 
 * are tested here.
 */


void initialize_vectors_int(vector<vector<int>>& V)
{
V.push_back(vector<int>(1,1));
V.push_back(vector<int>(2,1));
V.push_back(vector<int>(3,1));
V.push_back(vector<int>(4,1));
V.push_back(vector<int>(40));
iota(V[4].begin(),V[4].end(),0);
}

  
TEST(RangeMinimumBlock,MINIMUM_START_INTERVAL)
{ vector<vector<int>> V;
  initialize_vectors_int(V);
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumBlock<int>>();
  test_start_interval(V,R);
}
TEST(RangeMinimumNaive,MINIMUM_START_INTERVAL)
{ vector<vector<int>> V;
  initialize_vectors_int(V);
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumNaive<int>>();
  test_start_interval(V,R);
}
TEST(RangeMinimumPreprocessNaive,MINIMUM_START_INTERVAL)
{ vector<vector<int>> V;
  initialize_vectors_int(V);
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumPreprocessNaive<int>>();
  test_start_interval(V,R);
}
TEST(RangeMinimumSparse,MINIMUM_START_INTERVAL)
{ vector<vector<int>> V;
  initialize_vectors_int(V);
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumSparse<int>>();
  test_start_interval(V,R);
}
TEST(RangeMinimumHybrid,MINIMUM_START_INTERVAL)
{ vector<vector<int>> V;
  initialize_vectors_int(V);
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumHybrid<int>>();
  test_start_interval(V,R);
}
