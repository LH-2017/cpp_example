#include <stdio.h>
int main()
{
	//int inside = 10;
	int out = 10;
	do
	{
		//out--;
		int inside = 10;

		do
		{
			switch (out)
			{
			case 1:
				switch (inside)
				{
				case 5:
					printf("*");
					break;
				default:
					printf(" ");
				}
				inside--;
				
			}
			/*switch (inside)
			{
				case 5:
				case 6:
					printf(" ");
					break;
				default:
					printf("*");
			}
			
			inside--;*/
		} while (inside > 0);
		printf("\n");
		out--;
	} while (out>0);
	return 0;
}