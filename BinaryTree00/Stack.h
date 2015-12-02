typedef struct TreeNode TreeNode;
typedef char Element;
typedef int Bool;
typedef TreeNode Etype;

typedef struct Stack
{
	int capacity, top;
	Etype **elem;
}Stack;

Stack* CreateStack(int size);
void DestroyStack(Stack *stack);
void AddStack(Stack *stack, const Etype* x);
Etype* PopStack(Stack *stack);
void PrintStack(Stack *stack);
Bool IsEmptyStack(Stack *stack);
Bool IsFoolStack(Stack *stack);