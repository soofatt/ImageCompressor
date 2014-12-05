#ifndef ArrayIO_H
#define ArrayIO_H

void readBlock(Stream *in, int size, float matrixArray[][size]);
void writeBlock(Stream *out, int size, float matrixArray[][size]);
void writeBlock11Bit(Stream *out, int size, float matrixArray[][size]);
void readBlock11Bit(Stream *in, int size, short int matrixArray[][size]);
void splitByteAndWrite(Stream *out, float matrixArrayElement);
void readFileToRGB(Stream *in, uint8 arrayRed[8][8], uint8 arrayGreen[8][8], uint8 arrayBlue[8][8]);
void writeRGBToFile(Stream *out, uint8 arrayRed[8][8], uint8 arrayGreen[8][8], uint8 arrayBlue[8][8]);

#endif // ArrayIO_H
