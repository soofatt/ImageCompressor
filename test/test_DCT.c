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
  int imageMatrix[3] = {1, 2, 3};
  
  result = adderFunction(imageMatrix, 1, 3);
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, -1.732, result);
}

void test_adderFunction_case2(){
  float result;
  int imageMatrix[3] = {1, 2, 3};
  
  result = adderFunction(imageMatrix, 2, 3);
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, result);
}

void test_DCT_Function(){
  int imageMatrix[3] = {1, 2, 3};
  float DCTArray[3] = {0};
  
  DCT_Function(DCTArray, imageMatrix, sizeof(DCTArray)/sizeof(float));
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 3.464, DCTArray[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -1.414, DCTArray[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, DCTArray[2]);
}