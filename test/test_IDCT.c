#include "unity.h"
#include "IDCT.h"

void setUp(void){}

void tearDown(void){}

void test_cosine_function_to_evaluate_cos_180_degree(){
  float result;
  
  result = cos_IDCT(1,1);
	// printf("Cosine ans for 180 degree: %f\n",result);
  TEST_ASSERT_FLOAT_WITHIN(0.0001,-1.0000,result);
}

void test_cosine_function_to_evaluate_cos_90_degree(){
  float result;
  
  result = cos_IDCT(1,2);
	// printf("Cosine ans for 90 degree: %f\n",result);
  TEST_ASSERT_FLOAT_WITHIN(0.0001,0.0000,result);
}

void test_cosine_function_to_evaluate_cos_60_degree(){
  float result;
  
  result = cos_IDCT(1,3);
	// printf("Cosine ans for 60 degree: %f\n",result);
  TEST_ASSERT_FLOAT_WITHIN(0.0001,0.5000,result);
}

void test_cosine_function_to_evaluate_cos_45_degree(){
  float result;
  
  result = cos_IDCT(1,4);
	// printf("Cosine ans for 45 degree: %f\n",result);
  TEST_ASSERT_FLOAT_WITHIN(0.0001,0.7071,result);
}

void test_cosine_function_to_evaluate_cos_30_degree(){
  float result;
  
  result = cos_IDCT(1,6);
	// printf("Cosine ans for 30 degree: %f\n",result);
  TEST_ASSERT_FLOAT_WITHIN(0.0001,0.8660,result);
}

void test_cosine_function_to_evaluate_cos_0_degree(){
  float result;
  
  result = cos_IDCT(0,1);
	// printf("Cosine ans for 0 degree: %f\n",result);
  TEST_ASSERT_FLOAT_WITHIN(0.0001,1.0000,result);
}

void test_int_division_to_divide_1_by_3_should_return_0_dot_333(){
  float divideAns;
  divideAns = int_Divider(1,3);
  TEST_ASSERT_FLOAT_WITHIN(0.001,0.333,divideAns);
}

void test_oneD_IDCT_with_a_transform_array_should_return_1_2_3(){
  float transVal[] = {3.464, -1.414, 0};
  int invTransVal[3];
  
  oneD_IDCT(transVal, invTransVal,3);
  
  TEST_ASSERT_EQUAL(1,invTransVal[0]);
  TEST_ASSERT_EQUAL(2,invTransVal[1]);
  TEST_ASSERT_EQUAL(3,invTransVal[2]);
}



