#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>

typedef int Bool;
typedef int EType;

#define TRUE 1
#define FALSE !TRUE

typedef struct Queue{
	 EType *front, *rear, *elem, *first;
	 int capacity;
}Queue;

static Queue* CreateQueue(const int size);
static void DestroyQueue(Queue *queue);
static void AddQueue(Queue *queue, const EType x);
static void DeleteQueue(Queue *queue);
static int IsEmptyQueue(const Queue *queue);
static int IsFoolQueue(const Queue *queue);
static void PrintQueue(const Queue *queue);

int main(int argc, char *argv[])
{
	Queue* q = NULL;
	q = CreateQueue(5);
	
	AddQueue(q, 0);
	PrintQueue(q);

	AddQueue(q, 1);
	PrintQueue(q);

	AddQueue(q, 2);
	PrintQueue(q);

	DeleteQueue(q);
	PrintQueue(q);
	
	DeleteQueue(q);
	PrintQueue(q);

	AddQueue(q, 3);
	PrintQueue(q);
	
	AddQueue(q, 4);
	PrintQueue(q);

	DeleteQueue(q);
	PrintQueue(q);
	
	DeleteQueue(q);
	PrintQueue(q);

	AddQueue(q, 0);
	PrintQueue(q);

	AddQueue(q, 1);
	PrintQueue(q);

	AddQueue(q, 2);
	PrintQueue(q);

	DeleteQueue(q);
	PrintQueue(q);

	AddQueue(q, 4);
	PrintQueue(q);

	AddQueue(q, 5);
	PrintQueue(q);

	AddQueue(q, 6);
	PrintQueue(q);

	DestroyQueue(q);
	return 0;
}

Queue* CreateQueue(int size){
	Queue* queue = (Queue*)malloc(sizeof(Queue));
	queue->elem = (int*)malloc(sizeof(int)*size);
	queue->capacity = size;
	queue->front = queue->rear = NULL;
	return queue;
}

static void DestroyQueue(Queue *queue)
{
	free(queue->front);
	free(queue);
}

void AddQueue(Queue *queue, const EType x){
	//큐가 비어있을때
	if (IsEmptyQueue(queue)){
		queue->front = queue->rear = queue->first = &queue->elem[0];
		*(queue->rear) = x;
	}
	//큐가 꽉차서 용량을 늘려야할때
	else if (IsFoolQueue(queue) && queue->first == queue->front){
		EType *temp = (EType*)malloc(sizeof(EType)*queue->capacity*2);
		memcpy(temp, queue->front, sizeof(EType)*queue->capacity);
		free(queue->elem);
		queue->elem = temp;
		queue->rear = &queue->elem[queue->capacity-1];
		queue->front = queue->first = &queue->elem[0];

		*++queue->rear = x;
		printf("The queue is Full\n");
	}
	//rear는 끝까지갔지만 앞부분에 저장 공간이 남아있을때
	else if (IsFoolQueue(queue) && queue->first != queue->front){
		memcpy(queue->first, queue->front, queue->rear - queue->front + sizeof(EType));
		queue->rear = queue->elem + (queue->rear - queue->front + sizeof(EType))/sizeof(EType);
		queue->front = queue->first;
		*(++queue->rear) = x;
	}
	else {
		*(++queue->rear) = x;
	}
	printf("Add Queue = %d \n", x);
}
void DeleteQueue(Queue *queue){
	if (IsEmptyQueue(queue))
		printf("Queue is empty \n");
	printf("Delete Queue = %d\n", *queue->front); 
	queue->front++;
}

Bool IsEmptyQueue(const Queue *queue){
	if (queue->front == NULL || queue->front > queue->rear)
		return TRUE;
	else
		return FALSE;
}

Bool IsFoolQueue(const Queue *queue){
	if (queue->rear == &queue->elem[queue->capacity - 1])
		return TRUE;
	else
		return FALSE;
}

static void PrintQueue(const Queue *queue)
{
	if (IsEmptyQueue(queue))
		printf("The queue is empty \n");
	else
	{
		for (int i = 0; queue->front + i <= queue->rear; i++)
			printf("%d ", *(queue->front + i));
		printf("\n");
	}
}