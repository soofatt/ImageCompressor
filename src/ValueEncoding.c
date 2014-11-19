#include "ValueEncoding.h"

void valueEncoding(EncodeData *data, char runLength, short int nextSymbol){
  unsigned char category;
  
  category = getCategory(nextSymbol);
  
  data->runAndCategory = runLength;
  data->runAndCategory = (data->runAndCategory << 4) + category;
  data->symbol = nextSymbol;
}

void valueDecoding(EncodeData *data, RunLengthData *container){
  unsigned char category;
  short int temp, mask = 0x01, limit;
  int i;
  
  category = data->runAndCategory & 0x0F;
  container->run = data->runAndCategory >> 4;
  
  limit = 0x01 << category - 1;
  
  for(i = 0; i < 15 - category; i++){
    mask = (mask << 1) + 1;
  }
  mask = mask << category;
  
  if(data->symbol < limit)
    container->symbol = (data->symbol | mask) + 1;
  else
    container->symbol = data->symbol;
}

char getCategory(short int symbol){
  int i, bitSize;
  
  if(symbol < 0)
    symbol = symbol * -1;
  
  for(i = 0; i < 11; i++){
    if(((symbol>>i) & 0x01))
      bitSize = i + 1;
  }
  
  return bitSize;
}