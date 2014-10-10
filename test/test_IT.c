#include "unity.h"
#include "DCT.h"
#include "IDCT.h"

void setUp(void){}

void tearDown(void){}

void test_DCT_transform_array_and_should_invert_back_to_original_by_IDCT(){
  int imageMatrix[3] = {1, 2, 3};
  float DCTArray[3] = {0};
  int invTransVal[3];
  
  DCT_Function(DCTArray, imageMatrix, sizeof(DCTArray)/sizeof(float));
  
  oneD_IDCT(DCTArray, invTransVal, 0, 3);
  oneD_IDCT(DCTArray, invTransVal, 1, 3);
  oneD_IDCT(DCTArray, invTransVal, 2, 3);
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 3.464, DCTArray[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -1.414, DCTArray[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, DCTArray[2]);
  
  TEST_ASSERT_EQUAL(1,invTransVal[0]);
  TEST_ASSERT_EQUAL(2,invTransVal[1]);
  TEST_ASSERT_EQUAL(3,invTransVal[2]);
}


