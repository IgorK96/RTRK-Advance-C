#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>


static const int_least32_t treshold_array[3] = {20, 30, 40};




typedef struct _s
{
	int_least32_t value;
	int_least16_t index;
} val_ind_struct_t;

static val_ind_struct_t struct_array[4000];

static int compareMyType (const void* a, const void* b)
{
	val_ind_struct_t* pa =a;
	val_ind_struct_t* pb =b;

	return (pb->value - pa->value);
}

static void bubble_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	int_least16_t i;
	int_least16_t j;
	for (i = 0; i < (n - 1); i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (str_array[i].value < str_array[j].value)
			{
				val_ind_struct_t tmp;

				tmp = str_array[i];
				str_array[i] = str_array[j];
				str_array[j] = tmp;
			}
		}
	}
}


static void quick_sort(val_ind_struct_t* str_array, int_least16_t n)
{
	qsort(str_array, n, sizeof(val_ind_struct_t), compareMyType);
}


static void print(const val_ind_struct_t* str_array, int_least16_t n, int_fast8_t tr_index)
{
	int_least16_t i = 0;
	int_least32_t treshold;
	printf("Up to the %"PRIdFAST8". treshold: ", tr_index);

	treshold = treshold_array[tr_index - 1];

	while (str_array[i].value > treshold && i < n)
	{
		printf("%"PRIdLEAST32"(%"PRIdLEAST16") ", str_array[i].value, str_array[i].index);
		i++;
	}
	printf("\n");
}


void main()
{
	int_least16_t i;
	int_least16_t n;
	int_fast8_t treshold_index;
	int_fast8_t sort_index;

	void (*sort_function[2])(val_ind_struct_t*, int_fast8_t) ={bubble_sort, quick_sort};

	printf("Number of elements: ");
	scanf("%"SCNdLEAST16, &n);
	printf("\n");
	for (i = 0; i < n; i++)
	{
		printf("%"PRIdLEAST16". element: ", i);
		scanf("%"SCNdLEAST32, &(struct_array[i].value));
		struct_array[i].index = i;
		printf("\n");
	}
	printf("Trashold you want to use (1, 2, or 3): ");
	scanf("%"SCNdFAST8, &treshold_index);
	printf("\n");
	printf("Sorting algorithm you want to use (1- bubble, 2- quick): ");
	scanf("%"SCNdFAST8, &sort_index);
	printf("\n");



	(sort_function[sort_index-1])(struct_array, n);//-1 jer smo unosili 1 ,2 a krece od 0


	print(struct_array, n, treshold_index);
}
