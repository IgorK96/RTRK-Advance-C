#include "file3.h"
#include <stdio.h>
void use_it(){

	global_variable = increment();
	printf(" Vrednost globalne : %d ",global_variable);

}

void main()
{
	use_it();

}
