#include<stdio.h>
int main(){
	int smallCarton, largeCarton, totalCarton, smallCount, largeCount, totalCount;

	printf("\e[1;1H\e[2J");

	printf("How many \e[38;5;1mtwelve egg\e[0m count cartons do you want to buy? \e[38;5;2m");
	scanf("%d", &smallCarton);
	printf("\e[0m\e[1;1H\e[2J");
	printf("How many \e[38;5;1meighteen egg\e[0m count cartons do you want to buy? \e[38;5;2m");
	scanf("%d", &largeCarton);
	printf("\e[0m\e[1;1H\e[2J");

	totalCarton = smallCarton + largeCarton;

	smallCount = smallCarton * 12;
	largeCount = largeCarton * 18;
	totalCount = smallCount + largeCount;

	printf("You will have \e[38;5;1m%d eggs\e[0m in your %d \e[38;5;1mtwelve egg count\e[0m cartons.\n", smallCount, smallCarton);
	printf("You will have \e[38;5;1m%d eggs\e[0m in your %d \e[38;5;1meighteen egg count\e[0m cartons.\n", largeCount, largeCarton);
	printf("\n");
	printf("In \e[38;5;1mtotal\e[0m you will have \e[38;5;1m%d eggs\e[0m in your total of %d egg cartons.\n", totalCount, totalCarton);
}
