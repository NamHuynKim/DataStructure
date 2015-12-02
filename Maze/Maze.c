#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE !TRUE
#define ROW_SIZE 14
#define COL_SIZE 17

typedef int Bool;

//���� ��ǥ���� ����ü
typedef struct OffSets{
	int a, b;
}OffSets;

typedef enum directions{
	N, NE, E, SE, S, SW, W, NW
}Directions;

//��ġ�� ���� ������ ����ִ� ����ü
typedef struct Items
{
	int x, y;
	Directions dir;
}Items;

//���� ��ġ,���� �������� ����
typedef struct Stack
{
	int capacity, size;
	Items *top;
	Items *elem;
}Stack;

OffSets move[8] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

static Stack* CreateStack(int size);				//���� ����
static void DestroyStack(Stack *stack);				//���� �����
static void AddStack(Stack *stack, const Items x);	//���ÿ� Items �߰�
static void DeleteStack(Stack *stack);				//���� top�� �ִ� ���� �����
static void PrintStack(Stack *stack);				//���ÿ� �ִ� ��� ���� ���
static Bool IsEmptyStack(Stack *stack);				//������ ����ִ��� Ȯ��
static Bool IsFoolStack(Stack *stack);				//������ �������ִ��� Ȯ��
static void FindPath(const int m, const int p);		//�̷� ��ã�� �Լ� (iterative)
static void FindPathRecursive(Stack *stack, Items temp, const int m, const int p);
//�̷� ��ã�� �Լ� (recursive)

//�̷μ���
static int maze[ROW_SIZE][COL_SIZE] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
	{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

//�� �迭�� �̿��� ������ ���� ǥ����
static int mark[ROW_SIZE][COL_SIZE] = {
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1 },
	{ 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1 },
	{ 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1 },
	{ 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1 },
	{ 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1 },
	{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	{ 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
	{ 1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1 },
	{ 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
};

void FindPath(const int m, const int p)
{
	Stack* stack = CreateStack(m*p);
	mark[1][1] = 1;
	Items temp = { 1, 1, E };
	AddStack(stack,temp);
	while (!IsEmptyStack(stack))
	{
		temp = *stack->top;
		DeleteStack(stack);
		//������ġ
		int i = temp.x;
		int j = temp.y;
		int d = N;
		while (d < 8)
		{
			//������ġ
			int g = i + move[d].a;
			int h = j + move[d].b;
			if ((g == m-1) && (h == p-1)) //�ⱸ ã������
			{
				PrintStack(stack);
				printf("(%d.%d) dir = %d \n", i, j, d);
				DestroyStack(stack);
				return;
			}

			if ((!maze[g][h]) && (!mark[g][h]))
			{
				mark[g][h] = 1;
				temp.x = i;
				temp.y = j;
				temp.dir = d;
				AddStack(stack, temp); //������ġ ����
				i = g;
				j = h;
				d = N;
			}
			else
				d++;
		}
	}
	printf("No path in maze \n");
	DestroyStack(stack);		//�޸𸮹�ȯ
}

static void FindPathRecursive(Stack *stack, Items temp, const int m, const int p)
{
	if (IsEmptyStack(stack))
	{
		printf("No Path in maze \n");
		DestroyStack(stack);
		return;
	}
	else
	{
		temp = *stack->top;
		DeleteStack(stack);

		int i = temp.x;
		int j = temp.y;
		int d = temp.dir;

		if (d < 8)
		{
			int g = i + move[d].a;
			int h = j + move[d].b;
			if ((g == m - 1) && (h == p - 1)) //�ⱸ ã������
			{
				PrintStack(stack);
				printf("(%d.%d) dir = %d \n", i, j, d);
				printf("Find path! \n");
				DestroyStack(stack);
				return;
			}

			if ((!maze[g][h]) && (!mark[g][h]))
			{
				mark[g][h] = 1;
				temp.x = i;
				temp.y = j;
				temp.dir = d;
				AddStack(stack, temp);
				temp.x = g;
				temp.y = h;
				temp.dir = N;
				AddStack(stack, temp);
				return FindPathRecursive(stack, temp, m, p);

			}
			else
			{
				temp.dir++;
				AddStack(stack, temp);
				return FindPathRecursive(stack, temp, m, p);
			}
		}
		return FindPathRecursive(stack, temp, m, p);
	}
}

Stack* CreateStack(int size)
{
	Stack *stack = NULL;
	stack = (Stack*)malloc(sizeof(Stack));
	stack->elem = (Items*)malloc(sizeof(Items)*size);
	stack->top = &(stack->elem[0]) - 1;
	stack->capacity = size;
	stack->size = 0;

	return stack;
}

void DestroyStack(Stack *stack)
{
	free(stack->elem);
	free(stack);
}

void AddStack(Stack *stack, const Items x)
{
	if (IsFoolStack(stack)){
		Items *temp = (Items*)malloc(sizeof(Items)*stack->capacity * 2);
		memcpy(temp, stack->elem, sizeof(Items)*stack->capacity);
		free(stack->elem);
		stack->elem = temp;
		stack->top = &stack->elem[stack->capacity] - 1;
		stack->capacity *= 2;
	}
	stack->size++;
	*(++stack->top) = x;
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
	if (IsEmptyStack(stack))
		printf("Stack is empty \n");
	else if (IsFoolStack(stack))
		for (int i = 0; i < stack->size; i++)
			printf("(%d.%d) dir = %d \n", stack->elem[i].x, stack->elem[i].y, stack->elem[i].dir);
	else
		for (int i = 0; i < stack->size; i++)
			printf("(%d.%d) dir = %d \n", stack->elem[i].x, stack->elem[i].y, stack->elem[i].dir);
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


int main(int argc, char *argv[])
{
	Stack *stack = NULL;
	stack = CreateStack(ROW_SIZE*COL_SIZE);	//�̷��� ����ġ �����ص� ���û���
	mark[1][1] = 1;							//�̷ν�����ġ
	Items temp = { 1, 1, E };				//�̷� ��ã�� ���� ��ġ�� ����
	AddStack(stack, temp);
	FindPathRecursive(stack, temp, ROW_SIZE, COL_SIZE);
	//FindPath(ROW_SIZE, COL_SIZE);
	return 0;
}