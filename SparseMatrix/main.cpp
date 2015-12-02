// Lab 004 
// Name :
// Student ID :

#include "SparseMatrix.h"

// constructor
SparseMatrix::SparseMatrix(int cap) : capacity(cap)
{
	smArray = new MatrixTerm[capacity];
	terms = 0;
}


void SparseMatrix::NewTerm(const int row, const int col, const int value)
{	// Add a new term to the end of smArray
	if (terms == capacity)
	{// double capacity of smArray
		capacity *= 2;
		MatrixTerm *temp = new MatrixTerm[capacity]; // new array
		memcpy(temp, smArray, terms * sizeof(MatrixTerm));
		delete[] smArray;
		smArray = temp;
	}
	smArray[terms].row = row;
	smArray[terms].col = col;
	smArray[terms++].value = value;
}

int SparseMatrix::Compare(MatrixTerm &a, MatrixTerm &b)
{
	// if a is smaller than b in row major order, return negative value 
	// if a is the same as b in row major order, return 0
	// if b is smaller than a in row major order, return positive value
	if (a.row == b.row)
		return a.col - b.col;
	else
		return a.row - b.row;
}



// init the sparse matrix
void SparseMatrix::InitSparseMatrix(const char *msg)
{
	// get the matrix info from the user and 
	// construct the matrix
	cout << endl << "Init Sparse Matrix " << msg << endl;
	int row, col, value;

	cout << "Enter the number of rows and columns : " << endl;
	cin >> rows >> cols;

	while (1)
	{
		cout << "Enter a term (row, col, value)" << endl;
		cin >> row;
		if (row == -1)
			return;
		cin >> col >> value;
		NewTerm(row, col, value);
	}
}

void SparseMatrix::Show(const char *msg) {
	// show the content of smArray
	cout << "Content of smArray of " << msg << " :" << endl;
	for (int i = 0; i < terms; i++) {
		cout << "[" << i << "] " << smArray[i].row << " " << smArray[i].col << " " << smArray[i].value << endl;
	}
	cout << "=========" << endl;
}


int main()
{
	while (1)
	{
		SparseMatrix a;
		SparseMatrix b;

		// construct the sparse matrix a
		a.InitSparseMatrix("a");
		a.Show("a");

		// construct the sparse matrix a
		b.InitSparseMatrix("b");
		b.Show("b");

		SparseMatrix c;
		cout << "c = a + b" << endl;
		c = a.Add(b);
		c.Show("c");

		cout << endl;

		cout << "Continue (y/n) " << endl;
		char ans;
		cin >> ans;
		if (ans == 'n')
			break;
	}

	return 1;
}


