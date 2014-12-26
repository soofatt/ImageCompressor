#include "Stream.h"
#include "ArrayIO.h"
#include "dataType.h"

void readBlock(Stream *in, int size, float matrixArray[][size]){
	int row, col;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      matrixArray[row][col] = streamReadBits(in, 8);
    }
  }
}

void writeBlock(Stream *out, int size, float matrixArray[][size]){
  int row, col;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      streamWriteByte(out, matrixArray[row][col]);
    }
  }
}

void writeBlock11Bit(Stream *out, int size, float matrixArray[][size]){
  int row, col;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      splitByteAndWrite(out, matrixArray[row][col]);
    }
  }
}

void splitByteAndWrite(Stream *out, float matrixArrayElement){
	short int bytesToWrite;
  char tempByte;
  
  bytesToWrite = (short int)matrixArrayElement;
  
  tempByte = (bytesToWrite >> 8);
  streamWriteByte(out, tempByte);
  
  tempByte = bytesToWrite;
  streamWriteByte(out, tempByte);
  
}

void readBlock11Bit(Stream *in, int size, short int matrixArray[][size]){
	int row, col;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      matrixArray[row][col] = streamReadBits(in, 8);
      matrixArray[row][col] <<= 8;
      matrixArray[row][col] |= streamReadBits(in, 8);
    }
  }
}

void readFileToRGB(Stream *in, uint8 arrayRed[8][8], uint8 arrayGreen[8][8], uint8 arrayBlue[8][8]){
	int row, col;
  
  for(row = 0; row < 8; row++){
    for(col = 0; col < 8; col++){
      arrayRed[row][col] = streamReadBits(in, 8);
      arrayGreen[row][col] = streamReadBits(in, 8);
      arrayBlue[row][col] = streamReadBits(in, 8);
    }
  }
}

void writeRGBToFile(Stream *out, uint8 arrayRed[8][8], uint8 arrayGreen[8][8], uint8 arrayBlue[8][8]){
	int row, col;
  
  for(row = 0; row < 8; row++){
    for(col = 0; col < 8; col++){
      streamWriteByte(out, arrayRed[row][col]);
      streamWriteByte(out, arrayGreen[row][col]);
      streamWriteByte(out, arrayBlue[row][col]);
    }
  }
}

