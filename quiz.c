int main()

{

	int ar1[] = { 6, 3, 0, 2, 4 };

	float ar2[5] = { 3.2, 5.1, 8.4, 4.8 };

	char ar3[5];

	int i = 5, j, k;

	while (i--)

		ar3[i] = 'f' - i;

	k = 0;

	for (i = 0; i < 5; i++)

	{

		k--;

		for (j = 0; j < 5; j++)

		{

			k++;

			ar2[i] += ar1[j];

		}

		ar1[4 - i] += k;

	}



	for (i = 0; i < 5; i++)

		printf("%d - %.1f - %c\n", ar1[i], ar2[i], ar3[i]);

	return 0;

}
