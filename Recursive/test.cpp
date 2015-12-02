#include <iostream>
#include <string>

#define MAX_SIZE 3

int BinarySearch(int *arr, int max, int min, int search);
void PrintChars(char *str);
int fibonacci(int a, int b, int n);
int pow(int x, int y);
void MagicSquare(int i, int j, int count);

static int arr[3][3] = { 0 };

int main(int argc, char* argv[])
{
	char* str = "abcd";
	PrintChars(str);
	std::cout << fibonacci(1, 0, 4) << std::endl;
	arr[MAX_SIZE / 2][MAX_SIZE / 2] = 1;
	MagicSquare(MAX_SIZE / 2, MAX_SIZE / 2, 2);
	for (int i = 0; i < MAX_SIZE; i++)
	{
		for (int j = 0; j < MAX_SIZE; j++)
			std::cout << arr[i][j] << " ";
		std::cout << std::endl;
	}

	return 0;
}

void PrintChars(char *str)
{
	if (*str != NULL)
	{
		std::cout << *str;
		PrintChars(str+1);
		std::cout << *str;
	}
}

int fibonacci(int a, int b, int n)
{
	if (n > 0)
		return fibonacci(a + b, a, --n);
	else
		return a;
}

int BinarySearch(int *arr, int max, int min, int search)
{
	int middle = (max + min) / 2;
	if (arr[middle] == search)
		return middle;
	else if (arr[middle] < search)
		return BinarySearch(arr, middle, min, search);
	else if (arr[middle] > search)
		return BinarySearch(arr, max, middle, search);
	else
		return -1;
}

int pow(int x, int y)
{
	if (y == 0)
		return 1;
	else
		return x*pow(x, y - 1);
}

void MagicSquare(int i, int j, int count)
{
	int k, l;
	if (i - 1 < 0)
		k = MAX_SIZE - 1;
	else
		k = i - 1;
	if (j - 1 < 0)
		l = MAX_SIZE - 1;
	else
		l = j - 1;
	if (arr[k][l] != 0)
		i = (i + 1) % MAX_SIZE;
	else
		i = k; j = l;

	if (count <= MAX_SIZE * MAX_SIZE)
	{
		arr[i][j] = count;
		MagicSquare(i, j, ++count);
	}
	else
		return;
}