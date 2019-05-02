#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void rept(int c, char s){
	int newLine = (c >= 0); //will not print newline if c is negative
	c = abs(c);
	for (int i = 0; i < c; i++)
		printf("%c", s);
	if (newLine)
		printf("\n");
}
void boxHelper(char edge, char mid, int len) {
	printf("%c", edge);
	if (len >= 3)
		rept(-(len - 2), mid); //negative length to stop newline from being printed;
	if (len >= 2)
		printf("%c", edge);
	printf("\n");

}
void box(int h, int w) {
	boxHelper('+', '-', w);
	for (int y = 0; y < h - 2; y++)
		boxHelper('|', ' ', w);
	if(h >= 2)
		boxHelper('+', '-', w);
}
void utri(int h) {
	for (int i = 1; i <= h; i++)
		rept(i, '*');
}
void dtri(int h) {
	for (int i = h; i > 0; i--)
		rept(i, '*');

}
void barChart(int n, int min, int max) { //min and max are inclusive.
	int rNum;
	for (int y = 0; y < n; y++){
		rNum = rand() % (max - min + 1) + min;
		printf("%2d  ", rNum);
		rept(rNum, rNum % 2 ? '=' : '@');
	}
}
int main(){
	srand(6);  // use srand(6) in sample output
        rept(20, '#');
        barChart(9, 2, 11);
        rept(20, '-');
        barChart(4, 10, 15);
        rept(20, '-');
        box(3, 3);
        rept(20, '-');
        box(5, 7);
        rept(20, '-');
        utri(3);
        rept(20, '-');
        utri(5);
        rept(20, '-');
        dtri(3);
        rept(20, '-');
        dtri(5);
        rept(20, '#');

        return 0;
}

