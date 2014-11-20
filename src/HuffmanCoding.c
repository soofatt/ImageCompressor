#include <stdio.h>
#include "HuffmanCoding.h"

void dumpArray(int* data, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ",data[i]);
	}
}

int runLengthEncoding2(int size, int* dataOut, int dataIn[][size], scanTable* table){
	int i = 0, j = 0, zeroCount = 0, limit1D = size*size*2;
	
	while(table->column < 3){
		if(dataIn[table->row][table->column] != 0){
			if(zeroCount != 0)
				dataOut[i] = zeroCount;
			else
				dataOut[i] = 0; 
			i += 1; zeroCount = 0;
			dataOut[i] = dataIn[table->row][table->column]; i += 1;
		}
		else
			zeroCount += 1;
			
		//Suppose to call zig zag and update RC
		//table->column += 1;
		updateRCTable(table);
		printf("row : %d column : %d\n", table->row, table->column);
		
	}
	dumpArray(dataOut,6);
	return i;
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

void runLengthDecoding(int* dataIn, int* dataOut, int size){
	int i = 0, j = 0, repeatNo = 0;
	
	while(i != size){
		repeatNo = dataIn[i];
		i += 1;
		while(repeatNo != 0){
			dataOut[j] = dataIn[i];
			j += 1; repeatNo -= 1;
		}i += 1;
	}dumpArray(dataOut, 20);
}
