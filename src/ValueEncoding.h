#ifndef ValueEncoding_H
#define ValueEncoding_H

typedef struct EncodeData EncodeData;
struct EncodeData{
  unsigned char runAndCategory;//First 4 bits is run length, last 4 bits is category
  short int symbol;
};

typedef struct RunLengthData RunLengthData;
struct RunLengthData{
  unsigned char run;
  short int nextSymbol;
};

void valueEncoding(EncodeData *data, RunLengthData *input);// Parameters to be changed
void valueDecoding(EncodeData *data, RunLengthData *container);// Parameters to be changed
char getCategory(short int symbol);

#endif // ValueEncoding_H
