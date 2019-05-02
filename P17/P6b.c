#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int rows = 5, cols = 4;
	if(argc < 2){
		printf("ERROR: no file provided\n");
		return 0;
	}
	FILE *fp = fopen(argv[1], "r");
	fscanf(fp, "%d", &rows);
	fscanf(fp, "%d", &cols);

	int  *grid = calloc(rows * cols, sizeof(int));
	char *dups = calloc(rows * cols + 1, sizeof(char));

	//read

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			fscanf(fp, "%d", &grid[r * cols + c]);
		}
	}
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			dups[r * cols + c] = ' ';
		}
	}
	//row check
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if(dups[r * cols + c] != '-') {
				for(int i = c+1; i < cols; i++) {
					if(grid[r * cols + c] == grid[r * cols + i]) {
						dups[r * cols + c] = '-';
						dups[r * cols + i] = '-';
					}
				}
			}
		}
	}
	//column chack
	for (int c = 0; c < cols; c++) {
		for (int r = 0; r < rows; r++) {
			if(dups[r * cols + c] == '-' || dups[r * cols + c] == ' ') {
				for(int i = r+1; i < rows; i++) {
					if(grid[r * cols + c] == grid[i * cols + c]) {
						dups[r * cols + c] = (dups[r * cols + c] == ' ') ? '|' : '+';
						dups[i * cols + c] = (dups[i * cols + c] == ' ') ? '|' : '+';
					}
				}
			}
		}
	}

	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			printf("%c", dups[r * cols + c]);
		}
		printf("\n");
	}
	printf("%s\n", dups);
	return 0;
}

