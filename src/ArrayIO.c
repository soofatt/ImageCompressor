#include "Stream.h"
#include "ArrayIO.h"

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

void readBlockWithConvert(Stream *in, int size, float matrixArray[][size]){
	int row, col;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      matrixArray[row][col] = (signed char)streamReadBits(in, 8);
    }
  }
}