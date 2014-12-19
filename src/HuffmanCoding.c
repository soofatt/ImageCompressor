#include "CodeTable.h"
#include "HuffmanCoding.h"
// #include "PredeterminedTables.h"

uint16 dcLuminanceTable[12] = {0x00, 0x02, 0x03, 0x04, 0x05, 0x06, 0x0E, 0x1E, 0x3E, 0x7E, 0xFE, 0x1FE};
uint16 dcChrominanceTable[12] = {0x00, 0x01, 0x02, 0x06, 0x0E, 0x1E, 0x3E, 0x7E, 0xFE, 0x1FE, 0x3FE, 0x7FE};

uint16 acLuminanceTable[256] = {0x0A  , 0x00  , 0x01  , 0x04  , 0x0B  , 0x1A  , 0x78  , 0xF8  ,
                                0x3F6 , 0xFF82, 0xFF83, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x0C  , 0x1B  , 0x79  , 0x1F6 , 0x7F6 , 0xFF84, 0xFF85,
                                0xFF86, 0xFF87, 0xFF88, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x1C  , 0xF9  , 0x3F7 , 0xFF4 , 0xFF89, 0xFF8A, 0xFF8B,
                                0xFF8C, 0xFF8D, 0xFF8E, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x3A  , 0x1F7 , 0xFF5 , 0xFF8F, 0xFF90, 0xFF91, 0xFF92,
                                0xFF93, 0xFF94, 0xFF95, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x3B  , 0x3F8 , 0xFF96, 0xFF97, 0xFF98, 0xFF99, 0xFF9A,
                                0xFF9B, 0xFF9C, 0xFF9D, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x7A  , 0x7F7 , 0xFF9E, 0xFF9F, 0xFFA0, 0xFFA1, 0xFFA2,
                                0xFFA3, 0xFFA4, 0xFFA5, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x7B  , 0xFF6 , 0xFFA6, 0xFFA7, 0xFFA8, 0xFFA9, 0xFFAA,
                                0xFFAB, 0xFFAC, 0xFFAD, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0xFA  , 0xFF7 , 0xFFAE, 0xFFAF, 0xFFB0, 0xFFB1, 0xFFB2,
                                0xFFB3, 0xFFB4, 0xFFB5, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x1F8 , 0x7FC0, 0xFFB6, 0xFFB7, 0xFFB8, 0xFFB9, 0xFFBA,
                                0xFFBB, 0xFFBC, 0xFFBD, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x1F9 , 0xFFBE, 0xFFBF, 0xFFC0, 0xFFC1, 0xFFC2, 0xFFC3,
                                0xFFC4, 0xFFC5, 0xFFC6, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x1FA , 0xFFC7, 0xFFC8, 0xFFC9, 0xFFCA, 0xFFCB, 0xFFCC,
                                0xFFCD, 0xFFCE, 0xFFCF, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x3F9 , 0xFFD0, 0xFFD1, 0xFFD2, 0xFFD3, 0xFFD4, 0xFFD5,
                                0xFFD6, 0xFFD7, 0xFFD8, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x3FA , 0xFFD9, 0xFFDA, 0xFFDB, 0xFFDC, 0xFFDD, 0xFFDE,
                                0xFFDF, 0xFFE0, 0xFFE1, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0x7F8 , 0xFFE2, 0xFFE3, 0xFFE4, 0xFFE5, 0xFFE6, 0xFFE7,
                                0xFFE8, 0xFFE9, 0xFFEA, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x00  , 0xFFEB, 0xFFEC, 0xFFED, 0xFFEE, 0xFFEF, 0xFFF0, 0xFFF1,
                                0xFFF2, 0xFFF3, 0xFFF4, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                0x7F9 , 0xFFF5, 0xFFF6, 0xFFF7, 0xFFF8, 0xFFF9, 0xFFFA, 0xFFFB,
                                0xFFFC, 0xFFFD, 0xFFFE, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  };

