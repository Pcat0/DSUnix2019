#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1
#define false 0
typedef struct {
	char name[25];
	int iNum;
	float fNum;
} data;
//exit with error
void exitWErr(char *errmsg) {
	char *fullmsg = calloc(sizeof(char), sizeof(errmsg) + 22);
	strcpy(fullmsg, "\033[91merror:\033[0m ");
	strcat(fullmsg, errmsg);
	fprintf(stderr, fullmsg);
	exit(1);
}
int main(int argc, char *argv[]) {
	//check if a input file was given;
	if(argc < 2)
		exitWErr("No input file provided.\n");

	int recordCount = 0;
	data record;// = malloc(sizeof(data));
	char *ptName = argv[1];
	char *binName = calloc(sizeof(char), strlen(ptName) + 4);

	//format file names
	strcpy(binName, ptName);
	strcat(binName, ".bin");

	//Open Files
	FILE *pt = fopen(ptName, "r");
	FILE *bin = fopen(binName, "wb");

	//check if files were opened
	if (pt == NULL)
		exitWErr("Unable to open plain text input file\n");
	if (bin == NULL)
		exitWErr("Unabble to create binary output file");

	//write placeholder data length
	fwrite(&recordCount, sizeof(int), 1, bin);

	//read and right records
	while (!feof(pt)) {
		fscanf(pt, "%s %d %f ", &record.name, &record.iNum, &record.fNum);
		fwrite(&record, sizeof(data), 1, bin);
		recordCount++;
	}

	//move back to start of binary file
	fseek(bin, 0, SEEK_SET);
	//write data length
	fwrite(&recordCount, sizeof(int), 1, bin);

	printf("Successfully written %d records to %s\n", recordCount, binName);

	return 0;
}

