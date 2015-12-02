#include <stdio.h>

static int Fibonacci(int num);

int main(int argc, char* argv[])
{
	int num;
	for (num = 0; num <= 10; num++)
	{
		printf("Fibonacci(%d) = %d\n", num, Fibonacci(num));
	}
	return 0;
}

int Fibonacci(int num)
{
	if (num == 0 || num == 1)
		return num;
	else
		return Fibonacci(num-1) + Fibonacci(num-2);
}