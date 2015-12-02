#include <stdio.h>

void main()
{
	int i, j, score;
	int arr[10] = { 10, 20, 33, 35, 13, 22, 77, 45, 67, 88 };

	for (i = 0; i < 10; i++)
	{
		score = arr[0];
		if (score <= arr[i])
			score = arr[i];
	}

	printf("가장 높은 성적 = %d \n", score);
}