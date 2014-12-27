#include "CodeTable.h"
#include "HuffmanCoding.h"
#include "runLengthCoding.h"
#include "ValueEncoding.h"
#include "PredeterminedTables.h"

/*  huffmanEncode
 *  Desc.  : To encode given runLength and bitSize into corresponding codeword
 *           in predetermined Huffman Table
 *  Input
 *    runLength : The run length result from zig zag reordering (number of zeroes)
 *    bitSize   : The bit size of the symbol (number of bits representing the symbol)
 *    table[]   : The predetermined Huffman Table (Either DC Luminance, AC Luminance,
 *                DC Chrominance or AC Chrominance table)
 *
 *  Output
 *    result    : The codeword obtained from the Huffman Table
 */
uint16 huffmanEncode(uint8 runLength, uint8 bitSize, uint16 table[]){
  uint8 index = 0, counter = 0, shift = 0;
  uint16 tempResult, result;
  
  index = runLength;
  index = (index<<4) + bitSize;
  
  tempResult = table[index];

  if(tempResult == 1 && index <= 2)//Special case for indexes starting with 0
    counter = 1;
  else if(tempResult == 2 && index < 2)//""
    counter = 1;
  else if(tempResult == 3 && index < 3)//""
    counter = 1;
  
  while(tempResult != 0){
    counter++;
    tempResult >>= 1;
  }

  shift = 16 - counter;
  
  result = table[index] << shift;
  
  return result;
}

/*  huffmanEncodePull
 *  Desc.  : To encode given runLength and bitSize into corresponding codeword
 *           in predetermined Huffman Table. This function is used in pull method.
 *  Input
 *    progress  : To keep track of the position during zig zag reordering and run length encoding
 *    dataIn    : The 8x8 array of image data input
 *    table[]   : The predetermined Huffman Table (Either DC Luminance, AC Luminance,
 *                DC Chrominance or AC Chrominance table)
 *
 *  Output
 *    result    : The codeword and symbol obtained from the Huffman Table
 *                e.g result = 0x  0000    0000
 *                               codeword symbol
 */

uint32 huffmanEncodePull(State *progress, short int dataIn[][8], uint16 table[]){
  uint8 index = 0, counter = 0, shift = 0;
  uint16 tempResult, run, valueEncodedSymbol, bitSize;
  uint32 runAndSymbol, valueEncodeResult, result;
  short int symbol;
  
  runAndSymbol = runLengthEncode(8, dataIn, progress);
  
  run = runAndSymbol >> 16;
  symbol = runAndSymbol & 0x0000ffff;
  
  valueEncodeResult = valueEncoding(symbol);
  
  bitSize = valueEncodeResult >> 16;
  valueEncodedSymbol = valueEncodeResult & 0x0000ffff;

  index = run;
  index = (index<<4) + bitSize;
  
  tempResult = table[index];

  if(tempResult == 1 && index <= 2)//Special case for indexes starting with 0
    counter = 1;
  else if(tempResult == 2 && index < 2)//""
    counter = 1;
  else if(tempResult == 3 && index < 3)//""
    counter = 1;
  
  while(tempResult != 0){
    counter++;
    tempResult >>= 1;
  }

  shift = 16 - counter;
  
  result = table[index] << shift;
  
  result = (result << 16) + valueEncodedSymbol;
  
  return result;
}

/*  huffmanDecode
 *  Desc.  : To decode given codeword into run length and bit size from
 *           custom made Huffman Table (Built from predetermined Huffman Table)
 *  Input
 *    codeWord    : The codeword input
 *    huffmanTable: The custom made Huffman Table which is rearranged according to code length
 *
 *  Output
 *    result    : The decoded run length and bit size
 *                e.g result = 0x    F        0
 *                                runLength bitSize
 */
uint8 huffmanDecode(uint16 codeWord, CodeTable *huffmanTable){
  uint8 result, shift = 12, loop = 4;
  uint16 tableIndex;
  CodeTable *currentTable;
  
  currentTable = huffmanTable;
  
  tableIndex = (codeWord >> shift) & 0x000F;
  // printf("%x", tableIndex);
  while(loop != 0){
    if(currentTable->table[tableIndex]->codeType == CODETABLE){
      // printf("%d\n", currentTable->table[tableIndex]->codeType);
      // printf("%x\n", currentTable->table[0]->runSize);
      currentTable = currentTable->table[tableIndex];
      
      shift -= 4;
      tableIndex = (codeWord >> shift) & 0x000F;
      loop--;
      // printf("%d\n", ((RunSizeCode *)(currentTable->table[tableIndex]))->type);
      // printf("%d\n", ((RunSizeCode *)(currentTable->table[15]))->type);
      // printf("%d\n", ((RunSizeCode *)(currentTable->table[8]))->runSize);
      // printf("a\n");
      // printf("%x\n", ((RunSizeCode *)(currentTable->table[15]->table[0]))->runSize);
      // printf("%d\n", currentTable->table[tableIndex]->type);
      // printf("%d\n", loop);
      // printf("%d\n", tableIndex);
      // printf("%d\n", ((RunSizeCode *)(currentTable->table[tableIndex]))->type);
      if(((RunSizeCode *)(currentTable->table[tableIndex]))->type != CODETABLE || tableIndex == 0)
        return result = ((RunSizeCode *)(currentTable->table[tableIndex]))->runSize;
    }
    else{
      // printf("%d\n", currentTable->table[tableIndex]->type);
      // printf("%d\n", ((RunSizeCode *)(currentTable->table[tableIndex]))->type);
      // printf("%d\n", tableIndex);
      return result = ((RunSizeCode *)(currentTable->table[tableIndex]))->runSize;}
  }
  // printf("%x", ((RunSizeCode *)(huffmanTable->table[tableIndex]))->runSize);

}


