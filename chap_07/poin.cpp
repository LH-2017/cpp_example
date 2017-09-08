#include <stdio.h>
int main()
{
	//int *pvalue = 0;
	
	int value = 0x01020304;
	int value1 = 0;
	//pvalue = &value;
	printf("%x\n",&pvalue);
	printf("%x\n", *pvalue);
	if (0x01020304 == *pvalue)
	{
		printf("Ð¡¶Ë\n");
	}
	else
	{
		printf("´ó¶Ë\n");
	}

	return 0;
}