#ifndef HuffmanCoding_H
#define HuffmanCoding_H

#include "Scan.h"
void dumpArray(int* data, int size);
void runLengthEncoding(int* dataIn, int* dataOut, int size);
void runLengthDecoding(int* dataIn, int* dataOut, int size);
int runLengthEncoding2(int size, int* dataOut, int dataIn[][size], scanTable* table);
void runLengthDecoding2(int size, int* dataIn, int dataOut[][size], scanTable* table);

#endif // HuffmanCoding_H
