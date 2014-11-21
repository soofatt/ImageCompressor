#include "ValueEncoding.h"

#define putCategoryIntoInt(x) ((uint32)x) << 16
#define getCategoryFromInt(x) x >> 16

uint32 valueEncoding(int16 symbol){
  unsigned char category;
  short int mask = 0x01, value;
  int i;
  uint32 categoryAndSymbol = 0;
  
  category = getCategory(symbol);
  
  for(i = 0; i < 15 - category; i++){
    mask = (mask << 1) + 1;
  }
  mask = ~(mask << category);
  
  categoryAndSymbol = putCategoryIntoInt(category);
  value = symbol;
  
  if(value < 0)
    return categoryAndSymbol |= ((value & mask) - 1);
  else
    return categoryAndSymbol |= value;
}

int16 valueDecoding(uint32 categoryAndSymbol){
  unsigned char category;
  short int symbol, mask = 0x01, limit;
  int i;
  
  category = getCategoryFromInt(categoryAndSymbol);
  symbol = categoryAndSymbol;
  
  limit = 0x01 << category - 1;
  
  for(i = 0; i < 15 - category; i++){
    mask = (mask << 1) + 1;
  }
  mask = mask << category;
  
  if(symbol < limit)
    return (symbol | mask) + 1;
  else
    return symbol;
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