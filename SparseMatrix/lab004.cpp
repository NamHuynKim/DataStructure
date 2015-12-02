// Lab 004
// Name :
// Student ID :

#include "SparseMatrix.h"

SparseMatrix SparseMatrix::Add(SparseMatrix &b) {
	// Return the sum of the Sparse Matrices *this and b
	int aPos = 0, bPos = 0;
	SparseMatrix c(terms + b.terms);
	
	while ((aPos < terms) && (bPos < b.terms)){
		if (smArray[aPos].row == b.smArray[bPos].row){
			if (Compare(smArray[aPos], b.smArray[bPos]) < 0){
				c.NewTerm(smArray[aPos].row, smArray[aPos].col, smArray[aPos].value);
				aPos++;
			}
			else if (Compare(smArray[aPos], b.smArray[bPos]) == 0){
				if (smArray[aPos].value + b.smArray[bPos].value != 0)
					c.NewTerm(smArray[aPos].row, smArray[aPos].col, smArray[aPos].value + b.smArray[bPos].value);
				aPos++; bPos++;
			}
			else{
				c.NewTerm(b.smArray[bPos].row, b.smArray[bPos].col, b.smArray[bPos].value);
				bPos++;
			}
		}
		else if (smArray[aPos].row < b.smArray[bPos].row){
			c.NewTerm(smArray[aPos].row, smArray[aPos].col, smArray[aPos].value);
			aPos++;
		}
		else{
			c.NewTerm(b.smArray[bPos].row, b.smArray[bPos].col, b.smArray[bPos].value);
			bPos++;
		}
	}
	for (; aPos < terms; aPos++)
		c.NewTerm(smArray[aPos].row, smArray[aPos].col, smArray[aPos].value);
	for (; bPos < b.terms; bPos++)
		c.NewTerm(smArray[bPos].row, smArray[bPos].col, b.smArray[bPos].value);

	return c;
}
