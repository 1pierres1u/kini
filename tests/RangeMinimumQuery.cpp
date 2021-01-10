#include "../include/RangeMinimumQueryNaive.hpp"
#include "../include/RangeMinimumQueryBlock.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;


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
  RangeMinimumQueryNaive<int> R;
  R.build(V);
  for(size_t i=0; i<20; i++)
  { for(size_t j=i; j<20; j++)
    { EXPECT_EQ(V[i],R.range_minimum(i,j));
    }
  }
}

TEST(RangeMinimumQueryBlock,IDENTICAL_ELEMENTS)
{ vector<int> V(20,1);
  RangeMinimumQueryBlock<int> R;
  R.build(V);
  for(size_t i=0; i<20; i++)
  { for(size_t j=i; j<20; j++)
    { EXPECT_EQ(1,R.range_minimum(i,j));
    }
  }
}
TEST(RangeMinimumQueryBlock,MINIMUM_START_VECTOR)
{ vector<int> V(20);
  iota(V.begin(),V.end(),-1);
  RangeMinimumQueryBlock<int> R;
  R.build(V);
  for(size_t i=0; i<20; i++)
  { for(size_t j=i; j<20; j++)
    { EXPECT_EQ(V[i],R.range_minimum(i,j));
    }
  }
}

