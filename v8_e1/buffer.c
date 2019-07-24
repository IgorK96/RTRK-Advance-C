#include "buffer.h"


void CircularInit(Circle_Buff* Init)
{
	Init->front = Init->rear = Init ->buffer;
}

int CircularIsFull(Circle_Buff* Init)
{
	if(((Init->front - Init->rear) == 1) || ((Init->rear - Init->front) == (BUFF_SIZE-1)))
	{
		printf("Buffer is full !!! \n");
		return 1;
	}else return 0;
}

int circularIsEmpty(Circle_Buff* Init)
{
	if(Init->front == Init->rear)
	{
		printf("Buffer is empty !!! \n");
		return 1;
	}else return 0;
}

void CircularPut(Circle_Buff* Init, Buff_type n)
{

	if(Init->front == (Init->buffer)+BUFF_SIZE-1)
		{
			Init->front = Init->front - BUFF_SIZE;
		}
	*(Init->front) = n;
	Init->front++;
}

void CircularGet(Circle_Buff* Init, Buff_type n)
{
	n=*(Init->rear) ;
		if(Init->rear == Init->buffer+BUFF_SIZE-1)
		{
			Init->rear = Init->rear - BUFF_SIZE;
		}
	Init->rear++;
}

void CircularEmptyBuff(Circle_Buff* Init)
{
		Init->front = Init->rear;
}

void CircularDump(Circle_Buff* Init)
{
	int_least8_t i;
	int_least32_t n;
	if(circularIsEmpty(Init) == 0)
	{
		for(i = 0; i<BUFF_SIZE; i++)
		{
			n = *(Init->front);
			printf("%"PRIdLEAST32,n);
			printf("\n");
			//Init->front ++;
		}
	}else printf("Buffer is empty, nothing to print!!!");
}
