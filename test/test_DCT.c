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
