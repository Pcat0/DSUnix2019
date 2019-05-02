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
void exitWErr(char *errmsg) {
	char *fullmsg = calloc(sizeof(char), sizeof(errmsg) + 22);
	strcpy(fullmsg, "\033[91merror:\033[0m ");
	strcat(fullmsg, errmsg);
	fprintf(stderr, fullmsg);
	exit(1);
}

Record* readData(FILE *pt, int *len) {
	Record record;
	Record *records;
	int i = *len;
	if(feof(pt))
		return calloc(sizeof(Record), i);
	*len+=1;
	fscanf(pt, "%s %d %f ", &record.name, &record.iNum, &record.fNum);
	records = readData(pt, len);
	records[i] = record;
	return records;
}

int main(int argc, char *argv[]) {
	//check if a input file was given;
	if(argc < 2)
		exitWErr("No input file provided.\n");

	int recordCount = 0;
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

	int length = 0;
	Record *records = readData(pt, &length);
	fwrite(&length, sizeof(int), 1, bin);
	fwrite(records, sizeof(Record), length, bin);
	printf("Successfully written %d records to %s\n", length, binName);

	return 0;
}

