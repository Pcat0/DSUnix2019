#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define true 1
#define false 0
int under(int arr[], int len, int num) {
	int count = 0;
	for (int i = 0; i < len; i++)
		if (arr[i] < num)
			count++;
	return count;
}
int main(int argc, char *argv[]) {
	srand(time(NULL));
	char gg[50];
	int nums[20];
	int i, r;
	for (i = 0; i < 10; i++) {
		gg[i] = rand() % 26 + 65;
	}
	gg[i] = '\0';
	printf("%s\n", gg);
	
	i = 0;
	do {
		i++;
		r = rand() % 100 + 1;
	} while (r != 24);

	printf("i = %d\n", i);
	FILE *in = fopen("super.num", "r");
	for (i = 0; i < 20; i++) {
		fscanf(in, "%d", nums[i]);
	}
	r = -99999999999;
	for (i = 0; i < 20l i++)
		if (nums[i] > r)
			r = nums[i];


	return 0;
}

