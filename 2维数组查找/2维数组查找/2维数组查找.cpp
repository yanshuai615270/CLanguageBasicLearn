/*
2ά�������,
�ö�ά���� ÿһ�����ݴ������ҵ�����
ÿһ�д������µ�����
���⣬����һ�����֣��жϸ������Ƿ���ڸþ���֮�У�Ҫ��ʱ�临�ӶȲ�����O��n����
*/

#include "stdafx.h"

void getRowOrCloumnNum(int *num)
{
	printf("please enter the 2 dimension array's row or column number (must be intriger): ");

	scanf("%d", num);
	//bInputCheck(row);
	if (0 >= *num)
	{
		printf("illeagle input!\n");
		return; 
	}
	printf("the row number you inputed is %d\n", *num);
}

bool FindNumFromMatrix(int matrix[100][100], int row, int column, int numToFound)
{
	int curRow = 0;
	int curCloumn = column - 1;
	bool bFound = false;
	/*input check*/
	if (0 >= row || 0 >= column || NULL == matrix)
	{
		return false;
	}
	/*
	�Ӿ������Ͻ���Ϊ�����㣻
	�ж�ҪѰ�ҵ���ֵ�뵱ǰ�ڵ�Ƚϣ�
	���������Լ��ٸ��еĲ��ң����Ǹ��еĲ��ҡ�
	*/
	while (curRow <= row && curCloumn >= 0)
	{
		if (numToFound > matrix[curRow][curCloumn])
		{
			curRow++;
		}
		else if (numToFound < matrix[curRow][curCloumn])
		{
			curCloumn--;
		}
		else
		{
			printf("Found the num %d in matrix[%d][%d].\n", numToFound, curRow, curCloumn);
			bFound = true;
			break;
		}
	}
	return bFound;
}

int main()
{
	int matrix[100][100] = {0};
	int matrixNumTmp = 0;
	int row = 0;
	int column = 0;
	int numToFind = 0;
	bool bFindRet = false;

	getRowOrCloumnNum(&row);
	getRowOrCloumnNum(&column);

	if (0 >= row || 0 >= column)
	{
		return 0;
	}
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			printf("enter the matrix[%d][%d]num(must be intriger):\n", i,j);
			scanf("%d", &matrixNumTmp);
			matrix[i][j] = matrixNumTmp;
		}
	}
	printf("plea enter the num you want to find in this matrix.\n");
	scanf("%d", &numToFind);

	bFindRet = FindNumFromMatrix(matrix, row, column, numToFind);
	if (bFindRet)
	{
		printf("founded and end the pro.\n", numToFind);
	}
	else
	{
		printf("NOT founded and end the pro.\n", numToFind);
	}
    return 0;
}

