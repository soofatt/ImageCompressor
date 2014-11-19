#include "unity.h"
#include "ValueEncoding.h"

void setUp(void){
}

void tearDown(void){
}

void test_valueEncoding_given_length_0_symbol_3_should_produce_bitsize_2_symbol_11(void){
	EncodeData data;
  RunLengthData input = {.run = 0, .nextSymbol = 3};
  
  valueEncoding(&data, &input);
  
  TEST_ASSERT_EQUAL(0x02, data.runAndCategory);  
  TEST_ASSERT_EQUAL(0b11, data.symbol);  
}

void test_valueEncoding_given_length_0_symbol_neg_3_should_produce_bitsize_2_symbol_00(void){
	EncodeData data;
  RunLengthData input = {.run = 0, .nextSymbol = -3};
  
  valueEncoding(&data, &input);
  
  TEST_ASSERT_EQUAL(0x02, data.runAndCategory); 
  TEST_ASSERT_EQUAL(0b00, data.symbol); //revert to 1's comp. & mask unrelated bits  
}

void test_valueEncoding_given_length_2_symbol_165_should_produce_bitsize_8_symbol_10100101(void){
	EncodeData data;
  RunLengthData input = {.run = 2, .nextSymbol = 165};
  
  valueEncoding(&data, &input);
  
  TEST_ASSERT_EQUAL(0x28, data.runAndCategory); 
  TEST_ASSERT_EQUAL(0b10100101, data.symbol);  
}

void test_valueEncoding_given_length_10_symbol_1865_should_produce_bitsize_11_symbol_11101001001(void){
	EncodeData data;
  RunLengthData input = {.run = 10, .nextSymbol = 1865};
  
  valueEncoding(&data, &input);
  
  TEST_ASSERT_EQUAL(0xAB, data.runAndCategory); 
  TEST_ASSERT_EQUAL(0b11101001001, data.symbol);  
}

void test_valueEncoding_given_length_4_symbol_neg_1500_should_produce_bitsize_11_symbol_01000100011(void){
	EncodeData data;
  RunLengthData input = {.run = 4, .nextSymbol = -1500};
  
  valueEncoding(&data, &input);
  
  TEST_ASSERT_EQUAL(0x4B, data.runAndCategory); 
  TEST_ASSERT_EQUAL(0b01000100011, data.symbol);  
}

void test_valueDecoding_given_run_and_category_02_and_symbol_3_should_produce_runLength_0_symbol_3(void){
	EncodeData data = {.runAndCategory = 0x02, .symbol = 3};
  RunLengthData result;
  
  valueDecoding(&data, &result);
  
  TEST_ASSERT_EQUAL(0, result.run); 
  TEST_ASSERT_EQUAL(3, result.nextSymbol);
}

void test_valueDecoding_given_run_and_category_02_and_symbol_neg_3_should_produce_runLength_0_symbol_neg_3(void){
	EncodeData data = {.runAndCategory = 0x02, .symbol = 0b00};
  RunLengthData result;
  
  valueDecoding(&data, &result);
  
  TEST_ASSERT_EQUAL(0, result.run); 
  TEST_ASSERT_EQUAL(-3, result.nextSymbol);
}

void test_valueDecoding_given_run_and_category_02_and_symbol_neg_2_should_produce_runLength_0_symbol_neg_2(void){
	EncodeData data = {.runAndCategory = 0x02, .symbol = 0b01};
  RunLengthData result;
  
  valueDecoding(&data, &result);
  
  TEST_ASSERT_EQUAL(0, result.run); 
  TEST_ASSERT_EQUAL(-2, result.nextSymbol);
}

void test_valueDecoding_given_run_and_category_47_and_symbol_neg_64_should_produce_runLength_4_symbol_neg_64(void){
	EncodeData data = {.runAndCategory = 0x47, .symbol = 0b0111111};
  RunLengthData result;
  
  valueDecoding(&data, &result);
  
  TEST_ASSERT_EQUAL(4, result.run); 
  TEST_ASSERT_EQUAL(-64, result.nextSymbol);
}

void test_valueDecoding_given_run_and_category_AB_and_symbol_neg_1200_should_produce_runLength_10_symbol_neg_1200 (void){
	EncodeData data = {.runAndCategory = 0xAB, .symbol = 0b01101001111};
  RunLengthData result;
  
  valueDecoding(&data, &result);
  
  TEST_ASSERT_EQUAL(10, result.run); 
  TEST_ASSERT_EQUAL(-1200, result.nextSymbol);
}

void test_valueDecoding_given_run_and_category_3B_and_symbol_1750_should_produce_runLength_3_symbol_1750 (void){
	EncodeData data = {.runAndCategory = 0x3B, .symbol = 0b11011010110};
  RunLengthData result;
  
  valueDecoding(&data, &result);
  
  TEST_ASSERT_EQUAL(3, result.run); 
  TEST_ASSERT_EQUAL(1750, result.nextSymbol);
}