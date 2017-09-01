/*
2维数组查找,
该二维数组 每一行数据从左至右递增，
每一列从上至下递增，
问题，给定一个数字，判断该数据是否存在该矩阵之中，要求时间复杂度不大于O（n）；
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
	从矩阵右上角作为出发点；
	判断要寻找的数值与当前节点比较，
	并决定可以减少该行的查找，还是该列的查找。
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

