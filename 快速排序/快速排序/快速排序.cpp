/*
��������.cpp : �������̨Ӧ�ó������ڵ㡣
�ݹ鷽ʽʵ�֡�
*/

#include "stdafx.h"
#include <stdlib.h>

void QuitSort(int array[], int length, int start, int end)
{
	/* ���ֻ��һ���ڵ㣬ֱ�ӷ��� */
	if (length <= 1 || NULL == array || start == end)
		return;
	/* 
	��ȡstart��end֮���һ�������.
	Ҫ��������޶���һ����Χ�����Բ���ģ���Ӽӷ��ķ�ʽ��
	Ҫ���������r�� �䷶ΧΪ m<=r<=n������ʹ�����¹�ʽ��
	rand()%(n-m+1)+m
	��ԭ��Ϊ��������������
	0<=rand()%(n-m+1)<=n-m
	����
	0+m<=rand()%(n-m+1)+m<=n-m+m
	��
	m<=rand()%(n-m+1)+m<=n
	*/
	int index = rand() % (end - start + 1) + start;

	int iCurKey = array[index];
	for (int i = 0; i < length; i++)
	{
		if (array[i] >= iCurKey)
		{
			int tmp = array[i];
			array[i] = array[index];
			array[index] = tmp;
		}
	}
	QuitSort(array, index, 0, index - 1);
	QuitSort(array, end - index, index + 1, end);
}
int main()
{
	int array[] = { 3, 2, 4, 6, 7 };
	QuitSort(array, sizeof(array)/4, 0, (sizeof(array) / 4) - 1);


    return 0;
}

