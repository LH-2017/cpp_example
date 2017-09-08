/* Fig. 12.8: fig12_08.c
dynamic stack program */
#include <stdio.h>
#include <stdlib.h>

struct stackNode {   /* self-referential structure */
	int data;
	struct stackNode *nextPtr;
};  

typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void push(StackNodePtr *, int);
int pop(StackNodePtr *);
int isEmpty(StackNodePtr);
void printStack(StackNodePtr);
void instructions(void);

int main()
{
	StackNodePtr stackPtr = NULL;  /* points to stack top */
	int choice, value;

	instructions();
	printf("? ");
	scanf("%d", &choice);

	while (choice != 3) {

		switch (choice) {
		case 1:      /* push value onto stack */
			printf("Enter an integer: ");
			scanf("%d", &value);
			push(&stackPtr, value);
			printStack(stackPtr);
			break;
		case 2:      /* pop value off stack */
			if (!isEmpty(stackPtr))
				printf("The popped value is %d.\n",
				pop(&stackPtr));

			printStack(stackPtr);
			break;
		default:
			printf("Invalid choice.\n\n");
			instructions();
			break;
		}

		printf("? ");
		scanf("%d", &choice);
	}

	printf("End of run.\n");
	return 0;
}

/* Print the instructions */
void instructions(void)
{
	printf("Enter choice:\n"
		"1 to push a value on the stack\n"
		"2 to pop a value off the stack\n"
		"3 to end program\n");
}

/* Insert a node at the stack top */
void push(StackNodePtr *topPtr, int info)
{
	StackNodePtr newPtr;

	newPtr = (StackNode*)malloc(sizeof(StackNode));
	if (newPtr != NULL) {
		newPtr->data = info;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	}
	else
		printf("%d not inserted. No memory available.\n",
		info);
}

/* Remove a node from the stack top */
int pop(StackNodePtr *topPtr)
{
	StackNodePtr tempPtr;
	int popValue;

	tempPtr = *topPtr;
	popValue = (*topPtr)->data;
	*topPtr = (*topPtr)->nextPtr;
	free(tempPtr);
	return popValue;
}

/* Print the stack */
void printStack(StackNodePtr currentPtr)
{
	if (currentPtr == NULL)
		printf("The stack is empty.\n\n");
	else {
		printf("The stack is:\n");

		while (currentPtr != NULL) {
			printf("%d --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		printf("NULL\n\n");
	}
}

/* Is the stack empty? */
int isEmpty(StackNodePtr topPtr)
{
	return topPtr == NULL;
}



/**************************************************************************
* (C) Copyright 2000 by Deitel & Associates, Inc. and Prentice Hall.     *
* All Rights Reserved.                                                   *
*                                                                        *
* DISCLAIMER: The authors and publisher of this book have used their     *
* best efforts in preparing the book. These efforts include the          *
* development, research, and testing of the theories and programs        *
* to determine their effectiveness. The authors and publisher make       *
* no warranty of any kind, expressed or implied, with regard to these    *
* programs or to the documentation contained in these books. The authors *
* and publisher shall not be liable in any event for incidental or       *
* consequential damages in connection with, or arising out of, the       *
* furnishing, performance, or use of these programs.                     *
*************************************************************************/
