/*
	1���ڱ�_˼��_˳�������Ӧ�ã�
	�����㷨�У�ST.elem[0]��Ϊ���ڱ�����
	����Ŀ����ʹ��ѭ�����ص����ж��Ƿ�����Խ�磬��Ϊ��I==0ʱ��ѭ��һ����������
		1��ͨ�����롰�ڱ��������Ա���ܶ಻��Ҫ���ж���䣬�Ӷ��������Ч�ʡ�
	2��˳����ң����ҳɹ�ʱ��ƽ�����ҳ��ȣ�
	                                  ASL = (n + 1)/2
			  ����ʧ��ʱ��ƽ�����ҳ��ȣ�
									  ASL = n + 1
	˳�����  �ŵ㣺
		1��������Ԫ�صĴ洢��Ҫ��˳��洢������ʽ�洢���ɣ�
		2����Ԫ�ص�������Ҳ��Ҫ��
	ȱ�㣺
		1���� n �Ƚϴ�ʱ��ƽ�����ҳ��Ƚϴ�Ч�ʵͣ�

	3��������˳����ң�
		���ҳɹ�ʱ��ƽ�����ҳ��ȣ�
								ASL = (n + 1)/2
		����ʧ��ʱ��ƽ�����ҳ��ȣ�
								ASL = n/2 + n/��n+1��
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