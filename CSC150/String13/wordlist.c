#include <stdio.h>
#include <string.h>

int main()
{
	char wlist[25][50]; // 25 words, up to 50 in len
	int len, k;
	int w = 0;

	while ( fgets( wlist[w], 50, stdin ) != NULL )
	{
		// cut off trailing \n
		len = strlen( wlist[w] ) - 1;
		wlist[w][len] = '\0';
		// do the work
		printf("There are %d chars in -- %s\n", len, wlist[w]);

		w++;
	}
	printf("==Done==\n");
	printf("%d lines read\n", w);
	for ( k = 0; k < w; ++k )
	{
		printf("%s\n", wlist[k]);
	}



	return 0;
}
