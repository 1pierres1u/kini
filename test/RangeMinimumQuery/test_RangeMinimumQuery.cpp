#include "RangeMinimumQueryNaive.hpp"
#include "RangeMinimumQueryBlock.hpp"
#include "gtest/gtest.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include <fstream>
#include <memory>

using namespace std;


//TEST_TYPE can take the values "unique" or "thorough".
//"unique"   means only the range minimum over the whole vector
//"thorough" means all the ranges are tested
string TEST_TYPE="unique";

void build_vector(vector<int>& V,size_t size, string type="")
{ srand(0); //all the shuffled vectors will be the same
  V = vector<int>(size,1);
  if(type=="increasing")
  { iota(V.begin(),V.end(),0);
  }
  else if(type=="decreasing")
  { iota(V.begin(),V.end(),0);
    reverse(V.begin(),V.end());
  }
  else if(type=="shuffled")
  { 
    size_t N = V.size();
    for(auto& x:V)
  	x = rand()%N;	    
  }
}


void p_rmq_test_vector(const vector<int>& V,shared_ptr<PRangeMinimumQuery<int>> R){  
   size_t N = V.size();
   R->preprocess(&V);
   if(TEST_TYPE=="unique"){
	EXPECT_EQ(R->min(0,N-1),R->find_range_minimum(0,N-1));
   }
   else if(TEST_TYPE=="thorough"){
   	for(size_t i=0; i<N ; i++){ 
		   for(size_t j=i; j<N; j++){ 
			EXPECT_EQ(R->min(i,j),R->find_range_minimum(i,j));
      	           }
   	}
   }
}
void rmq_test_vector(const vector<int>& V,shared_ptr<RangeMinimumQuery<int>> R){  
   size_t N = V.size();
   R->preprocess(V);
   if(TEST_TYPE=="unique"){
	EXPECT_EQ(R->min(0,N-1),R->find_range_minimum(0,N-1));
   }
   else if(TEST_TYPE=="thorough"){
   	for(size_t i=0; i<N ; i++){ 
		   for(size_t j=i; j<N; j++){ 
			EXPECT_EQ(R->min(i,j),R->find_range_minimum(i,j));
      	           }
   	}
   }
}
void p_testing_rmq(size_t v_min_size, size_t v_max_size, shared_ptr<PRangeMinimumQuery<int>> rmq)
{ vector<int> V;
  for(size_t T=v_min_size; T<v_max_size; T++)
  { build_vector(V,T);
    p_rmq_test_vector(V,rmq);
    build_vector(V,T,"increasing");
    p_rmq_test_vector(V,rmq);
    build_vector(V,T,"decreasing");
    p_rmq_test_vector(V,rmq);
    build_vector(V,T,"shuffled");
    p_rmq_test_vector(V,rmq);
  }
}
void testing_rmq(size_t vector_min_size, size_t vector_max_size,shared_ptr<RangeMinimumQuery<int>> rmq)
{ vector<int> V;
  for(size_t T=vector_min_size; T<vector_max_size; T++)
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
/*******************************************/
/* RANGEMINIMUMQUERYNAIVE                  */
/*******************************************/
//
TEST(RangeMinimumQueryNaive,vector_size_1_to_100_thorough_test)
{ TEST_TYPE = "thorough";
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumQueryNaive<int>>();
  testing_rmq(1,100,R);
}
TEST(PRangeMinimumQueryNaive,vector_size_1_to_100_thorough_test)
{ TEST_TYPE = "thorough";
  shared_ptr<PRangeMinimumQuery<int>> R = make_shared<PRangeMinimumQueryNaive<int>>();
  p_testing_rmq(1,100,R);
}
//
TEST(RangeMinimumQueryNaive,vector_size_200_to_300_thorough_test)
{ TEST_TYPE = "thorough";
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumQueryNaive<int>>();
  testing_rmq(200,300,R);
}
TEST(PRangeMinimumQueryNaive,vector_size_200_to_300_thorough_test)
{ TEST_TYPE = "thorough";
  shared_ptr<PRangeMinimumQuery<int>> R = make_shared<PRangeMinimumQueryNaive<int>>();
  p_testing_rmq(200,300,R);
}
//
TEST(RangeMinimumQueryNaive,vector_size_10_to_100_unique_test)
{ TEST_TYPE = "unique";
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumQueryNaive<int>>();
  testing_rmq(10,100,R);
}
TEST(PRangeMinimumQueryNaive,vector_size_10_to_100_unique_test)
{ TEST_TYPE = "unique";
  shared_ptr<PRangeMinimumQuery<int>> R = make_shared<PRangeMinimumQueryNaive<int>>();
  p_testing_rmq(10,100,R);
}
//
TEST(RangeMinimumQueryNaive,vector_size_1500000_to_1500050_unique_test)
{ TEST_TYPE = "unique";
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumQueryNaive<int>>();
  testing_rmq(1500000,1500050,R);
}
TEST(PRangeMinimumQueryNaive,vector_size_1500000_to_1500050_unique_test)
{ TEST_TYPE = "unique";
  shared_ptr<PRangeMinimumQuery<int>> R = make_shared<PRangeMinimumQueryNaive<int>>();
  p_testing_rmq(1500000,1500050,R);
}

/*******************************************/
/* RANGEMINIMUMQUERYBLOCK                  */
/*******************************************/
//
TEST(RangeMinimumQueryBlock,vector_size_10_to_100_thorough_test)
{ TEST_TYPE = "thorough";
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumQueryBlock<int>>();
  testing_rmq(10,100,R);
}
TEST(PRangeMinimumQueryBlock,vector_size_10_to_100_thorough_test)
{ TEST_TYPE = "thorough";
  shared_ptr<PRangeMinimumQuery<int>> R = make_shared<PRangeMinimumQueryBlock<int>>();
  p_testing_rmq(10,100,R);
}
//
TEST(RangeMinimumQueryBlock,vector_size_200_to_300_thorough_test)
{ TEST_TYPE = "thorough";
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumQueryBlock<int>>();
  testing_rmq(200,300,R);
}
TEST(PRangeMinimumQueryBlock,vector_size_200_to_300_thorough_test)
{ TEST_TYPE = "thorough";
  shared_ptr<PRangeMinimumQuery<int>> R = make_shared<PRangeMinimumQueryBlock<int>>();
  p_testing_rmq(200,300,R);
}
//
TEST(RangeMinimumQueryBlock,vector_size_10_to_100_unique_test)
{ TEST_TYPE = "unique";
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumQueryBlock<int>>();
  testing_rmq(10,100,R);
}
TEST(PRangeMinimumQueryBlock,vector_size_10_to_100_unique_test)
{ TEST_TYPE = "unique";
  shared_ptr<PRangeMinimumQuery<int>> R = make_shared<PRangeMinimumQueryBlock<int>>();
  p_testing_rmq(10,100,R);
}
//
TEST(RangeMinimumQueryBlock,vector_size_1500000_to_1500050_unique_test)
{ TEST_TYPE = "unique";
  shared_ptr<RangeMinimumQuery<int>> R = make_shared<RangeMinimumQueryBlock<int>>();
  testing_rmq(1500000,1500050,R);
}
TEST(PRangeMinimumQueryBlock,vector_size_1500000_to_1500050_unique_test)
{ TEST_TYPE = "unique";
  shared_ptr<PRangeMinimumQuery<int>> R = make_shared<PRangeMinimumQueryBlock<int>>();
  p_testing_rmq(1500000,1500050,R);
}
