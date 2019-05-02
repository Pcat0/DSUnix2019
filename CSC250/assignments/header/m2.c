#include "hll.h"

int main()
{
	list AList;
	link here; 
	int k, x;

	AList = makeList();

	for ( k = 0; k < 5; ++k )
	{
		x = rand() % 100;
		insertBack( AList, x );
	}
	insertBack( AList, 84 );
	while ( AList->first->next )
	{
		removeFront(AList);
	}
	printList(AList);

	return 0;
}
