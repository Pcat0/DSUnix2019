#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

#define true 1
#define false 0

#define SLENGTH 30
#define LLENGTH 100
void printArr(char arr[LLENGTH][SLENGTH], int len) {
	for(int i = 0; i < len; i++)
		printf(arr[i]);
}
void sortStr(char arr[LLENGTH][SLENGTH], int len) {
	char temp[SLENGTH];
	int sm;
	for (int i = 0; i < len; i++) {
		sm = i;
		for (int j = i; j < len; j++)
			if (strcmp(arr[j], arr[sm]) < 0)
				sm = j;
		strcpy(temp, arr[i]);
		strcpy(arr[i], arr[sm]);
		strcpy(arr[sm], temp);
	}

}
int countChar(char str[], char c) {
	int len = strlen(str);
	int count = 0;
	c = tolower(c);
	for (int i = 0; i < len; i++)
		if (tolower(str[i]) == c)
			count++;
	return count;

}
int main(int argc, char *argv[]) {
	char list[LLENGTH][SLENGTH];
	char tempStr[SLENGTH];
	int rCount = 0;
	int len = 0;

	FILE *inFile, *outFile;
	inFile = fopen(argv[1], "r");
	outFile = fopen(argv[2], "w");

	if(inFile == NULL) {
		printf("ERR: Can't find input file (%s)\nQuitting...\n", argv[1]);
		return 1;
	}
	if(outFile == NULL) {
		printf("ERR: Can't find output file (%s)\nQuitting...\n", argv[2]);
		return 1;
	}
	while (fgets(tempStr, SLENGTH, inFile) != NULL) {
		len++;
		strcpy(list[len - 1], tempStr);
	}
	//printArr(list, len);
	//printf("----------\n");
	sortStr(list, len);
	for(int i = 0; i < len; i++){
		rCount += countChar(list[i], 'r');
		fprintf(outFile, "%d) %s", i, list[i]);
	}
	//printArr(list, len);
	printf("Word count: %d\n", len);
	printf("\"R\" count: %d\n", rCount);
	printf("First word: %s", list[0]);
	printf("Last word: %s\n", list[len-1]);
	//printf(list[0]);
	return 0;
}

