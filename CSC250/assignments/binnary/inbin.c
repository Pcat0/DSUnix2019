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
	char *binName = argv[1];
	data record;

	//Open Files
	FILE *bin = fopen(binName, "rb");

	//check if the file was opened
	if (bin == NULL)
		exitWErr("Unabble to create binary output file");

	//get record count
	fread(&recordCount, sizeof(int), 1, bin);
	printf("%d records in file.\n", recordCount);

	if(recordCount > 0) {
		//read first record
		fread(&record, sizeof(data), 1, bin);
		printf("record 1 of %d: %s %d %f\n", recordCount, record.name, record.iNum, record.fNum);
		if (recordCount > 1) {
			//read secound from last record
			fseek(bin, -sizeof(data) * 2, SEEK_END);
			fread(&record, sizeof(data), 1, bin);
			printf("record %d of %d: %s %d %f\n", recordCount - 1,recordCount, record.name, record.iNum, record.fNum);
		}
	}
	return 0;
}

