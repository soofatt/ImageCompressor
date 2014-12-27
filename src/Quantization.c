/**
 * File name :
 * Author :
 * Date : 
 *
 * References:
 * [1] Tinku Acharya, Ping-Sing Tsai, 
 *     JPEG2000 Standard for Image Compression Concepts, Algorithms and VLSI Architectures,
 *     Table 3.3 Luminance Quantization Table (pg. 67)
 * [2] Tinku Acharya, Ping-Sing Tsai, 
 *     JPEG2000 Standard for Image Compression Concepts, Algorithms and VLSI Architectures,
 *     Table 3.4 Chrominance Quantization Table (pg. 68)
 *
 */

#include "Quantization.h"
#include <math.h>

//[1]Luminance quantization matrix for 50% quality to compression ratio
const int quantizationMatrix50[8][8] = {{16, 11, 10, 16, 24, 40, 51, 61},
                                        {12, 12, 14, 19, 26, 58, 60, 55},
                                        {14, 13, 16, 24, 40, 57, 69, 56},
                                        {14, 17, 22, 29, 51, 87, 80, 62},
                                        {18, 22, 37, 56, 68, 109, 103, 77},
                                        {24, 35, 55, 64, 81, 104, 113, 92},
                                        {49, 64, 78, 87, 103, 121, 120, 101},
                                        {72, 92, 95, 98, 112, 100, 103, 99}};
                                        
//[1]Luminance quantization matrix for 90% quality to compression ratio                                        
const int quantizationMatrix90[8][8] = {{3, 2, 2, 3, 5, 8, 10, 12},
                                        {2, 2, 3, 4, 5, 12, 12, 11},
                                        {3, 3, 3, 5, 8, 11, 14, 11},
                                        {3, 3, 4, 6, 10, 17, 16, 12},
                                        {4, 4, 7, 11, 14, 22, 21, 15},
                                        {5, 7, 11, 13, 16, 12, 23, 18},
                                        {10, 13, 16, 17, 21, 24, 24, 21},
                                        {14, 18, 19, 20, 22, 20, 20, 20}};                                        

//[1]Luminance quantization matrix for 10% quality to compression ratio                                        
const int quantizationMatrix10[8][8] = {{80, 60, 50, 80, 120, 200, 255, 255},
                                        {55, 60, 70, 95, 130, 255, 255, 255},
                                        {70, 65, 80, 120, 200, 255, 255, 255},
                                        {70, 85, 110, 145, 255, 255, 255, 255},
                                        {90, 110, 185, 255, 255, 255, 255, 255},
                                        {120, 175, 255, 255, 255, 255, 255, 255},
                                        {245, 255, 255, 255, 255, 255, 255, 255},
                                        {255, 255, 255, 255, 255, 255, 255, 255}};

//[2]Quantization matrix for chrominance component of image                                        
const int quantizationMatrixChrominance[8][8] = {{17, 18, 24, 47, 99, 99, 99, 99},
                                                 {18, 21, 26, 66, 99, 99, 99, 99},
                                                 {24, 26, 56, 99, 99, 99, 99, 99},
                                                 {47, 66, 99, 99, 99, 99, 99, 99},
                                                 {99, 99, 99, 99, 99, 99, 99, 99},
                                                 {99, 99, 99, 99, 99, 99, 99, 99},
                                                 {99, 99, 99, 99, 99, 99, 99, 99},
                                                 {99, 99, 99, 99, 99, 99, 99, 99}};

/*  quantizationFunction
 *  Desc.  : Function to perform quantization on the 2D array.
 *           (Grouping of a range of values to a single discrete quantum value).
 *
 *  Input
 *    inputMatrix       : Input 2D array.
 *    quantizationMatrix: Fixed quantization matrix to be used for quantization.
 *
 */                                                 
void quantizationFunction(int size, float inputMatrix[][size], const int quantizationMatrix[][8]){
  int quantizedMatrix[size][size];
  int row, col;
  float result;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      result = inputMatrix[row][col] / quantizationMatrix[row][col];
      quantizedMatrix[row][col] = (int)round(result);
    }
  }
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      inputMatrix[row][col] = quantizedMatrix[row][col];
    }
  }
}       

/*  dequantizationFunction
 *  Desc.  : Function to perform dequantization on the 2D array.
 *
 *  Input
 *    inputMatrix       : Input 2D array.
 *    quantizationMatrix: Fixed quantization matrix to be used for dequantization.
 *
 */   
void dequantizationFunction(int size, float inputMatrix[][size], const int quantizationMatrix[][8]){
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