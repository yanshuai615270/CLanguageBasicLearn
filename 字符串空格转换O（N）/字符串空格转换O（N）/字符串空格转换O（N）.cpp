/*
字符串空格转换O（N）.cpp : 定义控制台应用程序的入口点。
将字符串中的空格替换为URL 中%20.（注：空格ASCII 为 32  转换为16进制即为  20）；
要求时间复杂度 为O（n）；
空间上不允许新增内存，已有的字符串的长度足够容纳转换后的字符串；
提示：从头遍历的方式不可行，时间复杂度为O（n2）.
*/

#include "stdafx.h"

/*
思路：
1）从头到尾遍历一次字符串，计算需要替换的空格的数量；
2）两个指针，一个指向原字符串结尾，一个指向新计算出的字符串结尾；
3）依次向前移动指针并将字符进行复制；
4）当指针1 和指针2都指向同一块内存时，停止即可。
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
	/* 计算字符串中的空格数 */
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