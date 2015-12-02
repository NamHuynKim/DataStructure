#include "Stack.h"
#include "Queue.h"
#include "BinaryTree.h"
#include <stdio.h>
#include <memory.h>

BinaryTree* CreateBinaryTree()
{	
	return (BinaryTree*)malloc(sizeof(BinaryTree));
}

TreeNode* CreateTreeNode(Element item)
{
	TreeNode *tn = (TreeNode*)malloc(sizeof(TreeNode));
	memset(tn, NULL, sizeof(TreeNode));
	tn->item = item;
	return tn;
}

void AddLeftBinaryTree(TreeNode *location, TreeNode *node)
{
	if (!location->left)
	{
		location->left = node;
	}
	else
	{
		printf("LeftNode is already existed \n");
	}
}

void AddRightBinaryTree(TreeNode *location, TreeNode *node)
{
	if (!location->right)
	{
		location->right = node;
	}
	else
	{
		printf("RighttNode is already existed \n");
	}
}

void Inorder(TreeNode *currentNode)
{
	if (currentNode)
	{
		Inorder(currentNode->left);
		printf("%c ", currentNode->item);
		Inorder(currentNode->right);
	}
}

void Preorder(TreeNode *currentNode)
{
	if (currentNode)
	{
		printf("%c ", currentNode->item);
		Preorder(currentNode->left);
		Preorder(currentNode->right);
	}
}

void Postorder(TreeNode *currentNode)
{
	if (currentNode)
	{
		Postorder(currentNode->left);
		Postorder(currentNode->right);
		printf("%c ", currentNode->item);
	}
}

void InorderIter(TreeNode *currentNode)
{
	Stack *stack = CreateStack(5);
	while (1)
	{
		while (currentNode)
		{
			AddStack(stack, currentNode);
			currentNode = currentNode->left;
		}
		
		if (IsEmptyStack(stack))
			return;
		currentNode = PopStack(stack);
		printf("%c ", currentNode->item);
		currentNode = currentNode->right;
	}
	DestroyStack(stack);
}

void Levelorder(TreeNode *currentNode)
{
	Queue *queue = CreateQueue(5);
	while (currentNode)
	{
		printf("%c ", currentNode->item);
		if (currentNode->left)
			AddQueue(queue, currentNode->left);
		if (currentNode->right)
			AddQueue(queue, currentNode->right);
		if (IsEmptyQueue(queue))
			return;
		currentNode = PopQueue(queue);
	}
}
