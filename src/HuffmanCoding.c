#include <stdio.h>
#include "HuffmanCoding.h"

void dumpArray(int* data, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ",data[i]);
	}
}

// int runLengthEncoding2(int size, int* dataOut, int dataIn[][size], scanTable* table){
	// int i = 0, j = 0, zeroCount = 0, part1 = 0, part2 = 0;
	// table->stage = 1;
	// while(i!=size){
		// part1 += (i+1);
		// i++;
	// }
	// part2 = (size*size)-part1;
	// i = 0;
	// while(j < part1){
		// if(dataIn[table->row][table->column] != 0){
			// if(zeroCount != 0)
				// dataOut[i] = zeroCount;
			// else
				// dataOut[i] = 0; 
			// i += 1; zeroCount = 0;
			// dataOut[i] = dataIn[table->row][table->column]; i += 1;
		// }
		// else
			// zeroCount += 1;
		// updateRCTable1(table);
		// j++;
	// }
	// j = 0;
	// while(j < part2){
		// updateRCTable2(table);
		// if(dataIn[table->row][table->column] != 0){
			// if(zeroCount != 0)
				// dataOut[i] = zeroCount;
			// else
				// dataOut[i] = 0; 
			// i += 1; zeroCount = 0;
			// dataOut[i] = dataIn[table->row][table->column]; i += 1;
		// }
		// else
			// zeroCount += 1;
		// j++;
	// }
	// dumpArray(dataOut,i);
	// return i;
// }

/*	printf("%d %d\n",part1,part2);
	printf("row : %d column : %d\n", table->row, table->column);
	printf("stage : %d\n", table->stage);
	printf("i : %d\n",i);
	dumpArray(dataOut,i);
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%d ",dataOut[i][j]);
		}printf("\n");
	}
*/

// void runLengthDecoding2(int size, int* dataIn, int dataOut[][size], scanTable* table){
	// int i = 0, j = 0, zeroCount = 0, part1 = 0, part2 = 0, check = 1, insert = 0;
	// table->firstStage = 1;
	// while(i!=size){
		// part1 += (i+1);
		// i++;
	// }
	// part2 = (size*size)-part1;
	// i = 0;	
	// while(j < part1){
		// if(zeroCount == 0){
			// if(check && dataIn[i] != 0){
				// zeroCount = dataIn[i];
				// check = 0; insert = 1;
			// }
			// else{
				// i++;
				// dataOut[table->row][table->column] = dataIn[i]; i++;
				// check = 1; insert = 0;
			// }
		// }
		// if(zeroCount!=0){
			// dataOut[table->row][table->column] = 0;
			// zeroCount--;
		// }
		// updateRCTable1(table);
		// j++;
	// }j = 0;
	// while(j < part2){
		// updateRCTable2(table);
		// if(zeroCount == 0){
			// if(check && dataIn[i] != 0){
				// zeroCount = dataIn[i];
				// check = 0; insert = 1;
			// }
			// else{
				// i++;
				// dataOut[table->row][table->column] = dataIn[i]; i++;
				// check = 1; insert = 0;
			// }
		// }
		// if(zeroCount!=0){
			// dataOut[table->row][table->column] = 0;
			// zeroCount--;
		// }
		// j++;
	// }
	// for(i = 0; i < size; i++){
		// for(j = 0; j < size; j++){
			// printf("%d ",dataOut[i][j]);
		// }printf("\n");
	// }
// }

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
