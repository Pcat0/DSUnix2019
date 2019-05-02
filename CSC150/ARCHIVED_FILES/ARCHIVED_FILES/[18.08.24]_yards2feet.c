#include<stdio.h>
int main() {
	int yd, ft;

	printf("Yards:");

	//REMBER THE &!
	scanf("%d", &yd);
	ft = yd*3;

	printf("%d yards is %d feet.\n", yd , ft);
	return 0;
}
