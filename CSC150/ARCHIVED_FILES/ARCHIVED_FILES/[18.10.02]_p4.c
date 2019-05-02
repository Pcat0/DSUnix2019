#include <stdio.h>
#include <stdlib.h>

int main(){
	int seed = 0, N = 0, a = 0, b = 0, pairs = 0, sums = 0;
	printf("Seed: ");
	scanf("%d", &seed);
	printf("Rolls: ");
	scanf("%d", &N);

	srand(seed);

	for(int i = 0; i < N; i++){
		a = rand() % 10 + 1;
		b = rand() % 10 + 1;
		if (N <= 10)
			printf("%2d %2d\n", a, b);
		if (a == b)
			pairs++;
		if (a + b == 15)
			sums++;
	}
	printf("pairs: %d\n", pairs);
	printf("sum 15: %d\n", sums);
	return 0;
}

