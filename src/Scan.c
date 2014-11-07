#include <stdio.h>
#include "Scan.h"

#define TransferVal() (out[i] = in[r][c])

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
