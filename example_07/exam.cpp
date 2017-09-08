#include <stdio.h>
int main()
{
	int a;      
	int *Ptr;    

	a = 7;
	Ptr = &a; 
	printf("*Ptr=%d\n", *Ptr);
	printf("&Ptr=%x\n", &Ptr);
	printf("Ptr=%x\n", Ptr);
	printf("*&Ptr = %x\n", *&Ptr);

	return 0;
}