#include <stdio.h>
#include <math.h>

int main(){
	int count, sum = 0, max = (int)-INFINITY, dup, dupPos = -1, num;
	scanf("%d", &count);
	int numbers[count];

	for (int i = 0; i < count; i++) {
		scanf("%d", &num);
		numbers[i] = num;
		if(num > max)
			max = num;
		sum += num;
		for (int j = 0; j < i && dupPos == -1; j++){
			if (numbers[j] == num){
				dup = num;
				dupPos = i;
			}
		}
	}
	printf("Length: %d\n", count);
	printf("Sum: %d\n", sum);
	printf("Max: %d\n", max);
	if (dupPos == -1) {
		printf("There are no duplicates\n");
	} else {
		printf("The number \"%d\" is duplicated at position %d\n", dup, dupPos);
	}
	printf("The first number was: %d\n", numbers[0]);
	return 0;
}

