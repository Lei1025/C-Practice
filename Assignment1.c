/*Lei Liu - lliu143 - ipc144 - 20153 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
const int num = 20;
void main()
{
	int days, i, j;
	double h, l, avr=0, all = 0;
	char cdt;
	do{
		printf("Weather Analyzer \n=============== \nPlease enter a positive number of days:");
		scanf("%d", &days);
	} while (days <= 0);
	for (i = 1; i <= days; i++){
		printf("Enter today's high:");
		scanf("%lf", &h);
		printf("Enter today's low:");
		scanf("%lf", &l);
		printf("Enter today's conditions (s: sunny, c: cloudy, p: precipitation):");
		scanf(" %c", &cdt);
		switch (cdt)
		{
		case's':
		{for (j = 0; j < num; j++)
			printf("@");
		}; break;
		case'c':
			for (j = 0; j < num; j++)
				printf("~"); break;
		case'p':{if (avr <= 0)
			for (j = 0; j < num; j++)
				printf("*");
				else
				for (j = 0; j < num; j++)
					printf(";"); }break;
		default:printf("Please enter the right character");
		}
		printf("\nToday's average temperature is:%.2lf\n", avr = (h + l) / 2);
		all += avr;
		
	}
	printf("\nAverage for all %d days is: %.2lf degrees", days, all / days);

	getchar(); getchar();
}
