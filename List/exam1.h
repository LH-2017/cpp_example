#include <cstdlib>
#include <cstdio>
#include <cstdint>

int main()
{
	char *pvalue = (char*)malloc(sizeof(int)); //char value[4];

	*pvalue = 0x11;

	printf("0x%p->%d\n", pvalue, pvalue[0]);


	pvalue[1] = 0x12;//pvalue+=1; pvalue++
	pvalue[2] = 0x13;//pvalue+=2;
	pvalue[3] = 0x14;
	printf("int32:0x%p->%#X\n", pvalue, *(int*)pvalue);
	printf("int16:0x%p->%#X\n", pvalue, *(uint16_t*)pvalue);
	uint16_t* ptemp = (uint16_t*)pvalue;
	ptemp++;
	printf("int16(last two bytes):0x%p->%#X\n", pvalue, *ptemp);

	free(pvalue);

	return 0;
}
