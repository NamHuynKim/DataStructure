#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "SelectionTree.h"

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



void Inorder(const TreeNode *nodeTree)
{
	if (!nodeTree) return;
	Inorder(nodeTree->childLeft);
	printf("%d ", nodeTree->item.data);
	Inorder(nodeTree->childRight);
}