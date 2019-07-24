#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

int main()
{
	int32_t i = 0;
	int32_t x = 10;
	int32_t y = 20;

	for (i=0; i<5; i++)
	{
		int32_t x = 0;
		static int32_t y = 0; // statik(kada je unutar bloka uz promenljivu) je ovde kao trejnost A NE VIDLJIVOST statik ovde pamti vrednost u svakoj petlji
		printf("x=%"PRId32", y=%"PRId32"\n", x++, y++); //ispisi x i y pa povecaj x i y
	}

	printf("\nx=%"PRId32", y=%"PRId32"\n", x++, y++);
	return 0;
}
