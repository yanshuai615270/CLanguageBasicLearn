/*
	折半查找.cpp
	该查找方法仅适用于有序的顺序表！
	折半查找的时间复杂度为：log2N.
*/

#include "stdafx.h"

int iBinarySerch(int iArray[], int iCurLow, int iCurHigh, int iKeyToFind)
{
	unsigned int uiCurMidle = 0;
	/* 入参检查 */
	if (iCurLow > iCurHigh || NULL == iArray)
		return -1;
	while (iCurLow <= iCurHigh)
	{
		uiCurMidle = (iCurHigh + iCurLow) / 2;
		if (iArray[uiCurMidle] < iKeyToFind)
		{
			iCurLow = uiCurMidle + 1;
		}
		else if (iArray[uiCurMidle] > iKeyToFind)
		{
			iCurHigh = uiCurMidle - 1;
		}
		else
		{
			return uiCurMidle;
		}
	}
	return -1;
}


int main()
{
	int iArray[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int iCurLow = 0;
	int iCurHigh = (sizeof(iArray) / sizeof(int)) - 1;
	int iKeyToFind = -1;
	int iRePosi = iBinarySerch(NULL, iCurLow, iCurHigh, iKeyToFind);
	if (-1 == iRePosi)
	{
		printf("no found!\n");
		return 0; 
	}
	printf("found %d at iArray[%d]!\n", iKeyToFind, iRePosi);
	return 0;
}

