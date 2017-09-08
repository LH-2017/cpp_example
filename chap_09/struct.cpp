#include <stdio.h>
#include <string.h>
#include <stdint.h>
union Number
{

	
	int16_t num1;
	 int8_t num2;
};

union student
{
	int num6ber;

	float score;

};
typedef union student * stuptr;

typedef struct _Person
{
	char na;
	char *name;
	int age;
	char *address;
}person1;





typedef struct _Person Person;

typedef struct _Person *PersonPtr;


int main()
{

	student stu1 = { 12345,  };
	int i = 0xab;
	 i <<= 4;
	 //i += 1;
	 //Person person1 = {"zhangsan",18,"jinan"};
	 //Person person2= person1;
	// person2.name = "zhangsan";
	// person2.age = 18;
	 //person2.address = "jinan";

	 
	 Number number;
	 number.num1 = 0x0102;
	 printf("num2:%#x\n", number.num2);

	 printf("%d\n", sizeof(Number));
	printf("%d\n", sizeof(_Person));

	enum Months 
	{ 
		JAN = 1, 
		FEB, 
		MAR, 
		APR, 
		MAY, 
		JUN, 
		JUL, 
		AUG, 
		SEP, 
		OCT, 
		NOV, 
		DEC 
	};
	printf("%07.2f\n", 98.736);
	printf("%*.*f\n", 7, 2, 98.736);

	int a = 1;
	float b = 0.23;
	int *c = &a;

	printf("%d\n %#x\n %f\t %5.3f\n %e\n %p\n %g\n", a, a, b, b, b, c, b);
}
