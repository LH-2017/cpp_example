/* Fig. 11.16: fig11_16.c
This program reads a random access file sequentially,
updates data already written to the file, creates new
data to be placed in the file, and deletes data
already in the file.                                  */
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>

typedef struct _Node
{

	//char name[256];
	int acctNum;
	char lastName[256];
	char firstName[256];
	int balance;
	_Node* next;
	_Node* pre;
} Node, *NodePtr;
struct clientData {
	int acctNum;
	//char *lastName;
	//char *firstName;
	char lastName[256] ;
	char firstName[256];
	int balance;
	clientData() {
		acctNum = -1;
		char lastName[256] = {0};
		char firstName[256] = {0};
		balance = -1;
	}
};
/*struct ListNode {
	clientData *data;
	ListNode *nextPtr;
	
	ListNode() :data(0), nextPtr(0) {

	}

};*/
int enterChoice(void);
void textFile(NodePtr);
void updateRecord(Node*);
void newRecord(Node*);
void deleteRecord(FILE *);
void show_info(FILE*,Node*);
void create_list(Node*, Node*, clientData*);
void init();


void init()
{
	FILE* cfPtr;

	if ((cfPtr = fopen("account.txt", "w")) == NULL)
	while (!feof(cfPtr)) {
		clientData *new_info =  (clientData*)malloc(sizeof(clientData));
		fscanf(cfPtr, "%d %s %s %d\n", new_info->acctNum, new_info->firstName, new_info->lastName, new_info->balance);
		create_list(0,0,new_info);
	}

	fclose(cfPtr);
	return ;
}
/*void create_list(Node *headerPtr, Node *tail, clientData *new_info)
{
	Node *curPtr = headerPtr;
	Node* newPtr = (Node*)malloc(sizeof(Node));
	memset(newPtr, 0, sizeof(Node));


	if (curPtr == 0) {
		curPtr = newPtr;
		//tail = curPtr;
		return;
	}
	else
	{
		newPtr->nextPtr = curPtr->nextPtr;
		curPtr->nextPtr = newPtr;
		curPtr = newPtr;
		curPtr->data = new_info;
		
	}
	//curPtr = curPtr->nextPtr;
	//tail->nextPtr = newPtr;
	//tail = tail->nextPtr;
	return;
}*/


int main()
{
	ListNode *headPtr=0;
	ListNode *tailPtr=0;
	init();
	FILE *cfPtr;
	int choice;

		while ((choice = enterChoice()) != 5) {

			switch (choice) {
			case 1:
				textFile(NodePtr);
				break;
			case 2:
			//	updateRecord(headPtr);
				break;
			case 3:
				newRecord(headPtr);
				show_info(cfPtr, headPtr);
				break;
			case 4:
			//	deleteRecord(cfPtr);
				break;
			case 5:
				show_info(cfPtr,headPtr);
				break;
			}
		

		fclose(cfPtr);
	}

	return 0;
}

void textFile(NodePtr)
{
	FILE *writePtr;
	NodePtr temPtr;

	if ((writePtr = fopen("accounts.txt", "w")) == NULL)
		printf("File could not be opened.\n");
	else {
		fprintf(writePtr, "%-6s%-16s%-11s%10s\n",
			"Acct", "Last Name", "First Name", "Balance");

		while (temPtr)
		{
			
			fprintf(writePtr, "%-6d%-16s%-11s%10.2f\n",
				temPtr->acctNum, temPtr->lastName,
				temPtr->firstName, temPtr->balance);
			temPtr = temPtr->next;


		}

		fclose(writePtr);
	}

}

int newRecord(NodePtr *ppNode, const char* data)
{
	if (*ppNode == 0)
	{
		return insertData(ppNode, data);
	}

	NodePtr pNode = *ppNode;

	while (pNode->next != 0)
	{
		pNode = pNode->next;
	}


	Node* pNewNode = (Node*)malloc(sizeof(Node));
	if (pNewNode == 0)
	{
		return -1;
	}
	memset(pNewNode, 0, sizeof(Node));

	pNode->next = pNewNode;

	strcpy(pNewNode->lastName, data);
	strcpy(pNewNode->firstName, data);

	return 0;

}

