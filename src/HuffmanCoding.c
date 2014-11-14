#include <stdio.h>
#include "HuffmanCoding.h"

void dumpArray(int* data, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ",data[i]);
	}
}

void runLengthEncoding(int* dataIn, int* dataOut, int size){
	int i = 0, j = 0, sum = 1;
	
	while(i != size){
		if(dataIn[i] == dataIn[i+1]){
			sum += 1; i += 1;
		}else{
			dataOut[j] = sum; j += 1;
			dataOut[j] = dataIn[i];
			sum = 1; i += 1; j += 1;
		}
	}
}
