#include "unity.h"
#include "Common.h"
#include "DCT.h"
#include "IDCT.h"
#include "Normalization.h"
#include "Quantization.h"
#include "Stream.h"
#include "ArrayIO.h"
#include "ColorConversion.h"
#include "dataType.h"

#define TEST_ASSERT_EQUAL_MATRIX(expected, actual) \
  assert8by8Matrix(expected, actual, __LINE__);

void assert8by8Matrix(float expectedMatrix[][8], float actualMatrix[0][8], int line){
  int i, j;
  
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      TEST_ASSERT_FLOAT_WITHIN(0.5, expectedMatrix[i][j], actualMatrix[i][j]);
    }
  }
}

void setUp(void){}

void tearDown(void){}

void test_DCT_transform_array_of_3_elements_and_should_invert_back_to_original_by_IDCT(){
  float imageMatrix[3] = {1, 2, 3};
  
  oneD_DCT_row(imageMatrix, sizeof(imageMatrix)/sizeof(float));
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 3.464, imageMatrix[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -1.414, imageMatrix[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2]);
  
  oneD_IDCT_row(imageMatrix, 3);
  round_float(imageMatrix, 3);
  
  TEST_ASSERT_EQUAL(1,imageMatrix[0]);
  TEST_ASSERT_EQUAL(2,imageMatrix[1]);
  TEST_ASSERT_EQUAL(3,imageMatrix[2]);
}

