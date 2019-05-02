#include <stdio.h>
#include <string.h>

int main()
{
	char phrase[50];
	int len, k;
	char c;
	char *ret;

	printf("Type in a line: ");
	ret = fgets( phrase, 50, stdin );

	while ( ret != NULL )
	{
		// cut off trailing \n
		len = strlen( phrase ) - 1;
		phrase[len] = '\0';
		printf("There are %d chars in -- %s\n", len, phrase);

		printf("Type in a line: ");
		ret = fgets( phrase, 50, stdin );
	}
	printf("==Done==\n");



	return 0;
}
