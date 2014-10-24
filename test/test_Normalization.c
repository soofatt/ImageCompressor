#include "unity.h"
#include "Normalization.h"
#include "Common.h"

void setUp(void){}

void tearDown(void){}

void test_normalizeMatrix_given_3by3_matrix_should_subtract_128(void){
	float inputMatrix[3][3] = {{25, 86, 256}, {0, 47, 135}, {211, 11, 165}};
  int size = 3;
  
  normalizeMatrix(size, inputMatrix);
  
  // dumpMatrix(size, inputMatrix);
  
  TEST_ASSERT_EQUAL(-103, inputMatrix[0][0]);
  TEST_ASSERT_EQUAL(-42, inputMatrix[0][1]);
  TEST_ASSERT_EQUAL(128, inputMatrix[0][2]);
  TEST_ASSERT_EQUAL(-128, inputMatrix[1][0]);
  TEST_ASSERT_EQUAL(-81, inputMatrix[1][1]);
  TEST_ASSERT_EQUAL(7, inputMatrix[1][2]);
  TEST_ASSERT_EQUAL(83, inputMatrix[2][0]);
  TEST_ASSERT_EQUAL(-117, inputMatrix[2][1]);
  TEST_ASSERT_EQUAL(37, inputMatrix[2][2]);
}

void test_denormalizeMatrix_given_3by3_matrix_should_subtract_128(void){
	float inputMatrix[3][3] = {{-103, -42, 128}, {-128, -81, 7}, {83, -117, 37}};
  int size = 3;
  
  denormalizeMatrix(size, inputMatrix);
  
  // dumpMatrix(size, inputMatrix);
  
  TEST_ASSERT_EQUAL(25, inputMatrix[0][0]);
  TEST_ASSERT_EQUAL(86, inputMatrix[0][1]);
  TEST_ASSERT_EQUAL(256, inputMatrix[0][2]);
  TEST_ASSERT_EQUAL(0, inputMatrix[1][0]);
  TEST_ASSERT_EQUAL(47, inputMatrix[1][1]);
  TEST_ASSERT_EQUAL(135, inputMatrix[1][2]);
  TEST_ASSERT_EQUAL(211, inputMatrix[2][0]);
  TEST_ASSERT_EQUAL(11, inputMatrix[2][1]);
  TEST_ASSERT_EQUAL(165, inputMatrix[2][2]);
}
