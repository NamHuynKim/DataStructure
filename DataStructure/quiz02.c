#include <stdio.h>
#include <stdlib.h>

int getLength(int* arr);
void printArray(int *arr);
int sumrray(int* arr);
int mean(int* arr);
void mode(int* arr);

void main()
{
	int arr[60] = { 5, 6, 7, 2, 5, 3, 9, 4, 6, 4, 4, 8, 0, 6, 3, 7, 0, 2, 0, 8, 7, 8, 0, 5, 8, 7, 3, 9, 7, 8, 3, 5, 2, 9, 7, 5, 3, 8, 7, 2
		, 7, 4, 7, 2, 5, 3, 8, 7, 5, 6, 4, 7, 6, 1, 6, 5, 7, 7, 7, 6 };

	printf("������ ���� 0���� 9������ ��������.\n\n");
	printArray(arr);
	printf("********\n  ���\n********\n");
	printf("�迭 ������ �� = %d \n", sizeof(arr)/ sizeof(arr[0]));
	printf("�迭 ������ ��ü �� = %d \n", summary(arr));
	printf("��� = %d \n", mean(arr));
	mode(arr);
}


void printArray(int *arr)
{
	int i;
	for (i = 0; i < 60; i++)
	{
		if ((i + 1) % 20 == 0)
			printf("%d \n", arr[i]);
		else
			printf("%d ", arr[i]);
	}
}

int summary(int *arr)
{
	int i, sum = 0;

	for (i = 0; i < 60; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int mean(int *arr)
{
	return summary(arr) / strlen(arr);
}

void mode(int *arr)
{
	int i,j;
	int count[10] = { 0 };

	printf("-------------------------------------------\n");
	printf("\t��\tȽ��\t������׷�\n");
	printf("-------------------------------------------\n");
	for (i = 0; i < 60; i++)
	{
		count[arr[i]] += 1;
	}

	for (i = 0; i < 10; i++)
	{
		printf("\t%d\t%d\t", i, count[i]);
		for (j = 0; j < count[i]; j++)
		{
			printf("*");
		}
		printf("\n");
	}
	printf("-------------------------------------------\n");
}