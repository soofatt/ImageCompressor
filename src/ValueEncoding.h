#ifndef ValueEncoding_H
#define ValueEncoding_H

typedef struct EncodeData EncodeData;
struct EncodeData{
  int runLength;
  int bitSize; // a.k.a category
  int symbol;
};

void valueEncoding(EncodeData *data, int length, short int nextSymbol);
int obtainBitSize(short int symbol);

#endif // ValueEncoding_H
