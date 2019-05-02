#include <stdio.h>
#include <string.h>

#define true 1
#define false 0

void stringToLower( char str[] ) {
	int len = strlen(str);
	for (int i = 0; i < len; i++ ){
		str[i] |= 32;
	}
}
int charInStr(char c, char str[]){
	int len = strlen(str);
	for (int i = 0; i < len; i++) {
		if (str[i] == c)
			return true;
	}
	return false;
}
int main(){
	char str1[50], str2[50];
	int sharCount = 0;
	scanf("%s %s", str1, str2);
	stringToLower(str1);
	stringToLower(str2);
	for (char c = 97; c < 123; c++) {
		if(charInStr(c, str1) && charInStr(c, str2)){
			sharCount += 1;
		}
	}
	printf("Similarly: %d\n", sharCount);
	return 0;
}

