#ifndef ColorConversion_H
#define ColorConversion_H
#include "dataType.h"

void convertToLuma(uint8 red[][8], uint8 green[][8], uint8 blue[][8], uint8 luma[][8]);
void convertToChromaB(uint8 blue[][8], uint8 luma[][8], uint8 chromaB[][8]);
void convertToChromaR(uint8 red[][8], uint8 luma[][8], uint8 chromaR[][8]);

void convertToRed(uint8 luma[][8], uint8 ChromaR[][8], uint8 red[][8]);
void convertToGreen(uint8 luma[][8], uint8 blue[][8], uint8 red[][8], uint8 green[][8]);
void convertToBlue(uint8 luma[][8], uint8 ChromaB[][8], uint8 blue[][8]);

#endif // ColorConversion_H
