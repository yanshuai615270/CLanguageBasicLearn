/* a+b.cpp : 定义控制台应用程序的入口点。
计算a + b的和

每行包行两个整数a和b
对于每行输入对应输出一行a和b的和
输入
1 5
输出
6
*/

#include "stdafx.h"


int main()
{
	int a = 0;
	int b = 0;
	printf("please enter the first num:\n");

	scanf("%d", &a);
	printf("please enter the second num:\n");

	scanf("%d", &b);
	printf("a + b = %d\n", (a + b));
    return 0;
}

