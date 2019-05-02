#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_WIDTH 12
#define GRID_HEIGHT 8
#define REPLACE_SET_SIZE 4
#define REPLACE_SET_COUNT 1

void DisplayGrid(int width, int height, char grid[][width]) {
	for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            printf("%c", grid[y][x]);
        }
        printf("\n");
    }
	printf("\n");
	return;
}

int main(){
	if (GRID_WIDTH * GRID_HEIGHT < REPLACE_SET_SIZE * REPLACE_SET_COUNT) {
		printf("[ERROR] Imposible Setting: to many replacements.\nQuitting.\n");
		return 1;
	}
	srand(time(NULL));
	char grid[GRID_HEIGHT][GRID_WIDTH];
	for (int y = 0; y < GRID_HEIGHT; y++) {
		for (int x = 0; x < GRID_WIDTH; x++) {
			grid[y][x] = '.';
		}
	}
	DisplayGrid(GRID_WIDTH, GRID_HEIGHT, grid);

	for (int i = 0; i < REPLACE_SET_COUNT; i++) {
		for (int j = 0; j < REPLACE_SET_SIZE; j++) {
			int x, y;
			do {
				x = rand() % (GRID_WIDTH);
				y = rand() % (GRID_HEIGHT);
 			} while(grid[y][x] != '.');
			grid[y][x] = '#';
		}
		DisplayGrid(GRID_WIDTH, GRID_HEIGHT, grid);
	}
	return 0;
}

