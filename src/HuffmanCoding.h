#ifndef HuffmanCoding_H
#define HuffmanCoding_H
#include "Scan.h"

typedef struct scanTable scanTable;
struct scanTable{
	int row;
	int column;
	char firstStage;
	char secondStage;
	char thirdStage;
	char finalStage;
};

void dumpArray(int* data, int size);
void runLengthEncoding(int* dataIn, int* dataOut, int size);
void runLengthDecoding(int* dataIn, int* dataOut, int size);
int runLengthEncoding2(int size, int* dataOut, int dataIn[][size], scanTable* table);


#endif // HuffmanCoding_H
