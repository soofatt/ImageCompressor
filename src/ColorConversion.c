#include <math.h>
#include "ColorConversion.h"
#include "dataType.h"

#define Cred	0.299
#define Cgreen	0.587
#define Cblue	0.114

/* Take Note
 *	The input range for RGB is start from 0 - 255, using uint8 is enough to store RGB
 *  The output range for Cb, Cr also start from 0 - 255
 *	From formula given, Y, luminance component always positive value
 *	However, Cb and Cr, Chrominance components might drop in range of -128 to 127
 *	Therefore, level shifting(+128) should do after Cb, Cr calculated
 *
 *	Note that Cr and Cb must be subtracted out 128 before getting back the rgb value
 */
void convertToLuma(RGB* colorRGB, YCbCr* lumaChrom){
  int row, col;
  for(row = 0; row < 8; row++)
    for(col = 0; col < 8; col++)
		(*(lumaChrom->Y))[row][col] = round( ( Cred*(*(colorRGB->red))[row][col] ) + ( Cgreen*(*(colorRGB->green))[row][col] ) + ( Cblue*(*(colorRGB->blue))[row][col] ) );
}

void convertToChromaB(RGB* colorRGB, YCbCr* lumaChrom){
  int row, col;
  for(row = 0; row < 8; row++)
    for(col = 0; col < 8; col++)
      (*(lumaChrom->Cb))[row][col] = round( ((*(colorRGB->blue))[row][col] - (*(lumaChrom->Y))[row][col]) / (2-(2*Cblue)) )+ 128;
}

void convertToChromaR(RGB* colorRGB, YCbCr* lumaChrom){
  int row, col;
  for(row = 0; row < 8; row++)
    for(col = 0; col < 8; col++)
      (*(lumaChrom->Cr))[row][col] = round( ((*(colorRGB->red))[row][col]  - (*(lumaChrom->Y))[row][col]) / (2-(2*Cred)) )+ 128;
}

void convertToRed(RGB* returnRGB, YCbCr* lumaChrom){
  int row, col;
  for(row = 0; row < 8; row++)
    for(col = 0; col < 8; col++)
      (*(returnRGB->red))[row][col] = ((*(lumaChrom->Cr))[row][col]-128)*(2-(2*Cred)) + (*(lumaChrom->Y))[row][col];
}

void convertToGreen(RGB* returnRGB, YCbCr* lumaChrom){
  int row, col;
  for(row = 0; row < 8; row++)
    for(col = 0; col < 8; col++)
		(*(returnRGB->green))[row][col] = ((*(lumaChrom->Y))[row][col] - (Cblue*(*(returnRGB->blue))[row][col]) - (Cred*(*(returnRGB->red))[row][col]) )/ Cgreen;
}

void convertToBlue(RGB* returnRGB, YCbCr* lumaChrom){
  int row, col;
  for(row = 0; row < 8; row++)
    for(col = 0; col < 8; col++)
		(*(returnRGB->blue))[row][col] = ((*(lumaChrom->Cb))[row][col] - 128) * (2 - (2*Cblue)) + (*(lumaChrom->Y))[row][col];
}
