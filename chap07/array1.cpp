#include <stdio.h>
#include <stdbool.h>


void print_array(int p[], int size)
{
	for (int i = 0; i < size; i++)
	{
		if (i % 5 == 0)
		{
			printf("\n");
		}

		printf("%d\t", p[i]);

	}

	printf("\n");
}


void bubble_element(int p[], int size)
{
	if (size < 2)
	{
		return;
	}
	for (int i = 0; i < size - 1; i++)
	{
		if (p[i] > p[i + 1])
		{
			int tmp = p[i];
			p[i] = p[i + 1];
			p[i + 1] = tmp;
		}
	}
}

void sort_array(int p[], int size)
{
	for (int i = 0; i < size; i++)
	{
		bubble_element(p, size - i);
	}
}

int binary_search(int p[], int first, int last, int element)
{
	if (first > last)
	{
		printf("not found! first:%d last %d\n", first, last);
		return -1;
	}

	int middle = (first + last) / 2;

	if (p[middle] == element)
	{
		return middle;
	}
	else if (p[middle] > element)//从左侧查找
	{
		return binary_search(p, first, - 1, element);
	}
	else //从右侧查找
	{
		return binary_search(p, middle + 1, last, element);
	}
}

#define SIZE 3


int main()
{

	int  msg[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		printf("input a number :\n");
		scanf("%d", &msg[i]);
	}

	printf("before sort:\n");
	print_array(msg, SIZE);

	sort_array(msg, SIZE);
	printf("after sort:\n");
	print_array(msg, SIZE);


	printf("input a num to search:\n");

	int element = -1;
	scanf("%d", &element);

	int ret = binary_search(msg, 0, SIZE - 1, element);

	if (ret != -1)
	{
		printf("index of the element is:%d\n", ret);
	}

	return 0;

}
