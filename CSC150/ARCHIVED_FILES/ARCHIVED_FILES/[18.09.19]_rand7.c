#include <stdio.h>
#include <stdlib.h>
int main(){
	int i = 0, num = 0;
 	while (num != 7) {
		num = rand() % 10 + 1;
		printf("%d\n", num);
		i++;
	}
	printf("--%d--\n", i);
	return 0;
}

