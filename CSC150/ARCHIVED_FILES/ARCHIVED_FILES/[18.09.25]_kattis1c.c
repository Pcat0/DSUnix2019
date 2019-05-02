#include <stdio.h>

int main() {
	int shift, i;
	char temp, string[40];
	scanf("%d", &shift);
	while(shift) {
		i = -1;
		getchar();
		temp = getchar();
		while (temp != '\n'){
			i++;
			if (temp == '_')
    				temp = '[';
  			else if(temp == '.')
   				temp = '\\';
  			temp -= (65 - shift);
  			temp %= 28;
  			temp += 65;
  			if (temp == '[')
  				string[i] = '_';
  			else if(temp == '\\')
				string[i] = '.';
			else
				string[i] = temp;
				temp = getchar();
			}
			for (; i >= 0; i--) {
				putchar(string[i]);
			}
			putchar('\n');
			scanf("%d", &shift);
		}
	return 0;
}
