#include "Quantization.h"
#include <Math.h>

const int quantizationMatrix50[8][8] = {{16, 11, 10, 16, 24, 40, 51, 61},
                                        {12, 12, 14, 19, 26, 58, 60, 55},
                                        {14, 13, 16, 24, 40, 57, 69, 56},
                                        {14, 17, 22, 29, 51, 87, 80, 62},
                                        {18, 22, 37, 56, 68, 109, 103, 77},
                                        {24, 35, 55, 64, 81, 104, 113, 92},
                                        {49, 64, 78, 87, 103, 121, 120, 101},
                                        {72, 92, 95, 98, 112, 100, 103, 99}};
                                        
void quantizationFunction(int size, float inputMatrix[][size]){
  int quantizedMatrix[size][size];
  int row, col;
  float result;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      result = inputMatrix[row][col] / quantizationMatrix50[row][col];
      quantizedMatrix[row][col] = (int)round(result);
    }
  }
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      inputMatrix[row][col] = quantizedMatrix[row][col];
    }
  }
}       

void dequantizationFunction(int size, float inputMatrix[][size]){
  int dequantizedMatrix[size][size];
  int row, col;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      dequantizedMatrix[row][col] = inputMatrix[row][col] * quantizationMatrix50[row][col];
    }
  }
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      inputMatrix[row][col] = dequantizedMatrix[row][col];
    }
  }
}