#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int wordcounter(char *string);
void main(){
	char st[101];
	int a;
	printf("Word Counter\n============\nText to be analyzed:");
	scanf(" %[^\n]", st);
	a = wordcounter(st);
	printf("Woud count: %d", a);
	getchar(); getchar();
}
int wordcounter(char string[]){
	int i=0, j=1;
	for (i = 0;; i++){
		string[i] = string[i];
		if (string[i] == '\0')
			break;
		else if ((string[i] == ' ' || string[i] == '\n' || string[i] == '\c' || string[i] == '\t' || string[i] == '\f' || string[i] == '\v') && (string[i + 1] != ' '  && string[i + 1] != '\n' && string[i + 1] != '\c' && string[i + 1] != '\t' && string[i + 1] != '\f' && string[i + 1] != '\v' && string[i + 1] != '\n' && string[i + 1] != '\0'))
			j++;
	}
	
	return j;
}
