#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

typedef int Bool;
typedef int Etype;
typedef enum tokentype TokenType;
#define TRUE 1
#define FALSE !TRUE

typedef struct token
{
	TokenType type;
	Etype value;
}Token;

typedef struct expr
{
	int size;
	Token *elem;
}Expr;

typedef struct Stack
{
	int capacity, size;
	Token *top;
	Token *elem;
}Stack;

static enum tokentype
{
	Operator,
	Operand,
	LParen,
	RParen,
	Term
};

static Stack* CreateStack(Stack *stack, int size);
static void DestroyStack(Stack *stack);
static void AddStack(Stack *stack, const Token x);
static void DeleteStack(Stack *stack);
static void PrintStack(Stack *stack);
static Bool IsEmptyStack(Stack *stack);
static Bool IsFoolStack(Stack *stack);

static Expr *CreateExpression(Token *tokens, const int size);
static void PrintExpression(const Expr *expr);
static Expr *MakePostfix(const Expr *expr);
static int Evaluation(const Expr *expr);
int ISP(Token *token);

int main(int argc, char *argv[])
{
	Expr *expInfix = NULL;
	Expr *expPostfix = NULL;
	int eval = 0;
	//2 * 3 / (2 - 1) + 5 * 3
	Token expr[14] = {
		{ Operand, 2 },
		{ Operator, '*' },
		{ Operand, 3 },
		{ Operator, '/' },
		{ LParen, '(' },
		{ Operand, 2 },
		{ Operator, '-' },
		{ Operand, 1 },
		{ RParen, ')' },
		{ Operator, '+' },
		{ Operand, 5 },
		{ Operator, '*' },
		{ Operand, 3 },
		{ Term, '#' }
	};
	expInfix = CreateExpression(&expr[0], 14);
	printf("Infix = ");
	PrintExpression(expInfix);
	expPostfix = MakePostfix(expInfix);
	printf("Postfix = ");
	PrintExpression(expPostfix);
	eval = Evaluation(expPostfix);
	printf("Evaluation = %d \n", eval);
	
	return 0;
}

static Expr *CreateExpression(Token *tokens, const int size)
{
	int i;
	Expr *infix = (Expr*)malloc(sizeof(Expr));
	infix->elem = (Token*)malloc(sizeof(Token)* size);
	infix->size = size;

	for (i = 0; i < size; i++)
	{
		infix->elem[i].type = tokens[i].type;
		infix->elem[i].value = tokens[i].value;
	}
	return infix;
}

static void PrintExpression(const Expr *expr)
{
	int i = 0;
	for (i = 0; i < expr->size; i++)
		if (expr->elem[i].type == Operand)
			printf("%d", expr->elem[i].value);
		else
			printf("%c", expr->elem[i].value);
	printf("\n");
}

