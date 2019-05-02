#include <stdio.h>
#include <string.h>

int main()
{
	char phrase[50];
	int len, k;
	char c;
	char *ret;

	while ( fgets( phrase, 50, stdin ) != NULL )
	{
		// cut off trailing \n
		len = strlen( phrase ) - 1;
		phrase[len] = '\0';
		// do the work
		printf("There are %d chars in -- %s\n", len, phrase);
	}
	printf("==Done==\n");



	return 0;
}
