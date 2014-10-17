#ifndef DCT_H
#define DCT_H

float cos_DCT(int sumIndex, int imageMatrixIndex, int numOfElement);
float adderFunction(float *imageMatrix, int imageMatrixIndex, int numOfElement);
void oneD_DCT_column(int size, float imageMatrix[][size], int col);
void oneD_DCT_row(float *imageMatrix, int numOfElement);
void twoD_DCT(int size, float imageMatrix[][size]);


#endif // DCT_H
