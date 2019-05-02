#include<stdio.h>
int main(){
	//printf("\e[0;31m test\n");
	int row = 6;
	int y, x;
	for (y = 0; y < 256; y += 6) {
		for (x = 0; x < 6 && y + x < 256; x++) {
			printf("%3d", x+y);
			printf("\e[48;5;%dm   ", x+y, x+y) ;
			printf("\e[0m  ");
		}
		printf("\n");
	}
	return 0;
}
