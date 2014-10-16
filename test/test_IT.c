#include "unity.h"
#include "DCT.h"
#include "IDCT.h"

void setUp(void){}

void tearDown(void){}

void test_DCT_transform_array_of_3_elements_and_should_invert_back_to_original_by_IDCT(){
  float imageMatrix[3] = {1, 2, 3};
  
  oneD_DCT(imageMatrix, sizeof(imageMatrix)/sizeof(float));
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 3.464, imageMatrix[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -1.414, imageMatrix[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2]);
  
  oneD_IDCT(imageMatrix, 3);
  round_float(imageMatrix, 3);
  
  TEST_ASSERT_EQUAL(1,imageMatrix[0]);
  TEST_ASSERT_EQUAL(2,imageMatrix[1]);
  TEST_ASSERT_EQUAL(3,imageMatrix[2]);
}

void test_DCT_transform_array_of_8_elements_and_should_invert_back_to_original_by_IDCT(){
  float imageMatrix[8] = {1,2,3,4,5,6,7,8};

  oneD_DCT(imageMatrix, sizeof(imageMatrix)/sizeof(float));
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 12.727, imageMatrix[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -6.442, imageMatrix[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0.673, imageMatrix[3]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[4]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0.200, imageMatrix[5]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[6]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0.050, imageMatrix[7]);
  
  oneD_IDCT(imageMatrix, 8);
  round_float(imageMatrix, 8);
  
  TEST_ASSERT_EQUAL(1,imageMatrix[0]);
  TEST_ASSERT_EQUAL(2,imageMatrix[1]);
  TEST_ASSERT_EQUAL(3,imageMatrix[2]);
  TEST_ASSERT_EQUAL(4,imageMatrix[3]);
  TEST_ASSERT_EQUAL(5,imageMatrix[4]);
  TEST_ASSERT_EQUAL(6,imageMatrix[5]);
  TEST_ASSERT_EQUAL(7,imageMatrix[6]);
  TEST_ASSERT_EQUAL(8,imageMatrix[7]);
}

void test_two_D_DCT_transform_array_of_3_elements_and_should_invert_back_to_original_by_IDCT(){
  float imageMatrix[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  int size = 3;
  
  twoD_DCT(size, imageMatrix);
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 5.999, imageMatrix[0][0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -2.449, imageMatrix[0][1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[0][2]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[1][0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[1][1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[1][2]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2][0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2][1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2][2]);
  
  twoD_IDCT(size, imageMatrix);
  
  TEST_ASSERT_EQUAL(1,imageMatrix[0][0]);
  TEST_ASSERT_EQUAL(1,imageMatrix[1][0]);
  TEST_ASSERT_EQUAL(1,imageMatrix[2][0]);
  TEST_ASSERT_EQUAL(2,imageMatrix[0][1]);
  TEST_ASSERT_EQUAL(2,imageMatrix[1][1]);
  TEST_ASSERT_EQUAL(2,imageMatrix[2][1]);
  TEST_ASSERT_EQUAL(3,imageMatrix[0][2]);
  TEST_ASSERT_EQUAL(3,imageMatrix[1][2]);
  TEST_ASSERT_EQUAL(3,imageMatrix[2][2]);
}


