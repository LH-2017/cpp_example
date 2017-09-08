#include <stdio.h>
#define SIZE 5


void sort_p(int *ptr, int size);
void sort_p_(int *ptr, int size);
void sort_array(int *ptr, int size);
void print_array_p(int *ptr,int size);


int main()
{

	int arr[SIZE] = { 4, 3, 2, 1, 0 };
	sort_p(arr, SIZE);
	//sort_array(arr, SIZE);
	print_array_p(arr,SIZE);
}
void print_array_p(int *ptr, int size)
{
	for (int i = 0; i < SIZE; i++)
	{
		//printf("%d\t", arr);
		printf("%d\t", *(ptr+i));
		//printf("%d\t", arr[i]);
	}
	printf("\n");
	return;
}
void sort_array(int *ptr, int size)
{
	for (int i = 0; i < size; i++)
	{
		sort_p_(ptr, size - i);
	}
	return ;
}

void sort_p_(int *ptr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (size<2)
		{
			return;
		}
		if (*(ptr + i) > *(ptr + 1 + i))
		{

			int tmp = *(ptr + i);
			*(ptr + i) = *(ptr + 1 + i);
			*(ptr + 1 + i) = tmp;

		}
	}
}
void sort_p(int *ptr, int size)
{
	for (int j = 0; j < size ; j++)
	{

		for (int i = 0; i < size- 1-j ; i++)
		{
			
			if (*(ptr + i) > *(ptr + 1 + i))
			{

				int tmp = *(ptr + i);
				*(ptr + i) = *(ptr + 1 + i);
				*(ptr + 1 + i) = tmp;

			}
		}
	}
}
