#include <iostream>

static void PrintArray(const int* array, const int rows);

int main(int argc, char* argv[])
{
	int arr[] = { 0, 1, 2, 3, 4 };
	PrintArray(arr, sizeof(arr) / sizeof(int));

	return 0;
}

void PrintArray(const int* array, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		std::cout << array[i];
	}
	std::cout << std::endl;
}