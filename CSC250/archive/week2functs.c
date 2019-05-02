#include <stdio.h>
#include <string.h>
int twice(int x) {
	return x * 2;
}
int square(int x) {
	return x * x;
}
void countUp(int start, int end) {
	for(int i = start; i <= end; i++){
		printf("%d ", i);
	}
	printf("\n");
}
void countDown(int start, int end) {
	for(int i = start; i >= end; i--) {
		printf("%d ", i);
	}
	printf("\n");
}
void countBetween(int start, int end) {
	if (start < end) {
		countUp(start, end);
	} else {
		countDown(start, end);
	}
}
int isLowercase(char c) {
	return ('a' <= c) && (c <= 'z');
}
int isUppercase(char c) {
	return ('A' <= c) && (c <= 'Z');
}
int isLetter(char c) {
	return isLowercase(c) || isUppercase(c);
}
int isOnlyLetters(char str[]){
	int len = strlen(str);
	int flag = 1;
	for (int i = 0; i < len; i++) {
		if (!isLetter(str[i])) {
			flag = 0;
			break;
		}
	}
	return flag;
}
void alternateCase(char str[]) {
	int i = 0;
	while (str[i] != '\0') {
		if(isLetter(str[i])) {
			str[i] ^= 32;
		}
		printf("%c", str[i]);
		i++;
	}
	printf("\n");
}
int main(){
	return 0;
}

