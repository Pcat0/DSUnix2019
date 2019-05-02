#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[25];
    int iNum;
    float fNum;
} Record;

char *reverseStr(char *str) {
	//(get it? rts is str backwards)
	int len = strlen(str);
	char *rts = malloc(sizeof(char) * (len+1));
	for(int i = 0; i < len; i++)
		rts[i] = str[len-1-i];
	rts[len] = '\0';
	return rts;
}
int charToNum(char c) {
	if('0' <= c && c <= '9') {
		return c - 48;
	} else {
		return -1;
	}
}
int strToInt(char *str){
	int len = strlen(str);
	int value = 0;
	for(int i = len-1, m = 1; i >= 0; i--) {
		int num = charToNum(str[i]);
		if (num != -1) {
			value += num * m;
			m *= 10;
		}
	}
	return value;
}
float strToFloat(char *str) {
	int len = strlen(str);
	float value = 0;
	int desLoc = 1;
	for(int i = len-1, m = 1; i >= 0; i--) {
		int num = charToNum(str[i]);
		if (num != -1) {
			value += num * m;
			m *= 10;
		} else if(str[i] == '.') {
			desLoc = m;
		}
	}
	return value/desLoc;
}

int fbof(FILE *fp) {
	return fp->_IO_read_ptr == fp->_IO_read_base;
}
//(get it? teg is get backwards)
char ftegc(FILE *fp) {
	return *(--fp->_IO_read_ptr);
}
char *readWordBW(FILE *fp) {
	char *_readWordBW(FILE *fp, int i) {
		if (fbof(fp))
			return calloc(sizeof(char), i);
		char c = ftegc(fp);
		if (c < '!' || '~' < c){
			if (i > 0)
				return calloc(sizeof(char), i);
			else
				return _readWordBW(fp, i);
		}
		char *word = _readWordBW(fp, i+1);
		word[i] = c;
		return word;
	}
	return _readWordBW(fp, 0);

}
int convertFile(FILE *pt, FILE *bin) {
	int _convertFile(FILE *pt, FILE *bin, int pos) {
		Record record;
		int i;
		if(fbof(pt)){
			//printf("%d\n", i);
			fwrite(&pos, sizeof(int), 1, bin);
			return pos;
		}

		record.fNum = strToFloat(reverseStr(readWordBW(pt)));
		record.iNum = strToInt(reverseStr(readWordBW(pt)));
		char *name = reverseStr(readWordBW(pt));

		for (i = 0; name[i] != '\0'; i++)
			record.name[i] = name[i];
		record.name[i] = '\0';

		int len = _convertFile(pt, bin, pos+1);

		//printf("%s %s %d %f\n", name, record.name, record.iNum, record.fNum);
		fwrite(&record, sizeof(Record), 1, bin);
		return len;
	}
	fseek(pt, 0, SEEK_END);
	return _convertFile(pt, bin, 0);
}

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

	//goto end of input file
//	fseek(pt, 0, SEEK_END);
	recordCount = convertFile(pt, bin);
	printf("Successfully written %d records to %s\n", recordCount, binName);
	return 0;
}

