#include <stdio.h>
#define MAX_SIZE 100

static float Sum(const float[], const int rows);

int main(int argc, char* argv[])
{
	float input[MAX_SIZE];
	float answer = 0.0;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		input[i] = (float)i;
	}
	answer = Sum(input, MAX_SIZE);
	printf("%f", answer);

	return 0;
}

float Sum(const float* arr, const int rows)
{
	float* Begin = &arr[0];
	float* Final = &Begin[0] + rows;
	float sum = 0.0;

	while (Begin != Final)
	{
		sum += *Begin;
		Begin++;
	}
	return sum;
}