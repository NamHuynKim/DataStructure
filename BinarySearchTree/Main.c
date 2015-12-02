#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include <stdio.h>
#include "BinarySearchTree.h"

int main(int argc, char *argv[])
{
	BST *tree = NULL;
	ElementTree item;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	tree = CreateBST();

	item.data = 40;
	AddRootBST(tree, item);

	item.data = 20;
	AddChildLeftBST(tree->root, item);

	item.data = 60;
	AddChildRightBST(tree->root, item);

	item.data = 10;
	AddChildLeftBST(tree->root->childLeft, item);

	item.data = 30;
	AddChildRightBST(tree->root->childLeft, item);

	item.data = 70;
	AddChildRightBST(tree->root->childRight, item);

	item.data = 50;
	AddChildLeftBST(tree->root->childRight, item);

	item.data = 45;
	Insertion(tree, item);

	item.data = 55;
	Insertion(tree, item);

	item.data = 52;
	Insertion(tree, item);

	item.data = 70;
	Insertion(tree, item);

	printf("Inorder Traversal:\n");
	Inorder(tree->root);
	printf("\n\n");

	printf("Get location:20 %d %d \n\n", tree->root->childLeft, Get(tree, 20));

	printf("Delete \n");
	Delete(tree, 20);
	Inorder(tree->root);
	printf("\n\n");

	DestroyBST(tree);
	return 0;
}