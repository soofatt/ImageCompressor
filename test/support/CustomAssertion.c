#include "CustomAssertion.h"
#include "unity.h"

void assertArrayData(float* inputArray, float* compareArray, const UNITY_LINE_TYPE lineNumber){
	int i;
	if(inputArray == NULL)
		UNITY_TEST_FAIL(lineNumber, "There no Input Array.\n");
	if(compareArray == NULL)
		UNITY_TEST_FAIL(lineNumber, "There no Output Array.\n");
		
	for(i = 0; i < 64; i++){
		UNITY_TEST_ASSERT_FLOAT_WITHIN(0.01, compareArray[i], inputArray[i], lineNumber, "Expected is different from actual.");
		if(inputArray[i] != compareArray[i])
			printf("\nExpected is %f but actual is %f\n",compareArray[i],inputArray[i]);
	}
}