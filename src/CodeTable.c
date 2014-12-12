#include "CodeTable.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

CodeTable *createTable(RunSizeCode runSizeCode[], int index, int arrayLength){
  CodeTable *codeTable = malloc(sizeof(CodeTable));
  int slots = 0, currentIndex, shift, i, j = 0;
  
  currentIndex = index;
  
  shift = getShift(runSizeCode[currentIndex].codeLength);
  slots = 1 << (4 - shift);
  
  if(runSizeCode[currentIndex].type == CODETABLE){
    while(slots != 0){
      codeTable->table[j] = (CodeTable *)(&runSizeCode[currentIndex]);
      j++;
      slots--;
    }
    currentIndex++;
    if(currentIndex >= arrayLength){
      codeTable->codeIndex = currentIndex;
      return;
    }
  }
  
  for(i = j; i < 16; ){
    shift = getShift(runSizeCode[currentIndex].codeLength);
    slots = 1 << (4 - shift);
    // assert(currentIndex < 8);
    
    if(runSizeCode[currentIndex].type == RUNSIZECODE){
      while(slots != 0){
        // assert(codeTable->table[i] != NULL); // Check if table is not null
        codeTable->table[i] = (CodeTable *)(&runSizeCode[currentIndex]);
        i++;
        slots--;
      }
    }
    else{
    printf("runSize: %d", runSizeCode[currentIndex].runSize);
      codeTable->table[i] = createTable(runSizeCode, currentIndex, arrayLength);
      currentIndex = codeTable->table[i]->codeIndex;
      i++;
    }
    if(currentIndex < arrayLength)
      currentIndex++;
    else
      break;
  }
  codeTable->codeIndex = currentIndex;
  return codeTable;
}

int getShift(int length){
  int shift;
  
  if(length > 4 && length <= 8)
    return shift = length - 4;
  else if(length > 8 && length <= 12)
    return shift = length - 8;
  else if(length > 12 && length <= 16)
    return shift = length - 12;
  else
    return shift = length;
}