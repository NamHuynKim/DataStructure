// Lab 004 
// Name :
// Student ID :

#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;



class SparseMatrix; // forward declaration

class MatrixTerm {
	friend class SparseMatrix;
private:
	int row, col, value;	// row number, column number, value
};

class SparseMatrix {
	int rows, cols, terms, capacity;
	MatrixTerm *smArray;	// list of non-zero terms

	void NewTerm(const int row, const int col, const int value);	// Insert row, column, value
	// Insert a new term into the SparseMatrix

public:
	SparseMatrix(int capacity = 10);
	// initialize the sparse matrix class 

	SparseMatrix Add(SparseMatrix &b);
	//Return the sum of the matrix *this and b

	void InitSparseMatrix(const char *msg);
	// Initialize the Sparse Matrix

	void Show(const char *msg);
	// show the content of smArray

	int Compare(MatrixTerm &a, MatrixTerm &b);	// compare the row and column of the two matrix terms.
	// if a is smaller than b in row major order, return negative value 
	// if a is the same as b in row major order, return 0
	// if b is smaller than a in row major order, return positive value
};

