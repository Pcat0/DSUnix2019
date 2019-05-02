#include<stdio.h>
int main() {
	int r, sp, sa;
	float pi, cp, ca;

	pi = 3.14;

	printf("Value: ");
	scanf("%d", &r);

	cp = 2 * pi * r;
	ca = pi * r * r;
	sp = r * 4;
	sa = r * r;
	printf("circle:\n	Area-%.2f\n	Perimeter-%.2f\n", ca, cp);
	printf("square:\n	Area-%.2d\n	Perimeter-%.2d\n", sp, sa);



}
