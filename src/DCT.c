#include "DCT.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

float cos_DCT(int sumIndex, int DCTArrayIndex, int numOfElement){
	float nominator, denominator, result;
	
	nominator = PI * (2 * sumIndex + 1) * DCTArrayIndex;
	denominator = 2 * numOfElement;
	
	result = nominator/denominator;
	
	return cos(result);
}

float adderFunction(int *imageMatrix, int DCTArrayIndex, int numOfElement){
  int x;
  float result = 0, temp;
  
  for(x = 0; x < numOfElement; x++){
    temp = imageMatrix[x] * (cos_DCT(x, DCTArrayIndex, numOfElement));
    result = result + temp;
  }
  
  return result;
}

void DCT_Function(float *DCTArray, int *imageMatrix, int numOfElement){
  int u;
  float coeff = 0;
  
  for(u = 0; u < numOfElement; u++){
    if(u == 0)
      coeff = 1/(sqrt(2));
    else
      coeff = 1;

    DCTArray[u] = sqrt(2.0/numOfElement) * coeff * adderFunction(imageMatrix, u, numOfElement);
  }
  
}