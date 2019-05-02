#include<stdio.h>
int main(){
	int dogs, cats;
	printf("How meny dogs do you have? ");
	scanf("%d", &dogs);

	printf("How meny cats do you have? ");
        scanf("%d", &cats);

	if (!cats && !dogs)
		printf("You have no pets");
	if (dogs) {
		printf("You have %d dog", dogs);
		if(dogs > 1)
			printf("s");
	}
	if (dogs && cats)
		printf(" and ");
	if (cats) {
		if (dogs > 0)
			printf("y");
		else
			printf("Y");
                printf("ou have %d cat", cats);
                if(cats > 1)
                        printf("s");
        }
	printf(".\n");
	return 0;
}
