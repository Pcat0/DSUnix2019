#include <stdio.h>

int main()
{
	int x, y;
	int *m;

	printf("----------------------------------\n");
	x = 19;
	y = 88;
	printf("X is %d\n", x);
	printf("Address of X is    %p\n", &x);

	printf("-- Change value pointed to by M --\n");


	m = &x;
	printf("M contains address %p\n", m);
	printf("M points to value %d\n", *m);
	return 0;
	printf("----------------------------------\n");
	x = 77;
	printf("X is %d\n", x);
	printf("Address of X is    %p\n", &x);
	printf("M contains address %p\n", m);
	printf("M points to value %d\n", *m);
	printf("-- Change value pointed to by M --\n");
	*m = 33;
	printf("M points to value %d\n", *m);
	printf("X is %d\n", x);
	printf("\n");
	printf("----------------------------------\n");
	printf("Y is still %d\n", y);
	printf("Address of Y is    %p\n", &y);
	m = &y;
	printf("Point m at y \n");
	printf("M contains address %p\n", m);
	printf("M points to value %d\n", *m);
	*m = 7;
	printf("M points to value %d\n", *m);
	printf("Y is now %d\n", y);
	printf("----------------------------------\n");
	return 0;
}
