/* Fig. 12.13: fig12_13.c
Operating and maintaining a queue */

#include <stdio.h>
#include <stdlib.h>

struct queueNode {   /* self-referential structure */
	char data;
	struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

/* function prototypes */
void printQueue(QueueNodePtr);
int isEmpty(QueueNodePtr);
char dequeue(QueueNodePtr *, QueueNodePtr *);
void enqueue(QueueNodePtr *, QueueNodePtr *, char);
void instructions(void);

int main()
{
	QueueNodePtr headPtr = NULL, tailPtr = NULL;
	int choice;
	char item;

	instructions();
	printf("? ");
	scanf("%d", &choice);

	while (choice != 3) {

		switch (choice) {

		case 1:
			printf("Enter a character: ");
			scanf("\n%c", &item);
			enqueue(&headPtr, &tailPtr, item);
			printQueue(headPtr);
			break;
		case 2:
			if (!isEmpty(headPtr)) {
				item = dequeue(&headPtr, &tailPtr);
				printf("%c has been dequeued.\n", item);
			}

			printQueue(headPtr);
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

void instructions(void)
{
	printf("Enter your choice:\n"
		"   1 to add an item to the queue\n"
		"   2 to remove an item from the queue\n"
		"   3 to end\n");
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr,
	char value)
{
	QueueNodePtr newPtr;

	newPtr = (QueueNode*)malloc(sizeof(QueueNode));

	if (newPtr != NULL) {
		newPtr->data = value;
		newPtr->nextPtr = NULL;

		if (isEmpty(*headPtr))
			*headPtr = newPtr;
		else
			(*tailPtr)->nextPtr = newPtr;

		*tailPtr = newPtr;
	}
	else
		printf("%c not inserted. No memory available.\n",
		value);
}

char dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr)
{
	char value;
	QueueNodePtr tempPtr;

	value = (*headPtr)->data;
	tempPtr = *headPtr;
	*headPtr = (*headPtr)->nextPtr;

	if (*headPtr == NULL)
		*tailPtr = NULL;

	free(tempPtr);
	return value;
}

int isEmpty(QueueNodePtr headPtr)
{
	return headPtr == NULL;
}

void printQueue(QueueNodePtr currentPtr)
{
	if (currentPtr == NULL)
		printf("Queue is empty.\n\n");
	else {
		printf("The queue is:\n");

		while (currentPtr != NULL) {
			printf("%c --> ", currentPtr->data);
			currentPtr = currentPtr->nextPtr;
		}

		printf("NULL\n\n");
	}
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
