#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define true 1
#define false 0
struct node {
	int data;
	struct node *link;
};

int max(int a, int b) {
	return (a > b) ? a : b;
}

struct node *createNode(int data){
	struct node *newNode;
	newNode = malloc(sizeof(struct node));
	newNode->data = data;
	newNode->link = NULL;
	return newNode;
}

void llAddStart(struct node **head, int data){
	struct node *newNode = createNode(data);
	newNode->link = *head;
	*head = newNode;
}
int llMax(struct node *head){
	int biggest;
	if(head->link == NULL)
		return head->data;
	return max(head->data, llMax(head->link));
}
int llLength(struct node *head) {
	if(head == NULL)
		return 0;
	return llLength(head->link) + 1;
}
void llPrint(struct node *head, char *format, int addNewLine) {
	if (head == NULL) {
		if(addNewLine)
			printf("\n");
		return;
	}
	printf(format, head->data);
	llPrint(head->link, format, addNewLine);
}

int main(int argc, char *argv[]) {
	struct node *head = NULL;
	llAddStart(&head, 2);
	llAddStart(&head, 5);
	llAddStart(&head, 3);
	llAddStart(&head, 4);	
	printf("    List: ");
	llPrint(head, "%d,", true);
	printf("  Length: %d\n", llLength(head));
	printf("     Max: %d\n", llMax(head));
	return 0;
}

