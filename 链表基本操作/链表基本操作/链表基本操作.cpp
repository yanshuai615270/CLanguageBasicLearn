/* 
链表基本操作.cpp 
链表的增删查改基本操作。
*/

#include "stdafx.h"

typedef struct ListNode 
{
	int value;
	ListNode* pNextListNode;
};

ListNode* insertNodeToListTail(ListNode* pHead)
{
	ListNode* pNewListNode = NULL;
	ListNode* pCurListNode = NULL;
	int value = 0;

	printf("enter the num you want to add at tail: \n");
	scanf("%d", &value);
	pNewListNode = (ListNode*)malloc(sizeof(ListNode));
	pNewListNode->value = value;
	pNewListNode->pNextListNode = NULL;
	if (NULL == pHead)
	{
		pHead = pNewListNode;
	}
	else
	{
		pCurListNode = pHead;
		while (pCurListNode->pNextListNode)
		{
			pCurListNode = pCurListNode->pNextListNode;
		}
		pCurListNode->pNextListNode = pNewListNode;
	}
	return pHead;
}

ListNode* deleteNodeFromList(ListNode* pHead)
{
	ListNode* pNodeToDel = NULL;
	ListNode* pNodeCur = NULL;
	int ValueOfNodeDel = 0;
	
	if (NULL == pHead || NULL == pHead->pNextListNode)
		return NULL;

	printf("enter the num you want to del: \n");
	scanf("%d", ValueOfNodeDel);
	pNodeCur = pHead;

	if (ValueOfNodeDel == pHead->value)
	{
		pNodeToDel = pHead;
		pHead = pHead->pNextListNode;
	}
	else
	{
		while (pNodeCur->pNextListNode->value != ValueOfNodeDel)
		{
			pNodeCur = pNodeCur->pNextListNode;
		}

		pNodeToDel = pNodeCur->pNextListNode;
		pNodeCur->pNextListNode = pNodeCur->pNextListNode->pNextListNode;
	}

	if (NULL != pNodeToDel)
	{
		free(pNodeToDel);
		pNodeToDel = NULL;
	}
	return pHead;
}

int main()
{
	ListNode* pHeadOfList = NULL;
	pHeadOfList = insertNodeToListTail(pHeadOfList);
	pHeadOfList = insertNodeToListTail(pHeadOfList);
	pHeadOfList = insertNodeToListTail(pHeadOfList);
	pHeadOfList = insertNodeToListTail(pHeadOfList);
 	pHeadOfList = deleteNodeFromList(pHeadOfList);
    return 0;
}

