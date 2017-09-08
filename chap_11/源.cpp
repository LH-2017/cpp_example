#include <cstdio>
#include <cstring>



struct Person
{
	int age;
	char name[256];
};

void print_person(const Person * p)
{
	printf("Person:\nage=%d\tname=%s\n", p->age, p->name);
}
int main()
{
	Person p[2] = { { 11, "wang er xiao" }, { 12, "zhang ga" } };

	FILE* file = fopen("E:\\", "w");

	size_t ret = fwrite(p, sizeof(Person), 2, file);
	//size_t ret = fwrite(p, 1, sizeof(Person)*2, file);

	if (ret != 2)
	{
		printf("error!\n");
	}

	fclose(file);


	file = fopen("C:\\tmp\\qw", "r");
	Person read = { 0 };

	fseek(file, sizeof(Person), SEEK_CUR);

	fread(&read, sizeof(Person), 1, file);

	fclose(file);

	print_person(&read);

	return 0;
}
