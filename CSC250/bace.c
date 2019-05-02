#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N   20
#define Max 50

#define true 1
#define false 0

int linSearch( int L[], int sz, int val ) {
	for (int i = 0; i <= sz; i++) {
		if (L[i] == val)
			return true;
	}
	return false;

}
void bubbleSort( int L[], int sz) {
	int cmp = 0;
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < sz - 1; j++) {
			cmp++;
			if (L[j] > L[j+1]) {
				L[j] = L[j] ^ L[j+1];
				L[j+1]=L[j] ^ L[j+1];
				L[j] = L[j] ^ L[j+1];
			}
		}
	}
	printf("cmp: %d\n", cmp);
}
int main() {
	int A[ N ];
	int i, j, temp;

	srand(43);

	for (i = 0; i < N; ++i)
		A[i] = rand() % Max + 1;

	for (i = 0; i < N; ++i)
		printf("%2d ", A[i]);

	printf("\n");
	// great stuff
	printf("\n---- suspense ----\n\n");

	bubbleSort(A, N);

	for (i = 0; i < N; ++i)
		printf("%2d ", A[i]);
	printf("\n");

	return 0;
}
