#include <stdio.h>
int main(){
	int count = -1, minors = 0, retired = 0, age = 0;
	while (age >= 0 ) {
		count++;
		printf("Enter a age: ");
		scanf("%d", &age);
		if (0 <= age && age < 19)
			minors++;
		if (age >= 65)
			retired++;
	}
	printf("You entered:\n");
	printf("	%d age(s).\n", count);
	printf("	%d minor(s).\n", minors);
	printf("	%d ritired(s).\n", retired);

	return 0;
}

