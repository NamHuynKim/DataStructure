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

struct treenode
{
	TreeNode *childLeft;
	ElementTree item;
	TreeNode *childRight;
};

typedef struct binarySearchTree
{
	TreeNode *root;
}BST;

BST *CreateBST(void);
void DestroyBST(BST *tree);
void AddRootBST(BST *tree, const ElementTree item);
void AddChildLeftBST(TreeNode *parent, const ElementTree item);
void AddChildRightBST(TreeNode *parent, const ElementTree item);

TreeNode *Get(const BST *tree, const EType key);
void Insertion(BST *bst, const ElementTree item);
void Delete(BST *bst, const EType key);

void Inorder(const TreeNode *nodeTree);

#endif