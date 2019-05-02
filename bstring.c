//remove
#include<stdio.h>




#include<string.h>
#include<stdlib.h>

char *bstr(int len) {
	return calloc(sizeof(char), len);
}

char *bstrcat(char *a, char *b){
	int i, lenA = strlen(a), lenB = strlen(b);
	char *out = malloc(sizeof(char) * (lenA + lenB + 1));
	for(i = 0; i < lenA; i++)
		out[i] = a[i];
	for(i = 0; i < lenB; i++)
		out[lenA + i] = b[i];
	out[lenA + lenB] = '\0';
	return out;
}





int main() {
	printf(bstrcat("123 ", "abc\n"));

	return 0;
}
