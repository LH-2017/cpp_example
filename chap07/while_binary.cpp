#include <stdio.h>
#define SIZE 5

void print_array(int arr[],int size);
int sort_array(int arr[], int size);
void bubble_sort(int arr[], int size);
void sort(int arr[], int size);
void sort_p(int *ptr, int size);
int binary_search(int arr[], int left,int right,int element);

/*int main()
{
	int arr[5] = {4,3,6,2,1};
	//char *p = (char*)&value;
	sort(arr,5);
	printf("%d", arr);
}*/
int main()
{
	int  num[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		printf("input a number :\n");
		scanf("%d", &num[i]);
	}
	print_array(num,SIZE);
	sort(num, SIZE);
	//bubble_sort(num, SIZE);
	print_array(num, SIZE);

	printf("input a num to search:\n");
	int element = -1;
	scanf("%d", &element);

	binary_search(num, 0, SIZE - 1, element);

	
}
void print_array(int arr[], int size)
{
	for (int i = 0; i < SIZE; i++)
	{
		//printf("%d\t", arr);
		printf("%d\t", arr[i]);
		//printf("%d\t", arr[i]);
	}
	printf("\n");
	return;
}
void sort_p(int *ptr, int size)
{
	for (int j = 0; j < size  - j; j++)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (size < 2)
				return;
			if (*ptr>*(ptr + 1))
			{
				
				int tmp=*ptr;
				*ptr = *(ptr + 1);
				*(ptr + 1) = tmp;

			}

		}

	}
	
	return;
}
void sort(int arr[], int size)
{
	for (int j = 0; j < size  ; j++)
	{
		for (int i = 0; i < size - j-1; i++)
		{
			if (size<2)
			{
				return;
			}
			if (arr[i]>arr[i + 1])
			{
				int tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;

			}
		}
	}
	return;
}



int sort_array(int arr[], int size)
{
	for (int i=0; i < size; i++)
	{
		bubble_sort(arr, size - i);
	}
	return 0;
}
//循环size-1遍
//每次循环处理无序部分
//两两排序
void bubble_sort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (size<2)
		{
			return;
		}
		if (arr[i]>arr[i + 1])
		{
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;

		}
	}
}
int  binary_search(int arr[], int left, int right, int element)
{
	while (1)
	{
		int middle = (left + right) / 2;
		if (arr[middle] == element)
		{
			printf("index of the element is:%d\n", middle);
			break;
		}
		if (arr[middle] < element)
		{
			left = middle + 1;
		}
		if (arr[middle]>element)
		{
			right = middle - 1;
		}
		if (left > right)
		{
			printf("The element not found\n");
			break;
			
		}
	}
	return 0;
}