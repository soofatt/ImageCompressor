#include "unity.h"
#include "CodeTable.h"

void setUp(void){}

void tearDown(void){}

void test_createTable_given_4_codes_up_to_codeLength_4(void){
	CodeTable *codeTable;
  RunSizeCode runSizeCode[8] = {{.type = RUNSIZECODE, .runSize = 0x00, .codeLength = 2},
                                {.type = RUNSIZECODE, .runSize = 0x01, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x02, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x03, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x04, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x05, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x06, .codeLength = 4},
                                {.type = CODETABLE, .runSize = 0x07, .codeLength = 5}};
                         
  createTable(codeTable, runSizeCode, 0);
  
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
}
