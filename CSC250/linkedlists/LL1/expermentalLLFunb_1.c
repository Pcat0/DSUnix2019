
// Linked List Assignment #1   Spring 2019
/*
Done:  work on together
ptr makeNode( int )
void printList( ptr )
ptr insertFront( ptr, int )
int listLength( ptr )


More Linked List for you to add
  -  purpose & behavior explained in class

int isEmpty( ptr )            1: if list is empty
int isInList( ptr, int )      1: if val is in list
ptr getLoc( ptr, int )        ptr to location of val
int maxVal( ptr )             largest value
ptr maxLoc( ptr )             location of largest value

ptr insertBack( ptr, int )    add value to end of list

ptr insertAfter( ptr start, ptr loc, int val )
                              add value to list after loc

ptr removeFront( ptr )        delete first item
ptr removeBack( ptr )         delete last item
ptr removeThisOne( ptr start, ptr loc ) delete item at this loc

*/


#include <stdio.h>
#include <stdlib.h>

struct boxtype
{
	int val;
	struct boxtype *link;
};

void next(struct boxtype **node) {
	if(node != NULL && *node != NULL) {
		*node = (*node)->link;
	}
}

struct boxtype *makeNode( int x ) {
	struct boxtype *tmp;
	tmp = malloc( sizeof(struct boxtype) );
	tmp->val = x;
	tmp->link = NULL;
	return tmp;
}


int listLength( struct boxtype *front ) {
	int count = 0;
	struct boxtype *step = front;
	while (step != NULL) {
		count++;
		next(&step);
	}
	return count;
}


void printList( struct boxtype *front ) {
	printf("List: ");
	for(struct boxtype *step = front; step != NULL; next(&step)) {
		printf("%d ", step->val);
	}
	printf("\n");
}


void insertFront( struct boxtype **list, int num ) {
	struct boxtype *newNode;

	newNode = makeNode(num);
	newNode->link = *list;
	*list = newNode;

}


int main()
{

	struct boxtype *b, *start;
	int i, x;

	start = NULL;

	printf("%d ", listLength(start));
	printList(start);

	insertFront(&start, 4);
	insertFront(&start, 3);
	insertFront(&start, 2);
	insertFront(&start, 1);

	printf("%d ", listLength(start));
	printList(start);

	/*
	for ( i = 0; i < 10; ++i )
	{
		x = rand() % 100;
		if ( x % 2 == 0 )
			start = insertFront( start, x );
		else
			start = insertBack( start, x );
		printList( start );
	}
	printf("Len %d\n", listLength( start ) );


	while ( !isEmpty( start ) )
	{
		x = start->val;
		printf("%d\n", x);
		start = removeFront( start );
		printList( start );
	}


	while ( !isEmpty( start ) )
	{
		start = removeBack( start );
		printList( start );
	}


	int mv;
	struct boxtype *ml;
	while ( !isEmpty( start ) )
	{
		mv = maxVal( start );
		ml = maxLoc( start );
		printf("big  %d\n", mv );
		start = removeThisOne( start, ml );
		printList( start );
	}
	/**/
	return 0;
}
