#include <cstdlib>
#include <stdio.h>
#include <cstdint>
#include <cstring>


struct Node
{
	char name[256];
	Node* next;
};


int main()
{
	Node *header = (Node*)malloc(sizeof(Node));
	Node* pCurNode = header;

	memset(header, 0, sizeof(Node));

	char name[256];
	memset(name, 0, 256);
	while (1)
	{
		fputs("input name:\n", stdout);
		scanf("%s", name);

		//找到可用节点
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
		
		strcpy_s(pCurNode->name, name);//赋值

		//遍历单链表，输出数据
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
