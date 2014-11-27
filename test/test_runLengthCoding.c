#include "unity.h"
#include "runLengthCoding.h"
#include "Scan.h"
#include "dataType.h"
void setUp(void){}

void tearDown(void){}

void test_runLengthEncoding_to_encode_lengthy_value(void){
	int size = 10;
	int input[10] = {5,5,66,21,1,0,0,0,0,2};
	int output[20] = {0};
	runLengthEncoding(input,output,size);
	TEST_ASSERT_EQUAL(2,output[0]);
	TEST_ASSERT_EQUAL(5,output[1]);
	TEST_ASSERT_EQUAL(1,output[2]);
	TEST_ASSERT_EQUAL(66,output[3]);
	TEST_ASSERT_EQUAL(1,output[4]);
	TEST_ASSERT_EQUAL(21,output[5]);
	TEST_ASSERT_EQUAL(1,output[6]);
	TEST_ASSERT_EQUAL(1,output[7]);
	TEST_ASSERT_EQUAL(4,output[8]);
	TEST_ASSERT_EQUAL(0,output[9]);
	TEST_ASSERT_EQUAL(1,output[10]);
	TEST_ASSERT_EQUAL(2,output[11]);
}

void test_runLengthEncoding_to_encode_lengthy_value_case_2(void){
	int size = 10;
	int input[10] = {5,3,66,21,1,4,6,7,8,2};
	int output[20] = {0};
	runLengthEncoding(input,output,size);
	TEST_ASSERT_EQUAL(1,output[0]);
	TEST_ASSERT_EQUAL(5,output[1]);
	TEST_ASSERT_EQUAL(1,output[2]);
	TEST_ASSERT_EQUAL(3,output[3]);
	TEST_ASSERT_EQUAL(1,output[4]);
	TEST_ASSERT_EQUAL(66,output[5]);
	TEST_ASSERT_EQUAL(1,output[6]);
	TEST_ASSERT_EQUAL(21,output[7]);
	TEST_ASSERT_EQUAL(1,output[8]);
	TEST_ASSERT_EQUAL(1,output[9]);
	TEST_ASSERT_EQUAL(1,output[10]);
	TEST_ASSERT_EQUAL(4,output[11]);
	TEST_ASSERT_EQUAL(1,output[12]);
	TEST_ASSERT_EQUAL(6,output[13]);
	TEST_ASSERT_EQUAL(1,output[14]);
	TEST_ASSERT_EQUAL(7,output[15]);
	TEST_ASSERT_EQUAL(1,output[16]);
	TEST_ASSERT_EQUAL(8,output[17]);
	TEST_ASSERT_EQUAL(1,output[18]);
	TEST_ASSERT_EQUAL(2,output[19]);
}

void test_runLengthEncoding_to_encode_lengthy_value_case_3(void){
	int size = 10;
	int input[10] = {5,3,0,21,5,4,0,7,8,2};
	int output[20] = {0};
	runLengthEncoding(input,output,size);
	TEST_ASSERT_EQUAL(1,output[0]);
	TEST_ASSERT_EQUAL(5,output[1]);
	TEST_ASSERT_EQUAL(1,output[2]);
	TEST_ASSERT_EQUAL(3,output[3]);
	TEST_ASSERT_EQUAL(1,output[4]);
	TEST_ASSERT_EQUAL(0,output[5]);
	TEST_ASSERT_EQUAL(1,output[6]);
	TEST_ASSERT_EQUAL(21,output[7]);
	TEST_ASSERT_EQUAL(1,output[8]);
	TEST_ASSERT_EQUAL(5,output[9]);
	TEST_ASSERT_EQUAL(1,output[10]);
	TEST_ASSERT_EQUAL(4,output[11]);
	TEST_ASSERT_EQUAL(1,output[12]);
	TEST_ASSERT_EQUAL(0,output[13]);
	TEST_ASSERT_EQUAL(1,output[14]);
	TEST_ASSERT_EQUAL(7,output[15]);
	TEST_ASSERT_EQUAL(1,output[16]);
	TEST_ASSERT_EQUAL(8,output[17]);
	TEST_ASSERT_EQUAL(1,output[18]);
	TEST_ASSERT_EQUAL(2,output[19]);
}

