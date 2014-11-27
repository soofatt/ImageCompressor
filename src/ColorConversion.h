#ifndef ColorConversion_H
#define ColorConversion_H
#include "dataType.h"

typedef struct RGB RGB;
struct RGB{
	uint8 (*red)[8][8];
	uint8 (*blue)[8][8];
	uint8 (*green)[8][8];
};

typedef struct YCbCr YCbCr;
struct YCbCr{
	uint8 (*Y)[8][8];
	uint8 (*Cb)[8][8];
	uint8 (*Cr)[8][8];
};

void convertToLuma(RGB* colorRGB, YCbCr* lumaChrom);
void convertToChromaB(RGB* colorRGB, YCbCr* lumaChrom);
void convertToChromaR(RGB* colorRGB, YCbCr* lumaChrom);

void convertToRed(RGB* returnRGB, YCbCr* lumaChrom);
void convertToGreen(RGB* returnRGB, YCbCr* lumaChrom);
void convertToBlue(RGB* returnRGB, YCbCr* lumaChrom);

#endif // ColorConversion_H
