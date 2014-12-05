#include "unity.h"
#include "HuffmanCoding.h"

void setUp(void){}

void tearDown(void){}

void test_huffmanEncodeDCL_given_run_and_bitsize_0x06_should_get_0x0E_chg_to_0xE0(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x06;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, dcLuminanceTable);
  
  TEST_ASSERT_EQUAL(0xE000, result);
}

void test_huffmanEncodeDCC_given_run_and_bitsize_0x0A_should_get_0x3FE_chg_to_0xFF80(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x0A;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, dcChrominanceTable);
  
  TEST_ASSERT_EQUAL(0xFF80, result);
}

void test_huffmanEncodeACL_given_run_and_bitsize_0x79_should_get_0xFFB4(void){
	uint8 runLength = 0x07;
  uint8 bitSize = 0x09;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acLuminanceTable);
  
  TEST_ASSERT_EQUAL(0xFFB4, result);
}

void test_huffmanEncodeACL_given_run_and_bitsize_0xF0_should_get_0x7F9_chg_to_0xFF20(void){
	uint8 runLength = 0x0F;
  uint8 bitSize = 0x00;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acLuminanceTable);
  
  TEST_ASSERT_EQUAL(0xFF20, result);
}

void test_huffmanEncodeACL_given_run_and_bitsize_0x00_should_get_0x0A_chg_to_0xA000(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x00;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acLuminanceTable);
  
  TEST_ASSERT_EQUAL(0xA000, result);
}

void test_huffmanEncodeACC_given_run_and_bitsize_0xB3_should_get_0xFFD3(void){
	uint8 runLength = 0x0B;
  uint8 bitSize = 0x03;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acChrominanceTable);
  
  TEST_ASSERT_EQUAL(0xFFD3, result);
}

void test_huffmanEncodeACC_given_run_and_bitsize_0xF0_should_get_0x3FA_chg_to_0xFE80(void){
	uint8 runLength = 0x0F;
  uint8 bitSize = 0x00;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acChrominanceTable);
  
  TEST_ASSERT_EQUAL(0xFE80, result);
}

void test_huffmanEncodeACC_given_run_and_bitsize_0x00_should_return_0x00(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x00;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acChrominanceTable);
  
  TEST_ASSERT_EQUAL(0x00, result);
}

void test_huffmanDecodeDCL_given_codeword_0xE000_should_return_0x06(void){
	uint16 codeWord = 0xE000;
  uint8 result;
  
  result = huffmanDecode(codeWord, decodeDCLTable);
  
  TEST_ASSERT_EQUAL(0x06, result);
}

void test_huffmanDecodeDCL_given_codeword_0xFC00_should_return_0x09(void){
	uint16 codeWord = 0xFC00;
  uint8 result;
  
  result = huffmanDecode(codeWord, decodeDCLTable);
  
  TEST_ASSERT_EQUAL(0x09, result);
}

void test_huffmanDecodeDCL_given_codeword_0xFF80_should_return_0x0A(void){
	uint16 codeWord = 0xFF80;
  uint8 result;
  
  result = huffmanDecode(codeWord, decodeDCCTable);
  
  TEST_ASSERT_EQUAL(0x0A, result);
}

void test_huffmanDecodeDCL_given_codeword_0xC000_should_return_0x03(void){
	uint16 codeWord = 0xC000;
  uint8 result;
  
  result = huffmanDecode(codeWord, decodeDCCTable);
  
  TEST_ASSERT_EQUAL(0x03, result);
}