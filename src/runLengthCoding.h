#ifndef runLengthCoding_H
#define runLengthCoding_H
#include "Scan.h"
#include "dataType.h"

typedef struct State State;
struct State{
	uint8 state;
	int index;
};

void dumpArray(int* data, int size);
void runLengthEncoding(int* dataIn, int* dataOut, int size);
void runLengthDecoding(int* dataIn, int* dataOut, int size);
uint32 runLengthEncode(int size, short int dataIn[][size], State* state);
void runLengthDecode(int size, short int dataOut[][size], State* state, uint32 runAndSymbol);

//int runLengthEncoding2(int size, int* dataOut, int dataIn[][size], scanTable* table);
//void runLengthDecoding2(int size, int* dataIn, int dataOut[][size], scanTable* table);

#endif // runLengthCoding_H
