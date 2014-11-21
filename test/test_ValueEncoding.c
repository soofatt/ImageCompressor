#include "unity.h"
#include "ValueEncoding.h"

void setUp(void){
}

void tearDown(void){
}

void test_valueEncoding_given_symbol_3_should_produce_bitsize_2_symbol_11(void){
	short int symbolInput = 3;
  unsigned int result;
  
  result = valueEncoding(symbolInput);
  
  TEST_ASSERT_EQUAL(0x00020003, result);
}

void test_valueEncoding_given_symbol_neg_3_should_produce_bitsize_2_symbol_00(void){
	short int symbolInput = -3;
  unsigned int result;
  
  result = valueEncoding(symbolInput);
  
  TEST_ASSERT_EQUAL(0x00020000, result); 
}

/*
 * Output: 0x00A5 = 0000 0000 1010 0101
 */
void test_valueEncoding_given_symbol_165_should_produce_bitsize_8_symbol_10100101(void){
	short int symbolInput = 165;
  unsigned int result;
  
  result = valueEncoding(symbolInput);
  
  TEST_ASSERT_EQUAL(0x000800A5, result);   
}

/*
 * Output: 0x0749 = 0000 0111 0100 1001
 */
void test_valueEncoding_given_symbol_1865_should_produce_bitsize_11_symbol_11101001001(void){
	short int symbolInput = 1865;
  unsigned int result;
  
  result = valueEncoding(symbolInput);
  
  TEST_ASSERT_EQUAL(0x000B0749, result);   
}

/*
 * Output: 0x0223 = 0000 0010 0010 0011
 */
void test_valueEncoding_given_symbol_neg_1500_should_produce_bitsize_11_symbol_01000100011(void){
	short int symbolInput = -1500;
  unsigned int result;
  
  result = valueEncoding(symbolInput);
  
  TEST_ASSERT_EQUAL(0x000B0223, result); 
}

void test_valueDecoding_given_categoryAndSymbol_0x00020003_should_produce_symbol_3(void){
	unsigned int catAndSymbol = 0x00020003;
  short int result;
  
  result = valueDecoding(catAndSymbol);
  
  TEST_ASSERT_EQUAL(0x0003, result);
}

void test_valueDecoding_given_categoryAndSymbol_0x00020000_should_produce_symbol_neg_3(void){
	unsigned int catAndSymbol = 0x00020000;
  short int result;
  
  result = valueDecoding(catAndSymbol);
  
  TEST_ASSERT_EQUAL(-3, result);
}

void test_valueDecoding_given_categoryAndSymbol_0x00020001_should_produce_symbol_neg_2(void){
	unsigned int catAndSymbol = 0x00020001;
  short int result;
  
  result = valueDecoding(catAndSymbol);
  
  TEST_ASSERT_EQUAL(-2, result);
}

void test_valueDecoding_given_categoryAndSymbol_0x0007003F_should_produce_symbol_neg_64(void){
	unsigned int catAndSymbol = 0x0007003F;
  short int result;
  
  result = valueDecoding(catAndSymbol);
  
  TEST_ASSERT_EQUAL(-64, result);
}

void test_valueDecoding_given_categoryAndSymbol_0x000B034F_should_produce_symbol_neg_1200(void){
	unsigned int catAndSymbol = 0x000B034F;
  short int result;
  
  result = valueDecoding(catAndSymbol);
  
  TEST_ASSERT_EQUAL(-1200, result);
}

void test_valueDecoding_given_categoryAndSymbol_0x000B034F_should_produce_symbol_1750(void){
	unsigned int catAndSymbol = 0x000B06D6;
  short int result;
  
  result = valueDecoding(catAndSymbol);
  
  TEST_ASSERT_EQUAL(1750, result);
}