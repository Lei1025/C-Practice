#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(){
	char Case, store[100] = { 0 };
	printf("Change Case\n===========\nCase (U for upper, L for lower) :");
	scanf("%c", &Case);
	printf("Name of the original file : original.dat\nName of the updated file : updated.dat ");
	FILE *f1 = fopen("original.dat", "r");
	FILE *f2 = fopen("update.dat", "w");

	
	if (Case == 'L' || Case == 'l'){
		//Upper case to Lower case
		if (f1){
			int i;
			for (i = 0; store[i] != -1; i++)
			{
				store[i] = fgetc(f1);
				if (store[i] >= 'A' && store[i] <= 'Z')
					store[i] += 32;
			}

		}
		else
			printf("open file failed");
	}
	else if (Case == 'U' || Case == 'u'){
		if (f1){
			int i;
			for (i = 0; store[i] != -1; i++)
			{
				store[i] = fgetc(f1);
				if (store[i] >= 'a' && store[i] <= 'z')
					store[i] -= 32;
			}

		}
		else
			printf("open file failed");
	}
	else
		printf("Please enter the right character!");
	int i; 
	for (i = 0; store[i] != -1; i++)
		fputc(store[i],f2);
	fclose(f1);
	fclose(f2);

	getchar(); getchar();
}
