#include <iostream>

static void PrintArray(int* array, const int rows);

int main(int argc, char* argv[])
{
	int arr[] = { 0, 1, 2, 3, 4 };
	PrintArray(arr, sizeof(arr) / sizeof(int));

	return 0;
}

void PrintArray(int* array, const int rows)
{
	int* Begin = &array[0];
	int* Final = &array[0] + rows;
	while (Begin != Final)
	{
		std::cout << Begin << " " << *Begin << std::endl;
		Begin++;
	}
}