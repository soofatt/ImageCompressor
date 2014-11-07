#include "DCT.h"
#include "IDCT.h"
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

void oneD_DCT_column(int size, float imageMatrix[][size], int col){
  int u, i, j, numOfElement;
  float coeff = 0, additionTotal = 0;
  float DCTArray[size][size];
  
  numOfElement = size;
  
  for(u = 0; u < numOfElement; u++){
    if(u == 0)
      coeff = 1/(sqrt(2));
    else
      coeff = 1;
    for(j = 0; j < numOfElement; j++){
      additionTotal += imageMatrix[j][col] * (cos_DCT(j, u, numOfElement));
    }
    DCTArray[u][col] = sqrt(2.0/numOfElement) * coeff * additionTotal;
    additionTotal = 0;
  }
  
  for(i = 0; i < numOfElement; i++){
    imageMatrix[i][col] = DCTArray[i][col];
  }
  
}

void oneD_DCT_row(float *imageMatrix, int numOfElement){
  int u, i, j;
  float coeff = 0, additionTotal = 0;
  float DCTArray[numOfElement];
  
  for(u = 0; u < numOfElement; u++){
    if(u == 0)
      coeff = 1/(sqrt(2));
    else
      coeff = 1;
    for(j = 0; j < numOfElement; j++){
      additionTotal += imageMatrix[j] * (cos_DCT(j, u, numOfElement));
    }
    DCTArray[u] = sqrt(2.0/numOfElement) * coeff * additionTotal;
    additionTotal = 0;
  }
  
  for(i = 0; i < numOfElement; i++){
    imageMatrix[i] = DCTArray[i];
  }
  
}

void twoD_DCT(int size, float imageMatrix[][size]){
  int i, row, col;
  
  for(row = 0; row < size; row++){
    oneD_DCT_row(imageMatrix[row], size);
  }

  for(col = 0; col < size; col++){
    oneD_DCT_column(size, imageMatrix, col);
  }
}
