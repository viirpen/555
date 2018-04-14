#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXRAND 10
#define ROW 4
#define COL 4

void printArray(int arr[ROW][COL]);
void matrixMultiply(int matrix1[ROW][COL], int matrix2[ROW][3], int result[ROW][3]);

int main(void)
{
	int i = 0, j = 0; /* ROWx4*/
	int m = 0; /* col matrix 2*/
	int matrix1[4][4] = { 0 };
	int matrix2[4][3] = { 0 };
	int result[4][3] = { 0 };


	for (i = 0; i < ROW; i++) { /* Matrix 1. 4 row 4 col*/
		for (j = 0; j < ROW; j++) {
			matrix1[i][j] = (int)(1 + rand() % MAXRAND);
		}
	}
	for (i = 0; i < ROW; i++) { /* Matrix 2. 4row3col*/
		for (m = 0; m < 3; m++) {
			matrix2[i][m] = (int)(1 + rand() % MAXRAND);
		}
	}
	
	printf("Matrix 1: \n");
	printArray(matrix1);

	printf("Matrix 2: \n");
	printArray(matrix2);

	matrixMultiply(matrix1, matrix2, result);

	printf("Results: \n");
	printArray(result);

	return 0;
}

void printArray(int arr[4][3]) { /* HOW do I make this shit print my 4x4 correct and my 4x3 matrixes*/
	int i = 0, j = 0, m = 0;
	for (i = 0; i < 4; i++) {
	for (j=0;j<3;j++)
	printf("%4d ", arr[i][j]);

	printf("\n");
	}
	printf("\n");
}

void matrixMultiply(int matrix1[ROW][COL], int matrix2[ROW][3], int result[ROW][3]) 
{
	int m = 0, j = 0, i = 0;
	int temp;
	for (j = 0; j < 4; j++) { /* j=matrix 1 col */
		for (m = 0; m < 3; m++) { /* m=matrix 2 col*/
			temp = matrix1[i][j];
			for (i = 0; i < 4; i++) { /* i=row for matrix1 and 2*/
				
				result[i][m] = result[i][j] + temp * matrix2[i][m];
			}
		}
	}

}