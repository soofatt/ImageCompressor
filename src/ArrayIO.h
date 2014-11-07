#ifndef ArrayIO_H
#define ArrayIO_H

void readBlock(Stream *in, int size, float matrixArray[][size]);
void writeBlock(Stream *out, int size, float matrixArray[][size]);
void writeBlock11Bit(Stream *out, int size, float matrixArray[][size]);
void readBlock11Bit(Stream *in, int size, short int matrixArray[][size]);
void splitByteAndWrite(Stream *out, float matrixArrayElement);

#endif // ArrayIO_H
