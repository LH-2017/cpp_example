#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>
#include <cstdbool>

typedef struct _Node
{

	char name[256];
	_Node* next;
	_Node* pre;
} Node,*NodePtr;

int insertData(NodePtr *, const char*);
void processList(NodePtr list)
{
	//遍历单链表，输出数据
	Node* pNode = list;

	while (pNode)
	{
		printf("%s\t", pNode->name);
		pNode = pNode->next;
	}

	fputs("\n", stdout);
}

bool isEmpty(NodePtr list)
{
	return list == 0;
}

/**
* 从指定节点后追加节点，并将数据赋值给这个节点。
* 1. 如果列表为空，生成新节点， 赋值
* 2. 直到到达列表末端，生成新节点
*
* @author zf (09/01/2017)
*
* @param NodePtr   列表头节点指针
*
* @param const char*   数据
*
* @return int  失败返回-1， 成功返回0
*/
int appendData(NodePtr *ppNode, const char* data)
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

	strcpy(pNewNode->name, data);

	return 0;

}
int insertData(NodePtr *ppNode, const char* data)
{
	NodePtr pCurNode = *ppNode;

	if (pCurNode == 0) //表为空的情况（插入节点位置为空）
	{
		*ppNode = (NodePtr)malloc(sizeof(Node));
		memset(*ppNode, 0, sizeof(Node));
		pCurNode = *ppNode;
		//strcpy((*ppNode)->name, data);
		//strcpy(pNode->name, data);//??	
	}
	else
	{
		//1. 生成新Node
		Node* pNewNode = (Node*)malloc(sizeof(Node));
		memset(pNewNode, 0, sizeof(Node));
		//2. 插入节点的next赋值给新Node
		pNewNode->next = pCurNode->next;
		//3. 
		pCurNode->next = pNewNode;
		pCurNode = pNewNode;

	}
	//复制数据（给节点数据赋值）
	strcpy(pCurNode->name, data);

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
	while (pNode!= 0)
	{
		if (strcmp(pNode->name, data) == 0)
		{
			//1.把要删除节点的next赋值给其前一个节点的next
			if (preNode == 0)//如果是头结点，就更新列表头指针
			{
				*ppNode = (*ppNode)->next;
			}
			else
			{
				preNode->next = pNode->next;
			}
			//2. 释放要删除节点占用的内存
			free(pNode);
			break;
		}
		preNode = pNode;
		pNode = pNode->next;
	}
}

int main()
{
	NodePtr header = 0;
	Node* pCurNode = header;

	//memset(header, 0, sizeof(Node));

	char name[256];

	while (1)
	{
		fputs("input name:\n", stdout);
		memset(name, 0, 256);
		scanf("%s", name);
		insertData(&header, name);
		processList(header);

	}


	return 0;
}
