#include "Queue.h"
#include <stdio.h>
#include <memory.h>

Queue *CreateQueue(const int size)
{
	Queue *q = (Queue*)malloc(sizeof(Queue));
	memset(q, NULL, sizeof(Queue));
	q->capacity = size;
	q->front = -1; q->rear = -1;
	q->elem = (Etype**)malloc(sizeof(Etype*)*size);

	return q;
}

void Destroy(Queue *queue)
{
	if (IsEmptyQueue(queue))
		return;
	while (queue->rear != queue->front)
	{
		free(queue->elem[queue->rear--]);
	}
	free(queue);
}

void AddQueue(Queue *queue, const Etype* x)
{
	if (IsEmptyQueue(queue))
	{
		queue->front = queue->rear = 0;
		queue->elem[queue->rear] = x;
		return;
	}

	if (IsFoolQueue(queue))
	{
		queue->capacity *= 2;
		Etype **temp = (Etype**)malloc(sizeof(Queue) * queue->capacity);
		memcpy(temp, queue->elem, sizeof(Queue*)*queue->capacity/2);
		queue->elem = temp;
		printf("Queue is full \n");
	}
	else if (queue->rear == queue->capacity - 1)
	{
		Etype **temp = (Etype**)malloc(sizeof(Queue) * queue->capacity);
		memcpy(temp, &queue->elem[queue->front], sizeof(Queue*)*(queue->rear - queue->front + 1));
		queue->elem = temp;
		queue->rear -= queue->front; queue->front = 0;
	}
	queue->elem[++queue->rear] = x;
}

Queue* PopQueue(Queue *queue)
{
	return queue->elem[queue->front++];
}

int IsEmptyQueue(const Queue *queue)
{
	return (queue->front == -1 || queue->front > queue->rear);
}

int IsFoolQueue(const Queue *queue)
{
	return (queue->front == 0 && queue->rear == queue->capacity - 1);
}

void PrintQueue(const Queue *queue)
{

}