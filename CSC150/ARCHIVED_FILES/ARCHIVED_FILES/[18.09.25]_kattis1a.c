#include <stdio.h>
int main(){
	int X, N, Pi, Pl = 0;
	scanf("%d", &X);
	scanf("%d", &N);
	Pl = X * (N + 1);
	for(int i = 0; i < N; i++) {
		scanf("%d", &Pi);
		Pl -= Pi;
	}
	printf("%d\n", Pl);
	return 0;
}

