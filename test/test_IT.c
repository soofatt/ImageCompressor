#include "unity.h"
#include "DCT.h"
#include "IDCT.h"

void setUp(void){}

void tearDown(void){}

void test_DCT_transform_array_of_3_elements_and_should_invert_back_to_original_by_IDCT(){
  float imageMatrix[3] = {1, 2, 3};
  float DCTArray[3] = {0};
  
  DCT_Function(DCTArray, imageMatrix, sizeof(DCTArray)/sizeof(float));
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 3.464, DCTArray[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -1.414, DCTArray[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, DCTArray[2]);
  
  oneD_IDCT(DCTArray, 3);
  round_float(DCTArray, 3);
  
  TEST_ASSERT_EQUAL(1,DCTArray[0]);
  TEST_ASSERT_EQUAL(2,DCTArray[1]);
  TEST_ASSERT_EQUAL(3,DCTArray[2]);
}

void test_DCT_transform_array_of_8_elements_and_should_invert_back_to_original_by_IDCT(){
  float imageMatrix[8] = {1,2,3,4,5,6,7,8};
  float DCTArray[8] = {0};

  DCT_Function(DCTArray, imageMatrix, sizeof(DCTArray)/sizeof(float));
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 12.727, DCTArray[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -6.442, DCTArray[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, DCTArray[2]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0.673, DCTArray[3]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, DCTArray[4]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0.200, DCTArray[5]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, DCTArray[6]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0.050, DCTArray[7]);
  
  oneD_IDCT(DCTArray, 8);
  round_float(DCTArray, 8);
  
  TEST_ASSERT_EQUAL(1,DCTArray[0]);
  TEST_ASSERT_EQUAL(2,DCTArray[1]);
  TEST_ASSERT_EQUAL(3,DCTArray[2]);
  TEST_ASSERT_EQUAL(4,DCTArray[3]);
  TEST_ASSERT_EQUAL(5,DCTArray[4]);
  TEST_ASSERT_EQUAL(6,DCTArray[5]);
  TEST_ASSERT_EQUAL(7,DCTArray[6]);
  TEST_ASSERT_EQUAL(8,DCTArray[7]);
}


