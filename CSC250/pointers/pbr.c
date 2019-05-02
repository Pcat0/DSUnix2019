#include <stdio.h>

void pbv( int num )
{
	printf("  PBV num %d\n", num);
	num = 33;
	printf("  PBV num %d\n", num);
}

void pbr( int *num )
{
	printf("  PBR num %d\n", *num);
	*num = 99;
	printf("  PBR num %d\n", *num);
}

int main()
{
	int x;
	printf("==== PBV Example ====\n");
	x = 11;
	printf("Main 1  %d\n", x);
	pbv( x );
	printf("Main 2  %d\n", x);
	printf("==== PBR Example ====\n");
	x = 77;
	printf("Main 3  %d\n", x);
	pbr( &x );
	printf("Main 4  %d\n", x);

	return 0;
}






