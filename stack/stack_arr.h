#ifndef _STACK_ARR_H_
#define _STACK_ARR_H_
#include<stdbool.h>
typedef struct _Stack
{
	char *data;
	int size;
	int capacity;
}Stack,*StackPtr;
static const int ALLOC_STEP = 100;
void inStack(StackPtr *StackPtr,const char data);
char outStack(StackPtr *StackPtr);
void searchStack(StackPtr );
bool is_empty(StackPtr);

#endif