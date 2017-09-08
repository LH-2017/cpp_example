#include <stdio.h>
int main()
{
	int inside = 10;
	int out = 10;
	do
	{
		out--;
		do
		{
			printf("*");
			inside--;
		} while (inside > 0);
		printf("\n");
	} while (out>0);
	return 0;
}