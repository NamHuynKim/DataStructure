typedef struct TreeNode TreeNode;
typedef char Element;
typedef int Bool;
typedef TreeNode Etype;

typedef struct queue{
	int front, rear, capacity;
	Etype **elem;
}Queue;

Queue *CreateQueue(const int size);
void Destroy(Queue *queue);
void AddQueue(Queue *queue, const Etype* x);
Queue* PopQueue(Queue *queue);
int IsEmptyQueue(const Queue *queue);
int IsFoolQueue(const Queue *queue);
void PrintQueue(const Queue *queue);