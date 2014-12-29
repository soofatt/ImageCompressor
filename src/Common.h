#ifndef Common_H
#define Common_H

void dumpMatrix(int size, float matrix[][size]);
void dumpMatrixInt(int size, short int matrix[][size]);
void convertToFloat(short int inputMatrix[][8], float outputMatrix[][8]);
void dumpMatrixUINT8(int size,unsigned char matrix[][size]);
void convertUINT8ToFloat(unsigned char inputMatrix[][8], float outputMatrix[][8]);
void convertToUINT16(float inputMatrix[][8], short int outputMatrix[][8]);

#endif // Common_H
