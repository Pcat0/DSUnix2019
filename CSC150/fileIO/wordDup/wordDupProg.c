#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_LINE_COUNT 750
#define MAX_LINE_LEN 50
int main(){
	char wList[MAX_LINE_COUNT][MAX_LINE_LEN];
	int w = -1, len;
	int longestLen = (int)-INFINITY, longestPos;
	int maxPos = -1;
	int dupPos = -1;
	while (fgets(wList[++w], 50, stdin) != NULL) {
		len = strlen(wList[w]) - 1;
		wList[w][len] = '\0';

		if(len > longestLen) {
			longestLen = len;
			longestPos = w;
		}
		if (maxPos == -1 || strcmp(wList[w], wList[maxPos]) == 1) {
			maxPos = w;
		}
		for (int j = 0; j < w && dupPos == -1; j++)
			if(!strcmp(wList[w], wList[j]))
				dupPos = w;
		printf("%s\n", wList[w]);
	}
	printf("The longest word is \e[3m%s\e[0m with a length of \033[3m%d\033[0m\n.", wList[longestPos], longestLen);
	printf("The \"Max\" word is: \033[3m%s\033[0m.\n", wList[maxPos]);
	if (dupPos == -1) {
		printf("The list is completely unique, no duplicates.");
	} else {
		printf("The first duplicate is \033[3m%s\033[0m at index \033m[3m%d\033[0m.", wList[dupPos], dupPos);
	}
	printf("The first value of the is list is \033[3m%s\033[0m", wList[0]);
	return 0;
}
