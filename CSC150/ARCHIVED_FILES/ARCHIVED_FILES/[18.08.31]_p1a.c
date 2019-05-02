#include<stdio.h>
int main(){
	int qty;
	float price, subtotal, tax, total;

	printf("What is the price of the item? \e[38;5;2m$");
	scanf("%f", &price);
	printf("\e[0mHow many do you want? \e[38;5;2m");
	scanf("%d", &qty);

	subtotal = price * qty;
	tax = subtotal * 0.06f;
	total = subtotal + tax;

	printf("\n\n\e[0mYour invoice:\n");
	printf("QTY	Item	Price	Amount\n");
	printf("%-8d%-8s%-8.2f%-8.2f\n", qty, "Item 1", price, subtotal);
	printf("		       ----------\n");
	printf("	      subtotal: $%-7.2f\n", subtotal);
	printf("		   tax: $%-7.2f\n", tax);
	printf("		 total: $%-7.2f\n", total);

	return 0;
}
