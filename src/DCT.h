#ifndef DCT_H
#define DCT_H

float cos_DCT(int sumIndex, int DCTArrayIndex, int numOfElement);
float adderFunction(int *imageMatrix, int DCTArrayIndex, int numOfElement);
void DCT_Function(float *DCTArray, int *imageMatrix, int numOfElement);

#endif // DCT_H
