#include <stdio.h>
#include <stdlib.h>

int main(){
	srand(11);
	int c1 = 0, c2 = 0, c3 = 0, c4 = 0, r;
	for (int i = 0; i < 10; i++){
		r = rand() % 4 + 1;
		printf("%d ", r);
		switch(r){
			case 1:
				c1++;
				break;
			case 2:
                                c2++;
                                break;
			case 3:
                                c3++;
                                break;
			case 4:
                                c4++;
                                break;

		}
	}

	printf("\n1) %d\n2) %d\n3) %d\n4) %d\n", c1, c2, c3, c4);
	return 0;
}

