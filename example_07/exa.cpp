#include<stdio.h>
int main()
{
	int value = 0x01020304;
	
	
	
	int *ptr = &value;
	printf("ptr=%p\n", ptr);
	printf("*ptr=%d\n", *ptr);
	printf("&*ptr=%p\n", &*ptr);
	printf("&*ptr=%x\n", *(char*)&ptr);
	printf("*&ptr=%p\n", *&ptr);
	return 0;
}

