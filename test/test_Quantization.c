#include "unity.h"
#include "Quantization.h"
#include "Common.h"

void setUp(void){}

void tearDown(void){}

void test_quantizationFunction_given_8by8_matrix_should_output_quantized_matrix(void){
	int size = 8;
  float inputMatrix[8][8] = {{162.250, 40.599, 20.003, 72.329, 30.250, 12.485, -19.650, -11.497},
                             {30.479, 108.416, 10.473, 32.293, 27.699, -15.505, 18.408, -1.996},
                             {-94.145, -60.051, 12.298, -43.419, -31.288, -6.067, -3.331, 7.144},
                             {-38.568, -83.358, -5.412, -22.170, -13.520, 15.492, -1.332, 3.535},
                             {-31.250, 17.934, -5.524, -12.356, 14.250, -5.962, 11.488, -6.024},
                             {-0.865, -11.764, 12.776, 0.181, 28.071, 12.573, 8.353, 2.936},
                             {4.630, -2.421, 12.169, 6.561, -18.700, -12.753, 7.702, 12.031},
                             {-9.953, 11.194, 7.812, -16.289, 21.465, 0.022, 5.906, 10.681}};
                             
  quantizationFunction(size, inputMatrix);
  
  // dumpMatrix(size, inputMatrix);
  
  TEST_ASSERT_EQUAL(10, inputMatrix[0][0]);
  TEST_ASSERT_EQUAL(4, inputMatrix[0][1]);
  TEST_ASSERT_EQUAL(2, inputMatrix[0][2]);
  TEST_ASSERT_EQUAL(5, inputMatrix[0][3]);
  TEST_ASSERT_EQUAL(1, inputMatrix[0][4]);
  TEST_ASSERT_EQUAL(0, inputMatrix[0][5]);
  TEST_ASSERT_EQUAL(0, inputMatrix[0][6]);
  TEST_ASSERT_EQUAL(0, inputMatrix[0][7]);
}

void test_dequantizationFunction_given_8by8_matrix_should_output_original_matrix_with_data_loss(){
	int size = 8;
  float inputMatrix[8][8] = {{10, 4, 2, 5, 1, 0, 0, 0},
                             {3, 9, 1, 2, 1, 0, 0, 0},
                             {-7, -5, 1, -2, -1, 0, 0, 0},
                             {-3, -5, 0, -1, 0, 0, 0, 0},
                             {-2, 1, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0}};
                             
  dequantizationFunction(size, inputMatrix);
  
  dumpMatrix(size, inputMatrix);

  TEST_ASSERT_EQUAL(160, inputMatrix[0][0]);
  TEST_ASSERT_EQUAL(44, inputMatrix[0][1]);
  TEST_ASSERT_EQUAL(20, inputMatrix[0][2]);
  TEST_ASSERT_EQUAL(80, inputMatrix[0][3]);
  TEST_ASSERT_EQUAL(24, inputMatrix[0][4]);
  TEST_ASSERT_EQUAL(0, inputMatrix[0][5]);
  TEST_ASSERT_EQUAL(0, inputMatrix[0][6]);
  TEST_ASSERT_EQUAL(0, inputMatrix[0][7]);
}