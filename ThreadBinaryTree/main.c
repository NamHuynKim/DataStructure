#define _CRTDBG_MAP_ALLOC
#include <stdio.h>
#include <crtdbg.h>
#include "ThreadBinaryTree.h"

int main(int argc, char *argv[])
{
	ThreadBinaryTree *tree = NULL;
	tree = CreateThreadBinaryTree();
	ElementTree item;
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	AddRoot(tree);

	item.data = 'A';
	AddChildLeft(tree, tree->root, item);

	item.data = 'B';
	AddChildLeft(tree, tree->root->childLeft, item);

	item.data = 'C';
	AddChildRight(tree, tree->root->childLeft, item);

	item.data = 'D';
	AddChildLeft(tree, tree->root->childLeft->childLeft, item);

	item.data = 'E';
	AddChildRight(tree, tree->root->childLeft->childLeft, item);

	item.data = 'H';
	AddChildLeft(tree, tree->root->childLeft->childLeft->childLeft, item);
	
	item.data = 'I';
	AddChildRight(tree, tree->root->childLeft->childLeft->childLeft, item);

	item.data = 'F';
	AddChildLeft(tree, tree->root->childLeft->childRight, item);

	item.data = 'G';
	AddChildRight(tree, tree->root->childLeft->childRight, item);

	item.data = 'J';
	AddChildRight(tree, tree->root->childLeft, item);

	item.data = 'K';
	AddChildLeft(tree, tree->root->childLeft->childLeft, item);

	InorderIter(tree);
	printf("\n");

	DestroyThreadBinaryTree(tree);
	return 0;
}