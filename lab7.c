#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void main()
{
	int barcode[100] = { 0 }, quantity[100] = { 0 }, i, j, k;
	double price[100] = { 0 }, value=0;

	printf("Grocery Store Inventory\n======================\n");

	for (i = 0; i < 100; i++){
		printf("Barcode:");
		scanf("%d", &barcode[i]);
		if (barcode[i] == 0)
			break;
		printf("Price:");
		scanf("%lf", &price[i]);
		printf("Quantity:");
		scanf("%d", &quantity[i]);
	}

	printf("Goods in Stock\n===============\nBarcode\t\tPrice\tQuantity\tValue\n-----------------------\n");
	for (j = 0; j < i; j++){
		printf("%d\t%.2lf\t%d\t%.2lf\n", barcode[j], price[j], quantity[j], price[j] * quantity[j]);
	}
	for (k = 0; k < i; k++){
		value += price[k] * quantity[k];
	}
	printf("\nTotal value goods in stock	%.2lf", value);

	getchar(); getchar();
}