#include "ValueEncoding.h"

#define putCategoryIntoInt(x) ((uint32)x) << 16
#define getCategoryFromInt(x) x >> 16

/*  valueEncoding
 *  Desc.  : Function to perform value encoding on a given symbol (Encode into bit size and symbol)
 *
 *  Input
 *    symbol   : The symbol to be value encoded (Obtained from run length encoding)
 *               Note : if symbol is -ve value, it will be output as its one's complement
 *
 *  Output
 *    categoryAndSymbol : The resulting category and symbol.
 *                        e.g 0x  0000     0000
 *                              category  symbol
 */
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

/*  valueDecoding
 *  Desc.  : Function to retrieve the symbol given the category and symbol
 *
 *  Input
 *    categoryAndSymbol : Input category and symbol.
 *
 *  Output
 *    symbol : The resulting symbol.
 *             Note: -ve symbol will be in its one's complement form and will be 
 *                   converted into its two's complement form.
 *
 */
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

/*  getCategory
 *  Desc.  : Subfunction to obtain the category of given symbol
 *
 *  Input
 *    symbol : Input symbol.
 *
 *  Output
 *    bitSize : The resulting category.
 *
 */
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