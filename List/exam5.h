#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>

struct clientData
{
	int acctNum;
	char lastName[256];
	char firstName[256];
	double balance;
};
typedef struct Node
{
	clientData *data;
	Node *next;
}*NodePtr;

int insertData(NodePtr *listPtr);
int addData(NodePtr *listPtr, clientData *data_info);
int addData(NodePtr *listPtr, clientData *data_info)
{
	if (*listPtr == 0)
	{
		return insertData(listPtr);
	}
	NodePtr curPtr = *listPtr;
	while (curPtr->next != 0)
	{
		curPtr = curPtr->next;
	}
	Node* newPtr = (Node*)malloc(sizeof(Node));
	if (newPtr == 0)
	{
		return -1;
	}
	memset(newPtr, 0, sizeof(Node));
	curPtr->next = newPtr;
	newPtr->data = data_info;

	return 0;

}
int insertData(NodePtr *listPtr)
{
	clientData *data_info = new clientData;
	printf("Enter acctNum,lastname, firstname, balance\n? ");
	scanf("%d%s%s%lf", &data_info->acctNum, data_info->firstName, data_info->lastName, &data_info->balance);
	NodePtr curPtr = *listPtr;
	if (curPtr == 0)
	{
		*listPtr = (NodePtr)malloc(sizeof(Node));
		memset(*listPtr, 0, sizeof(Node));
		curPtr = *listPtr;
	}
	else
	{
		Node *newPtr = (Node*)malloc(sizeof(Node));
		memset(newPtr, 0, sizeof(Node));
		newPtr->next = curPtr->next;
		curPtr->next = newPtr;
		curPtr = newPtr;

	}
	curPtr->data = data_info;
	
	return 0;
}
int deleteData(NodePtr *curPtr)
{
	int account;
	printf("Enter tne accNum you need to delete\n? ");
	scanf("%d", &account);
	if (curPtr == 0 || *curPtr == 0)
	{
		return -1;
	}
	NodePtr temPtr = *curPtr;
	NodePtr preNode = 0;
	while (temPtr != 0)
	{
		if (temPtr->data->acctNum == account)
		{
			if (preNode == 0)
			{
				*curPtr = (*curPtr)->next;
			}
			else
			{
				preNode->next = temPtr->next;
			}
			free(temPtr);
			break;
		}
		preNode = temPtr;
		temPtr = temPtr->next;
	}
}
NodePtr findData(NodePtr *list)
{
	int data;
	printf("Enter tne accNum you need to search\n? ");
	scanf("%d", &data);
	if (list == 0 || *list == 0)
	{
		return (NodePtr)(-1);
	}
	NodePtr curPtr = *list;
	NodePtr prePtr = 0;
	while (curPtr != 0)
	{
		if (curPtr->data->acctNum == data)
		{
			printf("%d\t%s\t%s\t%lf\n", curPtr->data->acctNum, curPtr->data->firstName, curPtr->data->lastName, curPtr->data->balance);
			break;
		}
		else
		{
			if (curPtr->next == NULL)
			{
				printf("not found\n");
			}
		}
		prePtr = curPtr;
		curPtr = curPtr->next;
	}
	return 0;

}
int updateData(NodePtr *curPtr)
{
	int acc;
	double transaction;
	printf("Enter account to update ( 1 - 100 ): ");
	scanf("%d", &acc);
	if (curPtr == 0 || *curPtr == 0)
	{
		return -1;
	}
	NodePtr temPtr = *curPtr;
	NodePtr preNode = 0;
	while (temPtr != 0)
	{
		if (temPtr->data->acctNum == acc)
		{
			printf("%-6d%-16s%-11s%10.2f\n\n",
				temPtr->data->acctNum, temPtr->data->lastName,
				temPtr->data->firstName, temPtr->data->balance);
			printf("Enter charge ( + ) or payment ( - ): ");
			scanf("%lf", &transaction);
			temPtr->data->balance += transaction;
			printf("%-6d%-16s%-11s%10.2f\n",
				temPtr->data->acctNum, temPtr->data->lastName,
				temPtr->data->firstName, temPtr->data->balance);

		}
		preNode = temPtr;
		temPtr = temPtr->next;
	}
}
int saveData(NodePtr listPtr)
{
	FILE *writePtr;
	NodePtr temPtr=listPtr;
	if ((writePtr = fopen("accounts.txt", "w")) == NULL)
	{
		printf("File could not be opened.\n");
	}
	else
	{
		fprintf(writePtr, "%-6s%-16s%-11s%10s\n",
			"Acct", "Last Name", "First Name", "Balance");

		while (temPtr)
		{
			clientData *new_data_info = temPtr->data;
			fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n",
				new_data_info->acctNum, new_data_info->firstName, new_data_info->lastName, new_data_info->balance);
			temPtr = temPtr->next;

		}

		fclose(writePtr);
	}
	return 0;
}
void print_list(NodePtr list)
{
	Node* curPtr = list;
	while (curPtr)
	{
		printf("%d\t%s\t%s\t%lf\n", curPtr->data->acctNum,curPtr->data->firstName,curPtr->data->lastName,curPtr->data->balance);
		curPtr = curPtr->next;
	}

	fputs("\n", stdout);
}
int enterChoice(void)
{
	int menuChoice;

	printf("\nEnter your choice\n"
		"1 - store a formatted text file of acounts called\n"
		"    \"accounts.txt\" for printing\n"
		"2 - update an account\n"
		"3 - add a new account\n"
		"4 - delete an account\n"
		"5 - print the data_info\n"
		"6 - end program\n? ");
	scanf("%d", &menuChoice);
	return menuChoice;
}

int main()
{
	NodePtr headPtr = 0;
	Node *curPtr = headPtr;
	
	int choice;
	bool exit = false;
	while ((choice = enterChoice())) 
	{

		switch (choice)
		{
		case 1:
			findData(&headPtr);
			break;
		case 2:
			updateData(&headPtr);
			break;
		case 3:
			
			insertData(&headPtr);
			break;
		case 4:
			deleteData(&headPtr);
			break;
		case 5:
			print_list(headPtr);
			break;
		case 6:
			exit=true;
			break;
		default:
				break;
		}
		if (exit) {
			saveData(headPtr);
			return -1;
		}



	}

	return 0;
	
	
}