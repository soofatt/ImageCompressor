#include "CodeTable.h"
#include <stdio.h>
#include <assert.h>
#include <malloc.h>

/*  createTable
 *  Desc.  : Function to tabulate the rearranged predetermined Huffman Table
 *  e.g : To retrieve 0xF0
 *  +---+
 *  |   |
 *  |   |    +---+
 *  | F | -> | 0 |
 *  +---+    |   |
 *           |   |
 *           +---+
 *  Input
 *    runSizeCode : Rearranged run/size according to code length
 *    index       : To keep track of position in runSizeCode[] during recursion.
 *    arrayLength : To make sure the function does not continue searching for elements in
 *                  runSizeCode[] when there is no elements left.
 *    
 *  Output
 *    codeTable : The generated code table.
 *
 */
CodeTable *createTable(RunSizeCode runSizeCode[], int index, int arrayLength){
  CodeTable *codeTable = malloc(sizeof(CodeTable));
  int slots = 0, currentIndex, shift, i = 0, j = 0;
  codeTable->codeType = RUNSIZECODE;
  currentIndex = index;
  
  shift = getShift(runSizeCode[currentIndex].codeLength);
  slots = 1 << (4 - shift);
  
  if(runSizeCode[currentIndex].type == CODETABLE){
    codeTable->codeType = CODETABLE;
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
    // printf("j : %d\n", j);
    // printf("currentIndex : %d\n", currentIndex);
  }
  
  for(i = j; i < 16; ){
    if(currentIndex >= arrayLength)
      break;
    
    shift = getShift(runSizeCode[currentIndex].codeLength);
    slots = 1 << (4 - shift);
    // assert(currentIndex < 8);
    
    if(runSizeCode[currentIndex].type == RUNSIZECODE || runSizeCode[currentIndex].type == RUNSIZECODE2){
      while(slots != 0){
        // assert(codeTable->table[i] != NULL); // Check if table is not null
        codeTable->table[i] = (CodeTable *)(&runSizeCode[currentIndex]);
        i++;
        slots--;
      }
    }
    else{
      codeTable->table[i] = createTable(runSizeCode, currentIndex, arrayLength);
      currentIndex = codeTable->table[i]->codeIndex - 1;
      i++;
    }
    if(currentIndex < arrayLength){
      currentIndex++;
    }
    else
      break;
  }
  codeTable->codeIndex = currentIndex;
  return codeTable;
}

/*  getShift
 *  Desc.  : Subfunction to obtain the amount of bits to shift.
 *           The output of this function will be used to obtain the slots
 *           to be allocated for each runSizeCode in the table.
 *
 *  Input
 *    length : Input code length.
 *
 *  Output
 *    shift : The number of shifts required to get slots.
 *
 */
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