/*
题目描述
计算字符串最后一个单词的长度，单词以空格隔开。

输入描述:
一行字符串，非空，长度小于5000。

输出描述:
整数N，最后一个单词的长度。

输入例子:
hello world

输出例子:
5
*/

#include "stdafx.h"


int main()
{
	int count = 0;
	int i = 0;
	//获取用户输入
	char *input = NULL;
	input = GetUserInput();
	if (NULL == input)
		return ERR;

	while(NULL != input[i])
	{
		if (' ' == input[i])
			count = 0;
		else
			++count;
		i++;
	}
	printf("input = %s\n", input);
	printf("out put is : %d\n", count);

    return OK;
}

