#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(){
	unsigned int length = 8000000;
	FILE *fp;
	char fileName[] = "/test";
	char filePath[4097];
	getcwd(&filePath, 4096);
	strcat(filePath, fileName);
	//printf("%s\n", filePath);

	fp = fopen(filePath, "a");
	for(unsigned int i = 0; i < length; i++){
		putc('/', fp);
	}
	fclose(fp);

	return 0;
}

