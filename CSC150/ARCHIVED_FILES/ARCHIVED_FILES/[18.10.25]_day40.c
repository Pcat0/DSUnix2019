#include <stdio.h>
void countBetween(int start, int end){
	int sign = (end - start > 0) - (end - start < 0);
	for(int i = start; i * sign <= end * sign; i += sign)
		printf("%d ", i);
	printf("\n");
}
int isVowel(char c){
	char vowels = {'a', 'e', 'i', 'o', 'u'};
	int flag = 0;
	for (int i=0; i<5; i++)
		flag = flag || c == vowels[i];
}

int main(){
	countBetween(3,7);
	countBetween(7,3);
	printf()
	return 0;
}
