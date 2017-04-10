#include "stdafx.h"

char* GetUserInput()
{
	char input[5000];
	printf("please enter the string :\n");
	gets_s(input);
	return input;
}

