#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

typedef struct Array
{
	int index;
	int *value;
}Array;

Array* Create(int size, int* list);
void Store(Array*, int i, int x); 
int ItemRetrieve(Array*, int i);
void BinarySearch(int search, Array* arr);

int main(int argc, char* argv[])
{
	int i;
	int arr[5] = { 2, 3, 5, 10, 15 };
	
	Array* array = Create(sizeof(arr)/sizeof(int), &arr[0]);

	for (i = 0; i < array->index; i++)
		printf("%d ", array->value[i]);
	printf("\n");

	Store(array, 3, 8);
	for (i = 0; i < array->index; i++)
		printf("%d ", array->value[i]);
	printf("\n");

	printf("Item Retrieve 3: %d \n", ItemRetrieve(array, 3));

	BinarySearch(8, array);

	free(array->value);
	free(array);
	return 0;
}

Array* Create(int j, int* list)
{
	int  i;
	Array* arr = (Array*)malloc(sizeof(Array));
	arr->index = j;
	arr->value = (int*)malloc(sizeof(int)*MAX_SIZE);
	for (i = 0; i < j; i++)
		arr->value[i] = list[i];

	return arr;
}

void Store(Array* arr, int i, int x)
{
	int count, temp = 0;
	arr->index += 1;
	int* array = (int*)malloc(sizeof(int)*arr->index);

	for (count = 0; count < arr->index; count++)
	{
		if (count == i - 1)
			array[count] = x;
		else
		{
			array[count] = arr->value[temp];
			temp++;
		}
	}
	arr->value = array;
}

int ItemRetrieve(Array* arr, int i)
{
	return arr->value[i-1];
}

void BinarySearch(int search, Array* arr)
{
	int first, middle, last;
	first = 0;
	last = arr->index - 1;
	middle = (first + last) / 2;

	while (first <= last) {
		if (arr->value[middle] < search)
			first = middle + 1;
		else if (arr->value[middle] == search) {
			printf("%d is located %d.\n", search, middle + 1);
			break;
		}
		else
			last = middle - 1;
		middle = (first + last) / 2;
	}
	if (first > last)
		printf("Not found! %d \n", search);
}