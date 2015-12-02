#include <stdio.h>
#include <memory.h>
#include <string.h>
#define bool int
#define TRUE 1
#define FALSE !TRUE

typedef struct Element Element;
typedef struct Node Node;
typedef struct Queue Queue;

struct Element{
	int key;
};

struct Node{
	Element item;
	Node *link;
};

struct Queue{
	Node *front;
	Node *rear;
};

static Queue *CreateQueue();
static void AddQueue(Queue *queue, const Element item);
static Element DeleteQueue(Queue *queue);
static void DestroyQueue(Queue *queue);
static void PrintQueue(Queue *queue);
static bool IsEmpty(Queue *queue);

int main(int argc, char *argv[])
{
	Queue *queue = NULL;
	Element item;
	queue = CreateQueue();

	item.key = 1;
	printf("Add 1st element into the queue. \n");
	AddQueue(queue, item);
	PrintQueue(queue);
	
	item.key = 2;
	printf("Add 2nd element into the queue. \n");
	AddQueue(queue, item);
	PrintQueue(queue);

	item.key = 3;
	printf("Add 3rd element into the queue. \n");
	AddQueue(queue, item);
	PrintQueue(queue);

	item.key = 4;
	printf("Add 4th element into the queue. \n");
	AddQueue(queue, item);
	PrintQueue(queue);

	printf("Delete the top element fron the queue. \n");
	item = DeleteQueue(queue);
	printf("Delete %d \n", item.key);
	PrintQueue(queue);

	printf("Delete the top element from the queue. \n");
	item = DeleteQueue(queue);
	printf("Delete %d \n", item.key);
	PrintQueue(queue);
	
	printf("Destroy the queue. \n");
	DestroyQueue(queue);

	return 0;
}

static Queue *CreateQueue()
{
	Queue *queue = (Queue*)malloc(sizeof(Queue));
	queue->front = NULL;
	queue->rear = NULL;

	return queue;
}
static void AddQueue(Queue *queue, const Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->link = NULL;
	newNode->item = item;
	if (queue->front == NULL)
	{
		queue->front = newNode;
		return;
	}
	else if (queue->rear == NULL)
	{
		queue->rear = newNode;
		queue->front->link = queue->rear;
		return;
	}
	queue->rear->link = newNode;
	queue->rear = queue->rear->link;
}

static Element DeleteQueue(Queue *queue)
{
	if (IsEmpty(queue))
	{
		printf("Queue is Empty. \n");
		return;
	}
	Node *deleteNode = (Node*)malloc(sizeof(Node));
	Element item;
	deleteNode = queue->front;
	item = deleteNode->item;
	queue->front = queue->front->link;
	free(deleteNode);
	return item;
}

static void DestroyQueue(Queue *queue)
{
	Node *begin = queue->front;
	while (begin)
	{
		Node *deleteNode = begin;
		begin = begin->link;

		printf("Destroy Node: %d \n", deleteNode->item.key);
		free(deleteNode);
	}
	free(queue);
}

static void PrintQueue(Queue *queue)
{
	Node *begin = queue->front;
	while (begin)
	{
		printf("%d ", begin->item.key);
		begin = begin->link;
	}
	printf("\n");
}

static bool IsEmpty(Queue *queue)
{
	if (queue->front == NULL && queue->rear == NULL)
		return TRUE;
	else
		return FALSE;
}