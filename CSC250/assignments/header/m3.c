#include "hll.h"

int main()
{
	list AList;
	link here; 
	int k, x;

	AList = makeList();

	insertFront( AList, 79 );	
	here = AList->last;

	for ( k = 0; k < 5; ++k )
	{
		x = rand() % 100;
		insertAfter( AList, here, x );
	}

	while ( AList->first->next != NULL )
	{
		here = AList->first->next;
		removeThisOne(AList,here);	
	}
	printList(AList);

	return 0;
}
