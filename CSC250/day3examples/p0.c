#include <stdio.h>
#include <string.h>

int main()
{
	char s[20], t[20];
	int n;

	printf("Enter word: ");
//	scanf("%s", s);
	fgets(s,20,stdin);
	n = strlen( s );
	n--;
	s[n] = '\0';


	printf("Entered: -->%s<--\n", s);

	return 0;
}
