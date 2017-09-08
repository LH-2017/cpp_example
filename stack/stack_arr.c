#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include "stack_arr.h"



void inStack(StackPtr *stackPtr,const char data)
{
	assert(stackPtr != 0);
	if (*stackPtr == 0)
	{
		*stackPtr = calloc(1, sizeof(Stack));
	}
	if ((*stackPtr)->size + 1 > (*stackPtr)->capacity)
	{
		(*stackPtr)->data = realloc((*stackPtr)->data, (*stackPtr)->capacity + ALLOC_STEP);
		(*stackPtr)->capacity = (*stackPtr)->capacity + ALLOC_STEP;
	}
	(*stackPtr)->data[(*stackPtr)->size] = data;
	(*stackPtr)->size++;
}
char outStack(StackPtr *stackPtr)
{
	assert(stackPtr != 0 && *stackPtr != 0 && (*stackPtr)->size != 0);
	(*stackPtr)->size--;
	printf("The popped value is %c\n", (*stackPtr)->data[(*stackPtr)->size]);
	
}
void searchStack(StackPtr stackPtr)
{
	assert(stackPtr != 0);
	for (int i = stackPtr->size-1; i >= 0; i--)
	{
		printf("%c", stackPtr->data[i]);
		printf("--> ");
	}
	printf("NULL");
}
bool is_empty(StackPtr stackPtr)
{
	return (stackPtr)->size == 0;
}