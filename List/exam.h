#include <cstdlib>
#include <cstdio>
#include <cstdint>
#include <cstring>

void ptr_fun(void *p)
{
   	p = 0;
}
  
void pptr_fun(void **p)
{
	*p = 0;
}

int main()
{

	char* msg = (char*)malloc(256);
	memset(msg, 0, 256);

	ptr_fun(msg);
 	pptr_fun((void**)&msg);



	msg[0] = 'h';
	msg[1] = 'e';
	msg[2] = 'l';
	msg[3] = 'l';
	msg[4] = 'o';
	msg[5] = '\n';


	fputs(msg, stdout);

	free(msg);



	return 0;
}
