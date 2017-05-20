#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// insert Fraction declaration first

// insert function prototypes here




struct Fraction{
	int numerator;
	int denominator;
};
// insert your function definitions here
void enter(struct Fraction*input){
	printf("Numerator:");
	scanf("%d", &(*input).numerator);
	printf("Denominator:");
	scanf("%d", &(*input).denominator);
	}

void simplify(struct Fraction *input){
	int max, min, i, c, d;
	if ((*input).numerator>(*input).denominator){
		max = (*input).numerator;
		min = (*input).denominator;
	}
	else{
		max = (*input).denominator;
		min = (*input).numerator;
	}
	for (i = min; min%i != 0 || max%i != 0; i--);
	(*input).numerator = (*input).numerator / i;
	(*input).denominator = (*input).denominator / i;
}

void display(struct Fraction *input){
	printf("%d / %d", (*input).numerator, (*input).denominator);
}
	

int main(void)
{
	struct Fraction f;
	printf("Fraction Simplifier\n");
	printf("===================\n");

	enter(&f);
	simplify(&f);
	display(&f);
	getchar(); getchar();
}