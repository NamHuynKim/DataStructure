#include <stdio.h>
#include <memory.h>
#define bool int
#define TRUE 1
#define FALSE !TRUE

typedef struct element Element;
typedef struct node Node;
typedef struct stack Stack;

struct element{
	int key;
};

struct node{
	Element item;
	Node *link;
};

struct stack{
	Node *top;
};

static void AddStack(Stack *stack, const Element item);
static Element DeleteStack(Stack *stack);
static void DestroyStack(Stack *stack);
static void PrintStack(Stack *stack);
static bool IsEmpty(Stack *stack);

int main(int argc, char *argv[])
{
	Stack stack;
	Element item;
	memset(&stack, 0x00, sizeof(Stack));

	item.key = 1;
	printf("Add 1st element into the stack. \n");
	AddStack(&stack, item);
	PrintStack(&stack);

	item.key = 2;
	printf("Add 2nd element into the stack. \n");
	AddStack(&stack, item);
	PrintStack(&stack);

	item.key = 3;
	printf("Add 3rd element into the stack. \n");
	AddStack(&stack, item);
	PrintStack(&stack);

	item.key = 4;
	printf("Add 4th element into the stack. \n");
	AddStack(&stack, item);
	PrintStack(&stack);

	printf("Delete the top element from the stack. \n");
	item = DeleteStack(&stack);
	printf("Delete %d \n", item.key);

	PrintStack(&stack);

	printf("Destroy the stack. \n");
	DestroyStack(&stack);

	
	return 0;
}

static void AddStack(Stack *stack, const Element item)
{
	if (IsEmpty(stack))
	{
		Node *newNode = (Node*)malloc(sizeof(Node));
		newNode->item = item;
		stack->top = newNode;
		newNode->link = NULL;
		return;
	}
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->item = item;
	newNode->link = stack->top;
	stack->top = newNode;
}

static Element DeleteStack(Stack *stack)
{
	if (IsEmpty(stack))
	{
		printf("Stack is empty. \n");
		return;
	}
	Element item;
	Node *deleteNode = (Node*)malloc(sizeof(Node));
	deleteNode = stack->top;
	item = deleteNode->item;
	stack->top = stack->top->link;
	free(deleteNode);
	return item;
}


static void DestroyStack(Stack *stack)
{
	Node *begin = (Node*)malloc(sizeof(Node));
	begin = stack->top;
	while (begin)
	{
		Node *deleteNode = begin;
		printf("%d is destroyed \n", deleteNode->item.key);
		begin = deleteNode->link;
		free(deleteNode);
	}
}

static void PrintStack(Stack *stack)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode = stack->top;
	while (newNode->link != NULL)
	{
		printf("%d ", newNode->item.key);
		newNode = newNode->link;
	}
	printf("%d \n", newNode->item.key);
}

static bool IsEmpty(Stack *stack)
{
	if (stack->top == NULL)
		return TRUE;
	else
		return FALSE;
}