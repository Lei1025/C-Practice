/*Lei Liu - lliu143 - ipc144 - 20153 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*V 1.1:
Changes:

1) declared i outside of loop, you don't need -std=c99 to compile anymore
2) added a check for existence of historicaldata.csv
*/

/*an instance of this struct holds the weather data for a single day*/
struct DailyData{
	int day;
	int month;
	int year;
	float high;
	float low;
	float precipitation;
	char condition;
};

/*an instance of this struct holds summary information for the weather
for a given month*/
struct MonthlyStatistic{
	float minTemperature;
	float maxTemperature;
	float averageTemperature;
	float totalPrecipitation;
};
int readDailyData(FILE* fp, struct DailyData allData[]);

int getRelevantRecords(int yearWanted, const struct DailyData allData[], int sz, struct DailyData yearData[]);
void sortYearData(struct DailyData yearData[], int sz);
void getStats(int month, const struct DailyData yearData[],
	int sz, struct MonthlyStatistic* monthStats);
void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly);
void graphLine(int month, const struct MonthlyStatistic* monthly);
void printVerbose(const struct DailyData yearData[], int sz);
char symbolToDraw(char condition, float avgTemp);
float average(float first, float second);
void draw(char c, int num);


int main(void){
	FILE* fp = fopen("historicaldata.csv", "r");
	if (!fp){
		printf("you need to put historicaldata.csv into this directory\n");
		exit(0);
	}
	struct DailyData  allData[3000];
	struct DailyData yearData[366];
	int numTotalRecords;

	numTotalRecords = readDailyData(fp, allData);
	int year;
	int reportType;
	int i;
	struct MonthlyStatistic monthly[12];
	printf("Please enter the year for the report: ");
	scanf("%d", &year);
	printf("Please enter the type of report you wish to generate:\n");
	printf("1) summary\n");
	printf("2) detailed\n");
	scanf("%d", &reportType);
	int numDays = getRelevantRecords(year, allData, numTotalRecords, yearData);
	sortYearData(yearData, numDays);

	for (i = 0; i < 12; i++){
		getStats(i + 1, yearData, numDays, &monthly[i]);
	}

	printf("Weather summary for %d\n", year);
	printf("|   Month   | High  |  Low  |  Avg  | Precip  |\n");
	printf("|-----------|-------|-------|-------|---------|\n");
	for (i = 0; i < 12; i++){
		printMonthlyStatistic(i + 1, &monthly[i]);
	}
	printf("\n\n");
	printf("Precipitation Graph\n\n");
	for (i = 0; i < 12; i++){
		graphLine(i + 1, &monthly[i]);
	}
	if (reportType == 2){
		printf("\n\n");
		printf("Detailed report:\n");
		printVerbose(yearData, numDays);
	}
	getchar(); getchar();
	return 0;
	
}
int readDailyData(FILE* fp, struct DailyData allData[]){
	int i = 0;
	while (fscanf(fp, "%d,%d,%d,%f,%f,%f,%c\n",
		&allData[i].year, &allData[i].month, &allData[i].day,
		&allData[i].high, &allData[i].low, &allData[i].precipitation,
		&allData[i].condition) == 7){
		i++;
	}
	return i;
}

/*This function is passed:

	a year (yearWanted)
	an array of DailyData(allData) - which contains every record found in the file
	size of the allData array (sz)
	another array of DailyData(yearData) - which has 366 elements.

	This function copy over all records from allData to yearData that matches yearWanted. Function returns number of records copied. */

int getRelevantRecords(int yearWanted, const struct DailyData allData[],
	int sz, struct DailyData yearData[]){
	int i = 0, j = 0;
	for (i = 0; i <= sz; i++){
		if (allData[i].year == yearWanted)
		{
			yearData[j] = allData[i];
			j++;
		}
	}
	return j;
}

/*This function is passed:

	array of DailyData (yearData)
	the size of the array (sz)

	This function sorts the records in the yearData array. The sorting is done so that the earliest date is the first record. */
void sortYearData(struct DailyData yearData[], int sz){
	struct DailyData sort[10];
	for (int j = 0; j < sz - 1; j++){// bubble sort months
		for (int i = 0; i < sz - 1; i++){
			if (yearData[i].month > yearData[i + 1].month){
				sort[0] = yearData[i];
				yearData[i] = yearData[i + 1];
				yearData[i + 1] = sort[0];
			}
		}
	}

	for (int j = 0; j < sz - 1; j++){ //bubble sort months 
		for (int i = 0; i < sz - 1; i++){
			if (yearData[i].month == yearData[i + 1].month && yearData[i].day > yearData[i + 1].day){
				sort[0] = yearData[i];
				yearData[i] = yearData[i + 1];
				yearData[i + 1] = sort[0];
			}
		}
	}
}

/*This function is passed

	a month as an integer (month)- 1 is January, 2 is February, ... etc.
	an array of DailyData (yearData)- array contains daily weather data for one year. You may assume the array is sorted.
	the size of the DailyData arrray (sz)
	a pointer to a MonthlyStatistics struct (monthStats) - used to pass back the gathered statisted

	This function find minimum temperature, the maximum temperature, the average temperature and total precipitation for a given month using the data in the array with a matching month. The results are passed back to the calling function by storing them into the appropriate data members of monthStats */
