#include <stdio.h>
int main()
{
	int out = 10;
	//int inside = 10;
	while (out > 0)
	{
		
		int inside = 10;
		while (inside > 0)
		{
			if (inside == 5 || inside == 6)
			{
				printf(" ");
				//break;
			}
			

				printf("*");
				inside--;
		
			
		}
		printf("\n");
		out--;
		
	}
	return 0;
}