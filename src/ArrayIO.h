#ifndef ArrayIO_H
#define ArrayIO_H

void readBlock(Stream *in, int size, float matrixArray[][size]);
void writeBlock(Stream *out, int size, float matrixArray[][size]);
void readBlockWithConvert(Stream *in, int size, float matrixArray[][size]);

#endif // ArrayIO_H
