#include <stdio.h>
#include <string.h>
#include <limits.h>

#define true 1
#define false 0

// good structure to use
struct stock {
	char name[25];
	int quantity;
	float price;
};

void toLower(char str[]){
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if('A' <= str[i] && str[i] <= 'Z')
			str[i] += 0x20;
	}
}

void clearScreen(){
	printf("\e[1;1H\e[2J");
}

void centerText(char start[], char text[], char end[], char pad, int width) {
	printf(start);
	int len = width - strlen(text) + 1;
	len = (len > 0) ? len : 1;
	for (int i = 0; i < len; i++) {
		if (i != len/2) {
			printf("%c", pad);
		} else {
			printf(text);
		}
	}
	printf(end);
}


void pause() {
    printf("\nPress any key to continue\n");
   	getchar();
    getchar();
}

void printProduct(struct stock inventory[], int index, int showKey) {
	if(showKey)
		printf("\e[7mID --    Name     QTY   Price\n\e[0m");
	printf("%2d -- %10s  %3d  %6.2f\n", index + 1, inventory[index].name, inventory[index].quantity, inventory[index].price );
}

void showInventory( struct stock inventory[], int N  ) {
	int i;
    for (i = 0; i < N; ++i)
		printProduct(inventory, i, i == 0);
}
float totalValue(struct stock item) {
	return item.quantity * item.price;
}

int inventoryRead( char fname[], struct stock items[] ) {
	int n = 0;
	char name[25];

	FILE *stuff = fopen(fname, "r");

	if (stuff == NULL)
		return -1;

	fscanf(stuff, "%s %d %f", items[0].name, &items[0].quantity, &items[0].price);
	while(!feof(stuff)) {
		n++;
		fscanf(stuff, "%s %d %f",  items[n].name, &items[n].quantity, &items[n].price);
	}
	return n;
}

void buy( struct stock items[], int len ) {
	int itemNum;
	centerText("\e[7m", "BUY", "\e[0m\n\n", ' ', 35);
	printf("Product number: ");
	//printf("------ Buy ------\nProduct number: ");
	scanf("%d", &itemNum);
	itemNum--;
	if( itemNum < 0 || len <= itemNum ) {
		printf("Invaid product number (%d). Unable to complete transaction.\n", itemNum + 1);
	} else if(items[itemNum].quantity < 1) {
		printf("Stock too low on %s. Unable to comlete transaction\n", items[itemNum].name);
	} else {
		items[itemNum].quantity--;
		printf("Transaction complete. Bought 1 %s for $%.2f\n", items[itemNum].name, items[itemNum].price);
	}
}

void stockItem( struct stock items[], int len ) {
	int itemNum;
	int quantity;
	centerText("\e[7m", "STOCK", "\e[0m\n\n", ' ', 35);
	printf("Product number: ");
	//printf("------ Stock ------\nProduct number: ");

	scanf("%d", &itemNum);
	itemNum--;
	if( itemNum < 0 || len <= itemNum ) {
		printf("Invaid product number (%d). Unable to stock product.\n", itemNum + 1);
		return;
	}
	printf("Quantity: ");
	scanf("%d", &quantity);
	if(quantity < 1) {
		printf("Quantity too low (%d). Unable to stock product.\n", quantity);
	} else {
		items[itemNum].quantity += quantity;
		printf("Successfully stocked %s with %d more units.\n", items[itemNum].name, quantity);
	}
}

int findStockLow( struct stock items[], int len ) {
	int lowestIndex = 0;
	for(int i = 0; i < len; i++) {
		if (items[lowestIndex].quantity > items[i].quantity) {
			lowestIndex = i;
		}
	}
	return lowestIndex;

}

int findStockHigh( struct stock items[], int len ) {
	int highestIndex = 0;
	for(int i = 0; i < len; i++) {
		if (items[highestIndex].quantity < items[i].quantity) {
			highestIndex = i;
		}
	}
	return highestIndex;

}

