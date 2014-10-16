#ifndef DCT_H
#define DCT_H

float cos_DCT(int sumIndex, int imageMatrixIndex, int numOfElement);
float adderFunction(float *imageMatrix, int imageMatrixIndex, int numOfElement);
void transpose_2D_DCT(int size,float matrix[][size]);
void oneD_DCT(float *imageMatrix, int numOfElement);
void twoD_DCT(int size, float imageMatrix[][size]);


#endif // DCT_H
