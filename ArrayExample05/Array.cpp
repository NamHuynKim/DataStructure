#include <iostream>

static int MaxScore(int* score, const int rows);

int main(int argc, char* argv[])
{
	int score[10] = { 10, 20, 83, 95, 13, 22, 77, 45, 67, 88 };
	std::cout << MaxScore(score, sizeof(score) / sizeof(int)) << std::endl;

	return 0;
}

int MaxScore(int* score, const int rows)
{
	int* Begin = &score[0];
	int* Final = &score[0] + rows;
	int max = *Begin;
	
	while (Begin != Final)
	{
		Begin++;
		if (max < *Begin)
			max = *Begin;
	}
	return max;
}