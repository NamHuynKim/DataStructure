#include <stdio.h>

void PrintArray(int* ptr, int rows, int cols);


int main(int argc, char* argv[])
{
	int rows, cols;
	int arr[3][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };


	rows = sizeof(arr) / sizeof(arr[0]);
	cols = sizeof(arr[0]) / sizeof(int);


	PrintArray(arr, rows, cols);

}

void PrintArray(int* ptr, int rows, int cols)
{
	int i, j;

	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%d  ", ptr[cols * i + j]);
		}
		printf("\n");
	}
}