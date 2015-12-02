#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct element Element;
typedef struct node Node;
typedef struct CircularLinkedList CircularLinkedList;

struct element
{
	int key;
};

struct node
{
	Element item;
	Node *llink;
	Node *rlink;
};

struct CircularLinkedList
{
	Node *head;
};

static CircularLinkedList *CreateCircularLinkedList();
static void AddFirstCircularLinkedList(CircularLinkedList *list, Element item);
static void AddLastCircularLinkedList(CircularLinkedList *list, Element item);
static void InsertCircularLinkedList(Node *node, Element item);
static void DeleteCircularLinkedList(CircularLinkedList *list, const int key);
static void PrintCircularLinkedList(CircularLinkedList *list);
static void PrintReverseCircularLinkedList(CircularLinkedList *list);
static void DestroyCircularLinkedList(CircularLinkedList *list);
static Node* FindLastNode(CircularLinkedList *list);

int main(int argc, char *argv[])
{
	CircularLinkedList *list = CreateCircularLinkedList();
	Element item;

	item.key = 2;
	AddFirstCircularLinkedList(list, item);
	DeleteCircularLinkedList(list, 2);
	PrintCircularLinkedList(list);
	PrintReverseCircularLinkedList(list);
	printf("\n");

	item.key = 1;
	AddFirstCircularLinkedList(list, item);
	PrintCircularLinkedList(list);
	PrintReverseCircularLinkedList(list);
	printf("\n");

	item.key = 3;
	AddLastCircularLinkedList(list, item);
	PrintCircularLinkedList(list);
	PrintReverseCircularLinkedList(list);
	printf("\n");

	item.key = 4;
	InsertCircularLinkedList(list->head, item);
	PrintCircularLinkedList(list);
	PrintReverseCircularLinkedList(list);
	printf("\n");

	DeleteCircularLinkedList(list, 3);
	PrintCircularLinkedList(list);
	PrintReverseCircularLinkedList(list);
	printf("\n");

	DestroyCircularLinkedList(list);
	PrintReverseCircularLinkedList(list);
	
	return 0;
}


static CircularLinkedList *CreateCircularLinkedList()
{
	CircularLinkedList *d = (CircularLinkedList*)malloc(sizeof(CircularLinkedList));
	memset(d, NULL, sizeof(CircularLinkedList));
	return d;
}

static void AddFirstCircularLinkedList(CircularLinkedList *list, Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *lastNode;
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	if (!list->head)
	{
		newNode->rlink = newNode;
		newNode->llink = newNode;
		list->head = newNode;
		return;
	}

	lastNode = FindLastNode(list);
	lastNode->rlink = newNode;
	list->head->llink = newNode;
	newNode->llink = lastNode;
	newNode->rlink = list->head;
	list->head = newNode;
}

static void AddLastCircularLinkedList(CircularLinkedList *list, Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	Node *lastNode;
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	if (!list->head)
	{
		newNode->rlink = newNode;
		newNode->llink = newNode;
		list->head = newNode;
		return;
	}
	lastNode = FindLastNode(list);
	lastNode->rlink = newNode;
	newNode->rlink = list->head;
	newNode->llink = lastNode;
}

static void InsertCircularLinkedList(Node *node, Element item)
{
	Node *newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, NULL, sizeof(Node));
	newNode->item = item;

	newNode->llink = node;
	newNode->rlink = node->rlink;
	node->rlink->llink = newNode;
	node->rlink = newNode;
}

static void DeleteCircularLinkedList(CircularLinkedList *list, const int key)
{
	Node *begin = list->head;
	Node *end = FindLastNode(list);

	while (begin)
	{
		if (begin->item.key == key)
		{
			if (begin == list->head)
			{
				if (begin->rlink == begin)
				{
					free(begin);
					list->head = NULL;
					break;
				}
				list->head = begin->rlink;
				begin->rlink->llink = end;
				end->rlink = list->head;
				free(begin);
				break;
			}
			else
			{
				begin->rlink->llink = begin->llink;
				begin->llink->rlink = begin->rlink;
				free(begin);
				break;
			}
		}
		else if (begin->rlink == list->head)
			break;
		begin = begin->rlink;
	}
}

static void PrintCircularLinkedList(CircularLinkedList *list)
{
	Node *begin = list->head;
	Node *end = FindLastNode(list);
	while (begin)
	{
		printf("%d ", begin->item.key);
		if (begin == end)
			break;
		begin = begin->rlink;
	}
	printf("\n");
}
static void PrintReverseCircularLinkedList(CircularLinkedList *list)
{
	Node *begin = list->head;
	Node *end = FindLastNode(list);

	while (begin)
	{
		printf("%d ", end->item.key);
		if (begin == end)
			break;
		end = end->llink;
	}
	printf("\n");
}

static void DestroyCircularLinkedList(CircularLinkedList *list)
{
	Node *begin = list->head;
	Node *end = FindLastNode(list);
	Node *deleteNode;
	while (begin)
	{
		deleteNode = begin;
		begin = begin->rlink;
		free(deleteNode);
		if (begin == end)
			break;

	}
	free(list);
	list->head = NULL;
}

static Node* FindLastNode(CircularLinkedList *list)
{
	Node *begin = list->head;

	while (begin)
	{
		if (begin->rlink == list->head)
			break;
		begin = begin->rlink;
	}
	return begin;
}