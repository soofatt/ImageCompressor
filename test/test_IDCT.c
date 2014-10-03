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