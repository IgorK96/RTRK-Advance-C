#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

extern int32_t sumAsm(int32_t, int32_t);
extern void printMessage();

int main(void)
{
	int32_t a =10;
	int32_t b = 3;
	int32_t c = 0;

	printf("=============================================\n");
	printf("Exercise1 - Embedded functions  \n");
	printf("=============================================\n");

	// Embedding assembly code - xor swap function // = je izlaz
	asm(" \
		eor  %0, %0, %1 \n \
		eor  %1, %1, %0 \n \
		eor  %0, %0, %1 \n"
		:"=r"(a), "=r"(b)
		:"r"(a), "r"(b)
		);
	printf("values of variables after xor swap function\n");
	printf("a = %"PRId32", b = %"PRId32", c = %"PRId32" \n\n", a, b, c);

	printf("=============================================\n");

	// Embedding assembly code - swap function using intermediary register
	asm(" \
		mov  %%r0, %0 \n \
		mov  %0, %1 \n \
		mov  %1, %%r0  \n"
		:"+r"(a), "+r"(b)
		:
		:"r0"
		);
	printf("values of variables after second swap function\n");
	printf("a = %"PRId32", b = %"PRId32", c = %"PRId32" \n\n", a, b, c);

	printf("=============================================\n");

	// Embedding assembly code - c = a + b
	printf("values of variables after adding\n");
	asm ("add  %0, %[operand1],%2  \n"
		:"=r"(c)
		:[operand1] "r"(a), "r"(b)
	);
	printf("a = %"PRId32", b = %"PRId32", c = %"PRId32"\n\n",a, b,c);
	printf("=============================================\n");

	// calling assembly function with parameters
	a = 0x10;
	b = 0x20;
	c = sumAsm(a, b);
	printf("values of variables after sumAsm function call\n");
	printf("a = %"PRId32", b = %"PRId32", c = %"PRId32"\n\n",a, b,c);
	printf("=============================================\n");

	// calling assembly function without paramaters
	printf("printMessage function call       \n");
	printMessage();

	return EXIT_SUCCESS;
}
