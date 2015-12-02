#include "SparseMatrix.h"

int main(int argc, char* argv[])
{
	int rows, cols, Terms = 0;
	

	int arr[][6] = { 15, 0, 0, 22, 0, -15,
		0, 11, 3, 0, 0, 0,
		0, 0, 0, -6, 0, 0,
		0, 0, 0, 0, 0, 0,
		91, 0, 0, 0, 0, 0,
		0, 0, 28, 0, 0, 0 };

	rows = sizeof(arr) / sizeof(arr[0]);
	cols = sizeof(arr[0]) / sizeof(int);

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (arr[i][j] != 0)
				Terms++;
		}
	}

	SparseMatrix sm(rows, cols, Terms);
}

SparseMatrix::SparseMatrix(int MaxRow, int MaxCol, int maxTerms)
{
	Rows = MaxRow;
	Cols = MaxCol;
	Terms = maxTerms;
}

SparseMatrix SparseMatrix::Transpose()
{
	SparseMatrix b;
	b.Rows = Cols;
	b.Cols = Rows;
	b.Terms = Terms;
	if (Terms > 0)
	{
		int CurrentB = 0;
		for (int c = 0; c < Cols; c++)
			for (int i = 0; i < Terms; i++)
			if (smArray[i].col == c)
			{
				b.smArray[CurrentB].row = c;
				b.smArray[CurrentB].col = smArray[i].row;
				b.smArray[CurrentB].value = smArray[i].value;
				CurrentB++;
			}
	}
	return b;
}

SparseMatrix SparseMatrix::FastTranspose()
{
	int* RowSize = new int[Cols];
	int* RowStart = new int[Cols];
	SparseMatrix b;
	b.Rows = Cols;
	b.Cols = Rows;
	b.Terms = Terms;
	if (Terms > 0)
	{
		for (int i = 0; i < Cols; i++)
			RowSize[i] = 0;
		for (int i = 0; i < Terms; i++)
			RowSize[smArray[i].col]++;
		RowStart[0] = 0;

		for (int i = 0; i < Terms; i++)
		{
			int j = RowStart[smArray[i].col];
			b.smArray[j].row = smArray[i].col;
			b.smArray[j].col = smArray[i].row;
			b.smArray[j].value = smArray[i].value;
			RowStart[smArray[i].col]++;
		}
	}
	return b;
}

SparseMatrix SparseMatrix::Add(SparseMatrix b)
{

}

SparseMatrix SparseMatrix::Multiply(SparseMatrix b)
{

}