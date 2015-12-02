#include "BinaryTree.h"


int main(int argc, char *argv[])
{
	TreeNode<char> *tn0 = new TreeNode<char>('A');
	TreeNode<char> *tn1 = new TreeNode<char>('/');
	TreeNode<char> *tn2 = new TreeNode<char>('B');
	tn1->AddLeft(tn0); tn1->AddRight(tn2);

	TreeNode<char> *tn3 = new TreeNode<char>('*');
	TreeNode<char> *tn4 = new TreeNode<char>('C');
	tn3->AddLeft(tn1); tn3->AddRight(tn4);

	TreeNode<char> *tn5 = new TreeNode<char>('*');
	TreeNode<char> *tn6 = new TreeNode<char>('D');
	tn5->AddLeft(tn3); tn5->AddRight(tn6);

	TreeNode<char> *tn7 = new TreeNode<char>('+');
	TreeNode<char> *tn8 = new TreeNode<char>('E');
	tn7->AddLeft(tn5); tn7->AddRight(tn8);

	Tree<char> *tree = new Tree<char>(tn7);

	std::cout << "Inorder" << std::endl;
	tree->Inorder();
	std::cout << std::endl;

	std::cout << "Preorder" << std::endl;
	tree->Preorder();
	std::cout << std::endl;

	std::cout << "Postorder" << std::endl;
	tree->Postorder();
	std::cout << std::endl;

	std::cout << "Inorder Iterative" << std::endl;
	tree->InorderIter();
	std::cout << std::endl;

	std::cout << "Levelorder" << std::endl;
	tree->Levelorder();
	std::cout << std::endl;
	return 0;
}