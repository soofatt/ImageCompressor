#include "unity.h"
#include "Quantization.h"
#include "Common.h"

void setUp(void){}

void tearDown(void){}

#define TEST_ASSERT_EQUAL_MATRIX(expected, actual) \
  assert8by8Matrix(expected, actual, __LINE__);

void assert8by8Matrix(float expectedMatrix[][8], float actualMatrix[0][8], int line){
  int i, j;
  
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      TEST_ASSERT_FLOAT_WITHIN(0.5, expectedMatrix[i][j], actualMatrix[i][j]);
    }
  }
}

void test_quantizationFunction_for_luminance_given_8by8_matrix_should_output_quantized_matrix(void){
	int size = 8;
  float inputMatrix[8][8] = {{162.250, 40.599, 20.003, 72.329, 30.250, 12.485, -19.650, -11.497},
                             {30.479, 108.416, 10.473, 32.293, 27.699, -15.505, 18.408, -1.996},
                             {-94.145, -60.051, 12.298, -43.419, -31.288, -6.067, -3.331, 7.144},
                             {-38.568, -83.358, -5.412, -22.170, -13.520, 15.492, -1.332, 3.535},
                             {-31.250, 17.934, -5.524, -12.356, 14.250, -5.962, 11.488, -6.024}, 
                             {-0.865, -11.764, 12.776, 0.181, 28.071, 12.573, 8.353, 2.936},
                             {4.630, -2.421, 12.169, 6.561, -18.700, -12.753, 7.702, 12.031},
                             {-9.953, 11.194, 7.812, -16.289, 21.465, 0.022, 5.906, 10.681}};
  
  float expectedMatrix[8][8] = {{10, 4, 2, 5, 1, 0, 0, 0},
                                {3, 9, 1, 2, 1, 0, 0, 0},
                                {-7, -5, 1, -2, -1, 0, 0, 0},
                                {-3, -5, 0, -1, 0, 0, 0, 0},
                                {-2, 1, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0}};
  
  quantizationFunction50(size, inputMatrix);
  
  // dumpMatrix(size, inputMatrix);
  
  TEST_ASSERT_EQUAL_MATRIX(expectedMatrix, inputMatrix);
}

void test_dequantizationFunction_for_luminance_should_output_original_matrix_with_data_loss(){
	int size = 8;
  float inputMatrix[8][8] = {{10, 4, 2, 5, 1, 0, 0, 0},
                             {3, 9, 1, 2, 1, 0, 0, 0},
                             {-7, -5, 1, -2, -1, 0, 0, 0},
                             {-3, -5, 0, -1, 0, 0, 0, 0},
                             {-2, 1, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0},
                             {0, 0, 0, 0, 0, 0, 0, 0}};
  
  float expectedMatrix[8][8] = {{160, 44, 20, 80, 24, 0, 0, 0},
                                {36, 108, 14, 38, 26, 0, 0, 0},
                                {-98, -65, 16, -48, -40, 0, 0, 0},
                                {-42, -85, 0, -29, 0, 0, 0, 0},
                                {-36, 22, 0, 0, 0, 0, 0, 0}, 
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0},
                                {0, 0, 0, 0, 0, 0, 0, 0}};
  
  dequantizationFunction50(size, inputMatrix);
  
  // dumpMatrix(size, inputMatrix);

  TEST_ASSERT_EQUAL_MATRIX(expectedMatrix, inputMatrix);
}

void test_quantizationFunction_for_chrominance_given_8by8_matrix_should_output_quantized_matrix(void){
	int size = 8;
  float inputMatrix[8][8] = {{499.25, 43.18, 55.25, 72.11, 24.00, -25.51, 11.21, -4.14},
                             {-129.78, -71.50, -70.26, -73.35, 59.43, -24.02, 22.61, -2.05},
                             {85.71, 30.32, 61.78, 44.87, 14.84, 17.35, 15.51, -13.19},
                             {-40.81, 10.17, -17.53, -55.81, 30.50, -2.28, -21.00, -1.26},
                             {-157.50, -49.39, 13.27, -1.78, -8.75, 22.47, -8.47, -9.23}, 
                             {92.49, -9.03, 45.72, -48.13, -58.51, -9.01, -28.54, 10.38},
                             {-53.09, -62.97, -3.49, -19.62, 56.09, -2.25, -3.28, 11.91},
                             {-20.54, -55.90, -20.59, -18.19, -26.58, -27.07, 8.47, 0.31}};
  
  float expectedMatrix[8][8] = {{29, 2, 2, 2, 0, 0, 0, 0},
                                {-7, -3, -3, -1, 1, 0, 0, 0},
                                {4, 1, 1, 0, 0, 0, 0, 0},
                                {-1, 0, 0, -1, 0, 0, 0, 0},
                                {-2, 0, 0, 0, 0, 0, 0, 0}, 
                                {1, 0, 0, 0, -1, 0, 0, 0},
                                {-1, -1, 0, 0, 1, 0, 0, 0},
                                {0, -1, 0, 0, 0, 0, 0, 0}};
  
  quantizationFunctionChrominance(size, inputMatrix);
  
  // dumpMatrix(size, inputMatrix);
  
  TEST_ASSERT_EQUAL_MATRIX(expectedMatrix, inputMatrix);
}