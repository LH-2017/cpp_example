#include <stdio.h>
#define H 20

int main()
{
	int climb = 0;
	int day = 0;
	int night = 0;
	bool day_ = true;
	do
	{
		if (day_)
		{
			climb += 5;
			day += 1;
			day_ = false;
		}
		else
		{
			climb -= 3;
			night += 1;
			day_ = true;
		}
	} 
	while (climb < H);

	printf("%d day\n", day);
	printf("%d night\n", night);

	return 0;
	
	
}