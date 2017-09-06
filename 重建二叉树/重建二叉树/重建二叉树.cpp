/* 
重建二叉树.cpp 
说明：
输入某二叉树的前序序列和中序序列遍历的结果，输出重新构建的树结构；
例如：前序{1，2，4，7，3，5，6，8}
	  中序{4，7，2，1，5，3，8，6}
还原二叉树结构为：
              1
            /    \
           2      3
          /      / \
         4	    5   6
          \        /
           7      8
*/
#include "stdafx.h"
typedef struct BinaryTreeNode
{
	int iValue;
	BinaryTreeNode* pLeftChild;
	BinaryTreeNode* pRightChild;
};

BinaryTreeNode* ReConstractBinaryTreeCore(int *piPreorderStart, int *piPreorderEnd, int* piInorderStart, int* piInorderEnd)
{
	int iRootValue = piPreorderStart[0];
	BinaryTreeNode* pstRoot = NULL;

	int* iPosRootCurInInorder = piInorderStart;

	pstRoot = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
	memset(pstRoot, 0, sizeof(BinaryTreeNode));
	
	pstRoot->iValue = iRootValue;
	pstRoot->pLeftChild = pstRoot->pRightChild = NULL;
	if (piPreorderStart == piPreorderEnd)
	{
		if ((piInorderStart == piInorderEnd) && (piInorderStart[0] = piPreorderStart[0]))
		{
			return pstRoot;
		}
		else
		{
			printf("00.invalid input!\n");
			return NULL;
		}
	}
	/* 查找根节点在中序序列中的位置 */
	while (*iPosRootCurInInorder != iRootValue && iPosRootCurInInorder <= piInorderEnd)
	{
		++iPosRootCurInInorder;
	}

	/* 在中序序列中找到根节点后，依次迭代构造左子树、右子树 */
	int iLeftLength = iPosRootCurInInorder - piInorderStart;
	int* piLeftPreOrderEnd = piPreorderStart + iLeftLength;

	if (iLeftLength > 0)
	{
		pstRoot->pLeftChild = ReConstractBinaryTreeCore(piPreorderStart + 1, piPreorderStart + iLeftLength, piInorderStart, iPosRootCurInInorder - 1);
	}
	if (iLeftLength < piPreorderEnd - piPreorderStart)
	{
		pstRoot->pRightChild = ReConstractBinaryTreeCore(piPreorderStart + iLeftLength + 1, piPreorderEnd, iPosRootCurInInorder + 1, piInorderEnd);
	}
	return pstRoot;

}

BinaryTreeNode* ReConstractBinaryTree(int *piPreorderStart, int* piInorderStart, int iLength)
{
	BinaryTreeNode* pRootCur = NULL;
	if (NULL == piPreorderStart || NULL == piInorderStart || 0 >= iLength)
		return NULL;

	return ReConstractBinaryTreeCore(piPreorderStart, piPreorderStart + iLength - 1, piInorderStart, piInorderStart + iLength - 1);
}
int main()
{
	int iPreorder[] = {1, 2, 4, 7, 3, 5, 6, 8};
	int iInorder[] = {4, 7, 2, 1, 5, 3, 8, 6};
	BinaryTreeNode* pRoot = NULL;
	printf("sizeof(iPreorder):%d \n", sizeof(iPreorder));
	pRoot = ReConstractBinaryTree(iPreorder, iInorder, (sizeof(iPreorder)/4));

    return 0;
}