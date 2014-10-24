#include "Common.h"
#include <stdio.h>

/*  Function    : dumpMatrix, printing square matrix
 *  
 *  Arguments
 *  ---------------
 *  size          : no of elements in a row or column
 *  matrix[][size]: Input square matrix
 *
 *  Return
 *  -------------
 *  NONE
 */
void dumpMatrix(int size,float matrix[][size]){
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%.3f ",matrix[i][j]);
		}
		printf("\n");
	}
}
