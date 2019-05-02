#include <stdio.h>
int main(){
	int limit, sum = 0, current = 1;
	printf("what number you you like to count to? ");
	scanf("%d", &limit);
	printf("Using a while loop:\n	");
	while (current <= limit) {
		sum += current;
		printf("%d ", current);
		current += 3;
	}
	printf("\n	The sum is: %d\n", sum);

	printf("Using a for loop:\n	");
	sum = 0;
	for(current = 1; current <= limit; current += 3) {
		sum += current;
		printf("%d ", current);
	}
	printf("\n	The sum is: %d\n", sum);
	return 0;
}

