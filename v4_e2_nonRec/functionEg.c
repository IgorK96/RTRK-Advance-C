#include "functionEg.h"


int_least32_t factorial(int_least16_t n)
{
	int_least16_t i;
	int_least16_t res = 1;

	for(i = 1; i <= n; i++){
		res = res * i;
	}

	return res;
}

int_least32_t fibonacci(int_least16_t n)
{
	int_least16_t a = 0;
	int_least16_t b = 1;
	int_least16_t c;
	int_least16_t i;


	if (n  == 0)
		return a;

	for(i =2; i <= n; i++){
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}

