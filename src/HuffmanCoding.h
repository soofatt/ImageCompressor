#ifndef HuffmanCoding_H
#define HuffmanCoding_H

#include "dataType.h"

extern uint16 dcLuminanceTable[12];
extern uint16 dcChrominanceTable[12];
extern uint16 acLuminanceTable[256];
extern uint16 acChrominanceTable[256];

extern uint8 decodeDCLTable[4][16];
extern uint8 decodeDCCTable[4][16];

uint16 huffmanEncode(uint8 runLength, uint8 bitSize, uint16 table[]);

uint8 huffmanDecode(uint16 codeWord, CodeTable *huffmanTable);

#endif // HuffmanCoding_H
