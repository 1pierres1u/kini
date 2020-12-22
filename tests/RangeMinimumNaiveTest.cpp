#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "../include/RangeMinimumNaive.hpp"
using namespace std;

TEST(RangeMinimumNaive,VECTOR_WITH_SAME_ELEMENTS)
{ vector<int> V(20,1);
  RangeMinimumNaive<int> R(V);
  for(size_t i=0; i<V.size(); i++)
	  EXPECT_EQ(1,R.range_minimum(0,i+1));
}

TEST(RangeMinimumNaive,INTERVAL_WITH_ONE_ELEMENT)
{ vector<int> V{1,2,3,4,5,6,7,8,9,10,11,12};
  RangeMinimumNaive<int> R(V);
  for(size_t i=0; i<V.size(); i++)
	  EXPECT_EQ(i+1,R.range_minimum(i,i));
}

TEST(RangeMinimumNaive,MINIMUM_AT_START_INTERVAL)
{ size_t N = 40;
  size_t K = 10;
  vector<int> V(N);
  for(size_t i=0; i<N;i++)
	  V[i]=i;
  RangeMinimumNaive<int> R(V);
  for(size_t i=0; i<V.size()-K; i++)
  {
	  EXPECT_EQ(i,R.range_minimum(i,i+1));
	  EXPECT_EQ(i,R.range_minimum(i,i+2));
	  EXPECT_EQ(i,R.range_minimum(i,i+3));
  }
}

TEST(RangeMinimumNaive,MINIMUM_AT_END_INTERVAL)
{ size_t N = 40;
  size_t K = 10;
  vector<int> V(N);
  for(size_t i=0; i<N;i++)
	  V[N-i-1]=i;
  RangeMinimumNaive<int> R(V);
  for(size_t i=N-1; i>4; i--)
  {
	  EXPECT_EQ(N-1-i,R.range_minimum(i-1,i));
	  EXPECT_EQ(N-1-i,R.range_minimum(i-2,i));
	  EXPECT_EQ(N-1-i,R.range_minimum(i-3,i));
  }
}
