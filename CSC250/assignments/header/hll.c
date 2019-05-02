#include "hll.h"

#define true 1
#define false 0

list makeList() {
	list newList = malloc(sizeof(list));
	newList->first = NULL;
	newList->last  = NULL;
	newList->len   = 0;
	return newList;
}


link makeNode( int x ) {
	link newNode = malloc(sizeof(node));
	newNode->next = NULL;
	newNode->data = x;
	return newNode;
}


int listLength( list L ) {
	return L->len;
}


// this function is good
void printList( list L ) {
	link mov;
	printf("List: [%2d]: ", L->len);
	mov = L->first;
	while ( mov != NULL )
	{
		printf("%2d ", mov->data );
		mov = mov->next;
	}
	printf("\n");
}


void insertFront( list L, int num ) {
	link newNode = makeNode(num);
	newNode->next = L->first;
	L->first = newNode;
	if (L->len == 0)
		L->last = newNode;
	L->len++;
}


// Good
int isEmpty( list front ) {
	if ( front->first == NULL )
		return 1;
	else
		return 0;
}


int isInList( list L, int num ) {
	link step = L->first;
	while (step != NULL) {
		if(step->data == num)
			return true;
		step = step->next;
	}
	return false;
}


link getLoc( list L, int num ) {
	link step = L->first;
	while (step != NULL) {
		if(step->data == num)
			return step;
		step = step->next;
	}
	return NULL;
}


int maxVal( list L ) {
	link step = L->first, max = step;
	while(step != NULL) {
		if (step->data > max->data)
			max = step;
		step = step->next;
	}
	if (max == NULL)
		return 0;
	return max->data;
}


link maxLoc( list L ) {
	link step = L->first, max = step;
	while(step != NULL) {
		if (step->data > max->data)
			max = step;
		step = step->next;
	}
	return max;
}


void insertBack( list L, int num ) {
	link newNode = makeNode(num);
	if (L->last != NULL)
		L->last->next = newNode;
	else
		L->first = newNode;
	L->last = newNode;
	L->len++;
}


void insertAfter( list L, link loc, int num ) {
	link newNode = makeNode(num);

	if(loc->next == NULL) L->last = newNode;
	newNode->next = loc->next;
	loc->next = newNode;
	L->len++;
}


void removeFront( list L ) {
	if(isEmpty(L)) return;

	link removedNode = L->first;
	if(L->len == 1) L->last = NULL;

	L->first = L->first->next;
	free(removedNode);
	L->len--;
}


void removeBack( list L ) {
	if(isEmpty(L)) return;

	link removedNode = L->last;
	if(L->len == 1) {
		L->first = NULL;
		L->last = NULL;
	} else {
		link step = L->first;
		for(int i = 0; i < L->len-2; i++)
			step = step->next;
		L->last = step;
		step->next = NULL;
	}
	free(removedNode);
	L->len--;
}


void removeThisOne( list L, link loc ) {
	if(isEmpty(L)) return;

	link last = NULL;
	if (loc == L->first) {
		L->first = loc->next;
	} else {
		last = L->first;
		while (last->next != loc)
			last = last->next;
		last->next = loc->next;
	}
	if (loc == L->last)
		L->last = last;
	free(loc);
	L->len--;
}




