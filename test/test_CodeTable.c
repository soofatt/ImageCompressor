#include "unity.h"
#include "CodeTable.h"
#include "PredeterminedTables.h"

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
                         
  codeTable = createTable(DCLumTable, 0, sizeof(DCLumTable)/sizeof(RunSizeCode));
  
  TEST_ASSERT_EQUAL(&DCLumTable[0], codeTable->table[0]);
  TEST_ASSERT_EQUAL(&DCLumTable[0], codeTable->table[3]);
  TEST_ASSERT_EQUAL(&DCLumTable[1], codeTable->table[5]);
  TEST_ASSERT_EQUAL(&DCLumTable[2], codeTable->table[7]);
  TEST_ASSERT_EQUAL(&DCLumTable[3], codeTable->table[9]);
  TEST_ASSERT_EQUAL(&DCLumTable[4], codeTable->table[11]);
  TEST_ASSERT_EQUAL(&DCLumTable[5], codeTable->table[13]);
  TEST_ASSERT_EQUAL(&DCLumTable[6], codeTable->table[14]);
  TEST_ASSERT_EQUAL(&DCLumTable[7], codeTable->table[15]->table[7]);
  TEST_ASSERT_EQUAL(&DCLumTable[8], codeTable->table[15]->table[11]);
  TEST_ASSERT_EQUAL(&DCLumTable[9], codeTable->table[15]->table[13]);
  TEST_ASSERT_EQUAL(&DCLumTable[10], codeTable->table[15]->table[14]);
  TEST_ASSERT_EQUAL(&DCLumTable[11], codeTable->table[15]->table[15]->table[7]);
}

void test_createTable_given_20_codes_up_to_codeLength_9(void){
	CodeTable *codeTable;
  RunSizeCode runSizeCode[20] = {{.type = RUNSIZECODE, .runSize = 0x01, .codeLength = 2},
                                 {.type = RUNSIZECODE, .runSize = 0x02, .codeLength = 2},
                                 {.type = RUNSIZECODE, .runSize = 0x03, .codeLength = 3},
                                 {.type = RUNSIZECODE, .runSize = 0x00, .codeLength = 4},
                                 {.type = RUNSIZECODE, .runSize = 0x04, .codeLength = 4},
                                 {.type = RUNSIZECODE, .runSize = 0x11, .codeLength = 4},
                                 {.type = CODETABLE, .runSize = 0x05, .codeLength = 5},
                                 {.type = RUNSIZECODE, .runSize = 0x12, .codeLength = 5},
                                 {.type = CODETABLE, .runSize = 0x21, .codeLength = 5},
                                 {.type = RUNSIZECODE, .runSize = 0x31, .codeLength = 6},
                                 {.type = RUNSIZECODE, .runSize = 0x41, .codeLength = 6},
                                 {.type = CODETABLE, .runSize = 0x06, .codeLength = 7},
                                 {.type = RUNSIZECODE, .runSize = 0x13, .codeLength = 7},
                                 {.type = RUNSIZECODE, .runSize = 0x51, .codeLength = 7},
                                 {.type = RUNSIZECODE, .runSize = 0x61, .codeLength = 7},
                                 {.type = RUNSIZECODE, .runSize = 0x07, .codeLength = 8},
                                 {.type = RUNSIZECODE, .runSize = 0x22, .codeLength = 8},
                                 {.type = RUNSIZECODE, .runSize = 0x71, .codeLength = 8},
                                 {.type = CODETABLE, .runSize = 0x14, .codeLength = 9},
                                 {.type = RUNSIZECODE, .runSize = 0x32, .codeLength = 9}};
                         
  codeTable = createTable(runSizeCode, 0, sizeof(runSizeCode)/sizeof(RunSizeCode));
  
  TEST_ASSERT_EQUAL(&runSizeCode[0], codeTable->table[0]);
  TEST_ASSERT_EQUAL(&runSizeCode[2], codeTable->table[8]);
  TEST_ASSERT_EQUAL(&runSizeCode[4], codeTable->table[11]);
  TEST_ASSERT_EQUAL(&runSizeCode[6], codeTable->table[13]->table[0]);
  TEST_ASSERT_EQUAL(&runSizeCode[7], codeTable->table[13]->table[8]);
  TEST_ASSERT_EQUAL(&runSizeCode[8], codeTable->table[14]->table[0]);
  TEST_ASSERT_EQUAL(&runSizeCode[9], codeTable->table[14]->table[8]);
  TEST_ASSERT_EQUAL(&runSizeCode[10], codeTable->table[14]->table[12]);
  TEST_ASSERT_EQUAL(&runSizeCode[11], codeTable->table[15]->table[0]);
  TEST_ASSERT_EQUAL(&runSizeCode[15], codeTable->table[15]->table[8]);
  TEST_ASSERT_EQUAL(&runSizeCode[18], codeTable->table[15]->table[11]->table[0]);
  TEST_ASSERT_EQUAL(&runSizeCode[19], codeTable->table[15]->table[11]->table[8]);
}

void test_createTable_given_162_codes_up_to_codeLength_16(void){
	CodeTable *codeTable;
  
  codeTable = createTable(ACLumTable, 0, sizeof(ACLumTable)/sizeof(RunSizeCode));
  
  TEST_ASSERT_EQUAL(&ACLumTable[0], codeTable->table[0]);
  TEST_ASSERT_EQUAL(&ACLumTable[2], codeTable->table[8]);
  TEST_ASSERT_EQUAL(&ACLumTable[4], codeTable->table[11]);
  TEST_ASSERT_EQUAL(&ACLumTable[6], codeTable->table[13]->table[0]);
  TEST_ASSERT_EQUAL(&ACLumTable[7], codeTable->table[13]->table[8]);
  TEST_ASSERT_EQUAL(&ACLumTable[8], codeTable->table[14]->table[0]);
  TEST_ASSERT_EQUAL(&ACLumTable[9], codeTable->table[14]->table[8]);
  TEST_ASSERT_EQUAL(&ACLumTable[10], codeTable->table[14]->table[12]);
  TEST_ASSERT_EQUAL(&ACLumTable[11], codeTable->table[15]->table[0]);
  TEST_ASSERT_EQUAL(&ACLumTable[15], codeTable->table[15]->table[8]);
  TEST_ASSERT_EQUAL(&ACLumTable[18], codeTable->table[15]->table[11]->table[0]);
  TEST_ASSERT_EQUAL(&ACLumTable[19], codeTable->table[15]->table[11]->table[8]);
  TEST_ASSERT_EQUAL(&ACLumTable[31], codeTable->table[15]->table[15]->table[2]);
  TEST_ASSERT_EQUAL(&ACLumTable[161], codeTable->table[15]->table[15]->table[15]->table[14]);
}