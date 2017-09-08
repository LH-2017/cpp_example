#include<stdio.h>
int main()
{
	
	int H = -1;
	int climb = 0;
	bool day_ = true;
	int day = 0;
	int night = 0;
	int day_up = -1;
	int night_up = -1;
	int ret = 0;
	FILE *cfptr;

	printf("Please input height,day_up,night_up:\n");

	while (scanf("%d%d%d", &H, &day_up, &night_up) != 3)
	{
		while (getchar() != '\n');
		printf("Please input height,day_up,night_up:\n");
		
	}

	while (climb < H)
	{
		if (day_)
		{
			climb += day_up;
			day += 1;
			day_=false;
		}
		else
		{
			climb += night_up;
			night += 1;
			day_ = true;

		}
	}
		printf("%d day\n", day);
		printf("%d night\n", night);

		return 0;
}