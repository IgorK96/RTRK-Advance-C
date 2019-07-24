#include "functionEg.h"


int_least32_t factorial(int_least16_t n)
{
	if (n <= 1)
		return 1;
	else
		return (n * factorial(n - 1));
}

int_least32_t fibonacci(int_least16_t n)
{
	if (n  == 0)
		return 0;
	else if(n == 1)
		return 1;
	else
		return(fibonacci(n-1) + fibonacci(n-2));
}

