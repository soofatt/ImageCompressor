#include "unity.h"
#include "Stream.h"

void setUp(void){}

void tearDown(void){}

void test_writeStuffedByte_given_0x0A_should_only_write_0x0A(void){
  CEXCEPTION_T error;
  Stream *fileStream = NULL;
  
  Try{
    fileStream = openStream("test/Data/StuffedByte_write", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  
  writeStuffedByte(fileStream, 0x0A);
  
  closeStream(fileStream);
}

void test_writeStuffedByte_given_0xFF_should_only_write_0xFF_and_0x00(void){
  CEXCEPTION_T error;
  Stream *fileStream = NULL;
  
  Try{
    fileStream = openStream("test/Data/StuffedByte_write2", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  
  writeStuffedByte(fileStream, 0xFF);
  
  closeStream(fileStream);
}

void test_writeStuffedByte_given_few_bytes_should_stuff_0xFF_with_0x00(void){
  CEXCEPTION_T error;
  Stream *fileStream = NULL;
  
  Try{
    fileStream = openStream("test/Data/StuffedByte_write3", "wb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  
  writeStuffedByte(fileStream, 0x32);
  writeStuffedByte(fileStream, 0xAB);
  writeStuffedByte(fileStream, 0xFF);
  writeStuffedByte(fileStream, 0x5C);
  
  closeStream(fileStream);
}

void test_readStuffedByte_given_0x0A_should_only_read_0x0A(void){
  CEXCEPTION_T error;
  Stream *fileStream = NULL;
  unsigned char result[5];
  
  Try{
    fileStream = openStream("test/Data/StuffedByte_write", "rb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  
  result[0] = readStuffedByte(fileStream);
  
  TEST_ASSERT_EQUAL(0x0a, result[0]);
  
  closeStream(fileStream);
}

void test_readStuffedByte_given_0xFF_and_0x00_should_only_read_0xFF(void){
  CEXCEPTION_T error;
  Stream *fileStream = NULL;
  unsigned char result[5];
  
  Try{
    fileStream = openStream("test/Data/StuffedByte_write2", "rb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  
  result[0] = readStuffedByte(fileStream);
  
  TEST_ASSERT_EQUAL(0xFF, result[0]);
  
  closeStream(fileStream);
}

void test_readStuffedByte_given_few_bytes_should_read_without_0x00(void){
  CEXCEPTION_T error;
  Stream *fileStream = NULL;
  unsigned char result[5];
  
  Try{
    fileStream = openStream("test/Data/StuffedByte_write3", "rb");
  }Catch(error){
    TEST_ASSERT_EQUAL(ERR_END_OF_FILE, error);
  }
  
  result[0] = readStuffedByte(fileStream);
  result[1] = readStuffedByte(fileStream);
  result[2] = readStuffedByte(fileStream);
  result[3] = readStuffedByte(fileStream);
  
  TEST_ASSERT_EQUAL(0x32, result[0]);
  TEST_ASSERT_EQUAL(0xAB, result[1]);
  TEST_ASSERT_EQUAL(0xFF, result[2]);
  TEST_ASSERT_EQUAL(0x5C, result[3]);
  
  closeStream(fileStream);
}