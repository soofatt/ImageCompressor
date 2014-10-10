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

void oneD_IDCT(float transVal[], int invTransVal[], int noOfElement){
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
    invTransVal[index] = round(total);
    total = 0;
  }
}