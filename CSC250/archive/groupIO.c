#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

#define true 1
#define false 0
int Min(int a, int b) {
	return (a < b) ? a : b;
}
int Max(int a, int b) {
	return (a > b) ? a : b;
}
int main(int argc, char *argv[]) {
	FILE *inFile = fopen(argv[1], "r");
	FILE *outFile = fopen(argv[2], "w");
	char tOutFName[1000];
	strcpy(tOutFName, argv[2]);
	strcat(tOutFName, ".total");
	FILE *tOutF = fopen(tOutFName, "w");
	int a, b, count, total, min = INT_MAX, max = INT_MIN;
	fscanf(inFile, "%d", &count);
	for (int i = 0; i < count; i++) {
		fscanf(inFile, "%d", &a);
		fscanf(inFile, "%d", &b);
		min = Min(min, Min(a, b));
		max = Max(max, Max(a, b));
		total += a + b;
		fprintf(outFile, "%d + %d = %d\n", a, b, a + b);
	}
	fprintf(tOutF, "count: %d\n", count);
	fprintf(tOutF, "total: %d\n", total);
	fprintf(tOutF, "min: %d\n", min);
	fprintf(tOutF, "max: %d\n", max);
	return 0;
}

