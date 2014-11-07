#ifndef _CUSTOM_ASSERTION_H_
#define _CUSTOM_ASSERTION_H_

#define TEST_ASSERT_EQUAL_ARRAY(inputArray, compareArray) \
 assertArrayData(inputArray, compareArray, __LINE__);

#endif //_CUSTOM_ASSERTION_H_