#include "unity.h"
#include "Stream.h"
#include "ArrayIO.h"
#include "dataType.h"
#include "Common.h"

void setUp(void){}

void tearDown(void){}

void test_insertIntoArray_given_64bytes_should_insert_into_8by8_matrix(void){
	CEXCEPTION_T error;
  Stream *fileStream = NULL;
  float inputMatrix[8][8];
  int size = 8;

  Try{
    fileStream = openStream("test/Data/Water lilies.7z.010", "rb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }

  insertIntoArray(fileStream, size, inputMatrix);
  
  TEST_ASSERT_EQUAL_HEX8(0x7F , inputMatrix[0][0]);
  TEST_ASSERT_EQUAL_HEX8(0x90 , inputMatrix[7][7]);
  
  closeStream(fileStream);
}

void test_outputToFile_given_8by8_matrix_should_output_to_64_bytes_in_file(void){
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
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }

  outputToFile(fileStream, size, inputMatrix);
  
  closeStream(fileStream);
}