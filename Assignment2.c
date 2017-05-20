/*Lei Liu - lliu143 - ipc144 - 20153 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int getInteger(int min, int max);
void getDailyData(float* high, float* low, char * condition);
void draw(char c, int num);
float average(float first, float second);
void displayResult(int days, float allDaysAverage);
char symbolToDraw(char condition, float averageTemperature);
void garbage();

/*This function is used to clean the buffer*/
void garbage(){
	while (getchar() != '\n');
}


/*
This function prompts the user to enter an integer between the min and the max
If the input entered by the user is invalid, it displays an error and asks again.
It will continue asking the user until the integer the user enters falls between
min and max (inclusive).
This function returns an integer, ensured to be between min and max (inclusive)
and assumes that min <= max
*/
int getInteger(int min, int max){
	int num = 0;//delare and initialize the day which should be entered by users
	do {
		printf("Enter an integer between 1 and 14:");
		scanf("%d", &num);
		garbage();
		if (num<min || num>max)
			printf("ERROR! Try again!\n");
	} while (num<min || num>max);
	
	return num;
}

/*
This function prompts the user to enter a day's worth of data (high temperature,
low temperature, weather condition) separated by commas, validates the input such
that the user is forced to enter a floating point number for the high, a floating
point number for the low. It ensures that the low temperature is not higher than
the high temperature and that the condition is one of: 'c', 's', or 'p'.
If the user enters invalid input, this function displays an error and asks again.
float * high: a pointer holding the address of the float to which the function
will copy the day's high temperature before returning.
float * low: a pointer holding the address of a float to which the function will
copy the day's low temperature before returning.
char* condition: a pointer holding the address of the char to which the function
will copy the day's condition before returning.
*/
void getDailyData(float* high, float* low, char* condition){
	int a;//declare this variable to make sure 3 parameters are input
	do {
		printf("Enter today's high, low, and condition (c=cloudy, s=sunny, p=precipitation)	separated by commas : ");
		a = scanf("%f,%f, %c", high, low, condition);
		garbage();
		if (a != 3)
			printf("ERROR! Try again!\n");
		else if (*high < *low)
			printf("ERROR! Try again!\n");
		else if (*condition != 'c' && *condition != 's' && *condition != 'p')
			printf("ERROR! Try again!\n");
	} while (1 == ((a != 3) || (*condition != 'c' && *condition != 's' && *condition != 'p') || (*high < *low)));
}


/*
This function draws a row of characters (such as @@@@@@@ ).
char c holds the character that will be repeated
int num holds the number of times that the character will be repeated
The number of characters is controlled by the value of "num".
*/
void draw(char c, int num){
	for (int i = 0; i < num; i++)
		printf("%c", c);
	printf("\n");
}

/*
This function returns the average of the first and second floating point number.
*/
float average(float first, float second){
	return (first + second) / 2;
}

/*
This function displays the average temperature for a period of days
(e.g. Your seven day average is: 14.3)
NOTE: it displays the int days as a word; for example, 3 as "three"
If the int days is greater than 9 (nine) it just prints the value;
for example Your 10 day average is: 12.2)
*/
void displayResult(int days, float allDaysAverage){
	char *string[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	if (days >= 1 && days <= 9)
		printf("Your %s day average is %.2lf", string[days], allDaysAverage);
	else
		printf("Your %d day average is %.2lf", days, allDaysAverage);
}

/*
This function returns the correct character (@, ~, *, ;) given the current
condition and the average temperature.
NOTE: Precipitation character (* or ;) will change depending on the average
temperature.
char condition represents the current conditions
float averageTemperature represents the average daily temperature
*/
char symbolToDraw(char condition, float averageTemperature){
	switch (condition)
	{
	case's':	return '@'; break;
	case'c':	return '~'; break;
	case'p':	{if (averageTemperature <= 0)
		return '*';
				else
					return ';'; }break;
	}
}

int main(void){
	int numDays;
	int i;
	float sum = 0;
	float dailyHigh;
	float dailyLow;
	char conditions;
	float dailyAvg = 0;
	//title
	printf("Weather Analyzer 2.0\n");
	printf("====================\n");
	//prompt the user for a number of days
	printf("How many days of data?\n");
	//get an integer between 1 and 14
	numDays = getInteger(1, 14);
	for (i = 0; i < numDays; i++){
		//get input from the user
		getDailyData(&dailyHigh, &dailyLow, &conditions);
		dailyAvg = average(dailyHigh, dailyLow);
		printf("Today's average temperature is: %.2f\n", dailyAvg);
		sum += dailyAvg;
		draw(symbolToDraw(conditions, dailyAvg), 20);
	}

	displayResult(numDays, (sum / numDays));
	getchar(); getchar();
	return 0;
}
