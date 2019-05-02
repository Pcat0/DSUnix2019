
// Linked List Assignment #1   Spring 2019
/*
DONE:  work on together
X	ptr makeNode( int )
X	void printList( ptr )
X	ptr insertFront( ptr, int )
X	int listLength( ptr )


More Linked List for you to add
  -  purpose & behavior explained in class

X	int isEmpty( ptr )            1: if list is empty
X	int isInList( ptr, int )      1: if val is in list
X	ptr getLoc( ptr, int )        ptr to location of val
X	int maxVal( ptr )             largest value
X	ptr maxLoc( ptr )             location of largest value

X	ptr insertBack( ptr, int )    add value to end of list

X	ptr insertAfter( ptr start, ptr loc, int val )
	                              add value to list after loc

X	ptr removeFront( ptr )        delete first item
X	ptr removeBack( ptr )         delete last item
_ 	ptr removeThisOne( ptr start, ptr loc ) delete item at this loc

*/


#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0


/*-------+
|  LIST  |
+-------*/
struct boxtype
{
	int val;
	struct boxtype *link;
};

struct boxtype *makeNode( int x ) {
	struct boxtype *tmp;
	tmp = malloc( sizeof(struct boxtype) );
	tmp->val = x;
	tmp->link = NULL;
	return tmp;
}

/*--------+
|  PRINT  |
+--------*/
void printList( struct boxtype *front ) {
	//printf("List: ");
	for(struct boxtype *step = front; step != NULL; step=step->link) {
		printf("%d ", step->val);
	}
	printf("\n");
}


/*----------+
|  UTILITY  |
+----------*/
int listLength( struct boxtype *front ) {
	int count = 0;
	struct boxtype *step = front;
	while (step != NULL) {
		count++;
		step=step->link;
	}
	return count;
}
int isEmpty( struct boxtype *list ) {
	return (list == NULL);
}
int isInList( struct boxtype *list, int val ) {
	for (struct boxtype *step=list; step!=NULL; step=step->link)
		if(step->val == val)
			return true;
	return false;
}
struct boxtype *getLoc( struct boxtype *list, int val ) {
	struct boxtype *loc = NULL;
	for (struct boxtype *step=list; step!=NULL; step=step->link){
		if (step->val == val) {
			loc = step;
			break;
		}
	}
	return loc;
}
int maxVal(struct boxtype *list) {
	struct boxtype *step = list;
	int max = step->val;
	while (step != NULL) {
		if (max < step->val)
			max = step->val;
		step = step->link;
	}
	return max;
}
struct boxtype *maxLoc( struct boxtype *list) {
	struct boxtype *step = list,
					*max = list;
	while (step != NULL) {
		if(max->val < step->val)
			max = step;
		step = step->link;
	}
	return max;
}


/*---------+
|  INSERT  |
+---------*/
struct boxtype *insertFront( struct boxtype *first, int num ) {
	struct boxtype *newNode;

	newNode = makeNode(num);
	newNode->link = first;

	return newNode;
}
struct boxtype *insertBack(struct boxtype *first, int num) {
	struct boxtype *step, *newNode;
	newNode = makeNode(num);
	if(!isEmpty(first)){
		step = first;
		while(step->link != NULL)
			step = step->link;
		step->link = newNode;
	} else {
		first = newNode;
	}
	return first;
}
struct boxtype *insertAfter(struct boxtype *first, struct boxtype *loc, int num) {
	struct boxtype *newNode;
	newNode = makeNode( num );
	newNode->link = loc->link;
	loc->link = newNode;
	return first;
}


/*---------+
|  REMOVE  |
+---------*/
struct boxtype *removeFront(struct boxtype *first) {
	struct boxtype *tail;
	if (!isEmpty(first)){
		tail = first->link;
		first = tail;
	}
	return first;
}
struct boxtype *removeBack(struct boxtype *first) {
	struct boxtype *step, *lastStep;
	if(!isEmpty(first) && first->link != NULL) {
		step = first;
		lastStep = NULL;
		while (step->link != NULL) {
			lastStep = step;
			step = step->link;
		}
		lastStep->link = NULL;
	} else {
		first = NULL;
	}
	return first;
}
struct boxtype *removeThisOne(struct boxtype *first, struct boxtype *loc) {
	struct boxtype *tail, *step, *leader;
	leader = makeNode(0);
	leader->link = first;
	step = leader;
	while (step->link != loc) {
		step = step->link;
	}
	tail = step->link->link;
	step->link = tail;

	first = leader->link;
	return first;

}
int main() {

	struct boxtype *b, *start;
	int i, x;

	start = NULL;

	/*
	printf("%d ", listLength(start));
	printList(start);

	start = insertBack(start, 5);
	start = insertBack(start, 7);
	start = insertBack(start, 8);
	start = insertFront(start, 4);
	b = getLoc(start, 5);
	start = insertAfter(start, b, 6);
	start = insertBack(start, 9);
	printList(start);

	start = removeFront(start);
	printf("Remove front:\n");
	printList(start);

	start = removeBack(start);
	printf("Remove back:\n");
	printList(start);

	start = removeThisOne(start, b);
	printf("Remove b:\n");
	printList(start);
	//printf("max: %d\nNext Value: %d\n", b->val, b->link->val);
	//printList(start);
	*/
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
