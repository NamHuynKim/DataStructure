#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "BinarySearchTree.h"

static void DestroyTreeNode(TreeNode *node);

BST *CreateBST(void)
{
	BST *tree = (BST*)malloc(sizeof(BST));
	memset(tree, 0x00, sizeof(BST));
	return tree;
}

void DestroyBST(BST *tree)
{
	DestroyTreeNode(tree->root);
	free(tree); tree = NULL;
}

void DestroyTreeNode(TreeNode *node)
{
	if (!node)	return;
	DestroyTreeNode(node->childLeft);
	DestroyTreeNode(node->childRight);
	free(node); node = NULL;
}

void AddRootBST(BST *tree, const ElementTree item)
{
	TreeNode *nodeNew = NULL;
	if (!tree) return;
	if (tree->root) return;

	nodeNew = (TreeNode *)malloc(sizeof(TreeNode));
	memset(nodeNew, NULL, sizeof(TreeNode));
	nodeNew->item = item;
	tree->root = nodeNew;
}

void AddChildLeftBST(TreeNode *parent, const ElementTree item)
{
	TreeNode *nodeNew = NULL;
	if (!parent)
		return;
	nodeNew = (TreeNode*)malloc(sizeof(TreeNode));
	memset(nodeNew, NULL, sizeof(TreeNode));
	nodeNew->item = item;
	parent->childLeft = nodeNew;
}

void AddChildRightBST(TreeNode *parent, const ElementTree item)
{
	TreeNode *nodeNew = NULL;
	if (!parent)
		return;
	nodeNew = (TreeNode*)malloc(sizeof(TreeNode));
	memset(nodeNew, NULL, sizeof(TreeNode));
	nodeNew->item = item;
	parent->childRight = nodeNew;
}

TreeNode *Get(const BST *tree, const EType key)
{
	TreeNode *currentNode = tree->root;
	while (currentNode)
	{
		if (key < currentNode->item.data)
			currentNode = currentNode->childLeft;
		else if (key > currentNode->item.data)
			currentNode = currentNode->childRight;
		else
			return currentNode;
	}
	return 0;
}

void Insertion(BST *tree, const ElementTree item)
{
	TreeNode *nodeNew = (TreeNode*)malloc(sizeof(TreeNode));
	memset(nodeNew, NULL, sizeof(TreeNode));
	nodeNew->item.data = item.data;

	TreeNode *t = tree->root, *parent = NULL;
	while (t)
	{
		parent = t;
		if (item.data < t->item.data)
			t = t->childLeft;
		else if (item.data > t->item.data)
			t = t->childRight;
		else
		{
			t->item.data = item.data; return;
		}
	}
	
	if (tree->root)
		if (item.data < parent->item.data)
			parent->childLeft = nodeNew;
		else
			parent->childRight = nodeNew;
	else
		tree->root = nodeNew;
}

void Delete(BST *tree, const EType key)
{
	TreeNode *deleteNode = NULL;
	TreeNode *t = tree->root, *parent = t;

	while (t)
	{
		if (t->childLeft && key == t->childLeft->item.data)
		{
			parent = t; t = t->childLeft; break;
		}
		else if (t->childRight && key == t->childRight->item.data)
		{
			parent = t; t = t->childRight; break;
		}
		if (key < t->item.data)
			t = t->childLeft;
		else if (key > t->item.data)
			t = t->childRight;
		
		parent = t;
	}

	deleteNode = t;
	if (deleteNode->childLeft)
	{
		t = deleteNode->childLeft;
		while (t->childRight)
			t = t->childRight;
		deleteNode->item.data = t->item.data;
		if (t->childLeft)
		{
			t->item.data = t->childLeft->item.data;
			free(t->childLeft);
			t->childLeft = NULL;
		}
		else
		{
			free(deleteNode->childLeft);
			deleteNode->childLeft = NULL;
		}
	}
	else if (deleteNode->childRight)
	{
		t = deleteNode->childRight;
		while (t->childLeft)
			t = t->childLeft;
		deleteNode->item.data = t->item.data;
		if (t->childRight)
		{
			t->item.data = t->childRight->item.data;
			free(t->childRight);
			t->childRight = NULL;
		}
		else
		{
			free(deleteNode->childRight);
			deleteNode->childRight = NULL;
		}
	}
	else
	{
		if (parent->childRight == deleteNode)
			parent->childRight = NULL;
		else
			parent->childLeft = NULL;
		free(deleteNode);
		deleteNode = NULL;
	}
}

void Inorder(const TreeNode *nodeTree)
{
	if (!nodeTree) return;
	Inorder(nodeTree->childLeft);
	printf("%d ", nodeTree->item.data);
	Inorder(nodeTree->childRight);
}