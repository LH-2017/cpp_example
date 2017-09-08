#include <stdio.h>
#define SIZE 10
void print_array(char msg[], int size);
void modify_array(char msg[], int size);
void modify_element(char p);
void modify_element(char p)//不改变数组实际的值
{
	p -= 1;
	return;
}
void modify_array(char msg[], int size)
{
	for (int i = 0; i < size; i++)
	{
		msg[i] -= 1;
	}
	return;
}
void print_array(char msg[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%c", msg[i]);
		printf("\n");
	}
	printf("%s\n", msg);
	printf("%d\n", msg);
	printf("%d\n", &msg[0]);
	return;
}

int main()
{
	char msg[SIZE];
	printf("input a string:\n");
	scanf("%s", msg);//数组名即为数组地址，所以scanf在这不需要加取地址符（&）
	//modify_array(msg, SIZE);
	//modify_element(msg[2]);
	print_array(msg, SIZE);

}