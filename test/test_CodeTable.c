#include "unity.h"
#include "CodeTable.h"

void setUp(void){}

void tearDown(void){}

void test_createTable_given_8_codes_up_to_codeLength_5(void){
	CodeTable *codeTable;
  RunSizeCode runSizeCode[8] = {{.type = RUNSIZECODE, .runSize = 0x00, .codeLength = 2},
                                {.type = RUNSIZECODE, .runSize = 0x01, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x02, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x03, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x04, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x05, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x06, .codeLength = 4},
                                {.type = CODETABLE, .runSize = 0x07, .codeLength = 5}};
                         
  codeTable = createTable(runSizeCode, 0, sizeof(runSizeCode)/sizeof(RunSizeCode));
  
  TEST_ASSERT_EQUAL(&runSizeCode[0], codeTable->table[0]);
  TEST_ASSERT_EQUAL(&runSizeCode[0], codeTable->table[1]);
  TEST_ASSERT_EQUAL(&runSizeCode[0], codeTable->table[2]);
  TEST_ASSERT_EQUAL(&runSizeCode[0], codeTable->table[3]);
  TEST_ASSERT_EQUAL(&runSizeCode[1], codeTable->table[4]);
  TEST_ASSERT_EQUAL(&runSizeCode[1], codeTable->table[5]);
  TEST_ASSERT_EQUAL(&runSizeCode[2], codeTable->table[6]);
  TEST_ASSERT_EQUAL(&runSizeCode[2], codeTable->table[7]);
  TEST_ASSERT_EQUAL(&runSizeCode[3], codeTable->table[8]);
  TEST_ASSERT_EQUAL(&runSizeCode[3], codeTable->table[9]);
  TEST_ASSERT_EQUAL(&runSizeCode[4], codeTable->table[10]);
  TEST_ASSERT_EQUAL(&runSizeCode[4], codeTable->table[11]);
  TEST_ASSERT_EQUAL(&runSizeCode[5], codeTable->table[12]);
  TEST_ASSERT_EQUAL(&runSizeCode[5], codeTable->table[13]);
  TEST_ASSERT_EQUAL(&runSizeCode[6], codeTable->table[14]);
  TEST_ASSERT_EQUAL(&runSizeCode[7], codeTable->table[15]->table[0]);
  TEST_ASSERT_EQUAL(&runSizeCode[7], codeTable->table[15]->table[7]);
}

void test_createTable_given_12_codes_up_to_codeLength_9(void){
	CodeTable *codeTable;
  RunSizeCode runSizeCode[12] = {{.type = RUNSIZECODE, .runSize = 0x00, .codeLength = 2},
                                {.type = RUNSIZECODE, .runSize = 0x01, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x02, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x03, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x04, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x05, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x06, .codeLength = 4},
                                {.type = CODETABLE, .runSize = 0x07, .codeLength = 5},
                                {.type = RUNSIZECODE, .runSize = 0x08, .codeLength = 6},
                                {.type = RUNSIZECODE, .runSize = 0x09, .codeLength = 7},
                                {.type = RUNSIZECODE, .runSize = 0x0A, .codeLength = 8},
                                {.type = CODETABLE, .runSize = 0x0B, .codeLength = 9}};
                         
  codeTable = createTable(runSizeCode, 0, sizeof(runSizeCode)/sizeof(RunSizeCode));
  
  TEST_ASSERT_EQUAL(&runSizeCode[0], codeTable->table[0]);
  TEST_ASSERT_EQUAL(&runSizeCode[0], codeTable->table[3]);
  TEST_ASSERT_EQUAL(&runSizeCode[1], codeTable->table[5]);
  TEST_ASSERT_EQUAL(&runSizeCode[2], codeTable->table[7]);
  TEST_ASSERT_EQUAL(&runSizeCode[3], codeTable->table[9]);
  TEST_ASSERT_EQUAL(&runSizeCode[4], codeTable->table[11]);
  TEST_ASSERT_EQUAL(&runSizeCode[5], codeTable->table[13]);
  TEST_ASSERT_EQUAL(&runSizeCode[6], codeTable->table[14]);
  TEST_ASSERT_EQUAL(&runSizeCode[7], codeTable->table[15]->table[7]);
  TEST_ASSERT_EQUAL(&runSizeCode[8], codeTable->table[15]->table[11]);
  TEST_ASSERT_EQUAL(&runSizeCode[9], codeTable->table[15]->table[13]);
  TEST_ASSERT_EQUAL(&runSizeCode[10], codeTable->table[15]->table[14]);
  TEST_ASSERT_EQUAL(&runSizeCode[11], codeTable->table[15]->table[15]->table[7]);
}
