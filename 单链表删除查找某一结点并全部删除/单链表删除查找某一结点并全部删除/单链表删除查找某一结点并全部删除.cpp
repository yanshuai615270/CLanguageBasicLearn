/*
������ɾ������ĳһ��㲢ȫ��ɾ��.cpp : �������̨Ӧ�ó������ڵ㡣
������
��Ŀ��Դ��ͬ�µ�һ��С���⣬���������ҵ����е���ĳһֵ�Ľڵ㲢ɾ����
���Ƽ򵥣���ʵҪ���ǵ��ĳ�����ͦ��ġ�
Ҫ��ʱ�临�Ӷ�O��n�����ռ临�Ӷ�O��1����
��ʾ����Ҫ���Ǹ����쳣������
*/

#include "stdafx.h"

/* ������ڵ� */
typedef struct ListNode
{
	int value;
	ListNode* pNextListNode;
};

ListNode* DeleteNodeFromSiglList(ListNode* pHead, int value)
{
	if (NULL == pHead)
		return pHead;

	ListNode* pCur = pHead;
	ListNode* pPre = pHead;

	while (pCur)
	{
		/* ��ǰ�ڵ���Ҫɾ���ĳ��� */
		if (pCur->value == value)
		{
			/* ͷ�ڵ���Ҫɾ���ĳ������� 1 1 1 2 ��Ҫɾ��1�ĳ��� */
			if (pCur == pHead)
			{
				pCur = pCur->pNextListNode;
				pPre = pHead = pCur;
				continue;
			}
			/* β�ڵ���Ҫɾ���ĳ�������1 1 1 2 ��Ҫɾ�� 2 �ĳ��� */
			if (pCur->pNextListNode == NULL)
			{
				pPre->pNextListNode = NULL;
				break;
			}
			/* ɾ���м�ڵ㳡�� �� 1 2 3 4 5 ɾ�� 2 ���� */
			else
			{
				/* �������������һ��Ϊ�м�����������ڵ���Ҫɾ���ĳ�������1 2 2 2 3 4 ɾ��2�ĳ��� */
				if (pCur->pNextListNode->value == value)
				{
					pPre->pNextListNode = pPre->pNextListNode->pNextListNode;
					pCur = pCur->pNextListNode;
				}
				/* �м�ֻ�е����ڵ���Ҫɾ���ĳ��� */
				else
				{
					pPre->pNextListNode = pPre->pNextListNode->pNextListNode;
					pPre = pCur;
					pCur = pCur->pNextListNode;
				}
			}
		}
		/* ��ǰ�ڵ㲻��Ҫɾ�� */
		else
		{
			pPre = pCur;
			pCur = pCur->pNextListNode;
		}
	}
	return pHead;
}
int main()
{
	ListNode SingleList[10] = { 0 };
	ListNode* pHead = SingleList;
	SingleList[0].value = 0;
	SingleList[0].pNextListNode = &SingleList[1];

	SingleList[1].value = 1;
	SingleList[1].pNextListNode = &SingleList[2];

	SingleList[2].value = 1;
	SingleList[2].pNextListNode = &SingleList[3];

	SingleList[3].value = 2;
	SingleList[3].pNextListNode = &SingleList[4];

	SingleList[4].value = 1;
	SingleList[4].pNextListNode = &SingleList[5];
	SingleList[5].value = 1;
	SingleList[5].pNextListNode = &SingleList[6];
	SingleList[6].value = 6;
	SingleList[6].pNextListNode = NULL;

	pHead = DeleteNodeFromSiglList(pHead, 1);

    return 0;
}

