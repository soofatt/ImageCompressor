#include "unity.h"
#include "Scan.h"
#include "CustomAssertion.h"

void setUp(void){}

void tearDown(void){}

void test_scanArray(void){
	//compareArray is the expected output array after scan process...
	float compareArray[64] = {10,22,35,12,43,53,44,11,68,11,71,24,
								35,48,81,53,0,44,35,52,31,12,29,83
								,74,5,110,35,102,120,64,59,54,73,
								23,17,92,36,44,59,65,79,90,88,47
								,61,51,48,33,74,50,46,78,88,88,7,
								16,95,96,78,8,98,97,81};
								
	float inArray[8][8] = {{10, 22, 53, 44, 81, 53, 35, 102}, 
                           {35, 43, 11, 48, 0, 110, 120, 90}, 
                           {12, 68, 35, 44, 5, 64, 79, 88},
                           {11, 24, 35, 74, 59, 65, 47, 88}, 
                           {71, 52, 83, 54, 59, 61, 78, 88}, 
                           {31, 29, 73, 44, 51, 46, 7, 8},
                           {12, 23, 36, 48, 50, 16, 78, 98}, 
                           {17, 92, 33, 74, 95, 96, 97, 81}};
	float outArray[64];
	
	scanArray(inArray,outArray);
	TEST_ASSERT_EQUAL_ARRAY(outArray,compareArray);
}
