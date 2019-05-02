#include<stdio.h>
int main() {
	int gal, pt, qt;

	printf("How many gallons: ");
	scanf("%d", &gal);

	pt = gal * 8;
	qt = gal * 4;

	printf("%d gallons is %d pints.\n", gal, pt);
	printf("%d gallons is %d quarts.\n", gal, qt);
	return 0;
}
