typedef struct TreeNode TreeNode;
typedef char Element;
typedef int Bool;
typedef TreeNode Etype;

struct TreeNode
{
	Element item;
	TreeNode *left;
	TreeNode *right;
};

typedef struct BinaryTree
{
	TreeNode *root;
}BinaryTree;

//binary tree functions
BinaryTree* CreateBinaryTree();
TreeNode* CreateTreeNode(Element item);
void AddLeftBinaryTree(TreeNode *location, TreeNode *node);
void AddRightBinaryTree(TreeNode *location, TreeNode *node);
void InorderIter(TreeNode *currentNode);
void Inorder(TreeNode *currentNode);
void Preorder(TreeNode *currentNode);
void Postorder(TreeNode *currentNode);
void Levelorder(TreeNode *currentNode);