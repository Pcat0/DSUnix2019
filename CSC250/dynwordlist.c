#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char buffer[1000];
	char *wlist[25]; // 25 words
	int len, k;
	int w = 0;

	while ( fgets(buffer, 1000, stdin ) != NULL ) {

		// cut off trailing \n
		len = strlen( buffer ) - 1;
		buffer[len] = '\0';

		//wlist[w] = malloc(sizeof(char) * (len + 1));
		wlist[w] = calloc(len + 1, sizeof(char));
		strcpy(wlist[w], buffer);

		// do the work
		printf("There are %d chars in -- %s\n", len, wlist[w]);

		w++;
	}
	printf("==Done==\n");
	printf("%d lines read\n", w);
	for ( k = 0; k < w; ++k) {
		printf("%s\n", wlist[k]);
	}


	return 0;
}
