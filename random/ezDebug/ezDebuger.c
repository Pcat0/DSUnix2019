#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	if (strlen(argv[1]) > 4096) {
		fprintf(stderr, "File path to error log is too long.\n");
		return 1;
	}
	FILE *errorLog;
	errorLog = fopen(argv[1], "r");
	if (errorLog != NULL) {
		while(1) {
	    	 char c = fgetc(errorLog);
    	 	 if(feof(errorLog)) break;
      		 printf("%c", c);
   		}
    	fclose(errorLog);
  	}
	return 0;
}

