#include "../include/RangeMinimumQueryNaive.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


TEST(RangeMinimumQueryNaive,FAILURE_RANGE_MINIMUM)
{ vector<int> V(20);
  RangeMinimumQueryNaive<int> R(V);
  try
  { R.range_minimum(1,0);
    FAIL() << "Expected out of range"; 	  
  }
  catch(std::out_of_range const& err)
  {EXPECT_EQ(err.what(),string("index_a > index_b"));
  }
  try
  { R.range_minimum(1,40);
    FAIL() << "Expected out of range"; 	  
  }
  catch(std::out_of_range const& err)
  {EXPECT_EQ(err.what(),string("index_b out of bound"));
  }
  try
  { R.range_minimum(51,61);
    FAIL() << "Expected out of range"; 	  
  }
  catch(std::out_of_range const& err)
  {EXPECT_EQ(err.what(),string("index_a out of bound"));
  }
}

TEST(RangeMinimumQueryNaive,IDENTICAL_ELEMENTS)
{ vector<int> V(20,1);
  RangeMinimumQueryNaive<int> R(V);
  for(size_t i=0; i<20; i++)
  { for(size_t j=i; j<20; j++)
    { EXPECT_EQ(1,R.range_minimum(i,j));
    }
  }
}
TEST(RangeMinimumQueryNaive,MINIMUM_START_VECTOR)
{ vector<int> V(20);
  iota(V.begin(),V.end(),-1);
  RangeMinimumQueryNaive<int> R(V);
  for(size_t i=0; i<20; i++)
  { for(size_t j=i; j<20; j++)
    { EXPECT_EQ(V[i],R.range_minimum(i,j));
    }
  }
}
