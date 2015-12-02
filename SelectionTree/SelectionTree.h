#ifndef BST_H
#define BST_H

#ifndef ETYPE
#define ETYPE
typedef int EType;
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

typedef struct treenode
{
	TreeNode *childLeft;
	ElementTree item;
	TreeNode *childRight;
}TreeNode;

typedef struct binarySearchTree
{
	TreeNode *root;
}BST;

BST *CreateBST(void);
void DestroyBST(BST *tree);
void AddRootBST(BST *tree, const ElementTree item);
void AddChildLeftBST(TreeNode *parent, const ElementTree item);
void AddChildRightBST(TreeNode *parent, const ElementTree item);


void Inorder(const TreeNode *nodeTree);

#endif