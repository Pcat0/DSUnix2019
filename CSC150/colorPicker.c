#include<stdio.h>

#define clear printf("\e[H\e[J"

#define gotoxy(x, y) printf("\e[%d;%dH", (x), (y))
#define movexy(x, y) printf("\e[%dC\e[%dA", x, y)

#define up(x) printf("\e[%dA", x)
#define down(x) printf("\e[%dB", x)
#define right(x) printf("\e[%dC", x)
#define left(x) printf("\e[%dD", x)

void drawColorCubeLayer(int layerIndex){

}
int main(){
	gotoxy(10, 10);
	printf("test");

	return 0;
}

