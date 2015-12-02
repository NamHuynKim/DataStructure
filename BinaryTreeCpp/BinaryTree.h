#ifndef _BINARYTREE_H_
#define _BINARYTREE_H_
#include <iostream>
#include "Queue.h"
#include "Stack.h"

template <class T> class Tree;

template <class T>
class TreeNode
{
	friend class Tree<T>;
public:
	TreeNode(T _data = NULL);
	void AddLeft(TreeNode<T> *node);
	void AddRight(TreeNode<T> *node);

private:
	T data;
	TreeNode<T> *left;
	TreeNode<T> *right;
};

template <class T>
class Tree
{
public:
	Tree(TreeNode<T> *_root = NULL);
	~Tree();
	void Visit(TreeNode<T> *currentNode) const;

	void Inorder() const;
	void Inorder(TreeNode<T> *currentNode) const;

	void Preorder() const;
	void Preorder(TreeNode<T> *currentNode) const;

	void Postorder() const;
	void Postorder(TreeNode<T> *currentNode) const;

	void InorderIter() const;
	void Levelorder() const;
private:
	TreeNode<T> *root;
};

template <class T>
TreeNode<T>::TreeNode(T _data = NULL) : data(_data), left(NULL), right(NULL) {}

template <class T>
void TreeNode<T>::AddLeft(TreeNode<T> *node)
{
	left = node;
}

template <class T>
void TreeNode<T>::AddRight(TreeNode<T> *node)
{
	right = node;
}

template <class T>
void Tree<T>::Visit(TreeNode<T> *currentNode) const
{
	std::cout << currentNode->data << " ";
}

template <class T>
Tree<T>::Tree(TreeNode<T> *_root) : root(_root) {}

template <class T>
void Tree<T>::Inorder() const
{
	Inorder(root);
}

template <class T>
Tree<T>::~Tree()
{

}

template <class T>
void Tree<T>::Inorder(TreeNode<T> *currentNode) const
{
	if (currentNode)
	{
		Inorder(currentNode->left);
		Visit(currentNode);
		Inorder(currentNode->right);
	}
}

template <class T>
void Tree<T>::Preorder() const
{
	Preorder(root);
}

template <class T>
void Tree<T>::Preorder(TreeNode<T> *currentNode) const
{
	if (currentNode)
	{
		Visit(currentNode);
		Preorder(currentNode->left);
		Preorder(currentNode->right);
	}
}

template <class T>
void Tree<T>::Postorder() const
{
	Postorder(root);
}

template <class T>
void Tree<T>::Postorder(TreeNode<T> *currentNode) const
{
	if (currentNode)
	{
		Postorder(currentNode->left);
		Postorder(currentNode->right);
		Visit(currentNode);
	}
}

template <class T>
void Tree<T>::InorderIter() const
{
	Stack<TreeNode<T>> *stack = new Stack<TreeNode<T>>(5);
	TreeNode<T> *currentNode = root;
	while (1)
	{
		while (currentNode)
		{
			stack->Push(currentNode);
			currentNode = currentNode->left;
		}
		if (stack->IsEmpty())
			return;
		currentNode = stack->Top(); stack->Pop();
		std::cout << currentNode->data << " ";
		currentNode = currentNode->right;
	}
}

template <class T>
void Tree<T>::Levelorder() const
{
	Queue<TreeNode<T>*> *queue = new Queue<TreeNode<T>*>(5);
	TreeNode<T> *currentNode = root;
	while (currentNode)
	{
		std::cout << currentNode->data << " ";
		if (currentNode->left)
			queue->Push(currentNode->left);
		if (currentNode->right)
			queue->Push(currentNode->right);
		if (queue->IsEmpty())
			return;
		currentNode = queue->Front(); queue->Pop();
	}
}
#endif