
#include "hll.h"

int main() {
	list AList;
	int k, x;

	AList = makeList();

	insertFront( AList, 12 );
	printList( AList );
	printf("Len %d\n", listLength( AList ) );

	for ( k = 0; k < 5; ++k )
	{
		x = rand() % 100;
		printf("Adding %d\n", x);
		insertFront( AList, x );
	}

	printList( AList );

	return 0;
}
