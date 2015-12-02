#include <stdio.h>

#define ROWS 7
#define COLS 7

static int square[ROWS][COLS] = { 0 };

static void CreateMagicSquare(int i, int j, int count);
static void PrintMatrix(int* square, int rows, int cols);

int main(int argc, char* argv[])
{
	int rows = 0;
	int cols = ROWS / 2;
	int iter = 1;
	square[rows][cols] = iter;

	CreateMagicSquare(rows, cols, ++iter);
	PrintMatrix(&square[0][0], ROWS, COLS);
	printf("\n");
	return 0;

}

void CreateMagicSquare(int i, int j, int count)
{
	int k, l;

	if (i - 1 < 0)
		k = ROWS - 1;
	else
		k = i - 1;

	if (j - 1 < 0)
		l = COLS - 1;
	else
		l = j - 1;

	if (square[k][l] != 0)
		i = (i + 1) % ROWS;
	else
		i = k; j = l;
	

	if (count <= ROWS * COLS)
	{
		square[i][j] = count;
		CreateMagicSquare(i, j, ++count);
	}
	else
		return;
}

void PrintMatrix(int* square, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf("%d ", square[j + i * rows]);
		printf("\n");
	}
}