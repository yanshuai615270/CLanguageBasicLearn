// learnC.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

enum diffTypeOfCup
{
	type1,
	type2,
	type3 = 10,
	type4,
} diffTypeOfCup;

int main()
{
	unsigned char *p1;
	unsigned long *p2;
	p1 = (unsigned char *)0x801000;
	p2 = (unsigned long *)0x810000;

	printf("p1 + 5 is %x \n", (p1 + 5));
	printf("p2 + 5 is %x \n", (p2+ 5));
    return 0;
}

