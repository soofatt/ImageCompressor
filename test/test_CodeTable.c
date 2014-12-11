#include "unity.h"
#include "CodeTable.h"

void setUp(void){}

void tearDown(void){}

void test_createTable_given_4_codes_up_to_codeLength_4(void){
	CodeTable *codeTable;
  RunSizeCode runSizeCode[4] = {{.type = RUNSIZECODE, .runSize = 0x01, .codeLength = 2},
                                {.type = RUNSIZECODE, .runSize = 0x02, .codeLength = 2},
                                {.type = RUNSIZECODE, .runSize = 0x03, .codeLength = 3},
                                {.type = RUNSIZECODE, .runSize = 0x00, .codeLength = 4}};
                                
  createTable(codeTable, runSizeCode, 0);
  
  TEST_ASSERT_EQUAL(runSizeCode[4].runSize, codeTable->table[0]);
}
