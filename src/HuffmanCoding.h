#ifndef HuffmanCoding_H
#define HuffmanCoding_H

typedef struct scanTable scanTable;
struct scanTable{
	int row;
	int column;
};

void dumpArray(int* data, int size);
void runLengthEncoding(int* dataIn, int* dataOut, int size);
void runLengthDecoding(int* dataIn, int* dataOut, int size);
void runLengthEncoding2(int size, int* dataOut, int dataIn[][size], scanTable* table);


#endif // HuffmanCoding_H
