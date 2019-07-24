#include "buffer.h"

int main()
{
	Circle_Buff New_buff;
	Buff_type p,g;
	p = 5;
	g = 0;
	CircularInit(&New_buff);
	CircularPut(&New_buff, p);
	CircularPut(&New_buff, g);
	//CircularGet(&New_buff, g);
	CircularDump(&New_buff);

	return 0;
}