void test_runLengthDecoding_to_decode_encode_value_into_original_value_and_sequence(void){
	int size = 12;
	int input[12] = {2,5,1,66,1,21,1,1,4,0,1,2};
	int output[20] = {0};
	runLengthDecoding(input,output,size);
	TEST_ASSERT_EQUAL(5,output[0]);
	TEST_ASSERT_EQUAL(5,output[1]);
	TEST_ASSERT_EQUAL(66,output[2]);
	TEST_ASSERT_EQUAL(21,output[3]);
	TEST_ASSERT_EQUAL(1,output[4]);
	TEST_ASSERT_EQUAL(0,output[5]);
	TEST_ASSERT_EQUAL(0,output[6]);
	TEST_ASSERT_EQUAL(0,output[7]);
	TEST_ASSERT_EQUAL(0,output[8]);
	TEST_ASSERT_EQUAL(2,output[9]);
}

void test_runLengthEncoder_should_return_run_0_and_symbol_160_with_index_0(){
	State progress = {.state = 0, .index = 0};
	uint32 returnRunAndSymbol;
	int size = 8;
	short int dataIn[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
							{ 36, 108,  14,  38,  26,   0,   0,   0},
							{-98, -65,  16, -48, -40,   0,   0,   0},
							{-42, -85,   0, -29,   0,   0,   0,   0},
							{-36,  22,   0,   0,   0,   0,   0,   0}, 
							{  0,   0,   0,   0,   0,   0,   0,   0},
							{  0,   0,   0,   5,   0,   0,   0,   0},
							{  1,   0,   0,   0,   0,   0,   0,   1}};
	
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(160,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(1,progress.index);
	
}

void test_runLengthEncoder_should_return_run_0_and_symbol_44_with_index_1(){
	State progress = {.state = 0, .index = 1};
	uint32 returnRunAndSymbol;
	int size = 8;
	short int dataIn[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
							{ 36, 108,  14,  38,  26,   0,   0,   0},
							{-98, -65,  16, -48, -40,   0,   0,   0},
							{-42, -85,   0, -29,   0,   0,   0,   0},
							{-36,  22,   0,   0,   0,   0,   0,   0}, 
							{  0,   0,   0,   0,   0,   0,   0,   0},
							{  0,   0,   0,   5,   0,   0,   0,   0},
							{  1,   0,   0,   0,   0,   0,   0,   1}};
	
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(44,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(2,progress.index);	
}

void test_runLengthEncoder_should_return_run_4_and_symbol_neg_29_with_index_20(){
	State progress = {.state = 0, .index = 20};
	uint32 returnRunAndSymbol;
	int size = 8;
	short int dataIn[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
							  { 36, 108,  14,  38,  26,   0,   0,   0},
							  {-98, -65,  16, -48, -40,   0,   0,   0},
							  {-42, -85,   0, -29,   0,   0,   0,   0},
							  {-36,  22,   0,   0,   0,   0,   0,   0}, 
							  {  0,   0,   0,   0,   5,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  1,   0,   0,   0,   0,   0,   0,   1}};
	
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	//first 16 bits(MSB) is the run(no of zero), second 16 bits(LSB) is the symbol of -29
	//no of zero is 4 so become 0x0004, -29 is FFE3 in hex
	TEST_ASSERT_EQUAL(0x0004FFE3,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(25,progress.index);	
}

void test_runLengthEncoder_should_return_run_15_and_symbol_0_with_index_47(){
	State progress = {.state = 0, .index = 47};
	uint32 returnRunAndSymbol;
	int size = 8;
	short int dataIn[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
							  { 36, 108,  14,  38,  26,   0,   0,   0},
							  {-98, -65,  16, -48, -40,   0,   0,   0},
							  {-42, -85,   0, -29,   0,   0,   0,   0},
							  {-36,  22,   0,   0,   0,   0,   0,   0}, 
							  {  0,   0,   0,   0,   5,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  1,   0,   0,   0,   0,   0,   0,   1}};
	
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	//It has more than 15 zero from index 47 which row and column is 6 and 3
	//so return run is 15 and symbol is 0;
	TEST_ASSERT_EQUAL(0x000F0000,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(63,progress.index);	
}

void test_runLengthEncoder_should_return_run_0_and_symbol_0_with_index_63(){
	State progress = {.state = 0, .index = 63};
	uint32 returnRunAndSymbol;
	int size = 8;
	short int dataIn[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
							  { 36, 108,  14,  38,  26,   0,   0,   0},
							  {-98, -65,  16, -48, -40,   0,   0,   0},
							  {-42, -85,   0, -29,   0,   0,   0,   0},
							  {-36,  22,   0,   0,   0,   0,   0,   0}, 
							  {  0,   0,   0,   0,   5,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  1,   0,   0,   0,   0,   0,   0,   0}};
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	//It check to the end, and there is zero there, but the zeroCount
	// not exceed 15, so send run = 0 and symbol 0 to represent EOB
	TEST_ASSERT_EQUAL(0x00000000,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(64,progress.index);	
}

void test_runLengthEncoder_should_return_run_0_and_symbol_0_with_index_47_if_there_are_no_more_non_zero_until_end(){
	State progress = {.state = 0, .index = 47};
	uint32 returnRunAndSymbol;
	int size = 8;
	short int dataIn[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
							  { 36, 108,  14,  38,  26,   0,   0,   0},
							  {-98, -65,  16, -48, -40,   0,   0,   0},
							  {-42, -85,   0, -29,   0,   0,   0,   0},
							  {-36,  22,   0,   0,   0,   0,   0,   0}, 
							  {  0,   0,   0,   0,   5,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  1,   0,   0,   0,   0,   0,   0,   0}};
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	//It check to the end, and there are no more non zero there, but the zeroCount
	// exceed 15, so send run = 0 and symbol 0 to represent EOB
	TEST_ASSERT_EQUAL(0x00000000,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(64,progress.index);	
}

void test_runLengthEncoder_should_return_run_15_and_symbol_0_with_index_45(){
	State progress = {.state = 0, .index = 45};
	uint32 returnRunAndSymbol;
	int size = 8;
	short int dataIn[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
							  { 36, 108,  14,  38,  26,   0,   0,   0},
							  {-98, -65,  16, -48, -40,   0,   0,   0},
							  {-42, -85,   0, -29,   0,   0,   5,   0},
							  {-36,  22,   0,   0,   0,   0,   0,   0}, 
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  1,   0,   0,   0,   0,   0,   0,   1}};
	
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	//It has more than 15 zero from index 45 which row and column is 3 and 6
	//so return run is 15 and symbol is 0, it also return index after 16 0's
	// Note that the 16th '0' at index 60 which row and column are 5 and 7
	// So, should start from next index which is 61 at row and column of 6 and 7
	TEST_ASSERT_EQUAL(0x000F0000,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(61,progress.index);	
}

void test_runLengthEncoder_should_do_all_the_2D_array(){
	State progress = {.state = 0, .index = 0};
	uint32 returnRunAndSymbol;
	int size = 8;
	short int dataIn[8][8] = {{160,  44,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   1,   0},
							  { 15,   0,   0,   0,   0,   0,   0,   0},
							  {  0, -85,   0,   0,   0,   0,   0,   0},
							  {-36,   0,   0,   0,   0,   0,   0,   0}, 
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0}};
	
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(160,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(1,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(44,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(2,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x0001000F,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(4,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x0006FFDC,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(11,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x0000FFAB,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(12,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x000F0000,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(28,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x00010001,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(30,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x00000000,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(64,progress.index);
}

void test_runLengthEncoder_should_return_run_15_and_symbol_0_with_index_0_with_array_start_with_15_zero(){
	State progress = {.state = 0, .index = 0};
	uint32 returnRunAndSymbol;
	int size = 8;
	short int dataIn[8][8] = {{  0,   0,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   1,   0,   0,   0},
							  {  0,   0,   0,   1, -40,   0,   0,   0},
							  {  0,   0,   0, -29,   0,   0,   5,   0},
							  {  0,  22,   0,   0,   0,   0,   0,   0}, 
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  1,   0,   0,   0,   0,   0,   0,   1}};
	
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x000F0000,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(16,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x00000001,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(17,progress.index);
}

void test_runLengthEncoder_should_return_run_15_and_symbol_0_with_index_0_from_array_start_with_35_zero(){
	State progress = {.state = 0, .index = 0};
	uint32 returnRunAndSymbol;
	short int size = 8;
	short int dataIn[8][8] = {{  0,   0,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   5,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0}, 
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  0,   0,   0,   0,   0,   0,   0,   0},
							  {  1,   0,   0,   0,   0,   0,   0,   1}};
	
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x000F0000,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(16,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x000F0000,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(32,progress.index);
	returnRunAndSymbol = runLengthEncode(size, dataIn, &progress);
	TEST_ASSERT_EQUAL(0x00030001,returnRunAndSymbol);
	TEST_ASSERT_EQUAL(0,progress.state);
	TEST_ASSERT_EQUAL(36,progress.index);
}

void test_runLengthDecode_to_decode_runAndSymbol_0x0003000D_should_have_3_zero_and_1_D_symbol_which_is_13_and_put_into_2D_array(){
	short int result[8][8];
	State progress = {.state = 0, .index = 0};
	uint32 runAndSymbol = 0x0003000D;
	
	runLengthDecode(8,result, &progress, runAndSymbol);
	
	TEST_ASSERT_EQUAL(0,result[0][0]);
	TEST_ASSERT_EQUAL(0,result[0][1]);
	TEST_ASSERT_EQUAL(0,result[1][0]);
	TEST_ASSERT_EQUAL(13,result[2][0]);
}

void test_runLengthDecode_to_decode_next_runAndSymbol_0x0000001D_should_have_no_zero_and_1D_symbol_which_is_29_and_put_into_next_index_2D_array(){
	short int result[8][8];
	State progress = {.state = 0, .index = 0};
	uint32 runAndSymbol = 0x0003000D;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x0000001D;
	runLengthDecode(8,result, &progress, runAndSymbol);
	TEST_ASSERT_EQUAL(29,result[1][1]);
}

void test_runLengthDecode_to_decode_next_runAndSymbol_0x000F0000_should_have_15_zero_and_one_0_symbol_put_into_next_index_2D_array(){
	short int result[8][8];
	State progress = {.state = 0, .index = 0};
	uint32 runAndSymbol = 0x0003000D;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x0000001D;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x000F0000;
	runLengthDecode(8,result, &progress, runAndSymbol);
	TEST_ASSERT_EQUAL(0,result[0][2]); // This is the first zero
	TEST_ASSERT_EQUAL(0,result[5][0]);
	TEST_ASSERT_EQUAL(0,result[6][0]); //This is the last 16th zero
}

void test_runLengthDecode_to_decode_next_runAndSymbol_0x00100000_do_nothing_and_return(){
	short int result[8][8];
	State progress = {.state = 0, .index = 0};
	uint32 runAndSymbol = 0x0003000D;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x0000001D;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x000F0000;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x00100000;
	runLengthDecode(8,result, &progress, runAndSymbol);
	//because this call does not make any changes to 2D array, 
	//and from previous call, progress.index stop at 22(latest index), it will not update to next
	TEST_ASSERT_EQUAL(22,progress.index);
}

void test_runLengthDecode_to_decode_next_runAndSymbol_0x00000000_should_fill_the_remaining_slot_with_0(){
	short int result[8][8];
	State progress = {.state = 0, .index = 0};
	uint32 runAndSymbol = 0x0003000D;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x0000001D;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x000F0000;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x00100000;
	runLengthDecode(8,result, &progress, runAndSymbol);
	runAndSymbol = 0x00000000;
	runLengthDecode(8,result, &progress, runAndSymbol);
	TEST_ASSERT_EQUAL(0,result[6][7]);
	TEST_ASSERT_EQUAL(0,result[7][6]);
	TEST_ASSERT_EQUAL(0,result[7][7]);
	TEST_ASSERT_EQUAL(65,progress.index); //Here show the last updated progress->index after getting the last index for 2D array which is 0x77
}

/* 
void test_runLengthEncoding2(){
	scanTable table = {.row = 0, .column = 0, .col_limit = 2, .stage = 0};
	int size = 8;
	int dataOut[128];
	int dataIn[8][8] = {{160,  44,  20,  80,  24,   0,   0,   0},
                        { 36, 108,  14,  38,  26,   0,   0,   0},
                        {-98, -65,  16, -48, -40,   0,   0,   0},
                        {-42, -85,   0, -29,   0,   0,   0,   0},
                        {-36,  22,   0,   0,   0,   0,   0,   0}, 
                        {  0,   0,   0,   0,   0,   0,   0,   0},
                        {  0,   0,   0,   5,   0,   0,   0,   0},
                        {  1,   0,   0,   0,   0,   0,   0,   1}};
						
	runLengthEncoding2(size, dataOut, dataIn, &table);
}

void test_runLengthDecoding2(){
	scanTable table = {.row = 0, .column = 0, .col_limit = 2, .firstStage = 0, .secondStage = 0, .thirdStage = 0, .finalStage = 0};
	int size = 8;
	int dataIn[24] = {1,2,3,4,0,5,0,6,0,99,0,11,0,12,0,13,0,87,0,15,19,56,29,5};
	int dataOut[8][8];
	runLengthDecoding2(size, dataIn, dataOut, &table);
}
*/