#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randomInt(int min, int max){
	return rand() % (max - min + 1) + min;
}
int *range(int start, int end, int step){
	int count = (start - end) / step;
	int out[count];
	for(int i = 0; i < count; i++)
		out[i] = start+count*step;
}
void printArray(int arr[], int len) {
	for(int i = 0; i < len; i++)
        printf("%d ", arr[i]);
	printf("\n");
}

int Max(int arr[], int len) {
	int max = arr[0];
	for (int i = 1; i < len; i++) max = (max > arr[i]) ? max : arr[i];
	return max;
}
int Min(int arr[], int len) {
    int min = arr[0];
    for (int i = 1; i < len; i++) min = (min < arr[i]) ? min : arr[i];
    return min;
}
int Sum(int arr[], int len) {
    int accum = arr[0];
    for (int i = 1; i < len; i++) accum += arr[i];
    return accum;
}
void fillArray(int arr[], int max, int len) {
    for (int i = 0; i < len; i++) arr[i] = randomInt(1, max);
}
int countUnder(int arr[], int len, int top) {
	int count = 0;
	for (int i = 0; i < len; i++)
		if(arr[i] < top)
			count++;
	return count;
}
int search(int arr[], int v, int len) {
	for (int i = 0; i <= len; i++)
		if(arr[i] == v)
			return 1;
	return 0;

}





int main(){
	int length = 70;
	int A[length];//range(0, 5, 1);

	srand(2929);

	fillArray(A, 20, length);
	printArray(A, length);
	printf("Max: %d\n", Max(A, length));
	printf("Min: %d\n", Min(A, length));
	printf("Sum: %d\n", Sum(A, length));
	printf("%d values under %s", countUnder(A, length, 3), 3)
	printf("",)

	return 0;
}
