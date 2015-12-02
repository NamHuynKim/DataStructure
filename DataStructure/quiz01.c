#include <stdio.h>

void main()
{
	int i, j;
	int arr[2][5] = { 10, 20, 33, 35, 13, 43, 22, 20, 69, 28 };

	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 5; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}