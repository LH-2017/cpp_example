#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>


int compare(int a, int b)
{
	return a > b;
}

typedef int (*FUN_PTR)(int, int);//定义了一个布尔型函数指针类型

void init(FUN_PTR *fptr)
{
	*fptr = compare;
}
int main()
{
	char *pt
	FUN_PTR fptr = 0;
	init(&fptr);
	fptr(1, 2);

	printf("%d\n", fptr(1, 2) ? 1 : 0);

}