uint16 acChrominanceTable[256] = {0x00  , 0x01  , 0x04  , 0x0A  , 0x18  , 0x19  , 0x38  , 0x78  ,
                                  0x1F4 , 0x3F6 , 0xFF4 , 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x0B  , 0x39  , 0xF6  , 0x1F5 , 0x7F6 , 0xFF5 , 0xFF88,
                                  0xFF89, 0xFF8A, 0xFF8B, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x1A  , 0xF7  , 0x3F7 , 0xFF6 , 0x7FC2, 0xFF8C, 0xFF8D,
                                  0xFF8E, 0xFF8F, 0xFF90, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x1B  , 0xF8  , 0x3F8 , 0xFF7 , 0xFF91, 0xFF92, 0xFF93,
                                  0xFF94, 0xFF95, 0xFF96, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x3A  , 0x1F6 , 0xFF97, 0xFF98, 0xFF99, 0xFF9A, 0xFF9B,
                                  0xFF9C, 0xFF9D, 0xFF9E, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x3B  , 0x3F9 , 0xFF9F, 0xFFA0, 0xFFA1, 0xFFA2, 0xFFA3,
                                  0xFFA4, 0xFFA5, 0xFFA6, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x79  , 0x7F7 , 0xFFA7, 0xFFA8, 0xFFA9, 0xFFAA, 0xFFAB,
                                  0xFFAC, 0xFFAD, 0xFFAE, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x7A  , 0x7F8 , 0xFFAF, 0xFFB0, 0xFFB1, 0xFFB2, 0xFFB3,
                                  0xFFB4, 0xFFB5, 0xFFB6, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0xF9  , 0xFFB7, 0xFFB8, 0xFFB9, 0xFFBA, 0xFFBB, 0xFFBC,
                                  0xFFBD, 0xFFBE, 0xFFBF, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x1F7 , 0xFFC0, 0xFFC1, 0xFFC2, 0xFFC3, 0xFFC4, 0xFFC5,
                                  0xFFC6, 0xFFC7, 0xFFC8, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x1F8 , 0xFFC9, 0xFFCA, 0xFFCB, 0xFFCC, 0xFFCD, 0xFFCE,
                                  0xFFCF, 0xFFD0, 0xFFD1, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x1F9 , 0xFFD2, 0xFFD3, 0xFFD4, 0xFFD5, 0xFFD6, 0xFFD7,
                                  0xFFD8, 0xFFD9, 0xFFDA, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x1FA , 0xFFDB, 0xFFDC, 0xFFDD, 0xFFDE, 0xFFDF, 0xFFE0,
                                  0xFFE1, 0xFFE2, 0xFFE3, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x7F9 , 0xFFE4, 0xFFE5, 0xFFE6, 0xFFE7, 0xFFE8, 0xFFE9,
                                  0xFFEA, 0xFFEB, 0xFFEC, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x00  , 0x3FE0, 0xFFED, 0xFFEE, 0xFFEF, 0xFFF0, 0xFFF1, 0xFFF2,
                                  0xFFF3, 0xFFF4, 0xFFF5, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  ,
                                  0x3FA , 0x7FC3, 0xFFF6, 0xFFF7, 0xFFF8, 0xFFF9, 0xFFFA, 0xFFFB,
                                  0xFFFC, 0xFFFD, 0xFFFE, 0x00  , 0x00  , 0x00  , 0x00  , 0x00  };
                                  
uint16 huffmanEncode(uint8 runLength, uint8 bitSize, uint16 table[]){
  uint8 index = 0, counter = 0, shift = 0;
  uint16 tempResult, result;
  
  index = runLength;
  index = (index<<4) + bitSize;
  
  tempResult = table[index];

  if(tempResult == 1 && index <= 2)
    counter = 1;
  else if(tempResult == 2 && index < 2)
    counter = 1;
  else if(tempResult == 3 && index < 3)
    counter = 1;
  
  while(tempResult != 0){
    counter++;
    tempResult >>= 1;
  }

  shift = 16 - counter;
  
  result = table[index] << shift;
  
  return result;
}

uint8 huffmanDecode(uint16 codeWord, CodeTable *huffmanTable){
  uint8 result, shift = 12, loop = 4;
  uint16 tableIndex;
  CodeTable *currentTable;
  
  currentTable = huffmanTable;
  
  tableIndex = (codeWord >> shift) & 0x000F;
  // printf("%x", tableIndex);
  while(loop != 0){
    if(currentTable->table[tableIndex]->type == CODETABLE){
      currentTable = currentTable->table[tableIndex];
      shift -= 4;
      tableIndex = (codeWord >> shift) & 0x000F;
      loop--;
      // if(((RunSizeCode *)(currentTable->table[tableIndex]))->type == RUNSIZECODE)
        return result = ((RunSizeCode *)(currentTable->table[tableIndex]))->runSize;
    }
    else
      return result = ((RunSizeCode *)(currentTable->table[tableIndex]))->runSize;
  }
  // printf("%x", ((RunSizeCode *)(huffmanTable->table[tableIndex]))->runSize);

}


