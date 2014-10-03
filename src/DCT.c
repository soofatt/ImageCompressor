#include "DCT.h"
#include <stdio.h>
#include <math.h>

#define PI 3.14159265

float cos_DCT(int sumIndex, int DCTArrayIndex, int DCTArraySize){
	float nominator, result;
	int denominator;
	
	nominator = PI * (2*sumIndex + 1) * DCTArrayIndex;
	denominator = 2 * DCTArraySize;
	
	result = nominator/denominator;
	
	return cos(result);
}