#include "RangeMinimumQueryNaive.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <fstream>
#include <memory>

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

void rmq_test_vector(const vector<int>& V,shared_ptr<RangeMinimumQuery<int>> R){  
   size_t N = V.size();
   R->preprocess(make_shared<const vector<int>>(V));
   for(size_t i=0; i<N ; i++){ 
	   for(size_t j=i; j<N; j++){ 
		EXPECT_EQ(R->min(i,j),R->find_range_minimum(i,j));
      }
   }
}

void testing_rmq(shared_ptr<RangeMinimumQuery<int>> rmq)
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
TEST(RangeMinimumQueryNaive,TEST_QUERY)
{ 
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumQueryNaive<int>>();
  testing_rmq(R);
}
