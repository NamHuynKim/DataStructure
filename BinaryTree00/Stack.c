#include "Stack.h"
#include <stdio.h>
#include <memory.h>

Stack* CreateStack(int size)
{
	Stack *stack = (Stack*)malloc(sizeof(Stack));
	memset(stack, NULL, sizeof(Stack));
	stack->capacity = size;
	stack->top = -1;
	stack->elem = (Etype**)malloc(sizeof(Etype*)*size);
	
	return stack;
}

void DestroyStack(Stack *stack)
{
	if (!stack)
		return;
	while (stack->top != -1)
	{
		free(stack->elem[stack->top--]);
	}
	free(stack);
}

void AddStack(Stack *stack, const Etype* x)
{
	if (IsFoolStack(stack))
	{
		stack->capacity *= 2;
		Etype **temp = (Etype**)malloc(sizeof(Etype*) * stack->capacity);
		memcpy(temp, stack->elem, sizeof(Etype*)*stack->capacity/2);
		free(stack->elem);
		stack->elem = temp;
		printf("Stack is full \n");
	}
	stack->elem[++stack->top] = x;
}

Etype* PopStack(Stack *stack)
{
	if (IsEmptyStack(stack)) 
		return;
	return stack->elem[stack->top--];
}

void PrintStack(Stack *stack)
{
	int _top = stack->top;
	if (IsEmptyStack(stack))
		return;
	while (_top == -1)
	{
		printf("%c ", stack->elem[_top--]);
	}
}

Bool IsEmptyStack(Stack *stack)
{
	return stack->top == -1;
}

Bool IsFoolStack(Stack *stack)
{
	return stack->top == stack->capacity - 1;
}