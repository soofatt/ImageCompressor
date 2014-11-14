#include "ValueEncoding.h"

void valueEncoding(EncodeData *data, int length, short int nextSymbol){
  data->runLength = length;
  data->bitSize = obtainBitSize(nextSymbol);
  data->symbol = nextSymbol;
    
}

int obtainBitSize(short int symbol){
  int i, bitSize;
  
  if(symbol < 0)
    symbol = symbol * -1;
  
  for(i = 0; i < 11; i++){
    if(((symbol>>i) & 0x01))
      bitSize = i + 1;
  }
  
  return bitSize;
}