#include "IDCT.h"
#include <math.h>

float cos_IDCT(int numerator, int denominator){
  float cosANS;
  cosANS = cos(PI*numerator/denominator);
  return cosANS;
}

float int_Divider(int numerator, int denominator){
  float div = (float)numerator/denominator;
  return div;
}

void round_float(float invTransVal[], int noOfELement){
  int i;
  for(i = 0; i < noOfELement; i++){
    invTransVal[i] = round(invTransVal[i]);
  }
}

int square_root(int val){
  int ans;
  ans = sqrt(val);
  return ans;
}

void transpose_2D(int size,float matrix[][size], float transposeMatrix[][size]){
  int row, col;
  for(row = 0; row<size; row++){
    for(col = 0; col<size; col++){
      transposeMatrix[col][row] = matrix[row][col];
    }
  }
}

void oneD_IDCT(float transVal[], float invTransVal[], int noOfElement){
  int i, num, den, index;
  float Cu, cosAns, divAns, total = 0;
  
  for(index = 0;index < noOfElement; index++){
    for(i = 0; i < noOfElement; i++){
      if(i == 0){
        divAns = int_Divider(1,noOfElement);
        Cu = sqrt(divAns);
      }
      else{
        divAns = int_Divider(2,noOfElement);
        Cu = sqrt(divAns);
      }
      num = (2*index + 1)*i;
      den = 2*noOfElement;
      cosAns = cos_IDCT(num,den);
      total += Cu * transVal[i] * cosAns;
    }
    // printf("          Total %d : %f\n",index,total);
    // printf("Round off Total %d : %f\n",index,round(total));
    invTransVal[index] = total;
    total = 0;
  }
}

void twoD_IDCT(int size,float transVal[][size],float invTransVal[][size]){
  int row, column;
  
  for(column = 0; column < size; column++){
    for(row = 0; row < size; row++){
      printf("%f  ",transVal[row][column]);
    }
  }
}