int findValueLow( struct stock items[], int len, float *value) {
	int index = 0;
	*value = totalValue(items[0]);
	for(int i = 0; i < len; i++) {
		if (*value > totalValue(items[i])) {
			index = i;
			*value = totalValue(items[i]);
		}
	}
	return index;

}

int findValueHigh( struct stock items[], int len, float *value) {
	int index = 0;
	*value = totalValue(items[0]);
	for(int i = 0; i < len; i++) {
		if (*value < totalValue(items[i])) {
			index = i;
			*value = totalValue(items[i]);
		}
	}
	return index;
}

int reorderList(struct stock out[], struct stock items[], int len, int threshold) {
	int newLen = 0;
	if(threshold < 0)
		return -1;
	for (int i = 0; i < len; i++) {
		if (items[i].quantity <= threshold) {
			out[newLen++] = items[i];
		}
	}
	return newLen;
}

void lowerProductName(struct stock *item) {
	toLower(item->name);
}

void lowerAllNames(struct stock items[], int len) {
	for (int i = 0; i < len; i++) {
		lowerProductName(&items[i]);
	}
}
float totalInventoryValue(struct stock items[], int len) {
	float sum;
	for (int i = 0; i < len; i++)
		sum += totalValue(items[i]);
	return sum;
}

void lowAndHigh(struct stock items[], int len, int *lowestIndex, int *highestIndex) {
	*lowestIndex = 0;
	*highestIndex = 0;
	for(int i = 0; i < len; i++) {
		if (items[*lowestIndex].quantity > items[i].quantity)
			*lowestIndex = i;
		if (items[*highestIndex].quantity < items[i].quantity)
			*highestIndex = i;
	}
}

