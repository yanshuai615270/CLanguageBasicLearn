/*
两个栈-队列实现.cpp
科普:
1、操作系统中,会给每个线程创建一个栈用来存储函数调用时各个函数的参数、返回地址以及临时变量等；
2、栈的特点是后进先出；
3、队列的特点是先进先出；

题目：
用两个栈实现一个队列。队列声明如下，请实现他的连个函数appendTail 和deleteHead，分别完成在队列尾部插入节点和队列头部删除节点的功能。

扩展：
用两个队列来实现一个栈的功能？
*/

#include "stdafx.h"

using namespace std;

int main()
{
	int List[5] = { 1, 2, 3, 4, 5 };
	stack <int> stk1;
	stack <int> stk2;
	int data = 0;

	for (int i = 0; i < sizeof(List)/4; i++)
	{
		stk1.push(List[i]);
	}
	while (stk1.empty() != true)
	{
		data = stk1.top();
		stk1.pop();
		stk2.push(data);
	}
	while (stk2.empty() != true)
	{
		printf("%d ", stk2.top());
		stk2.pop();
	}

    return 0;
}

