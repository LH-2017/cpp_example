#include <stdio.h>
int main()
{
	for (int row = 0; row < 10; row++)
	{
		switch (row)
		{
		case 1:
			for (int cloum = 0; cloum < 11; cloum++)
			{
				switch (cloum)
				{
				case 5:
					printf("*");
					break;
				default:
					printf(" ");
				}
			
		}
		printf("\n");
	}
	return 0;
}