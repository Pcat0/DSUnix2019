#include "hll.h"

int main() {


	list AList;
	link here;
	int k, x;

	AList = makeList();
	for ( k = 0; k < 14; ++k ) {
		x = rand() % 100;
		if ( k == 7 )
			insertBack( AList, 11 );
		if ( k == 8 )
			insertBack( AList, 9);
		insertBack( AList, x );
	}

	while ( AList->first->next != NULL )
	{
		here = maxLoc( AList );
		removeThisOne(AList,here);
	}
	printList(AList);

	return 0;
}
