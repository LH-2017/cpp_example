#include "stack_arr.h"
#include <stdio.h>


void instructions(void);
int main()
{
	StackPtr stackPtr = NULL;  /* points to stack top */
	int choice;
	char value;
	instructions();
	printf("? ");
	scanf("%d", &choice);

	while (choice != 4) {

		switch (choice) {
		case 1:      /* push value onto stack */
			printf("Enter an integer: ");
			scanf("\n%c", &value);
			inStack(&stackPtr, value);
			break;
		case 2:      /* pop value off stack */
			if (!is_empty(stackPtr))
			{
				 outStack(&stackPtr);
				
			}
			break;
		case 3:
			printf("stack elemments:\n\t");
			searchStack(stackPtr);
			printf("\n");
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
		"3 to search the value of the stack\n"
		"4 to end program\n");
}
