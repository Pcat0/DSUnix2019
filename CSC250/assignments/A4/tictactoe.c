#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
int convert(char c) {
	int num;

	switch (c) {
		case 'x':
		case 'X':
			num = 1;
			break;
		case 'o':
		case 'O':
			num = -1;
			break;
		default:
			num = 0;
			break;
	}
	return num;
}
void readBoard(int board[3][3]) {
	char buf[10];
	int len;
	printf("  Enter board:");
	fgets(buf, 10, stdin);
	len = strlen(buf);
	//buf[len] = '\0';
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = 0;

	for (int i = 0; i < len; i++) {
		//printf("%c", buf[i]);
		board[i/3][i%3] = convert(buf[i]);
	}
}
void printBoard(int board[3][3]) {
	char key[3] = {'o', ' ', 'x'};
	printf("\n  Board:\n");
	for (int i = 0; i < 3; i++) {
		printf("  ");
		for (int j = 0; j < 3; j++) {
			printf("%c", key[board[i][j] + 1]);
			if(j != 2)
				printf("|");
		}
		printf("\n");
		if(i != 2)
			printf("  -+-+-\n");
	}

}
int scoreBoard(int board[3][3]) {
	int check = 1;
	int sum;
	for (int y = 0; y < 3; y++) {
		sum = 0;
		for(int x = 0; x < 3; x++) {
			sum += board[y][x];
		}
		if (sum == 3 || sum == -3)
			return check + (sum>0 ? 20 : 30);
		check++;
	}
	for (int x = 0; x < 3; x++) {
		sum = 0;
		for(int y = 0; y < 3; y++) {
			sum += board[y][x];
		}
		if (sum == 3 || sum == -3)
			return check + (sum>0 ? 20 : 30);
		check++;
	}
	sum = board[0][0] + board[1][1] + board[2][2];
	if (sum == 3 || sum == -3)
		return check + (sum>0 ? 20 : 30);
	check++;

	sum = board[0][2] + board[1][1] + board[2][0];
	if (sum == 3 || sum == -3)
		return check + (sum>0 ? 20 : 30);

	return 0;

}
int main(int argc, char *argv[]) {
	printf("Patrick Ambli\n");
	int board[3][3];

	readBoard(board);
	printBoard(board);
	printf("  Current Board State: %d\n", scoreBoard(board));
	return 0;
}

