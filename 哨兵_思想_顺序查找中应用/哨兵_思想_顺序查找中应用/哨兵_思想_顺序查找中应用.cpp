/*
	�ڱ�_˼��_˳�������Ӧ�ã�
	�����㷨�У�ST.elem[0]��Ϊ���ڱ�����
	����Ŀ����ʹ��ѭ�����ص����ж��Ƿ�����Խ�磬��Ϊ��I==0ʱ��ѭ��һ����������
	ͨ�����롰�ڱ��������Ա���ܶ಻��Ҫ���ж���䣬�Ӷ��������Ч�ʡ�
*/

#include "stdafx.h"

typedef struct {
	int StuNum[101];
}ElemType;

typedef struct {
	int TableLength;
	ElemType *elem; //Ԫ�ش滧�ռ䣬0�ŵ�Ԫ���գ������ڱ�ʹ�á�
}SSTable;

int iSerchSeq(SSTable *pstSTbl, int key)
{
	int i = 0;
	pstSTbl->elem->StuNum[0] = key;
	for (i = pstSTbl->TableLength; pstSTbl->elem->StuNum[i] != key; --i);
	return i;
}

int main()
{
	SSTable STbl = {0};
	STbl.TableLength = 101;
	ElemType elemTy = {0};
	STbl.elem = &elemTy;

	for (int i = 1; i < STbl.TableLength; i++)
	{
		STbl.elem->StuNum[i] = i;
	}
	int iRePosition = iSerchSeq(&STbl, -1);
	if (0 == iRePosition)
	{
		printf("noFound!\n");
	}
	else
	{
		printf("serch result is STbl.elem->StuNum[%d] ", iRePosition);
	}
	return 0;
}