/*void updateRecord(ListNode *curPtr)
{
	int account;
	double transaction;
	int flag=0;
	ListNode *temPtr = curPtr;
//	struct clientData client = { 0, "", "", 0.0 };

	printf("Enter account to update ( 1 - 100 ): ");
	scanf("%d", &account);
	while (temPtr)
	{
		if (temPtr->data->acctNum==account)
		{
			flag = 1;
			printf("%-6d%-16s%-11s%10.2f\n\n",
				client.acctNum, client.lastName,
				client.firstName, client.balance);
			printf("Enter charge ( + ) or payment ( - ): ");
			scanf("%lf", &transaction);
			client.balance += transaction;
			printf("%-6d%-16s%-11s%10.2f\n",
				client.acctNum, client.lastName,
				client.firstName, client.balance);
		}
		else
		{
			temPtr = temPtr->nextPtr;
		}
		if (!flag)
		{
			printf("Acount #%d has no information.\n", account);
			break;
		}
	}*/
	/*fseek(fPtr,
		(account - 1) * sizeof(struct clientData),
		SEEK_SET);
	fread(&client, sizeof(struct clientData), 1, fPtr);

	if (client.acctNum == 0)
		printf("Acount #%d has no information.\n", account);
	else {
		printf("%-6d%-16s%-11s%10.2f\n\n",
			client.acctNum, client.lastName,
			client.firstName, client.balance);
		printf("Enter charge ( + ) or payment ( - ): ");
		scanf("%lf", &transaction);
		client.balance += transaction;
		printf("%-6d%-16s%-11s%10.2f\n",
			client.acctNum, client.lastName,
			client.firstName, client.balance);
		fseek(fPtr,
			(account - 1) * sizeof(struct clientData),
			SEEK_SET);
		fwrite(&client, sizeof(struct clientData), 1,
			fPtr);
	}*/
//}

/*void deleteRecord(FILE *fPtr)
{
	struct clientData client,
		blankClient = { 0, "", "", 0 };
	int accountNum;

	printf("Enter account number to "
		"delete ( 1 - 100 ): ");
	scanf("%d", &accountNum);
	fseek(fPtr,
		(accountNum - 1) * sizeof(struct clientData),
		SEEK_SET);
	fread(&client, sizeof(struct clientData), 1, fPtr);

	if (client.acctNum == 0)
		printf("Account %d does not exist.\n", accountNum);
	else {
		fseek(fPtr,
			(accountNum - 1) * sizeof(struct clientData),
			SEEK_SET);
		fwrite(&blankClient,
			sizeof(struct clientData), 1, fPtr);
	}
}
*/
void newRecord(ListNode *curPtr)
{
	curPtr = (ListNode*)malloc(sizeof(ListNode));
	clientData *new_info =new clientData;
	int flag = 0;
	ListNode *temPtr = curPtr;
	temPtr->data = new_info;
	
	
	int account;
	printf("Enter new account number ( 1 - 100 ): ");
	scanf("%d", &account);
	if (temPtr == NULL)
	{
		create_list(curPtr, 0, new_info);
	}
	while (temPtr)
	{
		if (curPtr->data->acctNum == account)
		{
			printf("Account #%d already contains information.\n");
			break;
		}
		else
		{
			printf("Enter lastname, firstname, balance\n? ");
			scanf("%s%s",new_info->firstName,new_info->lastName);
			create_list(curPtr,0,new_info);
			break;
		}
			curPtr = curPtr->nextPtr;
		
	}

	/*fseek(fPtr,
		(accountNum - 1) * sizeof(struct clientData),
		SEEK_SET);
	fread(&client, sizeof(struct clientData), 1, fPtr);

	if (client.acctNum != 0)
		printf("Account #%d already contains information.\n",
		client.acctNum);
	else {
		printf("Enter lastname, firstname, balance\n? ");
		scanf("%s%s%lf", &client.lastName, &client.firstName,
			&client.balance);
		client.acctNum = accountNum;
		fseek(fPtr, (client.acctNum - 1) *
			sizeof(struct clientData), SEEK_SET);

		fwrite(&client,
			sizeof(struct clientData), 1, fPtr);
	}*/
}
void show_info(FILE *fPtr,ListNode *curPtr)
{
	fPtr = fopen("account.txt", "w+");
	ListNode *temPtr =curPtr;

	if (fPtr == 0) {
		return;
	}

	while (temPtr) {
		clientData* client_info = temPtr->data;
		fprintf(fPtr, "%s %s %d\n", client_info->acctNum, client_info->firstName, client_info->lastName,client_info->lastName);
		temPtr = temPtr->nextPtr;
		printf( "%s %s %d\n", client_info->acctNum, client_info->firstName, client_info->lastName, client_info->lastName);
	}
	fclose(fPtr);
	
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
		"5 - end program\n? ");
	scanf("%d", &menuChoice);
	return menuChoice;
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
