
#ifndef BUFFER_H_
#define BUFFER_H_

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

typedef int_least32_t Buff_type;
#define BUFF_SIZE 10

typedef struct
{
	Buff_type buffer[BUFF_SIZE];
	Buff_type *front;
	Buff_type *rear;

}Circle_Buff;

void CircularInit(Circle_Buff* buff);
int CircularIsFull(Circle_Buff* Init);
int CircularIsEmpty(Circle_Buff* Init);
void CircularPut(Circle_Buff* Init, Buff_type n);
void CircularGet(Circle_Buff* Init, Buff_type n);
void CircularEmptyBuff(Circle_Buff* Init);
void CircularDump(Circle_Buff* Init);

#endif /* BUFFER_H_ */
