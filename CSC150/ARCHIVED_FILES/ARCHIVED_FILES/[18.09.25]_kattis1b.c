#include <stdio.h>
int main(){
	int P, K = 0, N, Nsqu;
	scanf("%d", &P);
	printf("\n");
	while (K < P) {
	//for (int i = 0; i < P; i++) {
		scanf("%d%d", &K, &N);
		Nsqu = N * N;
		printf("%d %d %d %d\n", K,
			(Nsqu + N) / 2,
			(Nsqu),
			(Nsqu + N)
		);
	}
	return 0;
}

