#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*int getrand()
{
int a;

srand(time(NULL));

a = rand() % 6+1;

return a;
}*/

void main()
{
	int a = 0, b = 0, c = 0, i = 0;
	printf("Game of Dice \n==============");

	do{
		printf("\nEnter total sought:");
		scanf("%d", &a);
		if (a > 12 || a < 2)
			printf("\n**Invalid Input! Try Again!**");
	} while (a > 12 || a < 2);

	for (i = 1; a != b + c; i++)
	{
		srand(time(NULL) + i);
		b = rand() % 6 + 1;
		c = rand() % 6 + 1;
		printf("\nresult of throw %d : %d + %d", i, b, c);
	}
	printf("\nYou got your total in %d throws!", i - 1);
	getchar(); getchar();




}


