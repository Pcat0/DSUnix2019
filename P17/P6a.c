#include <stdio.h>

int charToNum(char c) {
    if('0' <= c && c <= '9') {
        return c - 48;
    } else {
        return 10;
    }
}

int bowlingScore(char *str) {
	int score = 0;
	int i = 0;
	for (int frame = 0; frame < 10; frame++) {
		int subscore = 0;
		if (str[i] == 'x' || str[i] == 'X') {
			if(str[i + 2] != '/'){
				score += 10 + charToNum(str[i + 1]) + charToNum(str[i + 2]);
			} else {
				score += 20;
			}
			i++;
		} else {
			subscore = charToNum(str[i]);
			i++;
			if(str[i] == '/') {
				score += 10 + charToNum(str[i+1]);
			} else {
				score += subscore + charToNum(str[i]);
			}
			i++;
		}
	}
	return score;
}

int main(int argc, char *argv[]) {
	char game[30];
	scanf("%s", game);
	printf("%d\n", bowlingScore(game));
	return 0;
}

