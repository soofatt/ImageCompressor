#include "Normalization.h"

void normalizeMatrix(int size, float inputMatrix[][size]){
  int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			inputMatrix[i][j] -= 128;
		}
	}
}

void denormalizeMatrix(int size, float inputMatrix[][size]){
  int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			inputMatrix[i][j] += 128;
		}
	}
}