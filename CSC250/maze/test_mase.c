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
#define STEP_INTERVAL 50

typedef struct coordinate {
	int x;
	int y;
} coord;
typedef struct {
	int width;
	int hight;
	int pointCount;
	coord *points;
	coord start;
	coord end;
	int **map;
} maze;

int max(int a, int b) {
	return (a > b) ? a : b;
}
int inRange(int n, int min, int max) {
	return min <= n && n <= max;
}

void printMaze(maze m, int r, int c) {
	//static char key[3] = {' ', 'X', '+'};
	char *output = calloc(m.hight * m.width * 17 + m.hight, sizeof(char));
	for (int y = 0; y < m.hight; y++) {
		for (int x = 0; x < m.width; x++) {
			if (r == y && c == x)
				strcat(output, "@");
			else if(y == m.start.y && x == m.start.x)
				strcat(output, "\033[32mS\033[0m");
			else if(y == m.end.y && x == m.end.x)
				strcat(output, "\033[31mF\033[0m");
			else{
				switch(m.map[y][x]){
					case 0:
						strcat(output, " ");
						break;
					case 1:
						strcat(output, "\033[100m \033[0m");
						break;
					case 2:
						strcat(output, "+");
						break;
				}
			}
		}
		strcat(output, "\n");
	}
	printf(output);
}

int mazeStep(maze m, int r, int c) {
	if (!inRange(r, 0, m.hight - 1) || !inRange(c, 0, m.width - 1)){
		return false;
	}
	if( m.map[r][c] ) {
		return false;
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
		return true;
	}
	int won = false;
	m.map[r][c] = 2;
	//left
	won = mazeStep(m, r, c-1);
	//up
	won = won || mazeStep(m, r-1, c);
	//right
	won = won || mazeStep(m, r, c+1);
	//down
	won = won || mazeStep(m, r+1, c);

	m.map[r][c] = 0;

	if (won) {
		return true;
	}
	if(DRAW_MODE == 3) {
		printf("\033[2J\033[H");
		printMaze(m, r, c);
		usleep(STEP_INTERVAL * 100);
	}
	return false;
}
maze mazeFromFile(char *fileName) {
	FILE *fp = fopen(fileName, "r");

	int length = 0, line = 0, count = 0;
	maze m;



	if (fp == NULL) {
		printf("Err: unable to open file");
		exit(1);
	}
	m.width = 0;
	m.hight = 0;
	m.pointCount = 0;
	for (char c = fgetc(fp); !feof(fp); c = fgetc(fp)) {
		if (c == '\n') {
			m.hight++;
			m.width = max(m.width, length);
			length = 0;
		} else {
			if (c == 'O')
				m.pointCount++;
			length++;
		}
	}
	m.map = calloc(m.hight, sizeof(int *));
	for(int i = 0; i < m.hight; i++)
		m.map[i] = calloc(m.width, sizeof(int));

	m.points = calloc(m.pointCount, sizeof(coord));
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
				case 'O':
					m.map[line][length] = 0;
					m.points[count].x = length;
					m.points[count].y = line;
					count++;
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
	srand(time(NULL));
	//while(1) {
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
	while (1) {
		int startI, endI;
		startI = rand() % m.pointCount;
		do {
			endI = rand() % m.pointCount;
		} while(endI == startI);
		m.start = m.points[startI];
		m.end = m.points[endI];
		//printf("%d\n", m.pointCount);
		mazeStep(m, m.start.y, m.start.x);
		sleep(1);
	}
	return 0;
}

