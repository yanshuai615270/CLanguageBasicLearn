/*
	1、哨兵_思想_顺序查找中应用，
	下面算法中，ST.elem[0]称为“哨兵”。
	引入目的是使得循环不必单独判断是否数组越界，因为当I==0时，循环一定会跳出。
		1）通过引入“哨兵”，可以避免很多不必要的判断语句，从而提高运行效率。
	2、顺序查找，查找成功时，平均查找长度：
	                                  ASL = (n + 1)/2
			  查找失败时，平均查找长度：
									  ASL = n + 1
	顺序查找  优点：
		1）对数据元素的存储无要求，顺序存储或者链式存储均可；
		2）对元素的有序性也无要求；
	缺点：
		1）当 n 比较大时，平均查找长度较大，效率低；

	3、有序表的顺序查找：
		查找成功时，平均查找长度：
								ASL = (n + 1)/2
		查找失败时，平均查找长度：
								ASL = n/2 + n/（n+1）
*/

#include "stdafx.h"

typedef struct {
	int StuNum[101];
}ElemType;

typedef struct {
	int TableLength;
	ElemType *elem; //元素存户空间，0号单元留空，用作哨兵使用。
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