// Linked List program 1
//  - allocate a node
//  - attach to list
//  - print list
// Together
//  - add another node; and another
//  - find sum of items in list
//  - insert an item at the end

#include <stdio.h>
#include <stdlib.h>

struct boxtype
{
	int val;
	struct boxtype *link;
};


int main()
{
	struct boxtype *start, *b;

	start = malloc( sizeof( struct boxtype ) );
	start->val = 12;
	start->link = NULL;

	b = malloc( sizeof( struct boxtype ) );
	b->val = 5;
	b->link = start;
	start = b;

	// stuff happens

	b = start;
	while ( b != NULL )
	{
		printf("%2d ", b->val);	
		b = b->link;
	}
	printf("\n");

	return 0;
}


