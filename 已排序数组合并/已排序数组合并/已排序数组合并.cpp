/* 
已排序数组合并.cpp
问题:
两个已知排序好的数组1和数组2,将两个数组合并到数组1中(数组1中空间足够),并重新排好序.
提示:要求时间复杂度为O(n),空间复杂度为O(1),即不可新增内存开销.

注：本代码采用的为字符数组操作，若应用数值的数组，不适用。
*/

#include "stdafx.h"

void combineArray(char array1[20], char array2[10])
{
	int iCombineEnd = 0;
	int iArray1End = 0;
	int iArray2End = 0;

	iCombineEnd = strlen(array1) + strlen(array2);
	iArray1End = strlen(array1) - 1;
	iArray2End = strlen(array2) - 1;

	array1[iCombineEnd--] = '\0';
	while (iCombineEnd != iArray1End)
	{
        if (array1[iArray1End] >= array2[iArray2End])
		{
			array1[iCombineEnd--] = array1[iArray1End--];
		}
		else
		{
			array1[iCombineEnd--] = array2[iArray2End--];
		}
	}

	return;
}
int main()
{
	char array1[20] = { 0 };
	char array2[10] = { 0 };

	printf("enter the  num for array1:\n");
	gets_s(array1);
	printf("array1 is : %s \n", array1);
	
	printf("enter the  num for array2:\n");
	gets_s(array2);
	printf("array2 is : %s \n", array2);

	combineArray(array1, array2);
	printf("array result is : %s \n", array1);

	return 0;
}

