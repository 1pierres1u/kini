#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <gtest/gtest.h>
#include "../include/RangeMinimumBlock.hpp"
using namespace std;
/** 
 * FAILURE TEST
 *
 * Situations when an exception should be
 * thrown. They take when calling the method build
 * or the constructor.
 */


/**
 * @def TEST(RangeMinimumBlock,BUILD_METHOD_FAILURE)
 * @brief Throw an error
 *        > calling build(sBlockSize, const vector<T>& V)
 *                  RangeMinimumBlock(sBlockSize, const vector<T>& V)
 *          if sBlockSize <= 1 or
 *             sBlockSize > size of V
 *             V is empty
 */
TEST(RangeMinimumBlock,BUILD_METHOD_FAILURE)
{ vector<int> V(9,1);
  vector<int> U;
  RangeMinimumBlock<int> R;
  try
  { R.build(0,V);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const &err)
  { EXPECT_EQ(err.what(),std::string("sBlockSize<=1"));
  }
  try
  { R.build(11,V);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const &err)
  { EXPECT_EQ(err.what(),std::string("sBlockSize >= size of vector"));
  }
  try
  { R.build(U);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const &err)
  { EXPECT_EQ(err.what(),std::string("vElements is empty"));
  }
}

/**
 * @def TEST(RangeMinimumBlock,RANGE_MINIMUM_METHOD_FAILURE)
 * @brief Throw an error
 *        > calling range_minimum(index_a,index_b)
 *          if index_a > index_b
 *          if index_a and/or index_b greater/equal to size of vector 
 */
TEST(RangeMinimumBlock,RANGE_MINIMUM_METHOD_FAILURE)
{ vector<int> V(10,1);
  RangeMinimumBlock<int> R;
  R.build(3,V);
  try
  { R.range_minimum(4,3);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const& err)
  { EXPECT_EQ(err.what(),std::string("index_a > index_b"));
  }
  try
  { R.range_minimum(10,20);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const& err)
  { EXPECT_EQ(err.what(),std::string("index_a >= size of _vector"));
  }
  try
  { R.range_minimum(4,20);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const& err)
  { EXPECT_EQ(err.what(),std::string("index_b >= size of _vector"));
  }
}

/**
 * @def TEST(RangeMinimumBlock, CONSTRUCTOR_FAILURE)
 * @bried throw an error  
 *        > calling a contructor 
 *          if vector is empty
 *          if size of block >= size of vector
 *          if size of block <= 1
 */          

TEST(RangeMinimumBlock,CONSTRUCTOR_FAILURE)
{ vector<int> V(10,1);
  vector<int> U;
  try
  { RangeMinimumBlock<int> R(0,V);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const &err)
  { EXPECT_EQ(err.what(),std::string("blockSize <= 1"));
  }
  try
  { RangeMinimumBlock<int> R(1,V);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const &err)
  { EXPECT_EQ(err.what(),std::string("blockSize <= 1"));
  }
  try
  { RangeMinimumBlock<int> R(2,U);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const &err)
  { EXPECT_EQ(err.what(),std::string("vElements is empty"));
  }
  try
  { RangeMinimumBlock<int> R(10,V);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const &err)
  { EXPECT_EQ(err.what(),std::string("blockSize >= size of vector"));
  }
  try
  { RangeMinimumBlock<int> R(11,V);
    FAIL() << "Expected std::out_of_range";
  }
  catch(std::out_of_range const &err)
  { EXPECT_EQ(err.what(),std::string("blockSize >= size of vector"));
  }
}


/**
 * blockOfMinima Test
 * Test that the blockOfMinima vector built is correct.
 */
TEST(RangeMinimumBlock, blockOfMinima_CONSTRUCTION)
{vector<int> V(10,1);
 RangeMinimumBlock<int> R(2,V);
 vector<int> B(5,1);
 vector<int> block = R.blockOfMinima_();
 EXPECT_EQ(1,equal(B.begin(),B.end(),block.begin()));

 R.build(3,V);
 vector<int> B1(4,1);
 block = R.blockOfMinima_();
 EXPECT_EQ(1,equal(B1.begin(),B1.end(),block.begin()));

 vector<int> V1{1,2,3,4,5,6,7,8,9};
 R.build(2,V1);
 vector<int> B2{1,3,5,7,9};
 block = R.blockOfMinima_();
 EXPECT_EQ(1,equal(B2.begin(),B2.end(),block.begin())); 

 vector<int> V2{1,-1,3,-1,5,6,7,8,-1};
 R.build(3,V2);
 vector<int> B3{-1,-1,-1};
 block = R.blockOfMinima_();
 EXPECT_EQ(1,equal(B3.begin(),B3.end(),block.begin())); 

 R.build(V);
 vector<int> V3(5,1);
 block = R.blockOfMinima_();
 EXPECT_EQ(2,R.blockSize_());
 EXPECT_EQ(1,equal(V3.begin(),V3.end(),block.begin()));

 //When the vector size is between 1 and 3 and the method
 //build(vector only) or the constructor was used
 //a naive approach is used to find the range minimum. 
 //In this case the blockSize is set to 0 and the
 //blockOfMinima is empty.
 vector<int> V4{1,2,3};
 R.build(V4);
 EXPECT_EQ(0,R.blockSize_());
 EXPECT_EQ(0,R.blockOfMinima_().size());

 RangeMinimumBlock<int> R2(V4);
 EXPECT_EQ(0,R2.blockSize_());
 EXPECT_EQ(0,R2.blockOfMinima_().size());

 vector<int> V5{1,2};
 R.build(V5);
 EXPECT_EQ(0,R.blockSize_());
 EXPECT_EQ(0,R.blockOfMinima_().size());

 RangeMinimumBlock<int> R3(V5);
 EXPECT_EQ(0,R3.blockSize_());
 EXPECT_EQ(0,R3.blockOfMinima_().size());
 

 vector<int> V6{1,2};
 R.build(V6);
 EXPECT_EQ(0,R.blockSize_());
 EXPECT_EQ(0,R.blockOfMinima_().size());

 RangeMinimumBlock<int> R4(V6);
 EXPECT_EQ(0,R4.blockSize_());
 EXPECT_EQ(0,R4.blockOfMinima_().size());
}


