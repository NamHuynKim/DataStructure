#include <iostream>
#define MaxTerms 10

class SparseMatrix;

class MatrixTerm{
	friend class SparseMatrix;
private:
	int row, col, value;
};


class SparseMatrix{
private:
	int Rows, Cols, Terms;
	MatrixTerm smArray[MaxTerms];
public:
	SparseMatrix(int MaxRow, int MaxCol, int maxTerms);
	SparseMatrix();
	SparseMatrix Transpose();
	SparseMatrix FastTranspose();
};