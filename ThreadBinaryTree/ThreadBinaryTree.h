#ifndef THREAD_BINARYTREE_H_
#define THREAD_BINARYTREE_H_

#ifndef BOOL
#define BOOL
typedef int Bool;
#endif

#ifndef ETYPE
#define ETYPE
typedef char EType;
#endif

#ifndef ELEMENT_TREE
#define ELEMENT_TREE
typedef struct element ElementTree;
#endif

#ifndef TREENODE
#define TREENODE
typedef struct treenode TreeNode;
#endif

struct element
{
	EType data;
};

struct treenode
{
	TreeNode *childLeft;
	Bool threadLeft;
	ElementTree item;
	Bool threadRight;
	TreeNode *childRight;
};

typedef struct threadBinaryTree
{
	TreeNode *root;
}ThreadBinaryTree;


ThreadBinaryTree *CreateThreadBinaryTree(void);
void AddRoot(ThreadBinaryTree *tree);
void AddChildLeft(ThreadBinaryTree *tree, TreeNode *node, const ElementTree item);
void AddChildRight(ThreadBinaryTree *tree, TreeNode *node, const ElementTree item);
void DestroyThreadBinaryTree(ThreadBinaryTree *tree);
void DestroyTreeNode(TreeNode *node);
void DeleteNode(TreeNode *node);
void InorderIter(ThreadBinaryTree *tree);
#endif