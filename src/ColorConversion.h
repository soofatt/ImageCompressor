#ifndef ColorConversion_H
#define ColorConversion_H

void convertToLuma(short int red[][8], short int green[][8], short int blue[][8], short int luma[][8]);
void convertToChromaB(short int red[][8], short int green[][8], short int blue[][8], short int chroma[][8]);
void convertToChromar(short int red[][8], short int green[][8], short int blue[][8], short int chroma[][8]);

#endif // ColorConversion_H
