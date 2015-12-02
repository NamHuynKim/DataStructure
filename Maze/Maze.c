#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define TRUE 1
#define FALSE !TRUE
#define ROW_SIZE 14
#define COL_SIZE 17

typedef int Bool;

//방향 좌표위한 구조체
typedef struct OffSets{
	int a, b;
}OffSets;

typedef enum directions{
	N, NE, E, SE, S, SW, W, NW
}Directions;

//위치와 방향 정보를 담고있는 구조체
typedef struct Items
{
	int x, y;
	Directions dir;
}Items;

//길의 위치,방향 저장위한 스택
typedef struct Stack
{
	int capacity, size;
	Items *top;
	Items *elem;
}Stack;

OffSets move[8] = { { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { 0, -1 }, { -1, -1 } };

static Stack* CreateStack(int size);				//스택 생성
static void DestroyStack(Stack *stack);				//스택 지우기
static void AddStack(Stack *stack, const Items x);	//스택에 Items 추가
static void DeleteStack(Stack *stack);				//스택 top에 있는 원소 지우기
static void PrintStack(Stack *stack);				//스택에 있는 모든 원소 출력
static Bool IsEmptyStack(Stack *stack);				//스택이 비어있는지 확인
static Bool IsFoolStack(Stack *stack);				//스택이 가득차있는지 확인
static void FindPath(const int m, const int p);		//미로 길찾기 함수 (iterative)
static void FindPathRecursive(Stack *stack, Items temp, const int m, const int p);
//미로 길찾기 함수 (recursive)

//미로세팅
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

//이 배열을 이용해 지나온 길을 표시함
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
		//현재위치
		int i = temp.x;
		int j = temp.y;
		int d = N;
		while (d < 8)
		{
			//다음위치
			int g = i + move[d].a;
			int h = j + move[d].b;
			if ((g == m-1) && (h == p-1)) //출구 찾았을때
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
				AddStack(stack, temp); //현재위치 저장
				i = g;
				j = h;
				d = N;
			}
			else
				d++;
		}
	}
	printf("No path in maze \n");
	DestroyStack(stack);		//메모리반환
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
			if ((g == m - 1) && (h == p - 1)) //출구 찾았을때
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
	stack = CreateStack(ROW_SIZE*COL_SIZE);	//미로의 길위치 저장해둘 스택생성
	mark[1][1] = 1;							//미로시작위치
	Items temp = { 1, 1, E };				//미로 길찾기 시작 위치와 방향
	AddStack(stack, temp);
	FindPathRecursive(stack, temp, ROW_SIZE, COL_SIZE);
	//FindPath(ROW_SIZE, COL_SIZE);
	return 0;
}