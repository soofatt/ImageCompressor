#ifndef IDCT_H
#define IDCT_H

#include <stdio.h>


#define PI 3.14159265

float cos_IDCT(int numerator, int denominator);
float int_Divider(int numerator, int denominator);
void oneD_IDCT(float transVal[], int invTransVal[], int noOfElement);
#endif // IDCT_H
