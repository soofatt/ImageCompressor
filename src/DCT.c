#include "DCT.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

float cos_DCT(int sumIndex, int imageMatrixIndex, int numOfElement){
	float nominator, denominator, result;
	
	nominator = PI * (2 * sumIndex + 1) * imageMatrixIndex;
	denominator = 2 * numOfElement;
	
	result = nominator/denominator;
	
	return cos(result);
}

float adderFunction(float *imageMatrix, int imageMatrixIndex, int numOfElement){
  int x;
  float result = 0, temp = 0;
  
  for(x = 0; x < numOfElement; x++){
    temp = imageMatrix[x] * (cos_DCT(x, imageMatrixIndex, numOfElement));
    result = result + temp;
  }
  
  return result;
}

void transpose_2D_DCT(int size,float matrix[][size]){
  int row, col;
  float transposeMatrix[size][size];
  
  for(row = 0; row<size; row++){
    for(col = 0; col<size; col++){
      transposeMatrix[col][row] = matrix[row][col];
    }
  }
  for(row = 0; row<size; row++){
    for(col = 0; col<size; col++){
      matrix[row][col] = transposeMatrix[row][col];
    }
  }
}

void oneD_DCT(float *imageMatrix, int numOfElement){
  int u, i;
  float coeff = 0;
  float DCTArray[numOfElement];
  
  for(u = 0; u < numOfElement; u++){
    if(u == 0)
      coeff = 1/(sqrt(2));
    else
      coeff = 1;

    DCTArray[u] = sqrt(2.0/numOfElement) * coeff * adderFunction(imageMatrix, u, numOfElement);
  }
  
  for(i = 0; i < numOfElement; i++){
    imageMatrix[i] = DCTArray[i];
  }
  
}

void twoD_DCT(int size, float imageMatrix[][size]){
  int i, row;
  
  for(i = 0; i < 2; i++){
    for(row = 0; row < size; row++){
      oneD_DCT(imageMatrix[row], size);
    }
    transpose_2D_DCT(size, imageMatrix);
  }
}