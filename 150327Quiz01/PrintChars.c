#include <stdio.h>

static int Length(const char * str);
static void PrintChars(const char * str);
static void ReversePrintChars(const char * str);

int main(int argc, char* argv[])
{
	char * string = "Hello Kookmin Univ.";
	printf("The Length of \"%s\" = %d\n", string, Length(string));

	PrintChars(string);
	printf("\n");

	ReversePrintChars(string);
	printf("\n");
	return 0;
}

int Length(const char * str)
{
	if (*str != NULL)
		return Length(++str) + 1;
	else
		return 0;
}

void PrintChars(const char* str)
{
	if (*str != NULL)
	{
		printf("%c", *str);
		PrintChars(str + 1);
	}else
		return;
}
void ReversePrintChars(const char* str)
{
	if (*str != NULL)
	{
		ReversePrintChars(str + 1);
		printf("%c", *str);
	}
}