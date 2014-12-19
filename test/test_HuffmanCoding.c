#include "unity.h"
#include "CodeTable.h"
#include "PredeterminedTables.h"
#include "HuffmanCoding.h"

void setUp(void){}

void tearDown(void){}

void test_huffmanEncodeDCL_given_run_and_bitsize_0x06_should_get_0x0E_chg_to_0xE000(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x06;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, dcLuminanceTable);
  
  TEST_ASSERT_EQUAL(0xE000, result);
}

void test_huffmanEncodeDCL_given_run_and_bitsize_0x02_should_get_0x02_chg_to_0x6000(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x02;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, dcLuminanceTable);
  
  TEST_ASSERT_EQUAL(0x6000, result);
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

void test_huffmanEncodeACL_given_run_and_bitsize_0x02_should_get_0x01_chg_to_0x4000(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x02;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acLuminanceTable);
  
  TEST_ASSERT_EQUAL(0x4000, result);
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

void test_huffmanEncodeACC_given_run_and_bitsize_0x01_should_get_0x01_chg_to_0x4000(void){
	uint8 runLength = 0x00;
  uint8 bitSize = 0x01;
  uint16 result;
  
  result = huffmanEncode(runLength, bitSize, acChrominanceTable);
  
  TEST_ASSERT_EQUAL(0x4000, result);
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
  CodeTable *dcDecodeLumTable = createTable(DCLumTable, 0, sizeof(DCLumTable)/sizeof(RunSizeCode));
  result = huffmanDecode(codeWord, dcDecodeLumTable);
  
  TEST_ASSERT_EQUAL(0x06, result);
}

void test_huffmanDecodeDCL_given_codeword_0x6000_should_return_0x02(void){
	uint16 codeWord = 0x6000;
  uint8 result;
  CodeTable *dcDecodeLumTable = createTable(DCLumTable, 0, sizeof(DCLumTable)/sizeof(RunSizeCode));
  result = huffmanDecode(codeWord, dcDecodeLumTable);
  
  TEST_ASSERT_EQUAL(0x02, result);
}

void test_huffmanDecodeDCL_given_codeword_0xF000_should_return_0x07(void){
	uint16 codeWord = 0xF000;
  uint8 result;
  CodeTable *dcDecodeLumTable = createTable(DCLumTable, 0, sizeof(DCLumTable)/sizeof(RunSizeCode));
  result = huffmanDecode(codeWord, dcDecodeLumTable);
  
  TEST_ASSERT_EQUAL(0x07, result);
}