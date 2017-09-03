/*
���������ӡ.cpp
����һ���������������е�Ԫ�������ӡ��
Ҫ�󣺲�����ı�ԭ������Ľṹ
*/

/*
���䣺ջ�Ͷ��еĿ⺯����
===========================ջ============================
��ջ��Ӧ����ͷ�ļ�: #include <stack>
����: stack<int> s;
s.empty();         //���ջΪ���򷵻�true, ���򷵻�false;
s.size();          //����ջ��Ԫ�صĸ���
s.top();           //����ջ��Ԫ��, ����ɾ����Ԫ��
s.pop();           //����ջ��Ԫ��, ����������ֵ
s.push();          //��Ԫ��ѹ��ջ��

===========================����============================
����ͷ�ļ�: #include <queue>
����: queue<int> q;
q.empty();         //�������Ϊ�շ���true, ���򷵻�false
q.size();          //���ض�����Ԫ�صĸ���
q.front();         //���ض���Ԫ�ص���ɾ����Ԫ��
q.pop();           //��������Ԫ�ص���������ֵ
q.push();          //��Ԫ��ѹ�����
q.back();          //���ض�βԪ�ص�ֵ����ɾ����Ԫ��
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

	std::stack <ListNode*> stackList; // ����һ��ջ������ջ�Ŀ⺯�������������������Ԫ�����δ���ջ�С�

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

	/* ��ջ�е�Ԫ�����λ�ȡ�������֮��ɾ����ֱ��ջΪ�� */
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

