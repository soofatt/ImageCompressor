/**
 * Author: Chiang Choon Yong
 * Email: yong931231@hotmail.com
 * Date: 16 - 10 - 2014
 * Project name: Image Compressor - Inverse Discrete Cosine Transform
 * Programme: Microelectronic with Embedded Technology
 * Institution: Tunku Abdul Rahman University College
 * Copyright: GPLv3
 */

#include "IDCT.h"
#include <math.h>
void dumpMatrix(int size,float matrix[][size]){
	int i, j;
	for(i = 0; i < size; i++){
		for(j = 0; j < size; j++){
			printf("%.3f ",matrix[i][j]);
		}
		printf("\n");
	}
}
/*  Function    : cos_IDCT, cosine fractional value in term of PI
 *  
 *  Arguments
 *  -------------
 *  numerator/
 *  denominator : example > 5/6, 5 is numerator and 6 is denominator
 *
 *  Return
 *  -------------
 *  cosAns      : cosine value in floating no. which corresponding to the input
 */
float cos_IDCT(int numerator, int denominator){
  float cosANS;
  cosANS = cos(PI*numerator/denominator);
  return cosANS;
}

/*  Function    : int_Divider, divide integer value(numerator) by another integer value(denominator)
 *  
 *  Arguments
 *  -------------
 *  numerator/
 *  denominator : example > 5/6, 5 is numerator and 6 is denominator
 *
 *  Return
 *  -------------
 *  div         : Divided result in floating no. which corresponding to the input
 */
float int_Divider(int numerator, int denominator){
  float div = (float)numerator/denominator;
  return div;
}

/*  Function    : round_float, rounding the floating no. to the nearest integer
 *  
 *  Arguments
 *  -------------
 *  array[]     : Floating array to be rounded
 *  noOfElement : Total elements inside the array[]
 *
 *  Return
 *  -------------
 *  NONE
 */
void round_float(float array[], int noOfELement){
  int i;
  for(i = 0; i < noOfELement; i++){
    array[i] = round(array[i]);
  }
}

/*  Function    : transpose_2D, Transpose the 2D square array (length*length MATRIX)
 *  
 *  Arguments
 *  -------------
 *  size           : Total length or total no. of elements for a row/column
 *  matrix[][size] : input 2D square array
 *
 *  Return
 *  -------------
 *  NONE
 */
void transpose_2D(int size,float matrix[][size]){
  int row, col;
  float transposeMatrix[size][size];
  
  /*  Here show what transpose will do for 2D array
   *  [Input]                      [Output]
   *  +-     -+                    +-     -+
   *  | a b c |  After transpose   | a d g |
   *  | d e f |  --------------->  | b e h |
   *  | g h i |                    | c f i |
   *  +-     -+                    +-     -+
   */
  for(row = 0; row<size; row++){
    for(col = 0; col<size; col++){
      transposeMatrix[col][row] = matrix[row][col];
    }
  }
  for(row = 0; row<size; row++){
    for(col = 0; col<size; col++){
      matrix[row][col] = transposeMatrix[row][col];
    }
  }
}

/*  Function    : oneD_IDCT, perform inverse discrete cosine transform to 1D array and get back the original value
 *  
 *  Arguments
 *  -------------
 *  transVal[]     : 1D array with elements that need to be IDCT
 *  noOfElement    : Total elements inside the transVal[]
 *
 *  Return
 *  -------------
 *  NONE
 */
void oneD_IDCT(float transVal[], int noOfElement){
  int i, num, den, index;
  float Cu, cosAns, divAns, total = 0;
  float invTransVal[noOfElement];
  
  for(index = 0;index < noOfElement; index++){
    for(i = 0; i < noOfElement; i++){
      if(i == 0){
        divAns = int_Divider(1,noOfElement);
        Cu = sqrt(divAns);
      }
      else{
        divAns = int_Divider(2,noOfElement);
        Cu = sqrt(divAns);
      }
      num = (2*index + 1)*i;
      den = 2*noOfElement;
      cosAns = cos_IDCT(num,den);
      total += Cu * transVal[i] * cosAns;
    }
    // printf("          Total %d : %f\n",index,total);
    // printf("Round off Total %d : %f\n",index,round(total));
    invTransVal[index] = total;
    total = 0;
  }
  for(i = 0; i < noOfElement; i ++){
    transVal[i] = invTransVal[i];
  }
}

/*  Function    : twoD_IDCT, perform inverse discrete cosine transform to 2D array and get back the original value
 *  
 *  Arguments
 *  -------------
 *  transVal[][size]  : 2D array with elements that need to be IDCT
 *  size              : Total elements inside the transVal[] for row/column
 *
 *  Return
 *  -------------
 *  NONE
 */
void twoD_IDCT(int size,float transVal[][size]){
  int row, column;
  int loop;
  
  /*  To do DCT of 2D array, must perform 1D DCT to each row first follow by each column.
   *  For IDCT, will start from 1D IDCT for each column first then follow by each row.
   */
  for(loop = 0; loop<2; loop++){
    transpose_2D(size,transVal);  
    for(row = 0;row < size; row++){
      oneD_IDCT(transVal[row],size);
    }
  }
  for(row = 0;row < size; row++){
    round_float(transVal[row],size);
  }
}