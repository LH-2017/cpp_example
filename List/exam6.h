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
	int acctNum;
	char lastName[256];
	char firstName[256];
	double balance;
	//clientData *data;
	Node *next;
}*NodePtr;

int insertData(NodePtr *listPtr, int acc,char last_Name[256],char first_Name[256],double bala);
int addData(NodePtr *listPtr, int acc, char last_Name[256], char first_Name[256], double bala);
int addData(NodePtr *listPtr, int acc, char last_Name[256], char first_Name[256], double bala)
{
	if (*listPtr == 0)
	{
		return insertData(listPtr, acc,last_Name,first_Name, bala);
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
	curPtr->acctNum = acc;
	strcpy(curPtr->firstName ,first_Name);
	strcpy(curPtr->lastName, last_Name);
	curPtr->balance = bala;

	return 0;

}

int insertData(NodePtr *listPtr, int acc, char last_Name[256], char first_Name[256], double bala)
{

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
	printf("Enter lastname, firstname, balance\n? ");
	scanf("%d%s%s%lf", &acc,first_Name, last_Name, &bala);
	//curPtr->data = data_info;
	curPtr->acctNum = acc;
	strcpy(curPtr->firstName, first_Name);
	strcpy(curPtr->lastName, last_Name);
	curPtr->balance = bala;

	return 0;
}
int deleteData(NodePtr *curPtr, int account)
{
	if (curPtr == 0 || *curPtr == 0)
	{
		return -1;
	}
	NodePtr temPtr = *curPtr;
	NodePtr preNode = 0;
	while (temPtr != 0)
	{
		if (temPtr->acctNum==account)
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
NodePtr findData(NodePtr *list, int data)
{
	if (list == 0 || *list == 0)
	{
		return (NodePtr)(-1);
	}
	NodePtr curPtr = *list;
	NodePtr prePtr = 0;
	while (curPtr != 0)
	{
		if (curPtr->acctNum == data)
		{
			printf("%d\t%s\t%s\t%lf\n", curPtr->acctNum, curPtr->firstName, curPtr->lastName, curPtr->balance);
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
int updateData(NodePtr *curPtr, int acc, char last_Name[256], char first_Name[256], double bala)
{
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
		if (temPtr->acctNum == acc)
		{
			printf("%-6d%-16s%-11s%10.2f\n\n",
				temPtr->acctNum, temPtr->lastName,
				temPtr->firstName, temPtr->balance);
			printf("Enter charge ( + ) or payment ( - ): ");
			scanf("%lf", &transaction);
			temPtr->balance += transaction;
			printf("%-6d%-16s%-11s%10.2f\n",
				temPtr->acctNum, temPtr->lastName,
				temPtr->firstName, temPtr->balance);

		}
		preNode = temPtr;
		temPtr = temPtr->next;
	}
}
int saveData(NodePtr listPtr)
{
	FILE *writePtr;
	NodePtr temPtr = listPtr;
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
			fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n",
				temPtr->acctNum, temPtr->firstName, temPtr->lastName, temPtr->balance);
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
		printf("%d\t%s\t%s\t%lf\n", curPtr->acctNum, curPtr->firstName, curPtr->lastName, curPtr->balance);
		curPtr = curPtr->next;
	}

	fputs("\n", stdout);
}
int enterChoice(void)
{
	int menuChoice;

	printf("\nEnter your choice\n"
		"1 -search an data_info\n"
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
	int acc=0;
	char last_Name[256] = {0};
	char first_Name[256] = {0};
	double bala=0;
	int choice;
	bool exit = false;
	while ((choice = enterChoice()))
	{

		switch (choice)
		{
		case 1:
			printf("Enter tne accNum you need to d\n? ");
			scanf("%d", &acc);
			findData(&headPtr,acc);
			break;
		case 2:
			updateData(&headPtr, acc, first_Name, last_Name, bala);
			break;
		case 3:
			insertData(&headPtr,acc,first_Name,last_Name,bala);
			break;
		case 4:
			printf("Enter tne accNum you need to delete\n? ");
			scanf("%d", &acc);
			deleteData(&headPtr,acc);
			break;
		case 5:
			print_list(headPtr);
			break;
		case 6:
			exit = true;
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