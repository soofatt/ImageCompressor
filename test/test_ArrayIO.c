#include "unity.h"
#include "Stream.h"
#include "ArrayIO.h"
#include "dataType.h"
#include "Common.h"
#include "CustomAssertion.h"

void setUp(void){}

void tearDown(void){}

void test_readBlock_given_64bytes_should_insert_into_8by8_matrix(void){
	CEXCEPTION_T error;
  Stream *fileStream = NULL;
  float inputMatrix[8][8];
  int size = 8;

  Try{
    fileStream = openStream("test/Data/Water lilies.7z.010", "rb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_FILE_NOT_EXIST, error);
  }

  readBlock(fileStream, size, inputMatrix);
  
  TEST_ASSERT_EQUAL_HEX8(0x7F , inputMatrix[0][0]);
  TEST_ASSERT_EQUAL_HEX8(0x90 , inputMatrix[7][7]);
  
  closeStream(fileStream);
}

void test_writeBlock_given_8by8_matrix_should_output_to_64_bytes_in_file(void){
	CEXCEPTION_T error;
  Stream *fileStream = NULL;
  float inputMatrix[8][8] = {{127, 52, 169, 177, 74, 60, 66, 135},
                            {226, 201, 142, 99, 136, 105, 187, 207},
                            {181, 230, 171, 217, 96, 252, 199, 3},
                            {247, 46, 144, 100, 180, 251, 231, 145},
                            {35, 230, 185, 187, 196, 56, 173, 220},
                            {47, 70, 252, 10, 205, 140, 14, 129},
                            {180, 252, 66, 177, 204, 70, 38, 49},
                            {148, 180, 232, 191, 40, 26, 18, 144}};
  int size = 8;
  
  Try{
    fileStream = openStream("test/Data/Water lilies_Out.7z.010", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_FILE_NOT_EXIST, error);
  }

  writeBlock(fileStream, size, inputMatrix);
  
  closeStream(fileStream);
}

void test_writeBlock11Bit_given_8by8_matrix_should_output_to_128_bytes_in_file(void){
	CEXCEPTION_T error;
  Stream *fileStream = NULL;
  float inputMatrix[8][8] = {{127, 52, 169, 177, 74, 60, 66, 135},
                            {226, 201, 142, 99, 136, 105, 187, 207},
                            {181, 230, 171, 217, 96, 252, 199, 3},
                            {247, 46, 144, 100, 180, 251, 231, 145},
                            {35, 230, 185, 187, 196, 56, 173, 220},
                            {47, 70, 252, 10, 205, 140, 14, 129},
                            {180, 252, 66, 177, 204, 70, 38, 49},
                            {148, 180, 232, 191, 40, 26, 18, 144}};
  int size = 8;
  
  Try{
    fileStream = openStream("test/Data/Water lilies_Out2.7z.010", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_FILE_NOT_EXIST, error);
  }

  writeBlock11Bit(fileStream, size, inputMatrix);
  
  closeStream(fileStream);
}

void test_readBlock11Bit_given_128bytes_should_read_from_file_correctly(void){
  CEXCEPTION_T error;
  Stream *fileStream = NULL;
  short int inputMatrix[8][8];
  int i, j, size = 8;
  
  Try{
    fileStream = openStream("test/Data/Water lilies_Out2.7z.010", "rb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_FILE_NOT_EXIST, error);
  }
  
  readBlock11Bit(fileStream, size, inputMatrix);
  
  TEST_ASSERT_EQUAL_HEX8(0x7F , inputMatrix[0][0]);
  TEST_ASSERT_EQUAL_HEX8(0x90 , inputMatrix[7][7]);
  
  // for(i = 0; i < size; i++){
    // for(j = 0; j < size; j++){
      // printf("%d ", inputMatrix[i][j]);
    // }
    // printf("\n");
  // }
  
  closeStream(fileStream);
}

void test_readFileToRGB_to_get_64_bytes_data_for_R_G_and_B_array(){
  CEXCEPTION_T error;
  Stream *in = NULL;
  uint8 redMatrix[8][8];
  uint8 greenMatrix[8][8];
  uint8 blueMatrix[8][8];
  
  Try{
    in = openStream("test/Data/Water lilies.7z.010", "rb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_FILE_NOT_EXIST, error);
  }
  
  readFileToRGB(in, redMatrix, greenMatrix, blueMatrix);
  closeStream(in);
  TEST_ASSERT_EQUAL_HEX8(0x7F , redMatrix[0][0]);
  TEST_ASSERT_EQUAL_HEX8(0x34 , greenMatrix[0][0]);
  TEST_ASSERT_EQUAL_HEX8(0xa9 , blueMatrix[0][0]);
  TEST_ASSERT_EQUAL_HEX8(0xb1 , redMatrix[0][1]);
  TEST_ASSERT_EQUAL_HEX8(0x4a , greenMatrix[0][1]);
  TEST_ASSERT_EQUAL_HEX8(0x3c , blueMatrix[0][1]);
}

void test_writeRGBToFile_to_insert_64_bytes_data_from_R_G_and_B_array_to_file(){
  CEXCEPTION_T error;
  Stream *out = NULL;
  Stream *in = NULL;
  uint8 redInMatrix[8][8];
  uint8 greenInMatrix[8][8];
  uint8 blueInMatrix[8][8];
  uint8 redMatrix[8][8] = {{127, 2, 169, 177, 74, 60, 66, 135},
                            {226, 201, 142, 99, 136, 105, 187, 207},
                            {181, 230, 171, 217, 96, 252, 199, 3},
                            {247, 46, 144, 100, 180, 251, 231, 145},
                            {35, 230, 185, 187, 196, 56, 173, 220},
                            {47, 70, 252, 10, 205, 140, 14, 129},
                            {180, 252, 66, 177, 204, 70, 38, 49},
                            {148, 180, 232, 191, 40, 26, 18, 144}};
  uint8 greenMatrix[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
                            { 36, 108,  14,  38,  26,   0,   0,   0},
                            {-98, -65,  16, -48, -40,   0,   11,   0},
                            {-42, -85,   0, -29,   0,   3,   0,   0},
                            {-36,  22,   0,   0,   4,   0,   0,   0}, 
                            {  0,   0,   0,   0,   0,   0,   88,   0},
                            {  0,   0,   0,   5,   90,   0,   0,   0},
                            {  1,   0,   0,   0,   0,   0,   0,   1}};
  uint8 blueMatrix[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
                            { 36, 108,  14,  38,  26,   0,   0,   0},
                            {-98, -65,  16, -48, -40,   0,   0,   0},
                            {-42, -85,   0, -29,   0,   0,   0,   0},
                            {-36,  22,   0,   0,   0,   0,   0,   0}, 
                            {  0,   0,   0,   0,   0,   0,   0,   0},
                            {  0,   0,   0,   5,   0,   0,   0,   0},
                            {  1,   0,   0,   0,   0,   0,   0,   1}};
  
  Try{
    out = openStream("test/Data/Output.7z.010", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_FILE_NOT_EXIST, error);
  }
  
  writeRGBToFile(out, redMatrix, greenMatrix, blueMatrix);
  closeStream(out);
  //Read back from the output file and do the compare
  Try{
    in = openStream("test/Data/Output.7z.010", "rb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_FILE_NOT_EXIST, error);
  }
  readFileToRGB(in, redInMatrix, greenInMatrix, blueInMatrix);
  closeStream(in);
  
  TEST_ASSERT_EQUAL_UINT8_2D_ARRAY(redInMatrix, redMatrix);
  TEST_ASSERT_EQUAL_UINT8_2D_ARRAY(greenInMatrix, greenMatrix);
  TEST_ASSERT_EQUAL_UINT8_2D_ARRAY(blueInMatrix, blueMatrix);
}