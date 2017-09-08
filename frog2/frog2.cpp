#include <stdio.h>
//#define H 20
int main()
{
	int H;
	printf("Please enter the high of the wall:\n");
	scanf("%d\n", &H);
	int day_up=0;
	int night_up = 0;
	printf("");
	scanf("%d%d", &day_up, &night_up);
	int day = 0;
	int night = 0;
	int climb = 0;
	while (climb < H)
	{
		climb += day_up;
		climb -= night_up;
		day += 1;
	}
	if ( 0==climb%2)
	{
		night == day;
	}
	else
	{
		night = day - 1;
	}
	printf("%d day\n", day);
	printf("%d night\n", night);
}