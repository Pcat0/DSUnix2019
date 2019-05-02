#include "hll.h"

int main()
{
	list AList;
	link here; 
	int k, x;

	AList = makeList();

	for ( k = 0; k < 6; ++k )
	{
		x = rand() % 100;
		insertFront( AList, x );
	}

	while ( AList->first->next )
	{
		removeBack(AList);
	}
	printList(AList);

	return 0;
}
