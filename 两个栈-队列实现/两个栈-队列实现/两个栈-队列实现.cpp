/*
����ջ-����ʵ��.cpp
����:
1������ϵͳ��,���ÿ���̴߳���һ��ջ�����洢��������ʱ���������Ĳ��������ص�ַ�Լ���ʱ�����ȣ�
2��ջ���ص��Ǻ���ȳ���
3�����е��ص����Ƚ��ȳ���

��Ŀ��
������ջʵ��һ�����С������������£���ʵ��������������appendTail ��deleteHead���ֱ�����ڶ���β������ڵ�Ͷ���ͷ��ɾ���ڵ�Ĺ��ܡ�

��չ��
������������ʵ��һ��ջ�Ĺ��ܣ�
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

