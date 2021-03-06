#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define true 1
#define false 0

//DRAW_MODE 0: none, 1: log coordinates, 2: darw full maps, 3: darw maps in steps
#define DRAW_MODE 3
//STEP_INTERVAl interval
#define STEP_INTERVAL 100

typedef struct coordinate {
	int x;
	int y;
} coor;
typedef struct {
	int width;
	int hight;
	coor start;
	coor end;
	int **map;
} maze;

int max(int a, int b) {
	return (a > b) ? a : b;
}
int inRange(int n, int min, int max) {
	return min <= n && n <= max;
}

void printMaze(maze m, int r, int c) {
	static char key[3] = {' ', 'X', '+'};
	for (int y = 0; y < m.hight; y++) {
		for (int x = 0; x < m.width; x++) {
			if (r == y && c == x)
				printf("%c", '@');
			else if(y == m.start.y && x == m.start.x)
				printf("%c", 'S');
			else if(y == m.end.y && x == m.end.x)
				printf("%c", 'F');
			else
				printf("%c", key[m.map[y][x]]);
		}
		printf("\n");
	}
}

void mazeStep(maze m, int r, int c) {
	if (!inRange(r, 0, m.hight - 1) || !inRange(c, 0, m.width - 1)){
		return;
	}
	if( m.map[r][c] ) {
		return;
	}

	switch (DRAW_MODE) {
		case 0:
			break;
		case 1:
			printf("(c: %d, r: %d)", c, r);
			break;
		case 2:
			printMaze(m, r, c);
			printf("\n");
			break;
		case 3:
			printf("\033[2J\033[H");
			printMaze(m, r, c);
			usleep(STEP_INTERVAL * 1000);
			break;
	}



	if (r == m.end.y && c == m.end.x) {
		printf("winner\n");
		exit(0);
	}
	m.map[r][c] = 2;
	//left
	mazeStep(m, r, c-1);
	//up
	mazeStep(m, r-1, c);
	//right
	mazeStep(m, r, c+1);
	//down
	mazeStep(m, r+1, c);

	m.map[r][c] = 0;
	if(DRAW_MODE == 3) {
		printf("\033[2J\033[H");
		printMaze(m, r, c);
		usleep(10000);
	}
}
maze mazeFromFile(char *fileName) {
	FILE *fp = fopen(fileName, "r");

	int length = 0, line = 0;
	maze m;
	m.hight = 0;
	m.width = 0;
	if (fp == NULL) {
		printf("Err: unable to open file");
		exit(1);
	}
	for (char c = fgetc(fp); !feof(fp); c = fgetc(fp)) {
		if (c == '\n') {
			m.hight++;
			m.width = max(m.width, length);
			length = 0;
		} else {
			length++;
		}
	}
	m.map = calloc(m.hight, sizeof(int *));
	for(int i = 0; i < m.hight; i++)
		m.map[i] = calloc(m.width, sizeof(int));

	fseek(fp, 0, SEEK_SET);
	line = 0, length = 0;
	for (char c = fgetc(fp); !feof(fp); c = fgetc(fp)) {
		if (c == '\n') {
			line++;
			length = 0;
		} else {
			switch (toupper(c)) {
				case ' ':
					m.map[line][length] = 0;
					break;
				case 'X':
					m.map[line][length] = 1;
					break;
				case 'S':
					m.map[line][length] = 0;
					m.start.x = length;
					m.start.y = line;
					break;
				case 'F':
					m.map[line][length] = 0;
					m.end.x = length;
					m.end.y = line;
					break;
			}
			length++;
		}
	}
	/*for (int y = 0; y < m.hight; y++){
		for (int x = 0; x < m.width; x++){
			printf("%d", m.map[y][x]);
		}
		printf("\n");
	}*/
	return m;
}


int main(int argc, char *argv[]) {
	maze m = mazeFromFile(argv[1]);
	/*
	int m[6][6] = {
		{1,1,0,1,0,1},
		{1,1,0,0,0,1},
		{1,1,0,1,0,1},
		{0,0,0,1,1,1},
		{0,1,0,0,0,0},
		{0,1,1,1,0,1},
	};*/
	mazeStep(m, m.start.y, m.start.x);
	return 0;
}

