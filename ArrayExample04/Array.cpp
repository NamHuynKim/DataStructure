#include <iostream>

static int MaxScore(const int* score, const int rows);

int main(int argc, char* argv[])
{
	int score[10] = { 10, 20, 83, 95, 13, 22, 77, 45, 67, 88 };
	std::cout << MaxScore(score, sizeof(score) / sizeof(int)) << std::endl;

	return 0;
}

int MaxScore(const int* score, const int rows)
{
	int max = score[0];

	for (int i = 1; i < rows; i++)
	{
		if (max < score[i])
			max = score[i];
	}
	return max;
}