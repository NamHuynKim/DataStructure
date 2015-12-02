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
	int temp;
	for (int i = 0; i < size / 2; i++)
	{
		temp = array[i];
		array[i] = array[size - i -1];
		array[size - i - 1] = temp;
	}

	for (int i = 0; i < size; i++)
		std::cout << array[i] << " ";
}