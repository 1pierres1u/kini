#include <iostream>
#include <vector>
#include <gtest/gtest.h>
#include "../include/RangeMinimumNaive.hpp"
using namespace std;

TEST(RangeMinimumNaive,VECTOR_WITH_SAME_ELEMENTS)
{ vector<int> V(20,1);
  RangeMinimumNaive<int> R(V);
  for(size_t i=0; i<V.size()-1; i++)
	  EXPECT_EQ(1,R.range_minimum(0,i+1));
}

TEST(RangeMinimumNaive,INTERVAL_WITH_ONE_ELEMENT)
{ vector<int> V{1,2,3,4,5,6,7,8,9,10,11,12};
  RangeMinimumNaive<int> R(V);
  for(size_t i=0; i<V.size(); i++)
	  EXPECT_EQ(i+1,R.range_minimum(i,i));
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

/**
 * @def TEST(RangeMinimumNaive,OUT_OF_RANGE)
 * @brief throw an error when 
 *        calling range_minimum(index_a,index_b)
 *        if index out of range 
 *        if index_a is greater than index_b
 */
TEST(RangeMinimumNaive,OUT_OF_RANGE)
{
 vector<int> V{1,2,3,4,5,6};
 RangeMinimumNaive<int> R(V); 
 try
 { R.range_minimum(3,2);
   FAIL() << "Expected std::out_of_range"; 
 }
 catch(std::out_of_range const &err)
 {EXPECT_EQ(err.what(),std::string("index_a > index_b"));
 }
 try
 { R.range_minimum(2,30);
   FAIL() << "Expected std::out_of_range"; 
 }
 catch(std::out_of_range const &err)
 {EXPECT_EQ(err.what(),std::string("index_b >= size of vector"));
 }
 try
 { R.range_minimum(20,30);
   FAIL() << "Expected std::out_of_range"; 
 }
 catch(std::out_of_range const &err)
 {EXPECT_EQ(err.what(),std::string("index_a >= size of vector"));
 }
}
