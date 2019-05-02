
#include <stdio.h>
#include <stdlib.h>

typedef struct elem_type node;
typedef node *link;

struct  elem_type {
	int data;
	link next;
};

struct header_type {
	link first;
	link last;
	int  len;
};

typedef struct header_type *list;

list makeList();
link makeNode( int x );
int listLength( list front );
void printList( list front );
void insertFront( list first, int num );
int isEmpty( list front );
int isInList( list front, int num );
link getLoc( list front, int num );
int maxVal( list front );
link maxLoc( list front );
void insertBack( list front, int num );
void insertAfter( list front, link loc, int num );
void removeFront( list front );
void removeBack( list front );
void removeThisOne( list front, link loc );