static Expr *MakePostfix(const Expr *expr)
{
	int i = 0;
	int j = 0;
	Stack* s = NULL;
	s = CreateStack(s, expr->size);
	Expr *postfix = (Expr*)malloc(sizeof(Expr));
	postfix->elem = (Token*)malloc(sizeof(Token)*expr->size);
	postfix->size = 0;
	AddStack(s, expr->elem[expr->size-1]);
	while (expr->elem[i].type != Term)
	{
		switch (expr->elem[i].type)
		{
		case Operand:
			postfix->elem[j].type = expr->elem[i].type;
			postfix->elem[j++].value = expr->elem[i].value;
			postfix->size++;
			break;
		case LParen:
			AddStack(s, expr->elem[i]);
			break;
		case RParen:
			while ((*s->top).type != LParen)
			{
				postfix->elem[j].type = (*s->top).type;
				postfix->elem[j++].value = (*s->top).value;
				DeleteStack(s);
				postfix->size++;
			}
			DeleteStack(s);
			break;
		case Operator:
			while (ISP(&expr->elem[i]) >= ISP(s->top))
			{
				postfix->elem[j].type = (*s->top).type;
				postfix->elem[j++].value = (*s->top).value;
				DeleteStack(s);
				postfix->size++;
			}
			AddStack(s, expr->elem[i]);
		case Term:
			break;
		}
		i++;
	}

	while ((*s->top).type != Term)
	{
		postfix->elem[j].type = (*s->top).type;
		postfix->elem[j++].value = (*s->top).value;
		DeleteStack(s);
		postfix->size++;
	}
	return postfix;
}
static int Evaluation(const Expr *expr)
{
	int i;
	Etype x, y;
	Stack *s = NULL;
	Token temp;
	s = CreateStack(s, expr->size);

	for (i = 0; i < expr->size; i++)
	{
		if (expr->elem[i].type == Operand)
		{
			AddStack(s, expr->elem[i]);
		}
		else if (expr->elem[i].value == '*')
		{
			y = (*s->top).value;
			DeleteStack(s);
			x = (*s->top).value;
			DeleteStack(s);
			temp.type = Operand;
			temp.value = x*y;
			AddStack(s, temp);
		}
		else if (expr->elem[i].value == '/')
		{
			y = (*s->top).value;
			DeleteStack(s);
			x = (*s->top).value;
			DeleteStack(s);
			temp.type = Operand;
			temp.value = x/y;
			AddStack(s, temp);
		}
		else if (expr->elem[i].value == '+')
		{
			y = (*s->top).value;
			DeleteStack(s);
			x = (*s->top).value;
			DeleteStack(s);
			temp.type = Operand;
			temp.value = x+y;
			AddStack(s, temp);
		}
		else if (expr->elem[i].value == '-')
		{
			y = (*s->top).value;
			DeleteStack(s);
			x = (*s->top).value;
			DeleteStack(s);
			temp.type = Operand;
			temp.value = x-y;
			AddStack(s, temp);
		}
	}
	return (*s->top).value;
}

int ISP(Token *token)
{
	char op[7] = { '(', '+', '-', '*', '/', '%', '#' };
	int sp[7] = { 8, 3, 3, 2, 2, 2, 9 };
	int i = 0;
	for (; i < 8; i++)
		if (op[i] == token->value)
			return sp[i];
	return -1;
}

static Stack* CreateStack(Stack *stack, int size)
{
	stack = (Stack*)malloc(sizeof(Stack));
	stack->elem = (Token*)malloc(sizeof(Token)*size);
	stack->top = &(stack->elem[0]) - 1;
	stack->capacity = size;
	stack->size = 0;

	return stack;
}

static void DestroyStack(Stack *stack)
{
	free(stack->elem);
	free(stack);
}

void AddStack(Stack *stack, const Token x)
{
	if (IsFoolStack(stack)){
		Token *temp = (Token*)malloc(sizeof(Token)*stack->capacity * 2);
		memcpy(temp, stack->elem, sizeof(Token)*stack->capacity);
		free(stack->elem);
		stack->elem = temp;
		stack->top = &stack->elem[stack->capacity] - 1;
		stack->capacity *= 2;
		printf("The stack is Full\n");
	}
	stack->size++;
	(*++stack->top) = x;
}

void DeleteStack(Stack *stack)
{
	if (IsEmptyStack(stack))
		printf("Stack is empty \n");
	else
		stack->top--; stack->size--;
}

void PrintStack(Stack *stack)
{
	int i = 0;
	if (IsEmptyStack(stack))
		printf("Stack is empty \n");
	else if (IsFoolStack(stack))
	{
		for (i = 0; i < stack->size; i++)
			printf("%d ", stack->elem[i]);
		printf("\nThe stack is Full\n");
	}
	else
		for (i = 0; i < stack->size; i++)
			printf("%d ", stack->elem[i]);
		printf("\n");
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
	if (stack->top == &stack->elem[stack->capacity] - 1)
		return TRUE;
	else
		return FALSE;
}
