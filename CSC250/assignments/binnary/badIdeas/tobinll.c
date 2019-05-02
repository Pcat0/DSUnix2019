#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
typedef struct {
	char name[25];
	int iNum;
	float fNum;
} Record;

typedef struct nodeStruct {
	Record record;
	struct nodeStruct *link;
} *node;

node newNode(){
	node n = malloc(sizeof(struct nodeStruct));
	n->link = NULL;
	return n;

}


//exit with error
void exitWErr(char *errmsg) {
	char *fullmsg = calloc(sizeof(char), sizeof(errmsg) + 22);
	strcpy(fullmsg, "\033[91merror:\033[0m ");
	strcat(fullmsg, errmsg);
	fprintf(stderr, fullmsg);
	exit(1);
}

int main(int argc, char *argv[]) {
	if(argc < 2)
		exitWErr("No input file provided.\n");

	int recordCount = 0;
	char *ptName = argv[1];
	char *binName = calloc(sizeof(char), strlen(ptName) + 4);

	node head = malloc(sizeof(node));
	head->link = NULL;
	node step = head;

	strcpy(binName, ptName);
	strcat(binName, ".bin");

	FILE *pt = fopen(ptName, "r");
	FILE *bin = fopen(binName, "wb");

	if (pt == NULL)
		exitWErr("Unable to open plain text input file\n");
	if (bin == NULL)
		exitWErr("Unabble to create binary output file");

	recordCount++;
	fscanf(pt, "%s %d %f ", &step->record.name, &step->record.iNum, &step->record.fNum);

	while (!feof(pt)) {
		recordCount++;
		step->link = malloc(sizeof(struct nodeStruct));//newNode();
		step = ostep->link;
		step->link = NULL;
		fscanf(pt, "%s %d %f ", &step->record.name, &step->record.iNum, &step->record.fNum);
	}
	//free(step);

	fwrite(&recordCount, sizeof(int), 1, bin);

	step=head;
	while (step != NULL) {
		printf("test\n");
		fwrite(&(step->record), sizeof(struct nodeStruct), 1, bin);
		step = step->link;
	}
//	for(step=head; step != NULL; step = step->link);
//		printf("a\n");

	printf("Successfully written %d records to %s\n", recordCount, binName);

	return 0;
}

