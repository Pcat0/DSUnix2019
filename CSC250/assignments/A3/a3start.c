#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define true 1
#define false 0

#define MAXLENGTH 100

int manyUpper( char s[] ) {
	int count = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		if('A' <= s[i] && s[i] <= 'Z')
			count++;
	return count;

}
int manyDigit( char s[] ) {
	int count = 0;
	int len = strlen(s);
	for(int i = 0; i < len; i++)
		if('0' <= s[i] && s[i] <= '9')
			count++;
	return count;

}


int main( int argc, char *argv[] ) {
    char line[MAXLENGTH], longLine[MAXLENGTH], shortLine[MAXLENGTH];
    int lineNum = 0, longIndex, shortIndex, upperIndex, digitIndex;
	int longCount = 0, shortCount = MAXLENGTH + 1, upperCount = 0, digitCount = 0;
    FILE *infp; // please read file in main; not in functions
	infp = fopen(argv[1], "r");

	if (infp == NULL) {
		printf("ERR: Can not fine file at %s.\n", argv[1]);
		return 1;
	}
	while (fgets(line, MAXLENGTH, infp) != NULL) {
		lineNum++;
		int len = strlen(line);
		int upper = manyUpper(line);
		int digit = manyDigit(line);

		if (len > longCount){
			strcpy(longLine, line);
			longLine[len - 1] = '\0';
			longCount = len;
			longIndex = lineNum;
		}
		if (len < shortCount) {
			strcpy(shortLine, line);
			shortLine[len - 1] = '\0';
			shortCount = len;
			shortIndex = lineNum;
		}
		if (upper > upperCount) {
			upperCount = upper;
			upperIndex = lineNum;
		}
		if (digit > digitCount) {
			digitCount = digit;
			digitIndex = lineNum;
		}
	}
	printf("  Longest line [ %d & %s ]\n", longIndex, longLine);
	printf("  Shortest line [ %d & %s ]\n", shortIndex, shortLine);
	printf("  Most uppercase [ %d & %d ]\n", upperIndex, upperCount);
	printf("  Most digit [ %d & %d ]\n", digitIndex, digitCount);
    return 0;
}

