#include<stdio.h>

int re(int ); 

int main()
{
	while (true)
	{

		int integer = 0;
		printf("input the integer,input -1 to break : ");
		scanf("%d", &integer);
		if (-1 == integer)
		{
			break;
		}
		printf("%d\n", re(integer));
	}
	
	/*int integer2 = 0;
	int sum=0;
	printf("input the integer,input -1 to break : ");
	scanf("%d", &integer2);
	for ( int i = 0; i <=integer2; i++)
	{
		
		sum += i;	
	}
	printf("%d\n", sum);

	return 0;*/

}
int  re(int number)
{
	if (number == 1)
	{
		return 1;
	}
	if (number > 0)
	{
		return number + re(number-1) ;
	}
	
	//return 0;
}