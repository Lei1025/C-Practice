#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
double value(double a, double b, double c)
{
	int i; double z=1;
	for (i = 1; i <= c; i++) {
		z = z*(1 + b);
	}
	return a*z;
}
void main()
{
	double prin, rate, year;
	printf("Ivestment Calculator \n=================\nPrincipal   :");
	scanf("%lf", &prin);
	printf("Annual Rate :");
	scanf("%lf", &rate);
	printf("No. of Years:");
	scanf("%lf", &year);	
	printf("\nThe future value is $%.2lf", value(prin, rate, year));
	getchar(); getchar();
}