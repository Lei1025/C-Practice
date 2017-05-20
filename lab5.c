#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void simplify(int *numerator, int *denominator);
void main(){
	int numerator = 1, denominator = 1;
	printf("Fraction Simplifier\n=============\nNumerator:");
	scanf("%d", &numerator);
	if (numerator < 0){ printf("please enter a positive number or zero\n"); }
	printf("Denominator:");
	scanf("%d", &denominator);
	if (denominator <= 0){ printf("please enter a positive number\n"); }
	simplify(&numerator, &denominator);
	if (denominator == 1)
		printf("%d", numerator);
	else 
		printf("%d/%d", numerator, denominator);
	getchar(); getchar();
}
void simplify(int *numerator, int *denominator){
	int max, min, i, c, d;
	if (*numerator>*denominator){
		max = *numerator;
		min = *denominator;
	}
	else{
		max = *denominator;
		min = *numerator;
	}
	for (i = min; min%i != 0 || max%i != 0; i--);
	*numerator = *numerator / i;
	*denominator = *denominator / i;
}

