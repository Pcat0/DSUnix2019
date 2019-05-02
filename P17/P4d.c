#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char *argv[]) {
	int rows = 5, cols = 4;
	if(argc < 2){
		printf("ERROR: no file provided\n");
		return 0;
	}
	FILE *fp = fopen(argv[1], "r");
	fscanf(fp, "%d", &rows);
	fscanf(fp, "%d", &cols);

	int *grid = calloc(rows * cols, sizeof(int));

	//read

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			fscanf(fp, "%d", &grid[r * cols + c]);
		}
	}
	//row sum
	int maxSum = INT_MIN;
	int maxPos = 0;
	for (int r = 0; r < rows; r++) {
		int sum = 0;
		for (int c = 0; c < cols; c++) {
			sum += grid[r * cols + c];
		}
		if(sum > maxSum) {
			maxSum = sum;
			maxPos = r;
		}
	}
	printf("Highest row total:\n  Row: %d\n  Sum: %d\n", maxPos, maxSum);

	//column sum
	maxSum = INT_MIN;
	maxPos = 0;
	for (int c = 0; c < cols; c++) {
		int sum = 0;
		for (int r = 0; r < rows; r++) {
			sum += grid[r * cols + c];
		}
		if(sum > maxSum) {
			maxSum = sum;
			maxPos = c;
		}
	}
	printf("Highest column total:\n  Col: %d\n  Sum: %d\n", maxPos, maxSum);

	maxSum = INT_MIN;
	int maxR = 0;
	int maxC = 0;
	for (int c = 0; c <= cols - 3; c++) {
		for (int r = 0; r <= rows - 3; r++) {
			int sum = 0;
			for(int i = 0; i < 9; i++)
				sum += grid[cols*(i%3+r) + (i/3+c)];
			printf("(%d, %d) %d\n", c, r, sum);
			if(sum > maxSum) {
				maxSum = sum;
				maxC = c;
				maxR = r;
			}

		}
	}
	printf("Highest 3x3 box total:\n  Pos: (%d, %d)\n  Sum: %d\n", maxC, maxR,  maxSum);
	

	return 0;
}

