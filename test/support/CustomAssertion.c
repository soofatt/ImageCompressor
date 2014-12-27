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

void assertUINT82DArray(unsigned char inputArray[8][8], unsigned char compareArray[8][8], const UNITY_LINE_TYPE lineNumber){
	int i, j;
	if(inputArray == NULL)
		UNITY_TEST_FAIL(lineNumber, "There no Input Array.\n");
	if(compareArray == NULL)
		UNITY_TEST_FAIL(lineNumber, "There no Compare Array.\n");
		
	for(i = 0; i < 8; i++){
		for(j = 0; j < 8; j++){
		UNITY_TEST_ASSERT_EQUAL_UINT8(compareArray[i][j], inputArray[i][j], lineNumber, "Expected is different from actual.");
		if(inputArray[i][j] != compareArray[i][j])
			printf("\nExpected is %d but actual is %d\n",compareArray[i][j],inputArray[i][j]);
		}
	}
}

void assert8by8Matrix(float expectedMatrix[][8], float actualMatrix[0][8], int line){
  int i, j;
  
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      TEST_ASSERT_FLOAT_WITHIN(0.5, expectedMatrix[i][j], actualMatrix[i][j]);
    }
  }
}