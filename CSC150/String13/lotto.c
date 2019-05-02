#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void noRepeatRand(int values[], int count, int min, int max){
	int flage = 1;
	for (int i = 0; i < count; i++){
		int newValue;
		do{
			flage = 0;
			newValue = rand() % (max - min + 1) + min;
			for (int a = 0; a < i; a++){
				if (newValue == values[a]) {
					flage = 1;
					break;
				}
			}
		} while(flage);
		values[i] = newValue;
	}
}
void printIntArray(int array[], int len){
	for (int i = 0; i < len; i++)
		printf("%2d,", array[i]);
	printf("\n");
}
int main(){
	srand(time(NULL));
	int lottoValues[3];
	for (int i = 0; i < 20; i++){
		noRepeatRand(lottoValues, 3, 1, 25);
		printIntArray(lottoValues, 3);
	}
	return 0;
}

