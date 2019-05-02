#include <stdio.h>
#include <string.h>

struct Product {
	char name[25];
	int quantity;
	float price;
};

// read all products from file into items array
// return number of items
int getInventory( struct Product items[] ) {
	FILE *stuff;
	int n = 0;

	stuff = fopen( "products", "r");
	fscanf(stuff, "%s %d %f", items[0].name, &items[0].quantity, &items[0].price);
	while ( !feof( stuff ) ) {
		n++;
		fscanf(stuff, "%s %d %f", items[n].name, &items[n].quantity, &items[n].price);
	}
	return n;
}



// print out the inventory, there are N items
// print a number in front of each line
void showInventory( struct Product items[], int N  ) {
    for (int i = 0; i < N; ++i){
		printf("%s %d %f\n", items[i].name, items[i].quantity, &items[i].price);
	}
}


// interactive; ask user what product
//  decrease inventory quantity by 1
// for best results, make sure item # is in range
void buySomething( struct Product items[], int N  )
{
	// print the list to show choices
    showInventory( items, N );

	// ask which item

	// decrease quantity

	// print new quantity
}




int main() {
	int N;
	struct Product inventory[20];
	N = getInventory( inventory );
	showInventory(inventory, N);
	return 0;
}

