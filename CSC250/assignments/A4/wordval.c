// read a list
//   each element is a string and an integer
// print list 
// sort by string
// sort by number
/*
Additional notes::

Filename will be provided on the commandline

The program should not take any other input

File:
 each line will consist of a string/word and an integer value
 Input file contains a list of words, 1 per line.
  - there will be less than 100 words
  - all words will be less than 30 characters

Output::  first line is your first & last name
  - remaining outpput as requested below

Note::
 * Do NOT pass file pointers to functions, only the
    filenames and/or arrays

Function: sort the data
  Param: arrays
         # of items
         pick   to sort by word or number
                   by parameter, not interactive

Function:  display on screen
  Param: arrays
         # of items
   ** also print a "line number" 1,2,3  by each pair

Function: read data from file
  Param: filename
         arrays
  Return: number of items
*/


#include <stdio.h>
#include <string.h>

struct Data {
	char str[30];
	int num;
};

int readData(char fileName[], struct Data arr[]) {
	int n = 0;
	FILE *fp = fopen(fileName, "r");

	fscanf(fp, "%s %d", arr[0].str, &arr[0].num);

	while (!feof(fp)) {
		n++;
		fscanf(fp, "%s %d", arr[n].str, &arr[n].num);
	}
	return n;
}

void printData(struct Data arr[], int len){
	for (int i = 0; i < len; i++) {
		printf("%d) %s %d\n", i + 1, arr[i].str, arr[i].num);
	}
}

void switchValue(struct Data arr[], int a, int b) {
	char tStr[30];
	int tInt;

	strcpy(tStr, arr[a].str);
	strcpy(arr[a].str, arr[b].str);
	strcpy(arr[b].str, tStr);

	tInt = arr[a].num;
	arr[a].num = arr[b].num;
	arr[b].num = tInt;
}

/*
types:
	0) Sort by number
	1) Sort by word
*/
void sortData(struct Data arr[], int len, int type) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			switch(type) {
				case 0:
					if(arr[j].num > arr[j + 1].num)
						switchValue(arr, j, j + 1);
					break;
				case 1:
					if(strcmp(arr[j].str, arr[j + 1].str) > 0)
						switchValue(arr, j, j + 1);
					break;
			}
		}
	}
}

int main(int argc, char *argv[]) {
	printf("Patrick Ambli\n");
	// declare variables
	struct Data arr[100];
	int len;

	// read data
	len = readData(argv[1], arr);

	// print out how many lines were read
	printf("%d lines read.\n", len);

	// print out original data, number each line
	printf("\n--Original data--\n");
	printData(arr, len);

	// print out sorted by number , number each line
	printf("\n--Sorted by number--\n");
	sortData(arr, len, 0);
	printData(arr, len);

	// print out sorted by word , number each line
	printf("\n--Sorted by word--\n");
	sortData(arr, len, 1);
	printData(arr, len);

	return 0;
}