void test_DCT_transform_array_of_8_elements_and_should_invert_back_to_original_by_IDCT(){
  float imageMatrix[8] = {1,2,3,4,5,6,7,8};

  oneD_DCT_row(imageMatrix, sizeof(imageMatrix)/sizeof(float));
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 12.727, imageMatrix[0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -6.442, imageMatrix[1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0.673, imageMatrix[3]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[4]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0.200, imageMatrix[5]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[6]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -0.050, imageMatrix[7]);
  
  oneD_IDCT_row(imageMatrix, 8);
  round_float(imageMatrix, 8);
  
  TEST_ASSERT_EQUAL(1,imageMatrix[0]);
  TEST_ASSERT_EQUAL(2,imageMatrix[1]);
  TEST_ASSERT_EQUAL(3,imageMatrix[2]);
  TEST_ASSERT_EQUAL(4,imageMatrix[3]);
  TEST_ASSERT_EQUAL(5,imageMatrix[4]);
  TEST_ASSERT_EQUAL(6,imageMatrix[5]);
  TEST_ASSERT_EQUAL(7,imageMatrix[6]);
  TEST_ASSERT_EQUAL(8,imageMatrix[7]);
}

void test_two_D_DCT_transform_array_of_3_elements_and_should_invert_back_to_original_by_IDCT(){
  float imageMatrix[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
  int size = 3;
  
  twoD_DCT(size, imageMatrix);
  
  TEST_ASSERT_FLOAT_WITHIN(0.001, 5.999, imageMatrix[0][0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, -2.449, imageMatrix[0][1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[0][2]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[1][0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[1][1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[1][2]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2][0]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2][1]);
  TEST_ASSERT_FLOAT_WITHIN(0.001, 0, imageMatrix[2][2]);
  
  twoD_IDCT(size, imageMatrix);
  
  TEST_ASSERT_EQUAL(1,imageMatrix[0][0]);
  TEST_ASSERT_EQUAL(1,imageMatrix[1][0]);
  TEST_ASSERT_EQUAL(1,imageMatrix[2][0]);
  TEST_ASSERT_EQUAL(2,imageMatrix[0][1]);
  TEST_ASSERT_EQUAL(2,imageMatrix[1][1]);
  TEST_ASSERT_EQUAL(2,imageMatrix[2][1]);
  TEST_ASSERT_EQUAL(3,imageMatrix[0][2]);
  TEST_ASSERT_EQUAL(3,imageMatrix[1][2]);
  TEST_ASSERT_EQUAL(3,imageMatrix[2][2]);
}

void test_two_D_DCT_transform_array_of_8_elements_and_should_invert_back_to_original_by_IDCT(){
  float imageMatrix[8][8] = {{1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8},
                             {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8},
                             {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}};
                             
  float expectMatrix[8][8] ={{1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8},
                             {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8},
                             {1, 2, 3, 4, 5, 6, 7, 8}, {1, 2, 3, 4, 5, 6, 7, 8}};
  
  int size = 8;
  int i, j;
  twoD_DCT(size, imageMatrix);
  
  twoD_IDCT(size, imageMatrix);
  
  TEST_ASSERT_EQUAL_MATRIX(expectMatrix, imageMatrix);
}

void test_two_D_DCT_transform_array_of_8_elements_and_should_invert_back_to_original_by_IDCT_case2(){
  float imageMatrix[8][8] = {{10, 22, 53, 44, 81, 53, 35, 102}, 
                             {35, 43, 11, 48, 0, 110, 120, 90}, 
                             {12, 68, 35, 44, 5, 64, 79, 88},
                             {11, 24, 35, 74, 59, 65, 47, 88}, 
                             {71, 52, 83, 54, 59, 61, 78, 88}, 
                             {31, 29, 73, 44, 51, 46, 7, 8},
                             {12, 23, 36, 48, 50, 16, 78, 98}, 
                             {17, 92, 33, 74, 95, 96, 97, 81}};

  float expectMatrix[8][8] ={{10, 22, 53, 44, 81, 53, 35, 102}, 
                             {35, 43, 11, 48, 0, 110, 120, 90}, 
                             {12, 68, 35, 44, 5, 64, 79, 88},
                             {11, 24, 35, 74, 59, 65, 47, 88}, 
                             {71, 52, 83, 54, 59, 61, 78, 88}, 
                             {31, 29, 73, 44, 51, 46, 7, 8},
                             {12, 23, 36, 48, 50, 16, 78, 98}, 
                             {17, 92, 33, 74, 95, 96, 97, 81}};
                             
  int size = 8;
  int i, j;
  
  twoD_DCT(size, imageMatrix);
  
  // dumpMatrix(size,imageMatrix);
  
  twoD_IDCT(size, imageMatrix);
  
  // dumpMatrix(size,imageMatrix);
  
  TEST_ASSERT_EQUAL_MATRIX(expectMatrix, imageMatrix);
}

void test_two_D_DCT_transform_array_of_8_elements_and_should_invert_back_to_original_by_IDCT_with_normalization(){
  float imageMatrix[8][8] = {{154, 123, 123, 123, 123, 123, 123, 136}, 
                             {192, 180, 136, 154, 154, 154, 136, 110}, 
                             {254, 198, 154, 154, 180, 154, 123, 123},
                             {239, 180, 136, 180, 180, 166, 123, 123}, 
                             {180, 154, 136, 167, 166, 149, 136, 136}, 
                             {128, 136, 123, 136, 154, 180, 198, 154},
                             {123, 105, 110, 149, 136, 136, 180, 166}, 
                             {110, 136, 123, 123, 123, 136, 154, 136}};
                             
  float expectMatrix[8][8] ={{154, 123, 123, 123, 123, 123, 123, 136}, 
                             {192, 180, 136, 154, 154, 154, 136, 110}, 
                             {254, 198, 154, 154, 180, 154, 123, 123},
                             {239, 180, 136, 180, 180, 166, 123, 123}, 
                             {180, 154, 136, 167, 166, 149, 136, 136}, 
                             {128, 136, 123, 136, 154, 180, 198, 154},
                             {123, 105, 110, 149, 136, 136, 180, 166}, 
                             {110, 136, 123, 123, 123, 136, 154, 136}};                            
                             
  int size = 8;
  int i, j;

  normalizeMatrix(size, imageMatrix);
  
  twoD_DCT(size, imageMatrix);
  
  // dumpMatrix(size,imageMatrix);
  // printf("\n");
  
  twoD_IDCT(size, imageMatrix);
  
  denormalizeMatrix(size, imageMatrix);
  
  // dumpMatrix(size, imageMatrix);
  
  TEST_ASSERT_EQUAL_MATRIX(expectMatrix, imageMatrix);
}

void test_DCT_and_IDCT_with_quantization_and_dequantization(){
  float imageMatrix[8][8] = {{139, 144, 149, 153, 155, 155, 155, 155}, 
                             {144, 151, 153, 156, 159, 156, 156, 156}, 
                             {150, 155, 160, 163, 158, 156, 156, 156},
                             {159, 161, 162, 160, 160, 159, 159, 159}, 
                             {159, 160, 161, 162, 162, 155, 155, 155}, 
                             {161, 161, 161, 161, 160, 157, 157, 157},
                             {162, 162, 161, 163, 162, 157, 157, 157}, 
                             {162, 162, 161, 161, 163, 158, 158, 158}};                       
  int size = 8;
  int i, j;

  normalizeMatrix(size, imageMatrix);
  
  twoD_DCT(size, imageMatrix);
  // dumpMatrix(size,imageMatrix);
  quantizationFunction50(size, imageMatrix);
  // dumpMatrix(size,imageMatrix);
  // printf("\n");
  dequantizationFunction50(size, imageMatrix);
  // dumpMatrix(size,imageMatrix);
  twoD_IDCT(size, imageMatrix);
  // dumpMatrix(size,imageMatrix);
  denormalizeMatrix(size, imageMatrix);
  
  // dumpMatrix(size, imageMatrix);
}

/*
 *  Raw file                       DCT output
 *   -----                           -----
 *  |     |  read+chop      write   |     |
 *  |     |    ---->   DCT   ---->  |     |
 *  |     |                         |     |
 *   -----                           -----
 *  DCT output                     IDCT result
 *   -----                           -----
 *  |     |  read+chop      write   |     |
 *  |     |    ---->  IDCT   ---->  |     |
 *  |     |                         |     |
 *   -----                           -----
 */
void test_release1_given_file_should_output_close_to_original_file(){
  CEXCEPTION_T error;
  Stream *inStream = NULL;
  Stream *outStream = NULL;
  float inputMatrix[8][8];
  int size = 8, count = 0;
  
  Try{
    inStream = openStream("test/Data/Water lilies.7z.010", "rb");
    outStream = openStream("test/Data/Water lilies_RE1.7z.010", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  Try{
  while(1){
    readBlock(inStream, size, inputMatrix);
    //printf("%.3f", inputMatrix[0][0]);
    normalizeMatrix(size, inputMatrix);
    // dumpMatrix(size, inputMatrix);
    twoD_DCT(size, inputMatrix);
    // printf("%.3f", inputMatrix[0][0]);
    // dumpMatrix(size, inputMatrix);
    writeBlock11Bit(outStream, size, inputMatrix);
    
   if( feof(inStream->file) )
      { 
          break ;
      }
  }
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  closeStream(inStream);
  closeStream(outStream);
  // printf("\n");
  Stream *inStream2 = NULL;
  Stream *outStream2 = NULL;
  count = 0;
  short int inputMatrixIDCT[8][8];
  
  Try{
    inStream2 = openStream("test/Data/Water lilies_RE1.7z.010", "rb");
    outStream2 = openStream("test/Data/Water lilies_RE1Out.7z.010", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  Try{
  while(1){
    readBlock11Bit(inStream2, size, inputMatrixIDCT);
    // dumpMatrixInt(size, inputMatrixIDCT);
    convertToFloat(inputMatrixIDCT, inputMatrix);
    twoD_IDCT(size, inputMatrix);
    denormalizeMatrix(size, inputMatrix);
    // dumpMatrix(size, inputMatrix);
    
    writeBlock(outStream2, size, inputMatrix);
    
    if( feof(inStream2->file) )
      { 
          break ;
      }
  }
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  closeStream(inStream2);
  closeStream(outStream2);
}

/*
 *  Raw file                                          DCT output
 *   -----                                              -----
 *  |     |  read+chop                         write   |     |
 *  |     |    ---->   DCT ---->  Quantization  ---->  |     |
 *  |     |                                            |     |
 *   -----                                              -----
 *  DCT output                                           IDCT result
 *   -----                                                  -----
 *  |     |  read+chop                             write   |     |
 *  |     |    ---->  Dequantization  ---->  IDCT   ---->  |     |
 *  |     |                                                |     |
 *   -----                                                  -----
 */
void test_release2(){
  CEXCEPTION_T error;
  Stream *inStream = NULL;
  Stream *outStream = NULL;
  float inputMatrix[8][8];
  int size = 8, count = 0;
  
  Try{
    inStream = openStream("test/Data/Water lilies.7z.010", "rb");
    outStream = openStream("test/Data/Water lilies_RE2.7z.010", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  Try{
  while(1){
    readBlock(inStream, size, inputMatrix);
    //printf("%.3f", inputMatrix[0][0]);
    normalizeMatrix(size, inputMatrix);
    // dumpMatrix(size, inputMatrix);
    twoD_DCT(size, inputMatrix);
    // printf("%.3f", inputMatrix[0][0]);
    // dumpMatrix(size, inputMatrix);
    quantizationFunction50(size, inputMatrix);
    // dumpMatrix(size, inputMatrix);
    writeBlock11Bit(outStream, size, inputMatrix);
    
    if( feof(inStream->file) )
      { 
          break ;
      }
  }
  }Catch(error){
  TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  closeStream(inStream);
  closeStream(outStream);
  // printf("\n");
  Stream *inStream2 = NULL;
  Stream *outStream2 = NULL;
  count = 0;
  short int inputMatrixIDCT[8][8];
  
  Try{
    inStream2 = openStream("test/Data/Water lilies_RE2.7z.010", "rb");
    outStream2 = openStream("test/Data/Water lilies_RE2Out.7z.010", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  Try{
  while(1){
    readBlock11Bit(inStream2, size, inputMatrixIDCT);
    // dumpMatrixInt(size, inputMatrixIDCT);
    convertToFloat(inputMatrixIDCT, inputMatrix);
    dequantizationFunction50(size, inputMatrix);
    //dumpMatrix(size, inputMatrix);
    twoD_IDCT(size, inputMatrix);
    denormalizeMatrix(size, inputMatrix);
    // dumpMatrix(size, inputMatrix);
    
    writeBlock(outStream2, size, inputMatrix);
    
   if( feof(inStream2->file) )
      { 
          break ;
      }
  }
  }Catch(error){
  TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  closeStream(inStream2);
  closeStream(outStream2);
}

void test_release_compression_logic(){
CEXCEPTION_T error;
  Stream *inStream = NULL;
  Stream *outStream = NULL;
  float inputMatrixA[8][8], inputMatrixB[8][8], inputMatrixC[8][8];
  int size = 8;
  RGB colorRGB;
  YCbCr lumaChrom;

  uint8 R[8][8], G[8][8], B[8][8];
	uint8 Y[8][8], Cb[8][8], Cr[8][8];
  
  colorRGB.red = &R; colorRGB.green = &G; colorRGB.blue = &B;
  lumaChrom.Y = &Y; lumaChrom.Cb = &Cb; lumaChrom.Cr = &Cr;
	
	Try{
    inStream = openStream("test/Data/Water lilies.7z.010", "rb");
    outStream = openStream("test/Data/outputData.7z.010", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_FILE_NOT_EXIST, error);
  }
  
  readFileToRGB(inStream,R,G,B);
  
  convertUINT8ToFloat(Y, inputMatrixA);
  convertUINT8ToFloat(Cb, inputMatrixB);
  convertUINT8ToFloat(Cr, inputMatrixC);

  normalizeMatrix(8,inputMatrixA);
  normalizeMatrix(8,inputMatrixB);
  normalizeMatrix(8,inputMatrixC);
  
  twoD_DCT(8,inputMatrixA);
  twoD_DCT(8,inputMatrixB);
  twoD_DCT(8,inputMatrixC);
  
  quantizationFunction50(8,inputMatrixA);
  quantizationFunction50(8,inputMatrixB);
  quantizationFunction50(8,inputMatrixC);
  
  dumpMatrix(8, inputMatrixA);
  dumpMatrix(8, inputMatrixB);
  dumpMatrix(8, inputMatrixC);
  
  //To Encoder..... can only detect state.index to stop when it is 64
  //To Byte Stuff, output to file in Y, Cb, Cr
  //Repeat process until (!feof(inStream))
  
  closeStream(inStream);
  closeStream(outStream);
}

// convertToLuma(&colorRGB, &lumaChrom); convertToChromaB(&colorRGB, &lumaChrom); convertToChromaR(&colorRGB, &lumaChrom);
// dumpMatrixUINT8(8,Y); dumpMatrixUINT8(8,Cb); dumpMatrixUINT8(8,Cr);
// dumpMatrixUINT8(8,R); dumpMatrixUINT8(8,G); dumpMatrixUINT8(8,B);

// printf("\n");
// convertToRed(&colorRGB, &lumaChrom); convertToBlue(&colorRGB, &lumaChrom); convertToGreen(&colorRGB, &lumaChrom);
// dumpMatrixUINT8(8,R); dumpMatrixUINT8(8,G); dumpMatrixUINT8(8,B);

// dumpMatrix(8, inputMatrixA);
// dumpMatrix(8, inputMatrixB);
// dumpMatrix(8, inputMatrixC);

void xtest_release_decompression_logic(){
  //Huffman decoder
  //To Run Length Decode
  //Loop 3 times to get Y Cb Cr arrays
  //De-Q - IDCT - Denormalization - Color Conversion back to RGB
  //Output to file again
}



