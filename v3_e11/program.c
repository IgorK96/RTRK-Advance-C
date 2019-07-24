#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


static const int_least32_t TRESHOLD = 20;

void sort( int_least32_t* values, int_least16_t* indexes, int_least16_t n)//menjamo vrednost pa nemoze const
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (values[i] < values[j])
			{
				int_least32_t tmp;
				int_least16_t tmp1;

				tmp = values[i];
				values[i] = values[j];
				values[j] = tmp;

				tmp1 = indexes[i];
				indexes[i] = indexes[j];
				indexes[j] = tmp1;
			}
		}
	}
}


void print(const int_least32_t* values,const int_least16_t* indexes, int_least16_t n) //samo po adresi ide const NE po vrednosti
{
	int_least16_t i = 0;
	printf("Up to the first treshold: ");
	while (values[i] > TRESHOLD && i < n)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", values[i], indexes[i]);
		i++;
	}
	printf("\n");
}


	static int_least32_t values[40000];
	static int_least16_t indexes[40000];


void main()
{
	int_least16_t i;
	const int_least16_t n;

	printf("Number of elements: ");
	scanf("%"SCNdLEAST16"", &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32"", &values[i]);
		indexes[i] = i;
		printf("\n");
	}

	sort(values, indexes, n);

	print(values, indexes, n);
}
