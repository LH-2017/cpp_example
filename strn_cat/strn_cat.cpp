#include <stdio.h>
#include <string.h>

int strn_cat(char *s1, const char*s2, int size_n);
int main()
{
	char str1[256] = { 'h', 'e' };
	char *str = "llo";
	strn_cat(str1, str, 3);
	printf("%s\n", str1);
}
int strn_cat(char *s1, const char*s2, int size_n)
{
	if (s1 == 0 && s2 == 0)
	{
		return -1;
	}
	
	int len = strlen(s1);
	for (int i = 0; i <= size_n; i++)
	{
		s1[len+i] = s2[i];
		
	}
	return 0;
}
