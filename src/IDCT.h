#ifndef IDCT_H
#define IDCT_H

#include <stdio.h>


#define PI 3.14159265

float cos_IDCT(int numerator, int denominator);
float int_Divider(int numerator, int denominator);
void round_float(float array[], int noOfELement);
void oneD_IDCT(float transVal[], int noOfElement);
void twoD_IDCT(int size,float transVal[][size]);
void transpose_2D(int size, float matrix[][size]);
#endif // IDCT_H
