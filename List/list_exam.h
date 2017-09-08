#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct _Node
{
	char name[256];
	Node* next;
} Node, *NodePtr;
  
int main()
{
	Node *header = (Node*)malloc(sizeof(Node));
	Node* pCurNode = header;

	memset(header, 0, sizeof(Node));

	char name[256];

	while (1)
	{
		fputs("input name:\n", stdout);
		memset(name, 0, 256);
		scanf("%s", name);

		//�ҵ����ýڵ�
		while (pCurNode->name[0] != '\0')
		{
			if (pCurNode->next == 0)
			{
				Node* pNode = (Node*)malloc(sizeof(Node));
				memset(pNode, 0, sizeof(Node));
				pCurNode->next = pNode;
			}
			pCurNode = pCurNode->next;
		}

		strcpy(pCurNode->name, name);//��ֵ

		//�����������������
		Node* pNode = header;

		while (pNode)
		{
			printf("%s\t", pNode->name);
			pNode = pNode->next;
		}

		fputs("\n", stdout);

	}


	return 0;
}
