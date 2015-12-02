#include <stdio.h>
#define MaxTerms 20

typedef struct Term{
	int row, col, value;
}Term;

typedef struct SparseMatrix{
	Term smArray[MaxTerms];
	int Rows, Cols, Terms;
}SparseMatrix;

static SparseMatrix Create(int* arr,int row, int col);
static SparseMatrix Add(SparseMatrix s1, SparseMatrix s2);
static SparseMatrix Mul(SparseMatrix s1, SparseMatrix s2);
static SparseMatrix Transpose(SparseMatrix s1, SparseMatrix s2);
static SparseMatrix FastTranspose(SparseMatrix s1);
void printSparseMatrix(SparseMatrix s1);

int main(int argc, char* argv[])
{
	int rows, cols;
	int i, j;
	SparseMatrix s1, s2, s3, s4, s5;

	int arr[][6] = { 15, 0, 0, 22, 0, -15,
		0, 11, 3, 0, 0, 0,
		0, 0, 0, -6, 0, 0,
		0, 0, 0, 0, 0, 0,
		91, 0, 0, 0, 0, 0,
		0, 0, 28, 0, 0, 0 };

	rows = sizeof(arr) / sizeof(arr[0]);
	cols = sizeof(arr[0]) / sizeof(int);
	//initialize
	s1 = Create(arr, rows, cols);
	s2 = Create(arr, rows, cols);
	s3 = Create(arr, rows, cols);
	s4 = Create(arr, rows, cols);
	
	//Transpose 출력
	s4 = Transpose(s1, s4);
	printSparseMatrix(s1);
	printSparseMatrix(s4);
	
	//FastTranspose출력
	s5 = FastTranspose(s1);
	printSparseMatrix(s1);
	printSparseMatrix(s5);
}

static SparseMatrix Create(int* arr, int row, int col)
{
	int i, j, count = 0;
	SparseMatrix b;
	b.Cols = col;
	b.Rows = row;
	b.Terms = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (arr[i * col + j] != 0)
			{
				b.Terms++;
				b.smArray[count].row = i;
				b.smArray[count].col = j;
				b.smArray[count].value = arr[i * col + j];
				count++;
			}
		}
	}
	return b;
}

static SparseMatrix Add(SparseMatrix s1, SparseMatrix s2)
{
	int i, j;
	int count = 0;
	SparseMatrix b;

	b.Cols = s1.Cols;
	b.Rows = s1.Rows;
	

	while (s1.Terms >= count || s2.Terms >= count)
	{

	}
}

static SparseMatrix Transpose(SparseMatrix s1, SparseMatrix s2)
{
	int i, j;
	int count = 0;
	s2.Rows = s1.Cols;
	s2.Cols = s1.Rows;
	s2.Terms = s1.Terms;

	if (s1.Terms > 0)
	{
		for (i = 0; i < s1.Cols; i++)
		{
			for (j = 0; j < s1.Terms; j++)
			{
				if (s1.smArray[j].col == i)
				{
					s2.smArray[count].row = i;
					s2.smArray[count].col = s1.smArray[j].row;
					s2.smArray[count].value = s1.smArray[j].value;
					count++;
				}
			}
		}
	}
	return s2;
}

static SparseMatrix FastTranspose(SparseMatrix s1)
{
	int i, j;
	int RowSize[MaxTerms];
	int RowStart[MaxTerms];
	SparseMatrix b;
	
	b.Rows = s1.Cols;
	b.Cols = s1.Rows;
	b.Terms = s1.Terms;
	if (s1.Terms > 0)
	{
		for (i = 0; i < s1.Cols; i++)
			RowSize[i] = 0;
		for (i = 0; i < s1.Terms; i++)
			RowSize[s1.smArray[i].col]++;
		RowStart[0] = 0;

		for (i = 1; i < s1.Cols; i++)
			RowStart[i] = RowStart[i - 1] +RowSize[i - 1];

		for (i = 0; i < s1.Terms; i++)
		{
			j = RowStart[s1.smArray[i].col];
			b.smArray[j].row = s1.smArray[i].col;
			b.smArray[j].col = s1.smArray[i].row;
			b.smArray[j].value = s1.smArray[i].value;
			RowStart[s1.smArray[i].col]++;
		}
	}
	return b;
}

void printSparseMatrix(SparseMatrix s1)
{
	int i;

	for (i = 0; i < s1.Terms; i++)
		printf("%d %d %d \n", s1.smArray[i].row, s1.smArray[i].col, s1.smArray[i].value);
	printf("\n");
}