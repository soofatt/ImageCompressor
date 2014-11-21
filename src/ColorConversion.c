#include "ColorConversion.h"

void convertToLuma(short int red[][8], short int green[][8], short int blue[][8], short int luma[][8]){
  int row, col;
  
  for(row = 0; row < 8; row++){
    for(col = 0; col < 8; col++){
      luma[row][col] = ((0.299*red[row][col]) + (0.587*green[row][col]) + (0.114*blue[row][col]) + 0.5);
    }
  }
}

void convertToChromaB(short int red[][8], short int green[][8], short int blue[][8], short int chroma[][8]){
  int row, col;
  
  for(row = 0; row < 8; row++){
    for(col = 0; col < 8; col++){
      chroma[row][col] = ((-.1687436*red[row][col]) + (-0.331264*green[row][col]) + (0.500002*blue[row][col]) + 128 + 0.5);
    }
  }
}

void convertToChromaR(short int red[][8], short int green[][8], short int blue[][8], short int chroma[][8]){
  int row, col;
  
  for(row = 0; row < 8; row++){
    for(col = 0; col < 8; col++){
      chroma[row][col] = ((0.5*red[row][col]) + (-0.418688*green[row][col]) + (-0.081312*blue[row][col]) + 128 + 0.5);
    }
  }
}