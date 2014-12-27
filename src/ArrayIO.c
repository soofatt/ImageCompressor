#include "Stream.h"
#include "ArrayIO.h"
#include "dataType.h"

/*  readBlock
 *  Desc.  : Function to fill 8x8 array with input image data.
 *
 *  Input
 *    in : File in stream handler.
 *    matrixArray : 8x8 array container.
 *
 */
void readBlock(Stream *in, int size, float matrixArray[][size]){
	int row, col;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      matrixArray[row][col] = streamReadBits(in, 8);
    }
  }
}

/*  writeBlock
 *  Desc.  : Function to write elements from 8x8 array to file.
 *
 *  Input
 *    out : File out stream handler.
 *    matrixArray : 8x8 array container.
 *
 */
void writeBlock(Stream *out, int size, float matrixArray[][size]){
  int row, col;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      streamWriteByte(out, matrixArray[row][col]);
    }
  }
}

/*  writeBlock11Bit
 *  Desc.  : Function to write 2 bytes.
 *
 *  Input
 *    out : File out stream handler.
 *    matrixArray : 8x8 array container.
 *
 */
void writeBlock11Bit(Stream *out, int size, float matrixArray[][size]){
  int row, col;
  
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      splitByteAndWrite(out, matrixArray[row][col]);
    }
  }
}

/*  splitByteAndWrite
 *  Desc.  : Subfunction to split input into two bytes and write twice
 *
 *  Input
 *    out : File out stream handler.
 *    matrixArrayElement : Array element to be split.
 *
 */
void splitByteAndWrite(Stream *out, float matrixArrayElement){
	short int bytesToWrite;
  char tempByte;
  
  bytesToWrite = (short int)matrixArrayElement;
  
  tempByte = (bytesToWrite >> 8);
  streamWriteByte(out, tempByte);
  
  tempByte = bytesToWrite;
  streamWriteByte(out, tempByte);
  
}

/*  readBlock11Bit
 *  Desc.  : Function to read 2 bytes.
 *
 *  Input
 *    in : File in stream handler.
 *    matrixArray : 8x8 array container.
 *
 */
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

