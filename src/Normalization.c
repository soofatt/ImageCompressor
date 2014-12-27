#include "Normalization.h"

/*  normalizeMatrix
 *  Desc.  : Function to shift elements in the array from 0 to 255 to -128 to 127
 *
 *  Input
 *    inputMatrix : Input 2D array/matrix.
 *
 */
void normalizeMatrix(int size, float inputMatrix[][size]){
  int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			inputMatrix[i][j] -= 128;
		}
	}
}

/*  denormalizeMatrix
 *  Desc.  : Function to shift elements in the array from -128 to 127 to 0 to 255
 *
 *  Input
 *    inputMatrix : Input 2D array/matrix.
 *
 */
void denormalizeMatrix(int size, float inputMatrix[][size]){
  int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			inputMatrix[i][j] += 128;
		}
	}
}