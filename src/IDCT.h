#ifndef IDCT_H
#define IDCT_H

#include <stdio.h>


#define PI 3.14159265

void dumpMatrix(int size,float matrix[][size]);
float cos_IDCT(int numerator, int denominator);
float int_Divider(int numerator, int denominator);
void round_float(float array[], int noOfELement);
void oneD_IDCT_row(float transVal[], int noOfElement);
void oneD_IDCT_column(int size, float transVal[][size], int column);
void twoD_IDCT_with_transpose(int size,float transVal[][size]);
void twoD_IDCT(int size,float transVal[][size]);
void transpose_2D(int size, float matrix[][size]);
#endif // IDCT_H
