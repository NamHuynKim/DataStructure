#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ThreadBinaryTree.h"

#define false 0
#define true !false

ThreadBinaryTree *CreateThreadBinaryTree(void)
{
	ThreadBinaryTree *tree = (ThreadBinaryTree *)malloc(sizeof(ThreadBinaryTree));
	memset(tree, NULL, sizeof(ThreadBinaryTree));
	return tree;
}

void AddRoot(ThreadBinaryTree *tree)
{
	TreeNode *newNode = NULL;
	if (!tree) return;
	if (tree->root)	return;

	newNode = (TreeNode*)malloc(sizeof(TreeNode));
	memset(newNode, NULL, sizeof(TreeNode));
	newNode->childLeft = newNode;
	newNode->childRight = newNode;
	newNode->threadLeft = false;
	newNode->threadRight = false;
	tree->root = newNode;
}

void AddChildLeft(ThreadBinaryTree *tree, TreeNode *node, const ElementTree item)
{
	TreeNode *newNode = NULL;
	if (!tree->root) return;

	newNode = (TreeNode*)malloc(sizeof(TreeNode));
	memset(newNode, NULL, sizeof(TreeNode));
	newNode->item = item;
	if (node == tree->root)
	{
		newNode->childLeft = node;
		newNode->threadLeft = true;
		newNode->childRight = node;
		newNode->threadRight = true;
		node->childLeft = newNode;
	}
	else
	{
		newNode->childLeft = node->childLeft;
		newNode->threadLeft = node->threadLeft;
		newNode->childRight = node;
		newNode->threadRight = true;
		node->childLeft = newNode;
		node->threadLeft = false;
	}
	
}
void AddChildRight(ThreadBinaryTree *tree, TreeNode *node, const ElementTree item)
{
	TreeNode *newNode = NULL;
	if (!tree->root) return;
	if (!tree->root->childLeft) return;
	
	newNode = (TreeNode*)malloc(sizeof(TreeNode));
	memset(newNode, NULL, sizeof(TreeNode));
	newNode->item = item;
	newNode->childRight = node->childRight;
	newNode->threadRight = node->threadRight;
	newNode->childLeft = node;
	newNode->threadLeft = true;

	node->childRight = newNode;
	node->threadRight = false;
}

void DestroyThreadBinaryTree(ThreadBinaryTree *tree)
{
	DestroyTreeNode(tree->root->childLeft);
	free(tree->root);
	free(tree); tree = NULL;
}

void DestroyTreeNode(TreeNode *node)
{
	if (!node->threadLeft)
		DestroyTreeNode(node->childLeft);
	if (!node->threadRight)
		DestroyTreeNode(node->childRight);

	free(node); node = NULL;
}



void DeleteNode(TreeNode *node)
{

}

void InorderIter(ThreadBinaryTree *tree)
{
	TreeNode *currentNode = tree->root;
	TreeNode *temp;
	if (!tree->root) return;
	while (1)
	{
		temp = currentNode->childRight;
		if (!currentNode->threadRight)
			while (!temp->threadLeft)
				temp = temp->childLeft;
		currentNode = temp;
		printf("%c ", currentNode->item.data);

		if (currentNode->childRight == tree->root)
			return;
	}
}
