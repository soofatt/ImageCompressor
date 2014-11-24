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
void convertToLuma(uint8 red[][8], uint8 green[][8], uint8 blue[][8], uint8 luma[][8]){
  int row, col;
  for(row = 0; row < 8; row++)
    for(col = 0; col < 8; col++)
      luma[row][col] = round( ( Cred*red[row][col] ) + ( Cgreen*green[row][col] ) + ( Cblue*blue[row][col] ) );
}

void convertToChromaB(uint8 blue[][8], uint8 luma[][8], uint8 chromaB[][8]){
  int row, col;
  for(row = 0; row < 8; row++)
    for(col = 0; col < 8; col++)
      chromaB[row][col] = round( (blue[row][col] - luma[row][col]) / (2-(2*Cblue)) )+ 128;
}

void convertToChromaR(uint8 red[][8], uint8 luma[][8], uint8 chromaR[][8]){
  int row, col;
  for(row = 0; row < 8; row++)
    for(col = 0; col < 8; col++)
      chromaR[row][col] = round( (red[row][col] - luma[row][col]) / (2-(2*Cred)) )+ 128;
}

void convertToRed(uint8 luma[][8], uint8 ChromaR[][8], uint8 red[][8]){
  int row, col;
  for(row = 0; row < 8; row++){
    for(col = 0; col < 8; col++){
      red[row][col] = round( (ChromaR[row][col]-128)*(2-(2*Cred)) + luma[row][col] + 0.5 );
	  printf("%d ",red[row][col]);
	}printf("\n");
	}
}

// void convertToGreen(uint8 luma[][8], uint8 blue[][8], uint8 red[][8]), uint8 green[][8]){
	// blue = chromaB * 2 -2*Cblue+luma
// }

// void convertToBlue(uint8 luma[][8], uint8 ChromaB[][8], uint8 blue[][8]){
	// luma - Cblue*blue - Cred*red / Cgreen
// }
