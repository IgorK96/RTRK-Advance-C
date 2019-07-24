#include <stdint.h>
#include <stdio.h>

static int_least16_t global_variable = 33;

void print_value()
{
	printf(" Vrednost globalne = %d ", global_variable);
}
