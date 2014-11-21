#include <stdio.h>
#include "runLengthCoding.h"

void dumpArray(int* data, int size){
	int i;
	for(i = 0; i < size; i++){
		printf("%d ",data[i]);
	}
}

/* Function	: runLengthEncode
 * Do		: Return the run and symbol, run is the number of zero before symbol(non-zero)
 *
 * Argument
 * size		: is the row and column of 2D array
 * dataIn	: pass in 2D array from quantization
 * state	: contain the state to tell whether the operation to find zero should continue or not
 *				If 1, continue search for zero. Otherwise, it found non-zero symbol and return
 *
 * Return	: 
 * table[index]	: Concatenate value of row and column
 */
uint32 runLengthEncode(int size, short int dataIn[][size], State* state){
	uint8 row, column, zeroCount = 0, returnRC = 0x00;
	uint32 runAndSymbol = 0; uint16 symbol;
	int tempIndex;
	state->state = 1;
	while(state->state){
		//Look for row and column from lookup and store
		returnRC = lookupRC(state->index);
		column = returnRC & 0x0f;
		row = returnRC >> 4;
		if(dataIn[row][column] == 0){
			zeroCount += 1; state->index++;
		}
		else if(dataIn[row][column] != 0){
			if(runAndSymbol == 0x000F0000){
				state->index = tempIndex;
				state->state = 0;
			}else{
				runAndSymbol = zeroCount;
				runAndSymbol <<= 16;
				symbol = dataIn[row][column];
				runAndSymbol |= symbol;
				state->state = 0;state->index++;
			}
		}
		if(zeroCount >15){
			runAndSymbol = 15; runAndSymbol <<= 16; zeroCount = 0; tempIndex = state->index;
		}
		if(state->index == 64 && zeroCount != 0){
			runAndSymbol = 0; state->state = 0;
		}
	}
	printf("%d\n", column);
	printf("%d\n", row);
	printf("%d\n\n", dataIn[row][column]);
	
	return runAndSymbol;	
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
/* int runLengthEncoding2(int size, int* dataOut, int dataIn[][size], scanTable* table){
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
// }*/

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

/*// void runLengthDecoding2(int size, int* dataIn, int dataOut[][size], scanTable* table){
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
// }*/


