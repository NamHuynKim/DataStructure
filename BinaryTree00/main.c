#include "BinaryTree.h"

int main(int argc, char *argv[])
{
	BinaryTree *binaryTree = CreateBinaryTree();
	TreeNode *A = CreateTreeNode('A');
	TreeNode *B = CreateTreeNode('B');
	TreeNode *C = CreateTreeNode('C');
	TreeNode *D = CreateTreeNode('D');
	TreeNode *E = CreateTreeNode('E');
	TreeNode *F = CreateTreeNode('F');
	TreeNode *G = CreateTreeNode('G');
	TreeNode *H = CreateTreeNode('H');
	TreeNode *I = CreateTreeNode('I');
	TreeNode *J = CreateTreeNode('J');

	binaryTree->root = A;
	AddLeftBinaryTree(A, B);
	AddRightBinaryTree(A, C);
	AddLeftBinaryTree(B, D);
	AddLeftBinaryTree(D, G);
	AddRightBinaryTree(D, H);
	AddLeftBinaryTree(C, E);
	AddRightBinaryTree(C, F);
	AddLeftBinaryTree(E, I);
	AddRightBinaryTree(E, J);

	Inorder(binaryTree->root);
	printf("\n");
	Preorder(binaryTree->root);
	printf("\n");
	Postorder(binaryTree->root);
	printf("\n");
	InorderIter(binaryTree->root);
	printf("\n");
	Levelorder(binaryTree->root);
	printf("\n");

	return 0;
}
