#ifndef CodeTable_H
#define CodeTable_H

#define CODETABLE   1
#define RUNSIZECODE 2

#include "dataType.h"
typedef struct CodeTable CodeTable;
struct CodeTable{
  int type;
  CodeTable *table[16];
  int codeIndex;
};

typedef struct RunSizeCode RunSizeCode;
struct RunSizeCode{
  int type;
  uint8 runSize;
  char codeLength;
};

void createTable(CodeTable *codeTable, RunSizeCode runSizeCode[], int index);

#endif // CodeTable_H
