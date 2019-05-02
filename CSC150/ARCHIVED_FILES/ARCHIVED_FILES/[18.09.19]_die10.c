#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int count, d;
	srand(time(NULL));
	for (int i = 0; i < 10; i++) {
		d = rand() % 6 + 1;
		printf("%d ", d);
		if (d == 4)
			count++;
	}
	printf("\n%d 4s in the list\n", count);
	return 0;
}

