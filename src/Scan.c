#include <stdio.h>
#include "Scan.h"

#define TransferVal() (out[i] = in[r][c])

/* Function	: lookupRC
 * Do		: Return the row and column according to index
 *
 * Argument
 * index	: Reference to table created in lookupRC to obtain the next correct row and column
 *
 * Return	: 
 * table[index]	: Concatenate value of row and column
 */
uint8 lookupRC(int index){
	uint8 table[64] = {0x00, 0x01, 0x10, 0x20, 0x11, 0x02, 0x03, 0x12, 0x21, 0x30, 0x40, 0x31, 0x22, 0x13, 0x04,
						0x05, 0x14, 0x23, 0x32, 0x41, 0x50, 0x60, 0x51, 0x42, 0x33, 0x24, 0x15, 0x06, 0x07, 0x16,
						0x25, 0x34, 0x43, 0x52, 0x61, 0x70, 0x71, 0x62, 0x53, 0x44, 0x35, 0x26, 0x17, 0x27, 0x36,
						0x45, 0x54, 0x63, 0x72, 0x73, 0x64, 0x55, 0x46, 0x37, 0x47, 0x56, 0x65, 0x74, 0x75, 0x66,
						0x57, 0x67, 0x76, 0x77};
	return table[index];
}

void updateRCTable1(scanTable* table){
	if(table->row != 7){
		if(table->stage == 1){
			IncrementBy1(table->column);
			table->stage = 2;
		}
		else if(table->stage == 2){
			DecrementBy1(table->column); IncrementBy1(table->row);
			if(table->column == 0)
				table->stage = 3;
		}
		else if(table->stage == 3){
			IncrementBy1(table->row);
			table->stage = 4;
		}
		else if(table->stage == 4){
			DecrementBy1(table->row); IncrementBy1(table->column);
			if(table->row == 0){
				table->stage = 1;
			}
		}
		if(table->row == 7)
			table->stage = 1;
	}
}

void updateRCTable2(scanTable* table){
	if(table->stage == 1){
		IncrementBy1(table->column);
		table->stage = 2;
	}
	else if(table->stage == 2){
		DecrementBy1(table->row); IncrementBy1(table->column);
		if(table->column == 7)
			table->stage = 3;
	}
	else if(table->stage == 3){
		IncrementBy1(table->row);
		table->stage = 4;
	}
	else if(table->stage == 4){
		DecrementBy1(table->column); IncrementBy1(table->row);
		if(table->column == table->col_limit){
			table->stage = 1;
			table->col_limit += 2;
		}
	}
	if(table->row == 7 && table->column == 7)
		table->stage = 0;
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
