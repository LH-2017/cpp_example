#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void strn_copy(char*s1, const char*s2, int size_n);
int strn_cat(char *s1, const char*s2, int size_n);
int str_cmp(char *s1, const char*s2);
int str_len(const char *s1);
void str_chr(char *s1, int c);
int main()
{
	char str1[256] = { 'h','e' };
	char* str = "llo"; 
	///str_chr(str, 108);
	//str_cmp(str1, str);
	printf("%d\n", str_len(str));
	//printf("%d\n", str_cmp(str1,str));
	//strn_copy(str1, str, 3);
	//printf("%s\n", str1);
	//strn_cat(str1, str,3 );
	//printf("%s\n", str1);



}
/*void strn_cat(char *s1, const char *s2, int size_n)
{
	int i = 0;
	while (*s1 != '\0')
	{
		*s1++;
	}
	while (i <=size_n)
	{
		i++;
		*s1++ = *s2++;
	}

	return;
}*/
int strn_cat(char *s1, const char*s2, int size_n)
{
	if (s1 == 0 && s2==0)
	{
		return -1;
	}
	int len=str_len(s1);
	for ( int i = 0; i <= size_n; i++)
	{
		s1[len +i] = s2[i];
	}
	

	return 0;
}
/*int strn_cat(char *s1, const char *s2, int size_n)
{
	while (1)
	{
		if (*s1 != '\0')
		{
			*s1++;
		}
		else
		{
			break;
		}
	}
	if(*s1=='\0')
		{

			for (int i = 0; i < size_n; i++)
			{
				*s1++=*s2++;
			}
		}
	
	return 0;

}*/
void strn_copy(char *s1, const char *s2,int size_n )
{
	
	for (int i = 0; i < size_n; i++)
	{
		s1[i] = s2[i];
	}
	return;
} 
int str_cmp(char* s1, const char *s2)
{
	
	while(*s1 == *s2)
	{
		if (*s1 == 0 && *s2 == 0)
		{
			return -1;
		}
		*s1++;
		*s2++;
	}
	return *s1 - *s2;
	
}
int str_len(const char*s1)
{
	if (s1 == 0)
	{
		return-1;
	}
	for (int len = 0;; len++)
	{
		if (s1[len] == '\0')
		{
			
			return len;
		}
	}
	
	
}
/*int str_len(char* s1)
{
	int size = 0;
	if (s1 == 0)
	{
		return -1;
	}
	while (*s1 != '\0')
	{
		*s1++;
		size++;
	}
	printf("The string size is :%d\n",size);
	return 0;
}*/
void str_chr(char* s1, int c)
{
	while (*s1 != c)
	{
		if (*s1 == '\0')
		{
			printf("The character is not found!\n");
			return;
		}
		*s1++;
	}
	if (*s1 == c)
	{
		printf("The adress of the character is :%x\n", s1);
	}
}

