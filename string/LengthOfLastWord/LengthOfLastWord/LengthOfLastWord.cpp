/*
��Ŀ����
�����ַ������һ�����ʵĳ��ȣ������Կո������

��������:
һ���ַ������ǿգ�����С��5000��

�������:
����N�����һ�����ʵĳ��ȡ�

��������:
hello world

�������:
5
*/

#include "stdafx.h"


int main()
{
	int count = 0;
	int i = 0;
	//��ȡ�û�����
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

