#include "stdafx.h"


char *getUserInput()
{
	char strInput[1000];
	return gets_s(strInput);
}
int main()
{
	int i = 0;
	int n = 0;
	char chBuffer[9] = {0};
	char chInput[1000] = {0};
	memcpy(chInput, getUserInput(), 1000);
	if (NULL != chInput && '\0' != *chInput)
	{
		while (chInput[i] != '\0')
		{
			chBuffer[(i % 8)] = chInput[i];
			if (0 == ((i + 1) % 8))
			{
				chBuffer[8] = '\0';
				printf("%s\n", chBuffer);
				memset(chBuffer, '0', 8);
			}
			i++;
		}

		printf("%s\n", chBuffer);
	}

	memset(chInput, 0, 1000);
	memset(chBuffer, '0', 9);
	memcpy(chInput, getUserInput(), 1000);

	if (NULL != chInput && '\0' != *chInput)
	{
		while (chInput[n] != '\0')
		{
			chBuffer[(n % 8)] = chInput[n];
			if (0 == ((n + 1) % 8))
			{
				chBuffer[8] = '\0';
				printf("%s\n", chBuffer);
				memset(chBuffer, '0', 8);
			}
			n++;
		}
		chBuffer[8] = '\0';
		printf("%s\n", chBuffer);
	}
	return 0;
}