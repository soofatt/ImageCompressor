#ifndef _CUSTOM_ASSERTION_H_
#define _CUSTOM_ASSERTION_H_

#define TEST_ASSERT_EQUAL_ARRAY(inputArray, compareArray) \
 assertArrayData(inputArray, compareArray, __LINE__);

#define TEST_ASSERT_EQUAL_UINT8_2D_ARRAY(inputArray, compareArray) \
 assertUINT82DArray(inputArray, compareArray, __LINE__);

#define TEST_ASSERT_EQUAL_MATRIX(expected, actual) \
 assert8by8Matrix(expected, actual, __LINE__);
 
#endif //_CUSTOM_ASSERTION_H_