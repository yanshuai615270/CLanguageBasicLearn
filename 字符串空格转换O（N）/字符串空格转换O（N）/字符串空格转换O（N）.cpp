/*
�ַ����ո�ת��O��N��.cpp : �������̨Ӧ�ó������ڵ㡣
���ַ����еĿո��滻ΪURL ��%20.��ע���ո�ASCII Ϊ 32  ת��Ϊ16���Ƽ�Ϊ  20����
Ҫ��ʱ�临�Ӷ� ΪO��n����
�ռ��ϲ����������ڴ棬���е��ַ����ĳ����㹻����ת������ַ�����
��ʾ����ͷ�����ķ�ʽ�����У�ʱ�临�Ӷ�ΪO��n2��.
*/

#include "stdafx.h"

/*
˼·��
1����ͷ��β����һ���ַ�����������Ҫ�滻�Ŀո��������
2������ָ�룬һ��ָ��ԭ�ַ�����β��һ��ָ���¼�������ַ�����β��
3��������ǰ�ƶ�ָ�벢���ַ����и��ƣ�
4����ָ��1 ��ָ��2��ָ��ͬһ���ڴ�ʱ��ֹͣ���ɡ�
*/
int main()
{
	int iStrOldEnd = 0;
	int iStrNewEnd = 0;
	int i = 0;
	int iSpaceNum = 0;
	char cStr[100] = {0};

	printf("ple enter a string no longer than 30:\n");
	gets_s(cStr);
	printf("the str is \"%s\"\n", cStr);
	printf("sizeof cStr is %d \n.", sizeof(cStr));
	printf("length cStr is %d \n.", strlen(cStr));

	iStrOldEnd = strlen(cStr);
	/* �����ַ����еĿո��� */
	while ('\0' != cStr[i])
	{
		if (' ' == cStr[i])
			++iSpaceNum;
		i++;
	}
	iStrNewEnd = strlen(cStr) + (2 * iSpaceNum);

	while (iStrOldEnd != iStrNewEnd)
	{
		if (' ' == cStr[iStrOldEnd])
		{
			cStr[iStrNewEnd--] = '0';
			cStr[iStrNewEnd--] = '2';
			cStr[iStrNewEnd--] = '%';
			iStrOldEnd--;
		}
		else
			cStr[iStrNewEnd--] = cStr[iStrOldEnd--];
	}
	printf("new str is \" %s \"\n", cStr);
    return 0;
}