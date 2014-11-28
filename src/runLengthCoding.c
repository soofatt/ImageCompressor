#include <stdio.h>
#include "runLengthCoding.h"

#define getZeroCount(x) (x >> 16)
#define getSymbol(x) (x & 0x0000FFFF)
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
	uint8 row, column, zeroCount = 0, returnRC = 0x00, keep = 0;
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
			runAndSymbol = 15; runAndSymbol <<= 16; zeroCount = 0; 
			//Make sure next 16 zero will not overwrite tempIndex because
			//It can be non-zero after 32 zero
			if(keep == 0){ 
				tempIndex = state->index; keep = 1;
			}
		}
		if(state->index == 64 && zeroCount != 0){
			runAndSymbol = 0; state->state = 0;
		}
	}
	return runAndSymbol;	
}

void runLengthDecode(int size, short int dataOut[][size], State* state, uint32 runAndSymbol){
	int i, j;
	//Detect runAndSymbol content for no of '0' and symbol
	uint32 countZero = getZeroCount(runAndSymbol);
	uint32 symbol = getSymbol(runAndSymbol);
	uint8 row, column, returnRC = 0x00;
	//If runAndSymbol is 0x00000000, then all the 2D array slots filled with 0
	if(countZero == 0 && symbol == 0){
		state->state = 1;
		while(state->state){
			returnRC = lookupRC(state->index);
			column = returnRC & 0x0f; row = returnRC >> 4; state->index += 1;
			dataOut[row][column] = 0;
			if(returnRC == 0x77) state->state = 0;
		}
	}
	//ALways make sure countZero <= 15
	if(countZero <= 15){
		//if runAndSymbol is (15,0) > 0x000F0000
		if(countZero == 15)
			countZero += 1;
		//If no of '0' not zero, should insert 0 into first location of array
		//and then update to next index with lookupRC
		while(countZero!=0){
			returnRC = lookupRC(state->index);
			column = returnRC & 0x0f; row = returnRC >> 4; state->index += 1;
			dataOut[row][column] = 0; countZero -= 1;
		}
		returnRC = lookupRC(state->index); state->index += 1;
		column = returnRC & 0x0f; row = returnRC >> 4;
		dataOut[row][column] = symbol;
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

void runLengthDecoding(int* dataIn, int* dataOut, int size){
	int i = 0, j = 0, repeatNo = 0;
	
	while(i != size){
		repeatNo = dataIn[i];
		i += 1;
		while(repeatNo != 0){
			dataOut[j] = dataIn[i];
			j += 1; repeatNo -= 1;
		}i += 1;
	}//dumpArray(dataOut, 20);
}

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
	printf("%d\n", column);
	printf("%d\n", row);
	printf("%d\n\n", dataIn[row][column]);

int runLengthEncoding2(int size, int* dataOut, int dataIn[][size], scanTable* table){
	int i = 0, j = 0, zeroCount = 0, part1 = 0, part2 = 0;
	table->stage = 1;
	while(i!=size){
		part1 += (i+1);
		i++;
	}
	part2 = (size*size)-part1;
	i = 0;
	while(j < part1){
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
		updateRCTable1(table);
		j++;
	}
	j = 0;
	while(j < part2){
		updateRCTable2(table);
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
		j++;
	}
	dumpArray(dataOut,i);
	return i;
}


void runLengthDecoding2(int size, int* dataIn, int dataOut[][size], scanTable* table){
	int i = 0, j = 0, zeroCount = 0, part1 = 0, part2 = 0, check = 1, insert = 0;
	table->firstStage = 1;
	while(i!=size){
		part1 += (i+1);
		i++;
	}
	part2 = (size*size)-part1;
	i = 0;	
	while(j < part1){
		if(zeroCount == 0){
			if(check && dataIn[i] != 0){
				zeroCount = dataIn[i];
				check = 0; insert = 1;
			}
			else{
				i++;
				dataOut[table->row][table->column] = dataIn[i]; i++;
				check = 1; insert = 0;
			}
		}
		if(zeroCount!=0){
			dataOut[table->row][table->column] = 0;
			zeroCount--;
		}
		updateRCTable1(table);
		j++;
	}j = 0;
	while(j < part2){
		updateRCTable2(table);
		if(zeroCount == 0){
			if(check && dataIn[i] != 0){
				zeroCount = dataIn[i];
				check = 0; insert = 1;
			}
			else{
				i++;
				dataOut[table->row][table->column] = dataIn[i]; i++;
				check = 1; insert = 0;
			}
		}
		if(zeroCount!=0){
			dataOut[table->row][table->column] = 0;
			zeroCount--;
		}
		j++;
	}
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%d ",dataOut[i][j]);
		}printf("\n");
	}
}*/


