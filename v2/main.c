#include <stdio.h>
#include <stdint.h>

enum tresholds_t
{
	TRESHOLDS_FIRST = 10,
	TRESHOLDS_SECOND,
	TRESHOLDS_THIRD = 20
};


void sort(int_least8_t* values, int_least8_t* indexes, int_least8_t n)
{
	int_least8_t i;
	int_least8_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] - values[j] < 0)
			{
				int_least8_t tmp;
				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp;
			}
		}
	}
}


void print(int_least8_t* values, int_least8_t* indexes, int_least8_t n)
{
	int_least8_t i = 0;
	printf("Up to the first treshold: ");
	while (values[i] > TRESHOLDS_THIRD && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
	printf("Up to the second treshold: ");
	while (values[i] > TRESHOLDS_SECOND && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
	printf("Up to the third treshold: ");
	while (values[i] > TRESHOLDS_FIRST && i < n)
	{
		printf("%d(%d) ", values[i], indexes[i]);
		i++;
	}
}


void main()
{
	int_least32_t values[30000];
	int_least32_t indexes[30000];
	int_least8_t i;
	int_least8_t n;
	printf("Number of elements: ");
	scanf("%d", &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%d. element: ", i);
		scanf("%d", &values[i]);
		indexes[i] = i;
		printf("\n");
	}

	sort(values, indexes, n);

	print(values, indexes, n);
}
