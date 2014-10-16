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
  float invTransVal[3];
  
  oneD_IDCT(transVal, invTransVal,3);
  round_float(invTransVal, 3);
  
  TEST_ASSERT_EQUAL(1,invTransVal[0]);
  TEST_ASSERT_EQUAL(2,invTransVal[1]);
  TEST_ASSERT_EQUAL(3,invTransVal[2]);
}

void test_square_root_function(){
  int val = 9, sq_rt;
  sq_rt = square_root(val);
  TEST_ASSERT_EQUAL(3,sq_rt);
}

void test_transpose_2D_should_tranpose_the_2D_array(){
  int size = 3;
  float input2D[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  float transpose2D[size][size];
  
  transpose_2D(size,input2D,transpose2D);
  TEST_ASSERT_EQUAL(1,transpose2D[0][0]);
  TEST_ASSERT_EQUAL(2,transpose2D[1][0]);
  TEST_ASSERT_EQUAL(3,transpose2D[2][0]);
  TEST_ASSERT_EQUAL(4,transpose2D[0][1]);
  TEST_ASSERT_EQUAL(5,transpose2D[1][1]);
  TEST_ASSERT_EQUAL(6,transpose2D[2][1]);
  TEST_ASSERT_EQUAL(7,transpose2D[0][2]);
  TEST_ASSERT_EQUAL(8,transpose2D[1][2]);
  TEST_ASSERT_EQUAL(9,transpose2D[2][2]);
}

void test_2D_IDCT_with_2D_array_should_get_back_the_origin_value(){
  int size = 3;
  float transVal[3][3] = {{5.999824,-2.449120,0},{-0,0,0},{-0,0,0}};
  float invTransVal[size][size];
  // 2d_Array[r][c]
  twoD_IDCT(size, transVal,invTransVal);
  
  // TEST_ASSERT_EQUAL(1,invTransVal[0][0]);
  // TEST_ASSERT_EQUAL(1,invTransVal[1][0]);
  // TEST_ASSERT_EQUAL(1,invTransVal[2][0]);
  // TEST_ASSERT_EQUAL(2,invTransVal[0][1]);
  // TEST_ASSERT_EQUAL(2,invTransVal[1][1]);
  // TEST_ASSERT_EQUAL(2,invTransVal[2][1]);
  // TEST_ASSERT_EQUAL(2,invTransVal[0][2]);
  // TEST_ASSERT_EQUAL(2,invTransVal[1][2]);
  // TEST_ASSERT_EQUAL(2,invTransVal[2][2]);
}










