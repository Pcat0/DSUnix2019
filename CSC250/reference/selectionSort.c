#include <stdio.h>
#include <stdlib.h>
#define LEN 5

void printArr(int arr[], int len) {
	for(int i = 0; i < len; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void SelectionSort(int arr[], int len) {
	for(int i = len; i > 0; i--) {
		int lg = i;
		for(int j = 0; j < i; j++) {
			if(arr[j] >= arr[lg]) {
				lg = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[lg];
		arr[lg] = temp;
		printArr(arr, len);
	}

}

int main(){
	srand(42);
	int list[LEN];
	for (int i = 0; i <= LEN; i++)
		list[i] = rand() % 10;
	printArr(list, LEN);
	printf("----------------\n");
	SelectionSort(list, LEN);
	printf("----------------\n");
	printArr(list, LEN);
	return 0;
}

