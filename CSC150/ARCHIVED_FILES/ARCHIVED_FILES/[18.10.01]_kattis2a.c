#include <stdio.h>
int main(){
	int num, count=0, temp;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &temp);
		count += temp < 0;
	}
	printf("%d\n", count);
	return 0;
}

