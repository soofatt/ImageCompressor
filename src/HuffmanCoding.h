#ifndef HuffmanCoding_H
#define HuffmanCoding_H

#include "dataType.h"
extern uint16 dcLuminanceTable[12];
extern uint16 dcChrominanceTable[12];
extern uint16 acLuminanceTable[256];
extern uint16 acChrominanceTable[256];

short int huffmanEncode(uint8 runLength, uint8 bitSize, uint16 table[]);

#endif // HuffmanCoding_H
