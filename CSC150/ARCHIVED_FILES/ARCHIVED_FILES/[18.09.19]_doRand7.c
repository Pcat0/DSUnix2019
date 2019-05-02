#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int num, i;
	i = 0;
	srand(time(NULL));
 	do {
		num = rand() % 10 + 1;
		printf("%d) %d\n", i, num);
		i++;
	} while (num != 7);
	printf("7 was found, after %d times.\n", i);
	return 0;
}

