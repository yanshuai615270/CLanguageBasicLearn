/*
单链表删除查找某一结点并全部删除.cpp : 定义控制台应用程序的入口点。
描述：
题目来源自同事的一个小问题，单链表中找到所有等于某一值的节点并删除，
看似简单，其实要考虑到的场景还挺多的。
要求：时间复杂度O（n），空间复杂度O（1）；
提示：主要考虑各种异常场景。
*/

#include "stdafx.h"

/* 单链表节点 */
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
		/* 当前节点需要删除的场景 */
		if (pCur->value == value)
		{
			/* 头节点需要删除的场景比如 1 1 1 2 需要删除1的场景 */
			if (pCur == pHead)
			{
				pCur = pCur->pNextListNode;
				pPre = pHead = pCur;
				continue;
			}
			/* 尾节点需要删除的场景，如1 1 1 2 需要删除 2 的场景 */
			if (pCur->pNextListNode == NULL)
			{
				pPre->pNextListNode = NULL;
				break;
			}
			/* 删除中间节点场景 如 1 2 3 4 5 删除 2 场景 */
			else
			{
				/* 考虑两种情况，一种为中间有连续多个节点需要删除的场景，如1 2 2 2 3 4 删除2的场景 */
				if (pCur->pNextListNode->value == value)
				{
					pPre->pNextListNode = pPre->pNextListNode->pNextListNode;
					pCur = pCur->pNextListNode;
				}
				/* 中间只有单个节点需要删除的场景 */
				else
				{
					pPre->pNextListNode = pPre->pNextListNode->pNextListNode;
					pPre = pCur;
					pCur = pCur->pNextListNode;
				}
			}
		}
		/* 当前节点不需要删除 */
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

