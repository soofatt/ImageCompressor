#ifndef Scan_H
#define Scan_H
#include "dataType.h"
// #include "HuffmanCoding.h"

#define IncrementBy1(x) (x+=1)
#define DecrementBy1(x) (x-=1)

typedef struct scanTable scanTable;
struct scanTable{
	int row;
	int column;
	int col_limit;
	char stage;
};
void scanArray(float in[8][8], float* out);
void updateRCTable1(scanTable* table);
void updateRCTable2(scanTable* table);
uint8 lookupRC(int index);
#endif // Scan_H
