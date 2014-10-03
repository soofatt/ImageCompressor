#include "IDCT.h"

float cos_IDCT(int numerator, int denominator){
  float cosANS;
  cosANS = cos(PI*numerator/denominator);
  return cosANS;
}

void oneD_IDCT(){
  
}