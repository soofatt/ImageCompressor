#ifndef ValueEncoding_H
#define ValueEncoding_H

#define uint32 unsigned int
#define uint16 unsigned short int
#define int16 short int

uint32 valueEncoding(int16 symbol);
int16 valueDecoding(uint32 categoryAndSymbol);
char getCategory(short int symbol);

#endif // ValueEncoding_H
