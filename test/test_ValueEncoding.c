#include "unity.h"
#include "ValueEncoding.h"

void setUp(void){
}

void tearDown(void){
}

void test_valueEncoding_given_length_0_symbol_3_should_produce_bitsize_2_symbol_11(void){
	EncodeData data;
  
  valueEncoding(&data, 0, 3);
  
  TEST_ASSERT_EQUAL(0, data.runLength);  
  TEST_ASSERT_EQUAL(2, data.bitSize);  
  TEST_ASSERT_EQUAL(0b11, data.symbol);  
}

void test_valueEncoding_given_length_0_symbol_neg_3_should_produce_bitsize_2_symbol_00(void){
	EncodeData data;
  
  valueEncoding(&data, 0, -3);
  
  TEST_ASSERT_EQUAL(0, data.runLength);  
  TEST_ASSERT_EQUAL(2, data.bitSize);  
  TEST_ASSERT_EQUAL(-3, data.symbol);  
}

void test_valueEncoding_given_length_2_symbol_165_should_produce_bitsize_8_symbol_10100101(void){
	EncodeData data;
  
  valueEncoding(&data, 2, 165);
  
  TEST_ASSERT_EQUAL(2, data.runLength);  
  TEST_ASSERT_EQUAL(8, data.bitSize);  
  TEST_ASSERT_EQUAL(0b10100101, data.symbol);  
}

void test_valueEncoding_given_length_4_symbol_25_should_produce_bitsize_5_symbol_11001(void){
	EncodeData data;
  
  valueEncoding(&data, 4, 25);
  
  TEST_ASSERT_EQUAL(4, data.runLength);  
  TEST_ASSERT_EQUAL(5, data.bitSize);  
  TEST_ASSERT_EQUAL(0b11001, data.symbol);  
}