int main(int argc, char *argv[]) {
	struct stock inventory[100];
	int choice = 0;
	char filename[9999] = "products";
	int len;
	// initial inventory file name supplied on command line
 	// if no argument is supplied, you a file named  "products"
	// if a file is not able to be read, program should handle it

	if(argc > 1){
		strcpy(filename, argv[1]);
	}
	// read in the data to get things started
	len = inventoryRead(filename, inventory);
	if (len == -1) {
		printf("ERR: ID-10t\n	-Can not find file [%s]\n", filename);
		return 1;
	}
	// menu of options
	// each should call a function ; most work should happen in function
	// you can do some simple input or loop in main menu is needed

	do {
		clearScreen();
		centerText("\e[7m", "MENU", "\e[0m\n\n", ' ', 35);

		//printf("------ Menu ------------\n");
		// print out the nicely formatted list
		printf("1) Show Inventory\n");
		// ask for product number and buy one
		printf("2) Buy something \n");
		// ask for product number and quantity to add
		printf("3) Stock something\n");
		// what item has lowest number of items
		printf("4) Lowest inventory\n");
		// what item has highest number of items
		printf("5) Highest inventory\n");
		// lowest total value for a product inventory
		printf("6) Lowest total stocking value\n");
		// highest total value for a product inventory
		printf("7) Highest total stocking value\n");
		// list all products under a certain threshold (input)
		printf("8) Generate re-order list\n");
		// import a new inventory file
		printf("9) Load new inventory file\n");
		// change all product names to lowercase ( call function used in 11)
		printf("10) Lowercase all product names\n");
		// must pass a single structure to a function, not the full array
		printf("11) Lowercase a specific product name\n");
		// Find to total value of inventory in stock
		// - return a float value to main for processing
		printf("12) Total value of inventory\n");
		// The highest & lowest quantity values should be found
		// - just the integers should be make available to main
		// - one function finds both
		printf("13) High & Low quantity \n");
		// Save the current stock to a file - so it can be read in later
		// - ask for the filename to save to
		printf("14) Save to file\n");

		printf("0) Quit\n");

		// make sure the choice is a valid integer
		// before you go to the switch
		printf("> ");
		scanf("%d", &choice);
		// do the requested task

		clearScreen();
		switch (choice) {
			case 1:
				centerText("\e[7m", "INVENTORY", "\e[0m\n\n", ' ', 35);
				showInventory(inventory, len);
				pause();
				break;
			case 2:
				buy(inventory, len);
				pause();
				break;
			case 3:
				stockItem(inventory, len);
				pause();
				break;
			case 4:
				centerText("\e[7m", "FIND PRODUCT", "\e[0m\n\n", ' ', 35);
				centerText("", "Lowest Stock:", "\n", ' ', 29);
				printProduct(inventory, findStockLow( inventory, len ), true);
				pause();
				break;
			case 5:
				centerText("\e[7m", "FIND PRODUCT", "\e[0m\n\n", ' ', 35);
				centerText("", "Highest Stock:", "\n", ' ', 29);
				printProduct(inventory, findStockHigh( inventory, len ), true);
				pause();
				break;
			case 6: {
				float value;
				centerText("\e[7m", "FIND PRODUCT", "\e[0m\n\n", ' ', 35);
				centerText("", "Lowest Total Value:", "\n", ' ', 29);
				printProduct(inventory, findValueLow(inventory, len, &value), true);
				printf("Total value: $%.2f\n", value);
				pause();
				break;
			}
			case 7: {
				float value;
				centerText("\e[7m", "FIND PRODUCT", "\e[0m\n\n", ' ', 35);
				centerText("", "Highest Total Value:", "\n", ' ', 29);
				printProduct(inventory, findValueHigh(inventory, len, &value), true);
				printf("Total value: $%.2f\n", value);
				pause();
				break;
			}
			case 8: {
				centerText("\e[7m", "INVENTORY MANAGEMENT", "\e[0m\n\n", ' ', 35);
				struct stock orderList[100];
				int newLen, threshold;
				printf("Stock threshold: ");
				scanf("%d", &threshold);
				newLen = reorderList(orderList, inventory, len, threshold);

				if (newLen > 0) {
					printf("Products needing to be ordered:\n");
					showInventory(orderList, newLen);
				} else if(newLen == 0) {
					printf("No products need to be ordered\n");
				} else {
					printf("Invaild threshold (%d).\n", threshold);
				}
				pause();
				break;
			}
			case 9: {
				centerText("\e[7m", "INVENTORY FILE LOADER", "\e[0m\n\n", ' ', 35);
				printf("New file location> ");
				scanf("%s", &filename);
				int newLen = inventoryRead(filename, inventory);

				if (newLen < 0) {
					printf("ERR: ID-10t\n	-Can not find file [%s]\n", filename);
				} else {
					len = newLen;
					printf("New inventory file successfully loaded.\n");
				}
				pause();
				break;
			}
			case 10:
				centerText("\e[7m", "FORMAT PRODUCT ENTRY", "\e[0m\n\n", ' ', 35);
				lowerAllNames(inventory, len);
    			printf("\nSuccessfully formatted table.\n");
				pause();
				break;
			case 11: {
				int id;
				centerText("\e[7m", "FORMAT PRODUCT ENTRY", "\e[0m\n\n", ' ', 35);
				centerText("", "Lowercase product entry:", "\n", ' ', 35);
				printf("Product number: ");
				scanf("%d", &id);
				if(1 <= id && id <= len) {
					lowerProductName(&inventory[id-1]);
					centerText("", "\nSuccessfully formatted entry:\n", "", ' ', 29);
					printProduct(inventory, id - 1, 1);
				} else {
					printf("ERR: %d is not a vaild ID\n", id);
				}
				pause();
			}
			case 12:
				centerText("\e[7m", "INVENTORY STAT", "\e[0m\n\n", ' ', 35);
				printf("Current inventory value: $%.2f", totalInventoryValue(inventory, len));
				pause();
				break;
			case 13: {
				int low, high;
				centerText("\e[7m", "FIND PRODUCT", "\e[0m\n\n", ' ', 35);
				lowAndHigh(inventory, len, &low, &high);
				printf("\nLowest stock:\n");
				printProduct(inventory, low, true);
				printf("\n\nHighest stock:\n");
				printProduct(inventory, high, true);
				pause();
			}
		}
	} while (choice > 0);
	/**/
	return 0;
}

