/*
快速排序.cpp : 定义控制台应用程序的入口点。
递归方式实现。
*/

#include "stdafx.h"
#include <stdlib.h>

void QuitSort(int array[], int length, int start, int end)
{
	/* 如果只有一个节点，直接返回 */
	if (length <= 1 || NULL == array || start == end)
		return;
	/* 
	获取start和end之间的一个随机数.
	要让随机数限定在一个范围，可以采用模除加加法的方式。
	要产生随机数r， 其范围为 m<=r<=n，可以使用如下公式：
	rand()%(n-m+1)+m
	其原理为，对于任意数，
	0<=rand()%(n-m+1)<=n-m
	于是
	0+m<=rand()%(n-m+1)+m<=n-m+m
	即
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

