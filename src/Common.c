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
			printf("%.3f  ",matrix[i][j]);
		}
		printf("\n");
	}
}

void dumpMatrixUINT8(int size,unsigned char matrix[][size]){
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void dumpMatrixInt(int size, short int matrix[][size]){
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%d ",matrix[i][j]);
		}
		printf("\n");
	}
}

void convertToUINT16(float inputMatrix[][8], short int outputMatrix[][8]){
  int i, j;
  
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      outputMatrix[i][j] = inputMatrix[i][j];
    }
  }
}

void convertToFloat(short int inputMatrix[][8], float outputMatrix[][8]){
  int i, j;
  
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      outputMatrix[i][j] = inputMatrix[i][j];
    }
  }
}

void convertUINT8ToFloat(unsigned char inputMatrix[][8], float outputMatrix[][8]){
  int i, j;
  
  for(i = 0; i < 8; i++){
    for(j = 0; j < 8; j++){
      outputMatrix[i][j] = inputMatrix[i][j];
    }
  }
}