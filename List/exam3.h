#define _CRT_SECURE_NO_WARNINGS

//#include "pointer.h"

//#include "string_test.h"
//#include "shuffle.h"

//#include "file_test.h"

#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdbool>

typedef enum _Sex
{
	MALE=1,
	FEMALE

}Sex;

typedef struct _Node
{
	char name[256];
	int  salary;
	Sex  sex;
	struct _Node* next;
} Node, *NodePtr;


void processList(NodePtr list)
{
	//�����������������
	Node* pNode = list;
	int row = 1;
	while (pNode != 0)
	{
		printf(":%d\tname:%s\tsalary:%d\tsex:%d\n", row,pNode->name, pNode->salary, pNode->sex);
		//printf(":%d\t%s\n", row, pNode->name);
		pNode = pNode->next;
		row++;
	}

	fputs("\n", stdout);
}

bool isEmpty(NodePtr list)
{
	return list == 0;
}

int insertData(NodePtr *ppNode, const char* name, int sala, Sex s)
{
	
	NodePtr pCurNode = *ppNode;

	if (pCurNode == 0) //��Ϊ�յ����������ڵ�λ��Ϊ�գ�
	{
		*ppNode = (NodePtr)malloc(sizeof(Node));
		memset(*ppNode, 0, sizeof(Node));
		pCurNode = *ppNode;
	}
	else
	{
		//1. ������Node
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		//2. ����ڵ��next��ֵ����Node
		pNewNode->next = pCurNode->next;
		//3. 
		pCurNode->next = pNewNode;

		pCurNode = pNewNode;//���µ�ǰ���
	}
	//�������ݣ����ڵ����ݸ�ֵ��
	strcpy(pCurNode->name, name);
	pCurNode->salary = sala;
	pCurNode->sex = s;
	return 0;
}

/**
* ��ָ���ڵ��׷�ӽڵ㣬�������ݸ�ֵ������ڵ㡣
* 1. ����б�Ϊ�գ������½ڵ㣬 ��ֵ
* 2. ֱ�������б�ĩ�ˣ������½ڵ�
*
* @author zf (09/01/2017)
*
* @param NodePtr   �б�ͷ�ڵ�ָ��
*
* @param const char*   ����
*
* @return int  ʧ�ܷ���-1�� �ɹ�����0
*/
int appendData(NodePtr *ppNode, const char* data, int sala,Sex s)
{
	
	if (*ppNode == 0)
	{
		return insertData(ppNode, data,sala,s);
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

	strcpy(pNewNode->name, data);
	pNewNode->salary = sala;
	pNewNode->sex = s;

	return 0;

}


int deleteData(NodePtr *ppNode, const char* data)
{
	if (ppNode == 0 || *ppNode == 0)
	{
		return -1;
	}
	NodePtr pNode = *ppNode;
	NodePtr preNode = 0;
	while (pNode != 0)
	{
		if (strcmp(pNode->name, data) == 0)
		{
			//1.��Ҫɾ���ڵ��next��ֵ����ǰһ���ڵ��next
			if (preNode == 0)//�����ͷ��㣬�͸����б�ͷָ��
			{
				*ppNode = (*ppNode)->next;
			}
			else
			{
				preNode->next = pNode->next;
			}
			//2. �ͷ�Ҫɾ���ڵ�ռ�õ��ڴ�
			free(pNode);
			break;
		}
		preNode = pNode;
		pNode = pNode->next;
	}
}

void printNodeInfo(const NodePtr pNode)
{
	
	
		printf("name:%s\tsalary:%d\tsex:%d\n",pNode->name,pNode->salary,pNode->sex);
		
	
}

NodePtr findData(NodePtr *list, const char* name)
{
	if (list == 0 || *list == 0)
	{
		return (NodePtr)(-1) ;
	}
	NodePtr pNode = *list;
	NodePtr preNode = 0;
	while (pNode != 0)
	{
		if (strcmp(pNode->name, name) == 0)
		{
			printNodeInfo(pNode);
			break;
		}
		else
		{
			if (pNode->next == NULL)
			{
				printf("not found\n");
			}
		}
		preNode = pNode;
		pNode = pNode->next;
	}
	return 0;

}



int enterChoice(void)
{
	int menuChoice;

	printf("\nEnter your choice\n"
		"1 - add a new account\n"
		"2 - delete an account\n"
		"3 - print account info\n"
		"4 - print list contents\n"
		"5 - end program\n? ");
	scanf("%d", &menuChoice);
	return menuChoice;
}

int main()
{
	NodePtr header = 0;
	Node* pCurNode = header;

	char name[256];
	int sala ;
	Sex s ;

	while (1)
	{
		int choice = enterChoice();
		switch (choice)
		{
		case 1:
		{
				  fputs("input name,salary,sex:\n", stdout);
				  memset(name, 0, 256);
				 // scanf("%s%d", &name, &sala);
				  scanf("%s%d%d", &name,&sala,&s);
				  appendData(&header, name,sala,s);
		}
			break;
		case 2:
		{
				  fputs("input the name(delete):\n", stdout);
				  memset(name, 0, 256);
				  scanf("%s", name);
				  deleteData(&header, name);

		}
			break;
		case 3:
		{
				  fputs("input the name to find:\n", stdout);
				  memset(name, 0, 256);
				  scanf("%s", name);
				  NodePtr pNode = findData(&header, name);
				 /*if (pNode != 0)
				  {
					  printNodeInfo(pNode);
				  }
				  else
				  {
					  printf("not found\n");
				  }*/

				
		}
			break;
		case 4:
		{
				  fputs("list contents:\n", stdout);
				  processList(header);
		}
			break;
		default:
			return 0;
		}

	}

	return 0;
}