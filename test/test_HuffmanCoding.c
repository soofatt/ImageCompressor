#include "unity.h"
#include "HuffmanCoding.h"

void setUp(void){}

void tearDown(void){}

void test_huffmanEncodeDCL_given_run_and_bitsize_0x06_should_return_0x0E(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x06;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, dcLuminanceTable);
  
  TEST_ASSERT_EQUAL(0x0E, result);
}

void test_huffmanEncodeDCC_given_run_and_bitsize_0x0A_should_return_0x2FE(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x0A;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, dcChrominanceTable);
  
  TEST_ASSERT_EQUAL(0x2FE, result);
}

void test_huffmanEncodeACL_given_run_and_bitsize_0x79_should_return_0xFFB4(void){
	uint8 runLength = 0x07;
  uint8 bitSize = 0x09;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acLuminanceTable);
  
  TEST_ASSERT_EQUAL(0xFFB4, result);
}

void test_huffmanEncodeACL_given_run_and_bitsize_0xF0_should_return_0x7F9(void){
	uint8 runLength = 0x0F;
  uint8 bitSize = 0x00;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acLuminanceTable);
  
  TEST_ASSERT_EQUAL(0x7F9, result);
}

void test_huffmanEncodeACL_given_run_and_bitsize_0x00_should_return_0x0A(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x00;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acLuminanceTable);
  
  TEST_ASSERT_EQUAL(0x0A, result);
}

void test_huffmanEncodeACC_given_run_and_bitsize_0xB3_should_return_0xFFB4(void){
	uint8 runLength = 0x0B;
  uint8 bitSize = 0x03;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acChrominanceTable);
  
  TEST_ASSERT_EQUAL(0xFFD3, result);
}

void test_huffmanEncodeACC_given_run_and_bitsize_0xF0_should_return_0x3FA(void){
	uint8 runLength = 0x0F;
  uint8 bitSize = 0x00;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acChrominanceTable);
  
  TEST_ASSERT_EQUAL(0x3FA, result);
}

void test_huffmanEncodeACC_given_run_and_bitsize_0x00_should_return_0x00(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x00;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acChrominanceTable);
  
  TEST_ASSERT_EQUAL(0x00, result);
}