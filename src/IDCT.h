#ifndef IDCT_H
#define IDCT_H

#include <stdio.h>


#define PI 3.14159265

float cos_IDCT(int numerator, int denominator);
float int_Divider(int numerator, int denominator);
void round_float(float invTransVal[], int noOfELement);
void oneD_IDCT(float transVal[], float invTransVal[], int noOfElement);
void twoD_IDCT(int size,float transVal[][size],float invTransVal[][size]);
void transpose_2D(int size, float matrix[][size], float transposeMatrix[][size]);
#endif // IDCT_H
