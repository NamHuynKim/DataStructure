#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef int Bool;
typedef int Etype;
#define TRUE 1
#define FALSE !TRUE

typedef struct Stack
{
	int capacity, size;
	Etype *top;
	Etype *elem;
}Stack;

static Stack* CreateStack(int size);
static void DestroyStack(Stack *stack);
static void AddStack(Stack *stack, const Etype x);
static void DeleteStack(Stack *stack);
static void PrintStack(Stack *stack);
static Bool IsEmptyStack(Stack *stack);
static Bool IsFoolStack(Stack *stack);

int main(int argc, char *argv[])
{
	Stack* s = NULL;
	s = CreateStack(5);
	AddStack(s, 0);
	PrintStack(s);

	AddStack(s, 1);
	PrintStack(s);

	AddStack(s, 2);
	PrintStack(s);

	DeleteStack(s);
	PrintStack(s);

	DeleteStack(s);
	PrintStack(s);

	DeleteStack(s);
	PrintStack(s);

	AddStack(s, 3);
	PrintStack(s);

	AddStack(s, 4);
	PrintStack(s);

	AddStack(s, 5);
	PrintStack(s);

	AddStack(s, 6);
	PrintStack(s);

	AddStack(s, 7);
	PrintStack(s);

	DeleteStack(s);
	PrintStack(s);
	DestroyStack(s);
	return 0;
}

Stack* CreateStack(int size)
{
	Stack* stack = NULL;
	stack = (Stack*)malloc(sizeof(Stack));
	stack->elem = (Etype*)malloc(sizeof(Etype)*size);
	stack->top = &(stack->elem[0])-1;
	stack->capacity = size;
	stack->size = 0;

	return stack;
}

static void DestroyStack(Stack *stack)
{
	free(stack->elem);
	free(stack);
}

void AddStack(Stack *stack, const Etype x)
{
	if (IsFoolStack(stack)){
		Etype *temp = (Etype*)malloc(sizeof(Etype)*stack->capacity * 2);
		memcpy(temp, stack->elem, sizeof(Etype)*stack->capacity);
		free(stack->elem);
		stack->elem = temp;
		stack->top = &stack->elem[stack->capacity]-1;
		stack->capacity *= 2;
		printf("The stack is Full\n");
	}
	stack->size++;
	printf("Add Stack = %d\n", x);
	*(++stack->top) = x;
}

void DeleteStack(Stack *stack)
{
	if (IsEmptyStack(stack))
		printf("Stack is empty \n");
	else
	{
		printf("Delete Stack = %d\n", *stack->top);
		stack->top--; stack->size--;
	}
}

void PrintStack(Stack *stack)
{
	if (IsEmptyStack(stack))
		printf("Stack is empty \n");
	else if (IsFoolStack(stack))
	{
		for (int i = 0; i < stack->size; i++)
			printf("%d ", stack->elem[i]);
		printf("\nThe stack is Full\n");
	}
	else{
		for (int i = 0; i < stack->size; i++)
			printf("%d ", stack->elem[i]);
		printf("\n");
	}
}

Bool IsEmptyStack(Stack *stack)
{
	if (stack->top == &stack->elem[0] - 1)
		return TRUE;
	else
		return FALSE;
}

Bool IsFoolStack(Stack *stack)
{
	if (stack->top == &stack->elem[stack->capacity]-1)
		return TRUE;
	else
		return FALSE;
}
