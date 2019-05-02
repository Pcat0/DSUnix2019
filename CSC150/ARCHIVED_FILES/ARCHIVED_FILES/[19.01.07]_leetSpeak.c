#include <stdio.h>
#include <string.h>
#include <ctype.h>


struct ReplaceRule {
	char key;
	char value;
};
char replaceValue(char letter, struct ReplaceRule rule[], int ruleLength) {
	for (int i = 0; i < ruleLength; i++) {
		//printf("%c %c", rule[i].key, rule[i].value);
		if (tolower(letter) == rule[i].key) {
			return rule[i].value;
		}
	}
	return letter;
}

int main(){
	int ruleLen = 10;
	struct ReplaceRule rule[] = {
		{'s', '$'},
		{'o', '0'},
		{'l', '1'},
		{'a', '@'},
		{'e', '3'},
		{'t', '+'},
		{'g', '9'},
		{'s', '5'},
		{'c', '('},
		{'z', '2'}
	};
	char ch = ' ', lastCh = '\n';
	while (1) {
		scanf("%c", &ch);
		if (ch == '\n' && lastCh == '\n')
			break;
		ch = replaceValue(ch, rule, ruleLen);
		printf("%c", ch);
		lastCh = ch;
	}
	return 0;
}

