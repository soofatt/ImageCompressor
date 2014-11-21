#include <stdio.h>
#include "Scan.h"

	
#define TransferVal() (out[i] = in[r][c])

void updateRCTable1(scanTable* table){
	if(table->row != 7){
		if(table->firstStage == 1){
			IncrementBy1(table->column);
			OFF(table->firstStage); ON(table->secondStage); 
		}
		else if(table->secondStage == 1){
			DecrementBy1(table->column); IncrementBy1(table->row);
			if(table->column == 0){
				OFF(table->secondStage); ON(table->thirdStage); 
			}
		}
		else if(table->thirdStage == 1){
			IncrementBy1(table->row);
			OFF(table->thirdStage); ON(table->finalStage);
		}
		else if(table->finalStage == 1){
			DecrementBy1(table->row); IncrementBy1(table->column);
			if(table->row == 0){
				OFF(table->finalStage); ON(table->firstStage); 
			}
		}
		if(table->row == 7){
			ON(table->firstStage); OFF(table->secondStage);
			OFF(table->thirdStage); OFF(table->finalStage);
		}
	}
}

void updateRCTable2(scanTable* table){
	int i, j;
		if(table->firstStage == 1){
			IncrementBy1(table->column);
			OFF(table->firstStage); ON(table->secondStage); 
		}
		else if(table->secondStage == 1){
			DecrementBy1(table->row); IncrementBy1(table->column);
			if(table->column == 7){
				OFF(table->secondStage); ON(table->thirdStage); 
			}
		}
		else if(table->thirdStage == 1){
			IncrementBy1(table->row);
			OFF(table->thirdStage); ON(table->finalStage);
		}
		else if(table->finalStage == 1){
			DecrementBy1(table->column); IncrementBy1(table->row);
			if(table->column == table->col_limit){
				OFF(table->finalStage); ON(table->firstStage);
				table->col_limit += 2;
			}
		}
		i = table->row;
		j = table->column;
		if(i == 7 & j == 7){
			OFF(table->firstStage); OFF(table->secondStage);
			OFF(table->thirdStage); OFF(table->finalStage);
		}
}
/* Function	: scanArray
 * Do		: Perform Zig-Zag ordering to 2D array and insert into 1D array
 *
 * Argument
 * in		: input 2D array
 * out 		: output 1D array
 *
 * Return	: None
 */
void scanArray(float in[8][8], float* out){
	int i = 0, r = 0, c = 0, col_limit = 2; //r and c is row and column
	
	// printf("print 1:%d %d%d \n", i, r, c); > use this to print current i/r/c before "out[i] = in[r][c];"
	while(r != 8){
		TransferVal(); // Getting 2D array data and insert into 
		IncrementBy1(i); IncrementBy1(c);
		TransferVal();
		IncrementBy1(i);
		while(c != 0){
			DecrementBy1(c); IncrementBy1(r);
			TransferVal();
			IncrementBy1(i);
		}
		IncrementBy1(r);
		if(r == 8) break;
		TransferVal();
		IncrementBy1(i);
		while(r != 0){
			IncrementBy1(c); DecrementBy1(r);
			TransferVal();
			IncrementBy1(i);
		}
		DecrementBy1(i);
	}
	r = 7;
	while(r != 8){
		IncrementBy1(c);
		TransferVal();
		IncrementBy1(i);
		while(c != 7){
			IncrementBy1(c); DecrementBy1(r);
			TransferVal();
			IncrementBy1(i);
		}
		IncrementBy1(r);
		if(r == 8) break;
		TransferVal();
		IncrementBy1(i);
		while(c != col_limit){
			IncrementBy1(r); DecrementBy1(c);
			TransferVal();
			IncrementBy1(i);
		}
		col_limit += 2;
	}
}
