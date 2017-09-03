/*
链表逆序打印.cpp
给定一个链表，将该链表中的元素逆序打印。
要求：不允许改变原有链表的结构
*/

/*
补充：栈和队列的库函数；
===========================栈============================
在栈中应包含头文件: #include <stack>
定义: stack<int> s;
s.empty();         //如果栈为空则返回true, 否则返回false;
s.size();          //返回栈中元素的个数
s.top();           //返回栈顶元素, 但不删除该元素
s.pop();           //弹出栈顶元素, 但不返回其值
s.push();          //将元素压入栈顶

===========================队列============================
包含头文件: #include <queue>
定义: queue<int> q;
q.empty();         //如果队列为空返回true, 否则返回false
q.size();          //返回队列中元素的个数
q.front();         //返回队首元素但不删除该元素
q.pop();           //弹出队首元素但不返回其值
q.push();          //将元素压入队列
q.back();          //返回队尾元素的值但不删除该元素
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

void PrintListNodeReversed(ListNode* pHead)
{
	ListNode* pNodeCur = NULL;
	ListNode* pStackNodeCur = NULL;

	std::stack <ListNode*> stackList; // 构造一个栈，调用栈的库函数，遍历链表并将链表的元素依次存入栈中。

	if (NULL == pHead)
	{
		return;
	}
	pNodeCur = pHead;

	while (pNodeCur)
	{
		stackList.push(pNodeCur);
		pNodeCur = pNodeCur->pNextListNode;
	}

	/* 将栈中的元素依次获取并输出，之后删除，直至栈为空 */
	printf("list print reversed is : ");
	while (!stackList.empty())
	{
		pStackNodeCur = stackList.top();
		printf("%d\t", pStackNodeCur->value);
		stackList.pop();
	}
	printf("\n");
}
int main()
{
	ListNode* pHeadOfList = NULL;
	for (int i = 0; i < 10; i++)
	{
		pHeadOfList = insertNodeToListTail(pHeadOfList);
	}
	
	PrintListNodeReversed(pHeadOfList);
	return 0;
}

