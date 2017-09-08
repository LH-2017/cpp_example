#include <stdio.h>
int main()
{
	for (int row = 0; row < 15; row++)
	{
		switch (row)
		{
		case 0:
			for (int cloum = 0; cloum < 20; cloum++)
			{
				switch (cloum)
				{
				case 7:
					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;

		case 1:
			for (int cloum = 0; cloum < 20; cloum++)
			{
				switch (cloum)
				{
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

		case 2:
			for (int cloum = 0; cloum < 13; cloum++)
			{
				switch (cloum)
				{
					case 5:
					case 6:
					case 7:
					case 8:
					case 9:
					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;

		case 3:
			for (int cloum = 0; cloum < 20; cloum++)
			{
				switch (cloum)
				{
				case 0:
				case 1:
				case 2:
				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
				case 10:
				case 11:
				case 12:
				case 13:
				case 14:
					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
		case 4:
			for (int cloum = 0; cloum < 20; cloum++)
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
				case 9:
				case 10:
				case 11:
				case 12:

					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
		case 5:
			for (int cloum = 0; cloum < 20; cloum++)
			{
				switch (cloum)
				{

				case 3:
				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
				case 10:
				case 11:

					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
		case 6:
			for (int cloum = 0; cloum < 20; cloum++)
			{
				switch (cloum)
				{

				case 4:
				case 5:
				case 6:
				case 7:
				case 8:
				case 9:
				case 10:

					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
		case 7:
			for (int cloum = 0; cloum < 20; cloum++)
			{
				switch (cloum)
				{

				case 3:
				case 4:
				case 5:
				case 6:
				case 8:
				case 9:
				case 10:
				case 11:


					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
		case 8:
			for (int cloum = 0; cloum < 20; cloum++)
			{
				switch (cloum)
				{
				case 2:
				case 3:
				case 4:
				case 5:
				case 9:
				case 10:
				case 11:
				case 12:
		
					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
		case 9:
			for (int cloum = 0; cloum < 20; cloum++)
			{
				switch (cloum)
				{
				case 1:
				case 2:
				case 3:
				
				case 11:
				case 12:
				case 13:

					printf("*");
					break;
				default:
					printf(" ");
				}
			}
			printf("\n");
			break;
		
		case 10:
			for (int cloum = 0; cloum < 20; cloum++)
			{
				switch (cloum)
				{
				case 0:
				case 14:

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