void getStats(int month, const struct DailyData yearData[],
	int sz, struct MonthlyStatistic* monthly){
	float min = 100.0, max = -100.0, temperature = 0.0, precipitation = 0.0;
	int j = 0;
	for (int i = 0; i < sz; i++)
	{
		if (yearData[i].month == month)
		{
			if (min>yearData[i].low)
				min = yearData[i].low;
			if (max < yearData[i].high)
				max = yearData[i].high;
			temperature += (yearData[i].low + yearData[i].high) / 2;
			j++;
			precipitation += yearData[i].precipitation;
		}
	}
	(*monthly).minTemperature = min;
	monthly->maxTemperature = max;
	monthly->averageTemperature = (temperature / j);
	monthly->totalPrecipitation = precipitation;
}


/*
This function is passed:

a month as an integer (month)- 1 is January, 2 is February, ... etc.
a pointer to MonthlyStatistic struct

This function will print out one single row of the summary table. Each row of the table consists of text and values separated by the vertical bar symbol ('|').
*/

void printMonthlyStatistic(int month, const struct MonthlyStatistic* monthly){
	switch (month)
	{
	case 1: printf("|   January "); break;
	case 2: printf("|  February "); break;
	case 3: printf("|     March "); break;
	case 4: printf("|     April "); break;
	case 5: printf("|       May "); break;
	case 6: printf("|      June "); break;
	case 7: printf("|      July "); break;
	case 8: printf("|    August "); break;
	case 9: printf("| September "); break;
	case 10: printf("|   October "); break;
	case 11: printf("|  November "); break;
	case 12: printf("|  December "); break;
	default:
		break;
	}
	printf("| %-5.1lf | %-5.1lf | %-5.1lf | %-7.1lf |\n", monthly->maxTemperature, monthly->minTemperature, monthly->averageTemperature, monthly->totalPrecipitation);
}
/*This function is passed :

a month as an integer(month) - 1 is January, 2 is February, ... etc.
a pointer to MonthlyStatistic struct

It will print out one single row of the precipitation bar graph
*/
void graphLine(int month, const struct MonthlyStatistic* monthly){
	int num;//define the number of stars
	switch (month)
	{
	case 1: printf("     January | "); break;
	case 2: printf("    February | "); break;
	case 3: printf("       March | "); break;
	case 4: printf("       April | "); break;
	case 5: printf("         May | "); break;
	case 6: printf("        June | "); break;
	case 7: printf("        July | "); break;
	case 8: printf("      August | "); break;
	case 9: printf("   September | "); break;
	case 10: printf("     October | "); break;
	case 11: printf("    November | "); break;
	case 12: printf("    December | "); break;
	default:
		break;
	}
	num = (monthly->totalPrecipitation + 5) / 10;
	for (int i = 0; i < num; i++)
		printf("*");
	printf("\n");
}

/*
This function is passed:

array of DailyData (yearData) - this array holds data for a full year. You may assume it is already sorted
size of array (sz)

This function print the details of the weather data for each of the records in yearData. The output of this function is sz lines, where each line shows the detailed weather information for a specific date. This information includes the date as well as the average temperature and 20 symbols based on the condition of the day. */
void printVerbose(const struct DailyData allData[], int sz){
	for (int i = 0; i < sz; i++){
		switch (allData[i].month)
		{
		case 1: printf("     January"); break;
		case 2: printf("    February"); break;
		case 3: printf("       March"); break;
		case 4: printf("       April"); break;
		case 5: printf("         May"); break;
		case 6: printf("        June"); break;
		case 7: printf("        July"); break;
		case 8: printf("      August"); break;
		case 9: printf("   September"); break;
		case 10: printf("     October"); break;
		case 11: printf("    November"); break;
		case 12: printf("    December"); break;
		default:
			break;
		}
		printf(" %3d  %3d:	%5.1lf	", allData[i].day, allData[i].year, average(allData[i].high, allData[i].low));
		draw(symbolToDraw(allData[i].condition, average(allData[i].high, allData[i].low)), 20);
	}
}
/*This function returns the correct character ('@', '~', '*', ';') given the current condition and the average temperature. Function returns '@' for condition 's', '~' for condition 'c', '*' for condition 'p' if average temperature is below 0, ; for condition 'p' othewise. */
char symbolToDraw(char condition, float avgTemp){
	switch (condition)
	{
	case's':	return '@'; break;
	case'c':	return '~'; break;
	case'p':	{if (avgTemp <= 0)
		return '*';
				else
					return ';'; }break;
	}
}
/*This function returns the average of the first and second floating point number.*/
float average(float first, float second){
	return (first + second) / 2;
}
/*This function prints the symbol passed in num times.*/
void draw(char c, int num){
	for (int i = 0; i < num; i++)
		printf("%c", c);
	printf("\n");
}
