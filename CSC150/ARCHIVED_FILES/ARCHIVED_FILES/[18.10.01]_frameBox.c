#include <stdio.h>
int main(){
	int xMax, yMax;
	printf("Width: ");
	scanf("%d", &xMax);
	printf("Height: ");
	scanf("%d", &yMax);
	for(int y = 0; y < yMax; y++) {
		for(int x = 0; x < xMax; x++) {
			printf((x == 0 || y == 0 || x == xMax-1 || y == yMax - 1) ? "@" : "-");
		}
		printf("\n");
	}
	return 0;
}

