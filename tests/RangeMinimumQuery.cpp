#include "../include/RangeMinimumQueryNaive.hpp"
#include "../include/RangeMinimumQueryBlock.hpp"
#include "../include/RangeMinimumQuerySparse.hpp"
#include "../include/RangeMinimumQueryHybrid.hpp"
#include "../include/RangeMinimumQueryFischer.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <fstream>
using namespace std;

void build_vector(vector<int>& V,size_t size, string type="")
{ V = vector<int>(size,1);
  if(type=="increasing")
  { iota(V.begin(),V.end(),0);
  }
  else if(type=="decreasing")
  { iota(V.begin(),V.end(),0);
    reverse(V.begin(),V.end());
  }
  else if(type=="shuffled")
  { iota(V.begin(),V.end(),0);
    random_device rd;
    mt19937 g(rd());
    shuffle(V.begin(),V.end(),g); 
  }
}

void rmq_test_vector(const vector<int>& V,RangeMinimumQuery<int>* R)
{  size_t N = V.size();
   R->build(V);
   for(size_t i=0; i<N ; i++)
    { for(size_t j=i; j<N; j++)
      { int index_min = min_(V,i,j);
	EXPECT_EQ(V[index_min],R->range_minimum(i,j));
      }
    }
}

void testing_rmq(RangeMinimumQuery<int>* rmq)
{ vector<int> V;
  for(size_t T=1; T<190; T++)
  { build_vector(V,T);
    rmq_test_vector(V,rmq);
    build_vector(V,T,"increasing");
    rmq_test_vector(V,rmq);
    build_vector(V,T,"decreasing");
    rmq_test_vector(V,rmq);
    build_vector(V,T,"shuffled");
    rmq_test_vector(V,rmq);
  }
}

TEST(RangeMinimumQuerySparse,TEST_QUERY)
{ 
  RangeMinimumQuery<int>* R = new RangeMinimumQuerySparse<int>();
  testing_rmq(R);
}
TEST(RangeMinimumQueryNaive,TEST_QUERY)
{ 
  RangeMinimumQuery<int>* R = new RangeMinimumQueryNaive<int>();
  testing_rmq(R);
}
TEST(RangeMinimumQueryBlock,TEST_QUERY)
{ 
  RangeMinimumQuery<int>* R = new RangeMinimumQueryBlock<int>();
  testing_rmq(R);
}

TEST(RangeMinimumQueryHybrid,TEST_QUERY)
{ 
  RangeMinimumQuery<int>* R = new RangeMinimumQueryHybrid<int>();
  testing_rmq(R);
}

TEST(RangeMinimumQueryFischer,TEST_QUERY)
{ 
  RangeMinimumQuery<int>* R = new RangeMinimumQueryFischer<int>();
  testing_rmq(R);
}

