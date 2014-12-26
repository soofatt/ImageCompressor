#include "unity.h"
#include "CodeTable.h"
#include "PredeterminedTables.h"
#include "HuffmanCoding.h"
#include "runLengthCoding.h"
#include "ValueEncoding.h"
#include "Scan.h"

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

void test_huffmanEncodePull_DCL(void){
	State progress = {.state = 0, .index = 0};
  uint32 result;
  short int dataIn[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
                            { 36, 108,  14,  38,  26,   0,   0,   0},
                            {-98, -65,  16, -48, -40,   0,   0,   0},
                            {-42, -85,   0, -29,   0,   0,   0,   0},
                            {-36,  22,   0,   0,   0,   0,   0,   0}, 
                            {  0,   0,   0,   0,   5,   0,   0,   0},
                            {  0,   0,   0,   0,   0,   0,   0,   0},
                            {  1,   0,   0,   0,   0,   0,   0,   1}};
  
  result = huffmanEncodePull(&progress, dataIn, dcLuminanceTable);
  
  TEST_ASSERT_EQUAL(0xF80000A0, result);
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

void test_huffmanDecodeDCL_given_codeword_0xFF00_should_return_0x0B(void){
	uint16 codeWord = 0xFF00;
  uint8 result;
  CodeTable *dcDecodeLumTable = createTable(DCLumTable, 0, sizeof(DCLumTable)/sizeof(RunSizeCode));
  result = huffmanDecode(codeWord, dcDecodeLumTable);
  
  TEST_ASSERT_EQUAL(0x0B, result);
}

void test_huffmanDecodeDCC_given_codeword_0x4000_should_return_0x01(void){
	uint16 codeWord = 0x4000;
  uint8 result;
  CodeTable *dcDecodeChromTable = createTable(DCChromTable, 0, sizeof(DCChromTable)/sizeof(RunSizeCode));
  result = huffmanDecode(codeWord, dcDecodeChromTable);
  
  TEST_ASSERT_EQUAL(0x01, result);
}

void test_huffmanDecodeDCC_given_codeword_0xFC00_should_return_0x07(void){
	uint16 codeWord = 0xFC00;
  uint8 result;
  CodeTable *dcDecodeChromTable = createTable(DCChromTable, 0, sizeof(DCChromTable)/sizeof(RunSizeCode));
  result = huffmanDecode(codeWord, dcDecodeChromTable);
  
  TEST_ASSERT_EQUAL(0x07, result);
}

void test_huffmanDecodeDCC_given_codeword_0xFFC0_should_return_0x0B(void){
	uint16 codeWord = 0xFFC0;
  uint8 result;
  CodeTable *dcDecodeChromTable = createTable(DCChromTable, 0, sizeof(DCChromTable)/sizeof(RunSizeCode));
  result = huffmanDecode(codeWord, dcDecodeChromTable);
  
  TEST_ASSERT_EQUAL(0x0B, result);
}

/*
 *0xB000 -> 0x04        0xFFC5 -> 0x99
 *0xEC00 -> 0x41        0xFF20 -> 0xF0 (ZRL)
 *0xFDC0 -> 0x23        0xA000 -> 0x00 (EOB)
 */
void test_huffmanDecodeACL_given_few_codewords_should_return_correct_results(void){
	uint16 codeWord[6] = {0xB000, 0xEC00, 0xFDC0, 0xFFC5, 0xFF20, 0xA000};
  uint8 result;
  CodeTable *acDecodeLumTable = createTable(ACLumTable, 0, sizeof(ACLumTable)/sizeof(RunSizeCode));
  
  result = huffmanDecode(codeWord[0], acDecodeLumTable);
  TEST_ASSERT_EQUAL(0x04, result);
  result = huffmanDecode(codeWord[1], acDecodeLumTable);
  TEST_ASSERT_EQUAL(0x41, result);
  result = huffmanDecode(codeWord[2], acDecodeLumTable);
  TEST_ASSERT_EQUAL(0x23, result);
  result = huffmanDecode(codeWord[3], acDecodeLumTable);
  TEST_ASSERT_EQUAL(0x99, result);
  result = huffmanDecode(codeWord[4], acDecodeLumTable);
  TEST_ASSERT_EQUAL(0xF0, result);
  result = huffmanDecode(codeWord[5], acDecodeLumTable);
  TEST_ASSERT_EQUAL(0x00, result);
}

/*
 *0x4000 -> 0x01        0xFFEF -> 0xE4
 *0xF400 -> 0x71        0xFE80 -> 0xF0 (ZRL)
 *0xFC80 -> 0xB1        0x0000 -> 0x00 (EOB)
 */
void test_huffmanDecodeACC_given_few_codewords_should_return_correct_results(void){
	uint16 codeWord[6] = {0x4000, 0xF400, 0xFC80, 0xFFEF, 0xFE80, 0x0000};
  uint8 result;
  CodeTable *acDecodeChromTable = createTable(ACChromTable, 0, sizeof(ACChromTable)/sizeof(RunSizeCode));
  
  result = huffmanDecode(codeWord[0], acDecodeChromTable);
  TEST_ASSERT_EQUAL(0x01, result);
  result = huffmanDecode(codeWord[1], acDecodeChromTable);
  TEST_ASSERT_EQUAL(0x71, result);
  result = huffmanDecode(codeWord[2], acDecodeChromTable);
  TEST_ASSERT_EQUAL(0xB1, result);
  result = huffmanDecode(codeWord[3], acDecodeChromTable);
  TEST_ASSERT_EQUAL(0xE4, result);
  result = huffmanDecode(codeWord[4], acDecodeChromTable);
  TEST_ASSERT_EQUAL(0xF0, result);
  result = huffmanDecode(codeWord[5], acDecodeChromTable);
  TEST_ASSERT_EQUAL(0x00, result);
}