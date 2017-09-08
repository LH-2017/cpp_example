#include <stdio.h>
int main()
{
	for (int row = 0; row < 7; row++)
	{
		switch (row)
		{
		case 0:
		case 6:
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
			break;
		case 1:
		case 5:
			for (int cloum = 0; cloum < 11; cloum++)
			{
				switch (cloum)
				{
				case 4:
				case 5:
				case 6:
					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
		case 2:
		case 4:
			for (int cloum = 0; cloum < 11; cloum++)
			{
				switch (cloum)
				{
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
		case 3:
			for (int cloum = 0; cloum < 11; cloum++)
			{
				switch (cloum)
				{
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
			

		


			printf("\n");
		}
	}
		return 0;
	}