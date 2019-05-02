#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
int getch(void) {
      int c=0;

      struct termios org_opts, new_opts;
      int res=0;
          //-----  store old settings -----------
      res=tcgetattr(STDIN_FILENO, &org_opts);
      assert(res==0);
          //---- set new terminal parms --------
      memcpy(&new_opts, &org_opts, sizeof(new_opts));
      new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
      tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
      c=getchar();
          //------  restore old settings ---------
      res=tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
      assert(res==0);
      return(c);
}

/*
     65
     /\
68 <    > 67
     \/
     66
*/
int lineCount = 0;
void menudraw(char menuText[]) {
	int i = 0;
	while(menuText[i] != '\0') {
		printf("%c", menuText[i]);
		if (menuText[i] == '\n'){
			lineCount++;
			printf("%d) ", lineCount);
		}
		i++;
	}
	printf("\033[%dA", lineCount);
}
int main(){
	char menu[] = "Menu 1\nMenu 2\nMenu 3\nMenu 4\nMenu 5";
	menudraw(menu);
	while(1) {
		int c = getch();
		if(c == 65){
			printf("\033[1A");
		}
		if(c == 66) {
			printf("\033[1B");
		}
		if(c == 10) {
			
		}
	}
	return 0;
}

