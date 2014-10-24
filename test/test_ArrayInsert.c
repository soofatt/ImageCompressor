#include "unity.h"
#include "Stream.h"
#include "ArrayInsert.h"
#include "dataType.h"

void setUp(void){}

void tearDown(void){}

void test_insertIntoArray_given_64bytes_should_insert_into_8_row_8_col(void){
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
}
