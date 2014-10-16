#include "unity.h"
#include "DCT.h"

void setUp(){}

void tearDown(){}

void test_cos_DCT_case1(){
	float result;
	
	result = cos_DCT(0, 1, 3);
	
	TEST_ASSERT_FLOAT_WITHIN(0.001, 0.866, result);
}

void test_cos_DCT_case2(){
	float result;
	
	result = cos_DCT(2, 1, 3);
	
	TEST_ASSERT_FLOAT_WITHIN(0.001, -0.866, result);
}

void test_cos_DCT_case3(){
	float result;
	
	result = cos_DCT(2, 2, 3);
	
	TEST_ASSERT_FLOAT_WITHIN(0.001, 0.5, result);
}

void test_cos_DCT_case4(){
	float result;
	
	result = cos_DCT(5, 1, 4);
	
	TEST_ASSERT_FLOAT_WITHIN(0.001, -0.382, result);
}

void test_adderFunction_case1(){
  float result;
  float imageMatrix[3] = {1, 2, 3};
  
  result = adderFunction(imageMatrix, 1, 3);
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, -1.732, result);
}

void test_adderFunction_case2(){
  float result;
  float imageMatrix[3] = {1, 2, 3};
  
  result = adderFunction(imageMatrix, 2, 3);
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, result);
}

void test_oneD_DCT_with_3_elements(){
  float imageMatrix[3] = {1, 2, 3};
  
  int numOfElem = sizeof(imageMatrix)/sizeof(float);
  
  oneD_DCT(imageMatrix, numOfElem);
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 3.464, imageMatrix[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -1.414, imageMatrix[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2]);
}

void test_oneD_DCT_with_8_elements(){
  float imageMatrix[8] = {8, 7, 6, 5, 4, 3, 2, 1};
  
  int numOfElem = sizeof(imageMatrix)/sizeof(float);
  
  oneD_DCT(imageMatrix, numOfElem);
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 12.727, imageMatrix[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 6.442, imageMatrix[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0.673, imageMatrix[3]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0, imageMatrix[4]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0.200, imageMatrix[5]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[6]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0.050, imageMatrix[7]);
}

void test_2D_DCTFunction_given_3by3_matrix_1_2_3(){
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
  
}