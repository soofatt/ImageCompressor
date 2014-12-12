#include "CodeTable.h"
#include <stdio.h>
#include <assert.h>

void createTable(CodeTable *codeTable, RunSizeCode runSizeCode[], int index){
  int slots = 0, currentIndex, shift, i;
  
  currentIndex = index;
  
  for(i = 0; i < 16; ){
    if(runSizeCode[currentIndex].codeLength > 4 && runSizeCode[currentIndex].codeLength <= 8)
      shift = runSizeCode[currentIndex].codeLength - 4;
    else if(runSizeCode[currentIndex].codeLength > 8 && runSizeCode[currentIndex].codeLength <= 12)
      shift = runSizeCode[currentIndex].codeLength - 8;
    else if(runSizeCode[currentIndex].codeLength > 12 && runSizeCode[currentIndex].codeLength <= 16)
      shift = runSizeCode[currentIndex].codeLength - 12;
    else
      shift = runSizeCode[currentIndex].codeLength;

    slots = 1 << (4 - shift);
    assert(currentIndex < 8);
    
    if(runSizeCode[currentIndex].type == RUNSIZECODE){
      while(slots != 0){
        // assert(codeTable->table[i] != NULL); // Check if table is not null
        codeTable->table[i] = (CodeTable *)(&runSizeCode[currentIndex]);
        i++;
        slots--;
      }
    }
    else
      i++;
    
    currentIndex++;
  }
}