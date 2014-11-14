#include "unity.h"
#include "HuffmanCoding.h"

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

