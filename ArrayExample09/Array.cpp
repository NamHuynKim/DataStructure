#include <iostream>

static void ReverseArray(int* array, const int size);

int main(int argc, char* argv[])
{
	int array[] = { 10, 20, 33, 35, 13, 22, 77, 45, 67, 88 };
	ReverseArray(&array[0], sizeof(array) / sizeof(int));
	return 0;
}

void ReverseArray(int* array, const int size)
{
	int* Begin = &array[0];
	int* Final = Begin + size - 1;
	int* End = Begin + size / 2;
	int temp;

	while (Begin != End)
	{
		temp = *Begin;
		*Begin = *Final;
		*Final = temp;
		Begin++;
		Final--;
	}

	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
	std::cout << std::endl;
}