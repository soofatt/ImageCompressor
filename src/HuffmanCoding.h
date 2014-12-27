#ifndef HuffmanCoding_H
#define HuffmanCoding_H

#include "runLengthCoding.h"

uint16 huffmanEncode(uint8 runLength, uint8 bitSize, uint16 table[]);
uint8 huffmanDecode(uint16 codeWord, CodeTable *huffmanTable);
uint32 huffmanEncodePull(State *progress, short int dataIn[][8], uint16 table[]);

#endif // HuffmanCoding_H
