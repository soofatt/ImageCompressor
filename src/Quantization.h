#ifndef Quantization_H
#define Quantization_H

#define quantizationFunction50(size, inputMatrix) \
        quantizationFunction(size, inputMatrix, quantizationMatrix50)

#define quantizationFunction90(size, inputMatrix) \
        quantizationFunction(size, inputMatrix, quantizationMatrix90)

#define quantizationFunction10(size, inputMatrix) \
        quantizationFunction(size, inputMatrix, quantizationMatrix10)
        
#define dequantizationFunction50(size, inputMatrix) \
        dequantizationFunction(size, inputMatrix, quantizationMatrix50)

#define dequantizationFunction90(size, inputMatrix) \
        dequantizationFunction(size, inputMatrix, quantizationMatrix90)

#define dequantizationFunction10(size, inputMatrix) \
        dequantizationFunction(size, inputMatrix, quantizationMatrix10)
        
extern const int quantizationMatrix50[8][8];
extern const int quantizationMatrix90[8][8];
extern const int quantizationMatrix10[8][8];

void quantizationFunction(int size, float inputMatrix[][size], const int quantizationMatrix[][8]);
void dequantizationFunction(int size, float inputMatrix[][size], const int quantizationMatrix[][8]);

#endif // Quantization_H
