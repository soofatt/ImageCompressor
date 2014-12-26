#ifndef CodeTable_H
#define CodeTable_H

#define CODETABLE   1
#define CODETABLE2   4
#define RUNSIZECODE 2
#define RUNSIZECODE2 3

#include "dataType.h"
typedef struct CodeTable CodeTable;
struct CodeTable{
  int codeType;
  CodeTable *table[16];
  int codeIndex;
};

typedef struct RunSizeCode RunSizeCode;
struct RunSizeCode{
  int type;
  uint8 runSize;
  char codeLength;
};

CodeTable *createTable(RunSizeCode runSizeCode[], int index, int arrayLength);
int getShift(int length);

#endif // CodeTable_H
