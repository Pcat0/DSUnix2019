#include<stdio.h>
int main() {
	int n;
	printf("Value: ");
	scanf("%d", &n);
	if (n < 13) {
		printf("no\n");
	} else if(n <= 19) {
		printf("yes\n");
	} else {
		printf("no\n");
	}

}
