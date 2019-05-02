#include <stdio.h>
int main() {
	int h;
	printf("Height: ");
	scanf("%d", &h);
	for(int y = 0; y < h; y++){
		for(int i = 0; i < h - y; i++)
			printf(" ");
		for(int i = 0; i < (y*2+1); i++)
			printf("#");
		printf("\n");
	}
	for(int i = 0; i < h; i++)
		printf(" ");
	printf("#\n");
	return 0;
}

