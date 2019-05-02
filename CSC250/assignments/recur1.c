// Assignment: Intro to recursion
// due: Monday 4/8  7am
// submit each of the 4 functions to RecQ D2L quiz

// Description & rules:
/*
 You are presented with 2 problems
  a) determine if a positive integer value is even or odd
  b) find the sum of values in a linked list

 You will solve each problem twice
  a)  Iterative:  use a loop
  b)  Recursive:  use recursion; no loops allowed

 You also have to provide a clear explanation of the base case
   and how you break the problem down to move toward base.

 Function prototypes are presented below.  A sample main is also
 provided. But your funcitons should work for all cases not just
 those presented in this sample.


 Additional key details about the problems.

 Determine even or odd:
 - you are NOT allowed to use / % * operations.   Only + and -.
     - this is a key requirement; think about how to make it work
 - return 'e' for even and 'o' for odd.


 List sum:
 - very basic list if build int main().  Rememeber that it should
    be possible to change that construction and build a different list.
 - your function should work for any valid list so think about the cases.

*/


#include <stdio.h>
#include <stdlib.h>


struct lnodetype {
	int val;
	struct lnodetype *ptr;
};

// Even/Odd - iterative
char ievenorodd( int x ) {
	while (x > 1)
		x -= 2;
	return x ? 'o' : 'e';
}


// Even/Odd - recursive
char revenorodd( int x ) {
	if (x == 0)
		return 'e';
	if (x == 1)
		return 'o';
	return revenorodd(x - 2);
}


// Linked list summ - iterative
int illsum( struct lnodetype *t ) {
	int sum = 0;
	while (t != NULL) {
		sum += t->val;
		t = t->ptr;
	}
	return sum;
}


// Linked list summ - recursive
int rllsum( struct lnodetype *t ) {
	if (t == NULL)
		return 0;
	return t->val + rllsum(t->ptr);
}


// Basic main program

int main() {
	int n;
	char a, b;

	printf("Number: ");
	scanf("%d", &n);
	a = ievenorodd( n );
	b = revenorodd( n );
	printf("%c %c\n", a, b);


	struct lnodetype *h, *t;
	int x, y;

	// build a list
	h = NULL;
	for ( x = 0; x < 5; ++x ) {
		t = malloc(sizeof(struct lnodetype));
		t->val = n*(x+1)*(rand()%n+1)%19+1;
		t->ptr = h;
		h = t;
	}


	t = h;
	x = illsum( t );
	y = rllsum( t );
	printf("%d %d\n", x, y);

	return 0;
}
