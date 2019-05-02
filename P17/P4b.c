#include <stdio.h>

#define true 1
#define false 0
int sumrec(int max) {
	if(max == 1)
		return 1;
	return max + sumrec(max-1);
}
int facrec(int max) {
	if(max == 1)
		return 1;
	return max * facrec(max-1);
}
int sumiter(int max) {
	int sum = 0;
	for (int i = 1; i <= max; i++)
		sum += i;
	return sum;

}
int faciter(int max) {
	int fac = 1;
	for (int i = 1; i <= max; i++)
		fac *= i;
	return fac;

}
int main(int argc, char *argv[]) {
	int max;
	printf("Number: ");
	scanf("%d", &max);
	if(max < 1)
		return 0;
	printf("Recursive summation %d\n", sumrec(max));
	printf("Iterative summation %d\n", sumiter(max));
	printf("Recursive factorial %d\n", facrec(max));
	printf("Iterative factorial %d\n", faciter(max));
	return 0;
}

